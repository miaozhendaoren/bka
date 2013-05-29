//****************************************************************************
// @Project       motencpot
// @Module        myboardinit.c
// @Author        (alphabet.) Andreas Doepkens, Brian Schueler
// @Filename      MAIN.c
// @Date          21.03.2012
//
// Alle Funktionen von DAvE erzeugt und aus MAIN.c nach hier ausgelagert
//
//****************************************************************************
#include "myboardinit.h"

//****************************************************************************
// @Global Variables
//****************************************************************************
volatile unsigned int DummyToForceRead;

void MAIN_vInit(void)
{
  // USER CODE BEGIN (Init,2)

  // USER CODE END

  //// -----------------------------------------------------------------------
  //// Begin of Important Settings for the Start-Up File
  //// -----------------------------------------------------------------------
  ///  All following settings must be set in the start-up file. You can use
  ///  DAvE's project file (*.dpt) to include this register values into your
  ///  compiler EDE.

    ///  ---------------------------------------------------------------------
    ///  System Peripheral Bus Control Unit (SBCU):
    ///  ---------------------------------------------------------------------
    ///  SBCU starvation protection is enabled
    ///  the debug trace is enabled. Error information is captured in
    ///  register SBCU_EADD, SBCU_EDAT and SBCU_ECON
    ///  sample period of request for starvation protection: 64
    ///  SBCU bus time-out value: 65536 cycles

    //// this register must be set in the start-up file
    //// SBCU_CON  =  0x4009FFFF;

    ///  ---------------------------------------------------------------------
    ///  LMB External Bus Unit (EBU):
    ///  ---------------------------------------------------------------------
    ///  - enable the EBU module clock
    ///  - disable EndInit Protection of the CLC Register
    ///  - request EBU to run off input clock divided by 1

    //// this register must be set in the start-up file
    //// EBU_CLC  =  0x00110000;

    ///  External Arbitration:
    ///  - EBU is disabled

    //// this register must be set in the start-up file
    //// EBU_MODCON  =  0x00000000;

    ///  ---------------------------------------------------------------------
    ///  Data Memory Interface (DMI):
    ///  ---------------------------------------------------------------------
    ///  - No Data Cache
    ///  - 128 Kbyte Data Memory

    //// this register must be set in the start-up file
    //// DMI_CON  =  0x08000802;

    ///  ---------------------------------------------------------------------
    ///  Program Memory Interface (PMI):
    ///  ---------------------------------------------------------------------
    ///  - No Instruction Cache
    ///  - 40 Kbyte Program Memory

    //// this register must be set in the start-up file
    //// PMI_CON2  =  0x02800284;

  //// -----------------------------------------------------------------------
  //// End of Important Settings for the Start-Up File
  //// -----------------------------------------------------------------------

  ///  -----------------------------------------------------------------------
  ///  Clock System:
  ///  -----------------------------------------------------------------------
  ///  - external clock frequency: 20,00 MHz
  ///  - input divider (PDIV): 2
  ///  - PLL operation (VCOBYP = 0)
  ///  - VCO range: 700 MHz - 800 MHz
  ///  - feedback divider (NDIV): 72
  ///  - the VCO output frequency is: 720,00 MHz
  ///  - output divider (KDIV): 4
  ///  - CPU clock: 180,00 MHz
  ///  - the ratio fcpu /ffpi is  2 / 1
  ///  - the ratio fcpu /flmb is  1 / 1
  ///  - the ratio fcpu /fpcp is  1 / 1
  ///  - system clock: 90,00 MHz


   /// Comparing with the Compiler settings
   if(((SCU_PLLCON0  & 0X1018E00) != 0X1018E00) || ((SCU_PLLCON1 & 0X20003) != 0X20003) \
       || ((SCU_CCUCON0 & 0X1) != 0X1))
   {

  //// - after a software reset PLL refuse to lock again unless oscillator is
  ////   disconnected first

    MAIN_vResetENDINIT();
    SCU_PLLCON0_VCOBYP  =  0;    // reset VCO bypass
    SCU_PLLCON0_SETFINDIS  =  1; // disconnect OSC from PLL
    MAIN_vSetENDINIT();


  if (MAIN_vResetCheck())
  {
    if (!SCU_PLLSTAT_PWDSTAT)
    {
      MAIN_vResetENDINIT();
      SCU_CCUCON0  =  0x00000001; // set FPI,LMB and PCP dividers
      SCU_PLLCON0_VCOBYP  =  1;  // set VCO bypass (goto Prescaler Mode)
      while (!SCU_PLLSTAT_VCOBYST);// wait for prescaler mode
      SCU_PLLCON0  =  0x01058E21; // set P,N divider, connect OSC
      SCU_PLLCON1  =  0x00020003; // set K1,K2 divider
      MAIN_vSetENDINIT();
      while (SCU_PLLSTAT_VCOLOCK == 0);// wait for LOCK
      MAIN_vResetENDINIT();
      SCU_PLLCON0_VCOBYP  =  0;  // Reset VCO bypass (Leave Prescaler Mode)
      MAIN_vSetENDINIT();
    }
   }
  }

  ///  -----------------------------------------------------------------------
  ///  Interrupt System:
  ///  -----------------------------------------------------------------------
  ///  - four arbitration cycles (max. 255 interrupt sources)
  ///  - two clocks per arbitration cycle

  MTCR(0xFE2C,  0x00000000);     // load CPU interrupt control register
  ISYNC();

  ///  -----------------------------------------------------------------------
  ///  Peripheral Control Processor (PCP):
  ///  -----------------------------------------------------------------------
  ///  - stop the PCP internal clock when PCP is idle

  ///  - use Full Context save area (R[0] - R[7])
  ///  - start progam counter as left by last invocation
  ///  - channel watchdog is disabled
  ///  - maximum channel number checking is disabled

  MAIN_vResetENDINIT();
  PCP_CLC        =  0x00000000;  // load PCP clock control register
  PCP_CS         =  0x00000200;  // load PCP control and status register
  MAIN_vSetENDINIT();

  ///  - four arbitration cycles (max. 255 PCP channels)
  ///  - two clocks per arbitration cycle
  PCP_ICR        =  0x00000000;  // load PCP interrupt control register

  ///  - the PCP warning mechanism is disabled
  PCP_ITR        =  0x00000000;  // load PCP interrupt threshold register

  ///  - type of service of PCP node 4 is CPU interrupt
  PCP_SRC4       =  0x00001000;  // load service request control register 4

  ///  - type of service of PCP node 5 is CPU interrupt
  PCP_SRC5       =  0x00001000;  // load service request control register 5

  ///  - type of service of PCP node 6 is CPU interrupt
  PCP_SRC6       =  0x00001000;  // load service request control register 6

  ///  - type of service of PCP node 7 is CPU interrupt
  PCP_SRC7       =  0x00001000;  // load service request control register 7

  ///  - type of service of PCP node 8 is CPU interrupt
  PCP_SRC8       =  0x00001000;  // load service request control register 8

  ///  -----------------------------------------------------------------------
  ///  Configuration of the DMA Module Clock:
  ///  -----------------------------------------------------------------------
  ///  - enable the DMA module

  MAIN_vResetENDINIT();
  DMA_CLC        =  0x00000008;  // DMA clock control register
  DummyToForceRead  =  DMA_CLC;  // read it back to ensure it is read
  MAIN_vSetENDINIT();

  //   -----------------------------------------------------------------------
  //   Initialization of the Peripherals:
  //   -----------------------------------------------------------------------
  //   initializes the Parallel Ports
  IO_vInit();

  //   initializes the System Control Unit (SCU)
  SCU_vInit();

  //   initializes the Asynchronous Synchronous Serial Interface 1 (ASC1)
  ASC1_vInit();

  //   initializes the MultiCAN Controller
  CAN_vInit();

  //   initializes the General Purpose Timer Array 0 (GPTA0)
  GPTA0_vInit();

  //   initializes the Analog Digital Converter 0 (ADC0)
  ADC0_vInit();


  // USER CODE BEGIN (Init,3)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  System Start Conditions:
  ///  -----------------------------------------------------------------------

  //// - the CPU interrupt system is globally enabled
  ENABLE();

  //// - the PCP interrupt system is globally disabled


  // USER CODE BEGIN (Init,4)

  // USER CODE END

} //  End of function MAIN_vInit


