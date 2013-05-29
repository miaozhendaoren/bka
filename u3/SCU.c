//****************************************************************************
// @Module        System Control Unit (SCU)
// @Filename      SCU.c
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains functions that use the SCU module.
//
//----------------------------------------------------------------------------
// @Date          21.03.2012 15:50:36
//
//****************************************************************************

// USER CODE BEGIN (SCU_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"
#include "io.h"

// USER CODE BEGIN (SCU_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (SCU_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (SCU_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (SCU_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (SCU_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (SCU_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (SCU_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (SCU_General,9)

// USER CODE END


//****************************************************************************
// @Function      void SCU_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the SCU function 
//                library. It is assumed that the SFRs used by this library 
//                are in their reset state. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void SCU_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Settings for the Watchdog Timer:
  ///  -----------------------------------------------------------------------
  ///  - the watchdog timer is disabled
  ///  - the input frequency is fFPI / 16384
  ///  - period in normal watchdog mode =  728,18 us
  ///  - period in time-out mode =  728,18 us

  MAIN_vWriteWDTCON0(0xFFFC0000);
  WDT_CON1       =  0x00000008;  // load watchdog control register 1
  MAIN_vSetENDINIT();

  ///  -----------------------------------------------------------------------
  ///  Softare Reset Configuration:
  ///  -----------------------------------------------------------------------
  ///  - No reset is generated for a trigger of software reset
  ///  use the following programmed software configuration for booting after 
  ///  software reset:
  ///  - internal start from Flash. (CFG[15:8] = 11xxxxxx)
  ///  - HWCFG is not updated with SWCFG upon on Application Reset
  ///  -----------------------------------------------------------------------
  ///  ESRx Configuration:
  ///  -----------------------------------------------------------------------
  ///  ESR0
  ///  - ESR0 module is not enabled
  ///  ESR1
  ///  - ESR1 module is not enabled
  MAIN_vResetENDINIT();
  SCU_ESRCFG0    =  0x00000000;  // ESR0 confgiuration register
  SCU_ESRCFG1    =  0x00000000;  // ESR1 confgiuration register
  SCU_TRAPDIS    =  0x000003FB;  // Trap disable register configuration
  SCU_RSTCON     =  0x00000080;  // Reset configuration register
  MAIN_vSetENDINIT();

  SCU_IOCR       =  0x00000000;  // load input/output control register


  ///  -----------------------------------------------------------------------
  ///  External Request Unit:
  ///  -----------------------------------------------------------------------
  ///  REQLINE0 configuration:
  ///  - use signal REQ4 (= P0.14) as input
  ///  - a detected falling edge generates a trigger event
  ///  - bit INTF0 will be reset automatically if an edge of the input signal 
  ///    is detected, which has not been selected
  ///  - generate trigger event on output channel 0

  ///  REQLINE1 configuration:
  ///  - use signal REQ1 (= none) as input

  ///  REQLINE2 configuration:
  ///  - use signal REQ2 (= none) as input

  ///  REQLINE3 configuration:
  ///  - use signal REQ3 (= none) as input

  ///  Output channel 0 configuration:
  ///  - the bit INTF0 is taken into consideration for the pattern detection
  ///  - the detected pattern is taken into account; an activation of IOUT0 
  ///    is only possible due to a trigger event while the pattern is detected
  ///  - ERU0 interrupt generation is enabled
  ///  - ERU0 interrupt node pointer: SCU SRN 0

  ///  Output channel 1 configuration:
  ///  - the detected pattern is not taken into account; an activation of 
  ///    IOUT1 is always possible due to a trigger event

  ///  Output channel 2 configuration:
  ///  - the detected pattern is not taken into account; an activation of 
  ///    IOUT2 is always possible due to a trigger event

  ///  Output channel 3 configuration:
  ///  - the detected pattern is not taken into account; an activation of 
  ///    IOUT3 is always possible due to a trigger event

  SCU_EICR0      =  0x00000D10;  // external input channel 0 register
  SCU_EICR1      =  0x00000000;  // external input channel 1 register
  SCU_IGCR0      =  0x00008001;  // interrupt gating 0 register
  SCU_IGCR1      =  0x00000000;  // interrupt gating 1 register
  SCU_INTDIS     =  0x000000BD;  // interrupt disable register
  SCU_INTNP      =  0x00000000;  // interrupt node pointer register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used ERU Port Pins:
  ///  -----------------------------------------------------------------------
  ///  - P0.14 is used as  SCU_ERU input signal 4 ( REQ4)
  ///  - the pull-up device is assigned
  ///  - output driver characteristic: Medium driver

  MAIN_vResetENDINIT();
  P0_PDR        |=  0x00040000;  // load driver mode register
  MAIN_vSetENDINIT();
  P0_IOCR12      = (P0_IOCR12 & ~0x00F00000) | 0x00200000; // load control 
                                                           // register

  ///  -----------------------------------------------------------------------
  ///  Configuration of EXTCLK Output (both 0 and 1): 
  ///  -----------------------------------------------------------------------
  ///  - the EXTCLK1 output is disabled
  ///  - the EXTCLK0 output is disabled

  MAIN_vResetENDINIT();
  SCU_FDR        =  0x000003FE;  // load fractional divider register
  MAIN_vSetENDINIT();


  ///  -----------------------------------------------------------------------
  ///  Configuration of Emergency Stop:
  ///  -----------------------------------------------------------------------
  ///  - the clocked path with the emergency stop flag (EMSF) is selected

  MAIN_vResetENDINIT();
  SCU_EMSR       =  0x00000000;  // emergency stop register
  MAIN_vSetENDINIT();

  ///  -----------------------------------------------------------------------
  ///  Configuration of SCU Service Request Nodes 0 to 3 :
  ///  -----------------------------------------------------------------------
  ///  - SRN0 service request node configuration:
  ///  - SRN0 interrupt priority level (SRPN) = 3
  ///  - SRN0 CPU interrupt is selected

  SCU_SRC0       =  0x00001003;  // set service request control register


  // USER CODE BEGIN (Init,3)

  // USER CODE END

} //  End of function SCU_vInit


