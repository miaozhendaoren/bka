//****************************************************************************
// @Project       motencpot
// @Author        (alphabet.) Andreas Doepkens, Brian Schueler
// @Filename      MAIN.c
// @Date          21.03.2012
//
//****************************************************************************

// CAN0RXD P3.12 (CAN Node 0-Ausgang auf Tristate setzen)
// Auskommentieren, wenn der Ausgangstreiber im Pull-Up-Modus
// betrieben werden soll. (Siehe hierzu auch Eintrag in myDaveDoc.txt)
//#define CAN_TRISTATE

#include "myboardinit.h"
#include <stdio.h>
#include <math.h>


void v24PutString(char *s);

float pi_regler(float speed, float soll, float ist) {
	return speed * (soll / ist);
}

void setDirection(int direction) {
	switch(direction)
	{
		case -1: // backward
			IO_vSetPin(IO_P0_1);
			IO_vResetPin(IO_P0_2);
		break;

		case 0: // stop
			IO_vResetPin(IO_P0_2);
			IO_vResetPin(IO_P0_1);
		break;

		case 1: // forward
			IO_vSetPin(IO_P0_2);
			IO_vResetPin(IO_P0_1);
		break;

		default:
			v24PutString("Unknown direction\r\n");
		break;
	}
}

void v24PutString(char *s)
{
    char *sind=s;
	while (*sind!=0)
	{
		while (!ASC1_ubTxDataReady());
	    ASC1_vSendData(*sind);
	    sind++;
	}
}

int getCmpDutyCycle(uword reload, float dutycycle)
{
	//Berechnung des Comparewertes für die Prozentangabe des HI/LO-PWM-Verhältnisses
	return ((dutycycle)*reload)+(0xffffff*(1-dutycycle));
}


// Anschlüsse an die uC-Karte:
// ---------------------------

// Taster rot     : P0.4 und GND (pull-up)
// Taster schwarz : P0.5 und GND (pull-up)

// Geschwindigkeit für Motor an PWM (P0.0)
//              IN1 an P0.1 (symbol. IO_P0_1)
//              IN2 an P0.2 (symbol. IO_P0_2)
//
//                       IN1==1 && IN2==0 -> Motor forward
//                       IN1==0 && IN2==1 -> Motor reverse
//                       IN1==IN2         -> Motor fast stop
//


// Zaehlung der Encoderflanken am externen Interrupt (Portpin P0.14: Encoder Kanal A)
// die zugehörige ISR befindet sich in der Datei SCU.c:
//           void INTERRUPT (SCU_SRN0INT) SCU_viSRN0(void)
//
extern volatile unsigned int countEncoderTicks;
volatile unsigned int current_encoder_ticks;
//
// Encoder Kanal B an P0.7 (zur Bestimmung der Drehrichtung)


// Potentiometer: Mittenabriff an AN0 (siehe Variable "uword adcResult")
//


// Zählvariable für die Anzahl der Timer0-Überläufe
extern volatile unsigned int countTimerOverflows;
// die zugehörige ISR befindet sich in der Datei GPTA0.c:
//           void INTERRUPT (GPTA0_SRN5INT) GPTA0_viSRN5(void)
// ACHTUNG: Vor Benutzung von printf( ... ) muss der
//          Timer-Interrupt deaktiviert werden
//
// Makros zur Festlegung der Timer-Frequenz (in Hertz oder Mikrosekunden)
#define TMR_RELOAD_HZ(freq) (0xFFFFFF-(90000000/(freq)))
#define TMR_RELOAD_US(us) (TMR_RELOAD_HZ(1000000/(us)))


// V24-Kommunikation
// -----------------
//
// Verwendete Baud Rate 9600, 1 Stoppbit, keine Parität
// TxD an Port P3.8
// RxD an Port P3.9
// Funktionen zum Senden/Empfangen s. ASC1.c