//****************************************************************************
// @Function      void MAIN_vWriteWDTCON0(uword uwValue)
//
//----------------------------------------------------------------------------
// @Description   This function writes the parameter uwValue to the WDT_CON0
//                register which is password protected.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    uwValue:
//                Value for the WDTCON0 register
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (WriteWDTCON0,1)

// USER CODE END

void MAIN_vWriteWDTCON0(uword uwValue)
{
  uword uwDummy;

  uwDummy        =  WDT_CON0;
  uwDummy |=  0x000000F0;       //  set HWPW1 = 1111b

  if(WDT_CON1_DR)
  {
    uwDummy |=  0x00000008;     //  set HWPW0 = WDTDR
  }
  else
  {
    uwDummy &= ~0x00000008;     //  set HWPW0 = WDTDR
  }
  if(WDT_CON1_IR)
  {
    uwDummy |=  0x00000004;     //  set HWPW0 = WDTIR
  }
  else
  {
    uwDummy &= ~0x00000004;     //  set HWPW0 = WDTIR
  }

  uwDummy &= ~0x00000002;       //  set WDTLCK = 0
  WDT_CON0 =  uwDummy;          //  unlock access

  uwValue  |=  0x000000F2;      //  set HWPW1 = 1111b and WDTLCK = 1
  uwValue  &= ~0x0000000C;      //  set HWPW0 = 00b
  WDT_CON0  =  uwValue;         //  write access and lock

} //  End of function MAIN_vWriteWDTCON0