//****************************************************************************
// @Function      void SCU_vSetIdle(void) 
//
//----------------------------------------------------------------------------
// @Description   This function sets the CPU in IDLE mode. The CPU core clock 
//                is disabled. All peripherals remain powered and clocked. 
//                Processor memory is accessible to peripherals. A reset, 
//                watchdog timer event, a NMI Trap, or any enabled interrupt 
//                event will wake the CPU. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (SetIdle,1)

// USER CODE END

void SCU_vSetIdle(void)
{
  // USER CODE BEGIN (SetIdle,2)

  // USER CODE END

  SCU_PMCSR = 0x00000001;       //  set idle mode

  // USER CODE BEGIN (SetIdle,3)

  // USER CODE END

} //  End of function SCU_vSetIdle


//****************************************************************************
// @Function      void SCU_vSetSleep(void) 
//
//----------------------------------------------------------------------------
// @Description   This function sets the CPU in SLEEP mode. The system clock 
//                continues to be distributed only to those peripherals 
//                programmed to operate in Sleep Mode. A reset, watchdog 
//                timer event, a NMI Trap, or interrupts from operating 
//                peripherals will wake the CPU. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (SetSleep,1)

// USER CODE END

void SCU_vSetSleep(void)
{
  // USER CODE BEGIN (SetSleep,2)

  // USER CODE END

  SCU_PMCSR = 0x00000002;       //  set sleep mode

  // USER CODE BEGIN (SetSleep,3)

  // USER CODE END

} //  End of function SCU_vSetSleep