void main(void)
{
   volatile int i;
   uword adcResult = 0;
   char s[80];
   char cruise_control = 0;
   float controlled_speed = 0;
   float saved_ticks = 0;
   float allowed_delta_speed = 0;
   float gas_pedal_speed = 0;
   float current_speed;
   float current_delta_speed;
   int button_timer = 0;

   // CAN-Bus-Variablen
   int datalength;
   CAN_SWObj TransCan_Obj1, TransCan_Obj2; // 2 Transmit-Messageobjekte
   CAN_SWObj RecCan_Obj3,   RecCan_Obj4;   // 2 Receive-Messageobjekte
   CAN_SWObj RecCanBCast_Obj15;            // Broadcast-Messageobjekt


   // Initialisierung
   MAIN_vInit();
   // Alle Interrupts AUS
   DISABLE();
   // nach erfolgreicher Initialisierung leuchtet die unterste Leuchtdiode
   // auf dem Board; alle anderen LEDs sind ausgeschaltet
   printf("Board Initialisierung OK (Eine blaue LED sollte leuchten).\n");
   v24PutString("V24 Initialisierung OK.\r\n");
   // Alle Interrupts EIN
   ENABLE();

   // Timer: Wert (Freq. oder us) setzen und einschalten
   // --------------------------------------------------
   // Frequenz darf nicht kleiner als 10Hz (100000us) sein
   GPTA0_vSetGTReload(GPTA0_GT, 0, TMR_RELOAD_HZ(10));
   GPTA0_vStartGTTimer(0);


   // Drehrichtung des Motors einstellen (hier: forward)
   // -------------------------------------------------
   setDirection(1);


   // PWM-Einrichtung einschalten
   // ---------------------------
   GPTA0_vEnableTimerClock();
   GPTA0_vStartGTTimer(1);
   // Reloadwert (Frequenz)
   GPTA0_vSetGTReload(GPTA0_GT, 1, TMR_RELOAD_HZ(1000)); // 1000 Hz
   // Comparewerte (Tastverhältnis)
   // Achtung: 00 bzw. 01 für die beiden GTC (Global Timer Cells)!!!
   GPTA0_vWriteTmr(GPTA0_GTC, 00,
  			getCmpDutyCycle(GPTA0_uwGetGTReload(GPTA0_GT, 1),
  			0.5)); // oberer Comparewert
   GPTA0_vWriteTmr(GPTA0_GTC, 01, 0xFFFFFF); // unterer Comparewert
                                             // (ident. mit Timeroverflow-Wert)
   // Diese beiden GTCs stellen eine "globale" PWM-Einrichtung dar mit
   // dem Pulsverhältnis 50:50 (-> 0.5). Dieser ist die Clock für die im nächsten
   // Schritt realisierte lokale PWM mit LTCs


   // CAN-Message-Objekte initialisieren
   // ----------------------------------
   // init Obj1, 11-Bit Transmit-Object (siehe can.c)
   TransCan_Obj1.usMOCfg=0x18;        // 1 Daten-Byte(s), DIR=Transmit [8]
   CAN_vGetMsgObj(1,&TransCan_Obj1);  // Message-Objekt auslesen
   TransCan_Obj1.uwID=0x0011;         // Identifier setzen: 17 hex == 23 dec
   TransCan_Obj1.ubData[0]=0xee;
   CAN_vConfigMsgObj(1,&TransCan_Obj1);

   // init Obj2, 11-Bit Transmit-Object (siehe can.c)
   CAN_vGetMsgObj(2,&TransCan_Obj2);
   TransCan_Obj2.usMOCfg=0x38;        // 3 Daten-Byte(s), DIR=Transmit [8]
   TransCan_Obj2.uwID=0x0012;         // identifier-no 27 hex == 39 dec
   TransCan_Obj2.ubData[0]=0x03;
   TransCan_Obj2.ubData[1]=0x06;
   TransCan_Obj2.ubData[2]=0x09;
   CAN_vConfigMsgObj(2,&TransCan_Obj2);

   // init Obj3, 11-Bit Receive-Object (siehe can.c)
   CAN_vGetMsgObj(3,&RecCan_Obj3);    // Message-Objekt auslesen
   RecCan_Obj3.uwID=0x0013;           // Identifier setzen: 18 hex == 24 dec
   CAN_vConfigMsgObj(3,&RecCan_Obj3);

   // init Obj3, 11-Bit Receive-Object (siehe can.c)
   CAN_vGetMsgObj(4,&RecCan_Obj4);    // Message-Objekt auslesen
   RecCan_Obj4.uwID=0x0014;           // Identifier setzen: 28 hex == 40 dec
   CAN_vConfigMsgObj(4,&RecCan_Obj4);

   // init Obj15, Broadcast Receive-Object für alle Identifier
   // eine Initialisierung ist nicht erforderlich, da Obj.15 generell nur als Empfangsobjekt betrieben werden kann!!!
   while (1)
   {


#if 1
	   // Testcode 1: AD-Wandlung des Potis
	   // ---------------------------------

	   // 12-Bit ADC-Wandlung starten
	   ADC0_vStartSeq0ReqChNum(0,0,0,0);
	   // Warten bis Wandlung abgeschlossen
	   while(ADC0_uwBusy());
       // AD-Wert auslesen
	   adcResult=ADC0_uwGetResultData(RESULT_REG_0);

	   sprintf(s,"ADC Wert (Poti): %d mV \r\n", adcResult*5000/4096);
	   //v24PutString(s);
#endif


#if 1
	   // Testcode 2: PWM-Wert ausgeben (Ausgang: P0.0)
	   // --------------------------------------------
	   //(gesteuert über Potentiometer!!!)
	   // Diesen Testcode in Verbindung mit Testcode 1 betreiben!

	   // speed settings
	   gas_pedal_speed = adcResult*1.000/4096.0;

	   if (cruise_control != 1) {
		   current_speed = gas_pedal_speed;
	   } else {
		   current_speed = controlled_speed;
		   allowed_delta_speed = 0.05;

		   current_delta_speed = fabs(current_speed - gas_pedal_speed);

		   if ( current_delta_speed > allowed_delta_speed ) {
			   cruise_control = 0;
			   current_speed = gas_pedal_speed;
			   sprintf(s, "Tempomat deaktiviert, durch überschreiten.\r\n");
			   v24PutString(s);
			   sprintf(s, "Controlled Speed: %f Current Speed: %f.\r\n", controlled_speed, current_speed);
			   v24PutString(s);
		   }
	   }




	   //sprintf(s, "%f", current_speed);
	   //v24PutString(s);

	   current_speed = current_speed - 0.5;

	   if (current_speed < 0.02) {
		   setDirection(-1);
		   current_speed = current_speed * -1;
	   } else if (current_speed > 0.02) {
		   setDirection(1);
	   } else {
		   setDirection(0);
	   }

	   current_speed = pi_regler(current_speed, saved_ticks, current_encoder_ticks);

	   sprintf(s, "Speed: %f\r\n", current_speed);
	   v24PutString(s);

	   // PWM-Tastverhältnis einstellen
	   GPTA0_vWriteTmr(GPTA0_GTC, 00,
	   			getCmpDutyCycle(GPTA0_uwGetGTReload(GPTA0_GT, 1),
//	   			(float)adcResult*1.5151/4096.0)); // oberer Comparewert
	   			current_speed * 2)); // oberer Comparewert

	   sprintf(s,"Prozent-Wert (Poti): %.0f Prozent high \r\n", (float)adcResult*100.0/4096.0);
	   //v24PutString(s);

#endif


#if 1
	   // Testcode 3: roter/schwarzer Taster-Abfragen (und Status auf LEDs ausgeben)
	   // ---------------------------
	   // Achtung: printf() möglichst nicht verwenden!

	   if (!IO_ubReadPin(IO_P0_4)) // roter Taster
	   {
		   //IO_vSetPin(IO_P0_2);
		   //IO_vResetPin(IO_P0_1);
		   v24PutString("Tempomat ausgeschaltet\r\n");
		   cruise_control = 0;
	   }
	   if (!IO_ubReadPin(IO_P0_5)) // schwarzer Taster
	   {
		   // IO_vSetPin(IO_P0_1);
		   // IO_vResetPin(IO_P0_2);
		   if ( button_timer == 0 ) {

			   if ( cruise_control == 0 ) {
				   v24PutString("Tempomat eingeschaltet\r\n");
				   cruise_control = 1;
				   controlled_speed = adcResult * 1.0000/4096.0;
				   saved_ticks = current_encoder_ticks;
			   } else {
				   v24PutString("Tempomat ausgeschaltet\r\n");
				   cruise_control = 0;
			   }
		   }
		   button_timer = 4;
	   }

#endif


#if 1
	   // Testcode 4: Anzahl der Encoderflanken (externer Interrupt an P0.14) ausgeben
	   // ----------------------------------------------------------------------------

	   IO_vWritePort(P5,(unsigned char)~(countEncoderTicks)); // Anzahl der Encoderticks auf LEDs ausgeben

#endif


#if 1
	   // Testcode 5: (etwa) jede Sekunde LED togglen lassen
	   // ---------------------------
	   // Timer-Interrupt (GT0) wurde oben auf 10Hz eingestellt, d.h. er wird alle 100ms ausgelöst!

	   if (countTimerOverflows>=10)
	   {
		   countTimerOverflows=0;
		   IO_vTogglePin(IO_P5_7);

		   current_encoder_ticks = countEncoderTicks;
		   countEncoderTicks = 0;

		   //sprintf(s,"Encoderticks: %d\r\n", current_encoder_ticks);
		   //v24PutString(s);
	   }

	   if ( countTimerOverflows >= 1) {
		   if (button_timer > 0) {
			   button_timer--;
		   }
	   }
#endif


#if 0

	   // Testcode 6: CAN-Bus Betrieb
	   // ---------------------------
	   // ACHTUNG: Tristate oder Pull-Up Modus beachten für RXD (s. oben)!!!

	   for(i=0; i<3000000; i++);  // ACHTUNG: "i" muss "volatile int" sein!
	   CAN_vTransmit(1);
	   CAN_vTransmit(2);

	   if(CAN_ubNewData(3)) {
	     	IO_vWritePort(P5,0x00);
	        CAN_vGetMsgObj(3, &RecCan_Obj3);
	        v24PutString("New Can Message in Obj.3:\r\n");
	        sprintf(s,"Identifier(hex)   : %02x \r\n",RecCan_Obj3.uwID);
	        v24PutString(s);
	        datalength=RecCan_Obj3.usMOCfg>>4;
	        sprintf(s,"Data-length : %d \r\n",(int)datalength);
	        v24PutString(s);
	        for (i=0; i<datalength; i++){
	              sprintf(s,"Data[%d](hex): %02x \r\n",(int)i,(int)RecCan_Obj3.ubData[i]);
	              v24PutString(s);
	        }
	        v24PutString("\r\n");
	        CAN_vReleaseObj(3);
	   }

#if 1
	   // Broadcast-Message-Object (Receive-only)
	   // Fängt jedes Message-Object ab, das nicht individuell durch
	   // einen eigenen Identifier zugewiesen wurde.
	   if(CAN_ubNewData(15)) {
	    	IO_vWritePort(P5,0xaa);
	        CAN_vGetMsgObj(15, &RecCanBCast_Obj15);
	        v24PutString("New Broadcast Message in Obj.15:\r\n");
	        sprintf(s,"Identifier(hex)   : %02x \r\n",RecCanBCast_Obj15.uwID);
	        v24PutString(s);
	        datalength=RecCanBCast_Obj15.usMOCfg>>4;
	        sprintf(s,"Data-length : %d \r\n",(int)datalength);
	        v24PutString(s);
	        for (i=0; i<datalength; i++){
	           sprintf(s,"Data[%d](hex): %02x \r\n",(int)i,(int)RecCanBCast_Obj15.ubData[i]);
	           v24PutString(s);
	        }
	        v24PutString("\r\n");
	        CAN_vReleaseObj(15);
	   }
#endif
#endif

#if 0
	   v24PutString("Hello, again!\r\n");
#endif

   } // end while(1)

}
