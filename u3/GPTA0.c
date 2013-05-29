//****************************************************************************
// @Module        General Purpose Timer Array 0 (GPTA0)
// @Filename      GPTA0.c
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains functions that use the GPTA0 module.
//
//----------------------------------------------------------------------------
// @Date          21.03.2012 15:56:00
//
//****************************************************************************

// USER CODE BEGIN (GPTA0_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (GPTA0_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPTA0_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (GPTA0_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPTA0_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPTA0_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPTA0_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (GPTA0_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (GPTA0_General,9)

// USER CODE END


//****************************************************************************
// @Function      void GPTA0_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the GPTA0 function 
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

void GPTA0_vInit(void)
{



  volatile unsigned int uwTemp;

  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the Module Clock:
  ///  -----------------------------------------------------------------------
  #ifndef GPTA_CLOCK_INITIALIZATION
  #define GPTA_CLOCK_INITIALIZATION

  ///  - the GPTA module is stopped during sleep mode
  ///  - normal divider mode is selected
  ///  - bit DISCLK is reset by hardware while input singnal ECEN 
  ///    (CAN_INT_O15) is at high level
  ///  - required GPTA module clock is 90,00 MHz
  ///  - real GPTA module clock is 90,00 MHz

  MAIN_vResetENDINIT();
  GPTA0_CLC      =  0x00000000;  // load clock control register
  uwTemp         =  GPTA0_CLC;   // dummy read to avoid pipeline effects
  while ((GPTA0_CLC & 0x00000002 )== 0x00000002);  //wait until module is enabled
  GPTA0_FDR      =  0x400043FF;  // load fractional divider register
  uwTemp         =  GPTA0_FDR;   // dummy read to avoid pipeline effects
  MAIN_vSetENDINIT();

  #endif // end #ifndef GPTA_CLOCK_INITIALIZATION

  ///  -----------------------------------------------------------------------
  ///  Configuration of Filter and Prescaler Cells 0 - 5:
  ///  -----------------------------------------------------------------------
  ///  FPC0 configuration:
  ///  - FPC0 input selection: 90,00 MHz
  ///  - FPC0 operation mode: Delayed debounce filter mode on both edges
  ///  - Filter clock selection: Use bus line 0 (=GPTA0 clock / 2^0 (= 90,00 
  ///    MHz; 0,01 us))
  ///  - FPC0 timer is decremented on glitch
  ///  - FPC0 compare value is 0x0000

  GPTA0_FPCCTR0  =  0x00200000;  // load FPC0 control register
  GPTA0_FPCTIM0  =  0x00000000;  // load FPC0 timer register

  ///  FPC1 configuration:
  ///  - FPC1 input selection: 90,00 MHz
  ///  - FPC1 operation mode: Delayed debounce filter mode on both edges
  ///  - Filter clock selection: Use bus line 0 (=GPTA0 clock / 2^0 (= 90,00 
  ///    MHz; 0,01 us))
  ///  - FPC1 timer is decremented on glitch
  ///  - FPC1 compare value is 0x0000

  GPTA0_FPCCTR1  =  0x00200000;  // load FPC1 control register
  GPTA0_FPCTIM1  =  0x00000000;  // load FPC1 timer register

  ///  FPC2 configuration:
  ///  - FPC2 input selection: 90,00 MHz
  ///  - FPC2 operation mode: Delayed debounce filter mode on both edges
  ///  - Filter clock selection: Use bus line 0 (=GPTA0 clock / 2^0 (= 90,00 
  ///    MHz; 0,01 us))
  ///  - FPC2 timer is decremented on glitch
  ///  - FPC2 compare value is 0x0000

  GPTA0_FPCCTR2  =  0x00200000;  // load FPC2 control register
  GPTA0_FPCTIM2  =  0x00000000;  // load FPC2 timer register

  ///  FPC3 configuration:
  ///  - FPC3 input selection: 90,00 MHz
  ///  - FPC3 operation mode: Delayed debounce filter mode on both edges
  ///  - Filter clock selection: Use bus line 0 (=GPTA0 clock / 2^0 (= 90,00 
  ///    MHz; 0,01 us))
  ///  - FPC3 timer is decremented on glitch
  ///  - FPC3 compare value is 0x0000

  GPTA0_FPCCTR3  =  0x00200000;  // load FPC3 control register
  GPTA0_FPCTIM3  =  0x00000000;  // load FPC3 timer register

  ///  FPC4 configuration:
  ///  - FPC4 input selection: 90,00 MHz
  ///  - FPC4 operation mode: Delayed debounce filter mode on both edges
  ///  - Filter clock selection: Use bus line 0 (=GPTA0 clock / 2^0 (= 90,00 
  ///    MHz; 0,01 us))
  ///  - FPC4 timer is decremented on glitch
  ///  - FPC4 compare value is 0x0000

  GPTA0_FPCCTR4  =  0x00200000;  // load FPC4 control register
  GPTA0_FPCTIM4  =  0x00000000;  // load FPC4 timer register

  ///  FPC5 configuration:
  ///  - FPC5 input selection: 90,00 MHz
  ///  - FPC5 operation mode: Delayed debounce filter mode on both edges
  ///  - Filter clock selection: Use bus line 0 (=GPTA0 clock / 2^0 (= 90,00 
  ///    MHz; 0,01 us))
  ///  - FPC5 timer is decremented on glitch
  ///  - FPC5 compare value is 0x0000

  GPTA0_FPCCTR5  =  0x00200000;  // load FPC5 control register
  GPTA0_FPCTIM5  =  0x00000000;  // load FPC5 timer register


  GPTA0_FPCSTAT  =  0x00000000;  // load FPC status register


  ///  -----------------------------------------------------------------------
  ///  Configuration of Phase Discrimination Logic Cells 0 - 1:
  ///  -----------------------------------------------------------------------
  ///  PDL0 configuratin:
  ///  - PDL0 provide DCM0 cell input with FPC0 output (= 90,00 MHz)
  ///  - PDL0 operates in '2 Sensor Mode' and provide DCM1 cell input with 
  ///    FPC2 output (= 90,00 MHz)

  ///  PDL1 configuratin:
  ///  - PDL1 provide DCM2 cell input with FPC3 output (= 90,00 MHz)
  ///  - PDL1 operates in '2 Sensor Mode' and provide DCM3 cell input with 
  ///    FPC5 output (= 90,00 MHz)

  GPTA0_PDLCTR   =  0x00000000;  // load PDL control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Duty Cycle Measurement and Limit Checking Cells 0 - 3:
  ///  -----------------------------------------------------------------------
  ///  DCM0 configuration:
  ///  - DCM0 input signal is 90,00 MHz
  ///  - DCM0 capture the timer contents to CAV capture register on a falling 
  ///    input signal edge

  GPTA0_DCMCTR0  =  0x00000000;  // load DCM control register 0
  GPTA0_DCMCOV0  =  0x00000000;  // load DCM capture/compare register 0
  GPTA0_DCMTIM0  =  0x00000000;  // load DCM timer register 0
  GPTA0_DCMCAV0  =  0x00000000;  // load DCM capture register 0

  ///  DCM1 configuration:
  ///  - DCM1 input signal is 90,00 MHz
  ///  - DCM1 capture the timer contents to CAV capture register on a falling 
  ///    input signal edge

  GPTA0_DCMCTR1  =  0x00000000;  // load DCM control register 1
  GPTA0_DCMCOV1  =  0x00000000;  // load DCM capture/compare register 1
  GPTA0_DCMTIM1  =  0x00000000;  // load DCM timer register 1
  GPTA0_DCMCAV1  =  0x00000000;  // load DCM capture register 1

  ///  DCM2 configuration:
  ///  - DCM2 input signal is 90,00 MHz
  ///  - DCM2 capture the timer contents to CAV capture register on a falling 
  ///    input signal edge

  GPTA0_DCMCTR2  =  0x00000000;  // load DCM control register 2
  GPTA0_DCMCOV2  =  0x00000000;  // load DCM capture/compare register 2
  GPTA0_DCMTIM2  =  0x00000000;  // load DCM timer register 2
  GPTA0_DCMCAV2  =  0x00000000;  // load DCM capture register 2

  ///  DCM3 configuration:
  ///  - DCM3 input signal is 90,00 MHz
  ///  - DCM3 capture the timer contents to CAV capture register on a falling 
  ///    input signal edge

  GPTA0_DCMCTR3  =  0x00000000;  // load DCM control register 3
  GPTA0_DCMCOV3  =  0x00000000;  // load DCM capture/compare register 3
  GPTA0_DCMTIM3  =  0x00000000;  // load DCM timer register 3
  GPTA0_DCMCAV3  =  0x00000000;  // load DCM capture register 3

  ///  -----------------------------------------------------------------------
  ///  Configuration of Digital Phase Locked Loop Cell:
  ///  -----------------------------------------------------------------------
  ///  - use DCM0 output signal (= no output signal enabled) as PLL input
  ///  - period of the PLL input signal in GPTA clocks = 0
  ///  - number of output pulses to be generated within one input signal 
  ///    period = 0

  GPTA0_PLLCTR   =  0x00000000;  // load PLL control register
  GPTA0_PLLMTI   =  0x00000000;  // load PLL micro tick register
  GPTA0_PLLSTP   =  0x00000000;  // load PLL step register
  GPTA0_PLLREV   =  0x00000000;  // load PLL reload register
  GPTA0_PLLCNT   =  0x00000000;  // load PLL counter register
  GPTA0_PLLDTR   =  0x00000000;  // load PLL delta register

  ///  -----------------------------------------------------------------------
  ///  Configuration of GPTA Clock Bus 0 - 7:
  ///  -----------------------------------------------------------------------
  ///  - Clock bus signal 0: GPTA0 clock / 2^0 (= 90,00 MHz; 0,01 us)
  ///  - Clock bus signal 1: PLL output
  ///  - Clock bus signal 2: DCM3 (= no output signal enabled)
  ///  - Clock bus signal 3: DCM2 (= no output signal enabled)
  ///  - Clock bus signal 4: DCM1 (= no output signal enabled)
  ///  - Clock bus signal 5: DCM0 (= no output signal enabled)
  ///  - Clock bus signal 6: FPC1 output (= 90,00 MHz)
  ///  - Clock bus signal 7: FPC4 output (= 90,00 MHz)

  GPTA0_CKBCTR   =  0x0000FFFF;  // load clock bus control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Global Timers 0 - 1:
  ///  -----------------------------------------------------------------------
  ///  GT0 configuration:
  ///  - GT0 input is clock bus signal 0 (= GPTA0 clock / 2^0 (= 90,00 MHz; 
  ///    0,01 us))
  ///  - GT0 compare flag is the 9th bit of the substraction result
  ///  - enable service request when the GT0 timer overflows

  GPTA0_GTCTR0   =  0x00000080;  // load GT control register 0
  GPTA0_GTREV0   =  0x00424242;  // load GT reload value register 0
  GPTA0_GTTIM0   =  0x00424242;  // load GT timer register 0

  ///  GT1 configuration:
  ///  - GT1 input is clock bus signal 0 (= GPTA0 clock / 2^0 (= 90,00 MHz; 
  ///    0,01 us))
  ///  - GT1 compare flag is the 9th bit of the substraction result

  GPTA0_GTCTR1   =  0x00000000;  // load GT control register 1
  GPTA0_GTREV1   =  0x00BABE23;  // load GT reload value register 1
  GPTA0_GTTIM1   =  0x00BABE23;  // load GT timer register 1

  ///  -----------------------------------------------------------------------
  ///  Configuration of Global Timer Cells 0 - 31:
  ///  -----------------------------------------------------------------------
  ///  Global Timer Cell 0 configuration:
  ///  - GTC0 cell is enabled after initialization
  ///  - GTC0 mode: Compare with GT1 timer
  ///  - equal compare "="
  ///  - action transfer: set the GTC0 output by an local event only

  GPTA0_GTCXR00  =  0x00C0FFEE;  // load GTC0 x register
  GPTA0_GTCCTR00  =  0x00001803; // load GTC0 control register

  ///  Global Timer Cell 1 configuration:
  ///  - GTC1 cell is enabled after initialization
  ///  - GTC1 mode: Compare with GT1 timer
  ///  - equal compare "="
  ///  - output of GTC1 is connected to GPTA0_OUT0 (P0.0)
  ///  - action transfer: reset the GTC1 output by an local event or copy the 
  ///    previous cell action
  ///  - bypass functionality for GTC1 cell is disabled

  GPTA0_GTCXR01  =  0x00EBBE00;  // load GTC1 x register
  GPTA0_GTCCTR01  =  0x00003003; // load GTC1 control register


  GPTA0_SRNR     =  0x00000000;  // load service request node redirection 
                                 // register

  ///  -----------------------------------------------------------------------
  ///  Configuration of Local Timer Cells 0 - 63:
  ///  -----------------------------------------------------------------------
  ///  Local Timer Cell 63 configuration:
  ///  - compare uses normal sequence of timer bits
  ///  - the input line is not connected to the LTC63 cell

  GPTA0_LTCXR63  =  0x00000000;  // load LTC63 x register
  GPTA0_LTCCTR63  =  0x00000000; // load LTC63 control register


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used GPTA0 Port Pins:
  ///  -----------------------------------------------------------------------
  ///  - P0.0 is used as  GPTA0 output signal 0 ( GPTA0_OUT0)
  ///  - the push/pull function is activated
  ///  - output driver characteristic: medium driver
  ///  - the emergency stop function is disabled

  P0_IOCR0       = (P0_IOCR0 & ~0x000000F0) | 0x00000090; // load control 
                                                          // register


  ///  -----------------------------------------------------------------------
  ///  Configuration of Service Request Nodes 0 - 37:
  ///  -----------------------------------------------------------------------
  ///  - SRN5 service request node configuration:
  ///  - SRN5 interrupt priority level (SRPN) = 4
  ///  - SRN5 CPU interrupt is selected

  GPTA0_SRC05    =  0x00001004;  // set service request control register


  ///  -----------------------------------------------------------------------
  ///  Configuration of the GPTA-to-MSC Multiplexer:
  ///  -----------------------------------------------------------------------
  #ifndef GPTA_TO_MSC_MULTIPLEXER_INITIALIZATION
  #define GPTA_TO_MSC_MULTIPLEXER_INITIALIZATION
  GPTA0_MMXCTR00  =  0x00000000; // load GPTA-to-MSC Multiplex register 00
  GPTA0_MMXCTR01  =  0x00000000; // load GPTA-to-MSC Multiplex register 01
  #endif // end #ifndef GPTA_TO_MSC_MULTIPLEXER_INITIALIZATION

  ///  -----------------------------------------------------------------------
  ///  Multiplexer Register Array FIFO:
  ///  -----------------------------------------------------------------------

  GPTA0_MRACTL_MAEN  =  0;         //   disable multiplexer array
  while(GPTA0_MRACTL_MAEN != 0);     // wait for bit MAEN
  GPTA0_MRACTL_WCRES  =  1;        //   reset count


    // Default,Default,Default,Default,Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OTMCR1 register
    // Default,Default,Default,Default,Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OTMCR0 register


    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH13 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL13 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH12 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL12 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH11 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL11 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH10 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL10 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH9 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL9 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH8 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL8 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH7 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL7 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH6 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL6 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH5 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL5 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH4 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL4 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH3 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL3 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH2 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL2 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH1 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRL1 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x00000000; // save GPTA0_OMCRH0 register
    // Default,Default,Default,GPTA0_OUT0-GPTA0_GTC1
    GPTA0_MRADIN = 0x00000001; // save GPTA0_OMCRL0 register

    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRH7 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRL7 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRH6 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRL6 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRH5 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRL5 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRH4 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRL4 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRH3 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRL3 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRH2 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRL2 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRH1 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRL1 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRH0 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x30303030; // save GPTA0_LIMCRL0 register

    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x40404040; // save GPTA0_GIMCRH3 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x40404040; // save GPTA0_GIMCRL3 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x40404040; // save GPTA0_GIMCRH2 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x40404040; // save GPTA0_GIMCRL2 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x40404040; // save GPTA0_GIMCRH1 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x40404040; // save GPTA0_GIMCRL1 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x40404040; // save GPTA0_GIMCRH0 register
    // Default,Default,Default,Default
    GPTA0_MRADIN = 0x40404040; // save GPTA0_GIMCRL0 register

  GPTA0_MRACTL_MAEN  =  1;         //   enable multiplexer array

  // USER CODE BEGIN (Init,3)

  // USER CODE END

  //// - GPTA0 GT0 timer is not started after initialization; to start the 
  ////   GT0 timer use the macro GPTA0_vStartGTTimer(0)

  //// - GPTA0 GT1 timer is not started after initialization; to start the 
  ////   GT1 timer use the macro GPTA0_vStartGTTimer(1)

  GPTA0_EDCTR_G0EN  =  1;          // enable GPTA0 timer clock


  // USER CODE BEGIN (Init,4)

  // USER CODE END

} //  End of function GPTA0_vInit


//****************************************************************************
// @Function      void GPTA0_viSRN5(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the interrupt service routine for the Service 
//                Request Node 5 of the GPTA0 module. 
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

// USER CODE BEGIN (SRN5,1)
volatile unsigned int countTimerOverflows = 0;
// USER CODE END

void INTERRUPT (GPTA0_SRN5INT) GPTA0_viSRN5(void)
{
  countTimerOverflows++;

  GPTA0_SRSC0 = 0x00002000;  //  reset GT0 service request bit
} //  End of function GPTA0_viSRN5



// USER CODE BEGIN (GPTA0_General,10)

// USER CODE END