//****************************************************************************
// @Function      void SCU_vServiceWDT(ushort usReload, ubyte ubPassword) 
//
//----------------------------------------------------------------------------
// @Description   This function service the watchdog timer. If the watchdog 
//                timer is used in an application, it has to be regularly 
//                serviced to prevent it from overflowing. 
//                Example: 
//                To service the watchdog timer with the initialization 
//                reload value and without changing the password, this 
//                function must be called as follow: 
//                SCU_vServiceWDT(SCU_WDT_RELOAD,0);
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    usReload: 
//                16-bit reload value for the watchdog timer
// @Parameters    ubPassword: 
//                8-bit password
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (ServiceWDT,1)

// USER CODE END

void SCU_vServiceWDT(ushort usReload, ubyte ubPassword)
{
  MAIN_vWriteWDTCON0((usReload << 16) + (ubPassword << 8) + 1); // service WDT

} //  End of function SCU_vServiceWDT


//****************************************************************************
// @Function      void SCU_vDisableWDT(void) 
//
//----------------------------------------------------------------------------
// @Description   This function disables the watchdog timer.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (DisableWDT,1)

// USER CODE END

void SCU_vDisableWDT(void)
{
  MAIN_vResetENDINIT();
  WDT_CON1 |=  0x00000008;                   //  disable watchdog
  MAIN_vSetENDINIT();

} //  End of function SCU_vDisableWDT


//****************************************************************************
// @Function      void SCU_vEnableWDT(void) 
//
//----------------------------------------------------------------------------
// @Description   This function enables the watchdog timer.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (EnableWDT,1)

// USER CODE END

void SCU_vEnableWDT(void)
{
  MAIN_vResetENDINIT();
  WDT_CON1 &= ~0x00000008;                   //  enable watchdog
  MAIN_vSetENDINIT();

} //  End of function SCU_vEnableWDT


//****************************************************************************
// @Function      void SCU_vSoftReset(uword uwOptions) 
//
//----------------------------------------------------------------------------
// @Description   This function generates a software reset. The software 
//                reset triggers two functions either application reset or 
//                system reset. In addition, it has the option to change the 
//                boot configuration. 
//                Example: 
//                To reset the controller with the configured soft reset 
//                option, this function must be called as follow: 
//                SCU_vSoftReset(SCU_RESET_OPTIONS);
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    uwOptions: 
//                Required options for the soft reset (value for the RST_REQ 
//                register)
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (SoftReset,1)

// USER CODE END

void SCU_vSoftReset(uword uwOptions)
{
  // USER CODE BEGIN (SoftReset,2)

  // USER CODE END

  MAIN_vResetENDINIT();
  SCU_SWRSTCON = (uwOptions | 0x2);                        //  request SW reset
  MAIN_vSetENDINIT();

} //  End of function SCU_vSoftReset


//****************************************************************************
// @Function      void SCU_viSRN0(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the Service 
//                Request Node 0 of the SCU module. 
//                Please note that you have to add application specific code 
//                to this function.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (SRN0,1)
volatile unsigned int countEncoderTicks = 0;
// USER CODE END

void INTERRUPT (SCU_SRN0INT) SCU_viSRN0(void)
{

  // USER CODE BEGIN (SRN0,2)

  // USER CODE END

  if (SCU_INTSTAT_ERUI0)      // if ERU0 interrupt
  {
        // USER CODE BEGIN (SRN0_ERU0,1)
	    if (IO_ubReadPin(IO_P0_7)==0)
	    {
	    	// Drehrichtung forward
	    	countEncoderTicks++;
	    }
	    else
	    {
	    	// Drehrichtung backward
	        countEncoderTicks--;
	    }
        // USER CODE END

        SCU_INTCLR_ERUI0      = 1;    // clear ERU0 interrupt
  }


  // USER CODE BEGIN (SRN0,3)

  // USER CODE END

} //  End of function SCU_viSRN0



// USER CODE BEGIN (SCU_General,10)

// USER CODE END