//****************************************************************************
// @Function         ubyte MAIN_vResetCheck(void)
//
//----------------------------------------------------------------------------
// @Description
//      This function checks the reset types (application/system).
//
//----------------------------------------------------------------------------
// @Returnvalue   1 on system reset
//                0 on application reset
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

ubyte MAIN_vResetCheck(void)
{
  ubyte ubWDTAppReset,ubESR0AppReset,ubESR1AppReset,ubSWAppReset;
  ubyte ubWDTSysReset,ubESR1SysReset,ubSWSysReset;
  ubyte ubChkAppReset,ubEsr0Chk,ubOtherSysReset;
  uword uwReset,uwOtherReset;

  ubWDTAppReset = ((SCU_RSTCON & (uword)(0X00000080)) && (SCU_RSTSTAT & (uword)(0X00000008)));
  ubSWAppReset = ((SCU_RSTCON & (uword)(0X00000200)) && (SCU_RSTSTAT & (uword)(0X00000010)));
  ubESR0AppReset = ((SCU_RSTCON & (uword)(0X00000002)) && (SCU_RSTSTAT & (uword)(0X00000001)));
  ubESR1AppReset = ((SCU_RSTCON & (uword)(0X00000008)) && (SCU_RSTSTAT & (uword)(0X00000002)));
  ubChkAppReset = (!(ubWDTAppReset || ubSWAppReset || ubESR1AppReset));
  ubEsr0Chk = ((SCU_RSTCON & (uword)(0X00000003)) && (SCU_RSTSTAT & (uword)(0X0000001B)));

  ubWDTSysReset = ((SCU_RSTCON & (uword)(0X00000040)) && (SCU_RSTSTAT & (uword)(0X00000008)));
  ubSWSysReset = ((SCU_RSTCON & (uword)(0X00000100)) && (SCU_RSTSTAT & (uword)(0X00000010)));
  ubESR1SysReset = ((SCU_RSTCON & (uword)(0X00000004)) && (SCU_RSTSTAT & (uword)(0X00000002)));
  ubOtherSysReset = ( ((ubWDTSysReset || ubSWSysReset || ubESR1SysReset))&& (SCU_RSTSTAT & (uword)(0X00000001)));

  uwReset =  (((ubChkAppReset & !ubEsr0Chk)||(ubChkAppReset & ubEsr0Chk) && (!(ubESR0AppReset)|| ubOtherSysReset)));
  uwOtherReset = (SCU_RSTSTAT & (uword)(0X003F0000)) ;
  if(uwReset || uwOtherReset)
  {
    return 1;
  }
  else
  {
    return 0;
  }

} //  End of function MAIN_vResetCheck


//****************************************************************************
// @Function      sword main(void)
//
//----------------------------------------------------------------------------
// @Description   This is the main function.
//
//----------------------------------------------------------------------------
// @Returnvalue   Returns an sword value
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

// USER CODE BEGIN (Main,1)

// USER CODE END
