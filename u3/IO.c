//****************************************************************************
// @Module        Parallel Ports
// @Filename      IO.c
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains functions that use the IO module.
//
//----------------------------------------------------------------------------
// @Date          21.03.2012 16:08:47
//
//****************************************************************************

// USER CODE BEGIN (IO_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (IO_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (IO_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (IO_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (IO_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (IO_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (IO_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (IO_General,9)

// USER CODE END


//****************************************************************************
// @Function      void IO_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the IO function 
//                library. It is assumed that the SFRs used by this library 
//                are in their reset state. 
//                Note:
//                Alternate outputs are set in their own initialization 
//                function.
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

// USER CODE BEGIN (IO_Function,1)

// USER CODE END

void IO_vInit(void)
{
  // USER CODE BEGIN (IO_Function,2)

  // USER CODE END


  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P0:
  ///  -----------------------------------------------------------------------
  ///  P0.0:
  ///  - is used as alternate output for the  GPTA0 output signal 0
  ///  - output driver characteristic: medium driver
  ///  P0.1:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  - output driver characteristic: medium driver
  ///  P0.2:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  - output driver characteristic: medium driver
  ///  P0.3:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  - output driver characteristic: Medium driver
  ///  P0.4:
  ///  - is used as general input
  ///  - pull-up device is assigned
  ///  - output driver characteristic: medium driver
  ///  P0.5:
  ///  - is used as general input
  ///  - pull-up device is assigned
  ///  - output driver characteristic: medium driver
  ///  P0.6:
  ///  - is used as general input
  ///  - pull-up device is assigned
  ///  - output driver characteristic: medium driver
  ///  P0.7:
  ///  - is used as general input
  ///  - pull-up device is assigned
  ///  - output driver characteristic: medium driver
  ///  P0.14:
  ///  - is used as alternate input for the  SCU_ERU input signal 4
  ///  - output driver characteristic: Medium driver

  P0_OMR         =  0x00000000;  // load data output register
  MAIN_vResetENDINIT();
  P0_PDR         =  0x00040000;  // load pad driver mode register
  MAIN_vSetENDINIT();
  P0_IOCR0       =  0x80808020;  // load port control register 0
  P0_IOCR4       =  0x20202020;  // load port control register 4
  P0_IOCR8       =  0x20202020;  // load port control register 8
  P0_IOCR12      =  0x20202020;  // load port control register 12

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P1:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P1 is used

  P1_OMR         =  0x00000000;  // load data output register
  MAIN_vResetENDINIT();
  P1_PDR         =  0x00000000;  // load pad driver mode register
  MAIN_vSetENDINIT();
  P1_IOCR0       =  0x20202020;  // load port control register 0
  P1_IOCR4       =  0x20202020;  // load port control register 4
  P1_IOCR8       =  0x20202020;  // load port control register 8
  P1_IOCR12      =  0x20202020;  // load port control register 12

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P2:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P2 is used

  P2_OMR         =  0x00000000;  // load data output register
  MAIN_vResetENDINIT();
  P2_PDR         =  0x00000000;  // load pad driver mode register
  MAIN_vSetENDINIT();
  P2_IOCR0       =  0x20202020;  // load port control register 0
  P2_IOCR4       =  0x20202020;  // load port control register 4
  P2_IOCR8       =  0x20202020;  // load port control register 8
  P2_IOCR12      =  0x20202020;  // load port control register 12

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P3:
  ///  -----------------------------------------------------------------------
  ///  P3.12:
  ///  - is used as alternate input for the  CAN node 0 input signal 1
  ///  - output driver characteristic: medium driver
  ///  P3.13:
  ///  - is used as alternate output for the  CAN node 0 output signal 1
  ///  - output driver characteristic: strong driver, sharp edge

  P3_OMR         =  0x00000000;  // load data output register
  MAIN_vResetENDINIT();
  P3_PDR         =  0x00000000;  // load pad driver mode register
  MAIN_vSetENDINIT();
  P3_IOCR0       =  0x20202020;  // load port control register 0
  P3_IOCR4       =  0x20202020;  // load port control register 4
  P3_IOCR8       =  0x20202020;  // load port control register 8
  P3_IOCR12      =  0x20202020;  // load port control register 12

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P4:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P4 is used

  P4_OMR         =  0x00000000;  // load data output register
  MAIN_vResetENDINIT();
  P4_PDR         =  0x00000000;  // load pad driver mode register
  MAIN_vSetENDINIT();
  P4_IOCR0       =  0x20202020;  // load port control register 0

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P5:
  ///  -----------------------------------------------------------------------
  ///  P5.0:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is low level
  ///  - output driver characteristic: Strong driver soft edge
  ///  P5.1:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is high level
  ///  - output driver characteristic: Strong driver soft edge
  ///  P5.2:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is high level
  ///  - output driver characteristic: Strong driver soft edge
  ///  P5.3:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is high level
  ///  - output driver characteristic: Strong driver soft edge
  ///  P5.4:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is high level
  ///  - output driver characteristic: Strong driver soft edge
  ///  P5.5:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is high level
  ///  - output driver characteristic: Strong driver soft edge
  ///  P5.6:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is high level
  ///  - output driver characteristic: Strong driver soft edge
  ///  P5.7:
  ///  - is used as general purpose output
  ///  - push/pull output is selected
  ///  - the pin status is high level
  ///  - output driver characteristic: Strong driver soft edge

  P5_OMR         =  0x000000FE;  // load data output register
  MAIN_vResetENDINIT();
  P5_PDR         =  0x00000000;  // load pad driver mode register
  MAIN_vSetENDINIT();
  P5_IOCR0       =  0x80808080;  // load port control register 0
  P5_IOCR4       =  0x80808080;  // load port control register 4
  P5_IOCR8       =  0x20202020;  // load port control register 8
  P5_IOCR12      =  0x20202020;  // load port control register 12

  ///  -----------------------------------------------------------------------
  ///  Configuration of Port P6:
  ///  -----------------------------------------------------------------------
  ///  - no pin of port P6 is used

  P6_OMR         =  0x00000000;  // load data output register
  MAIN_vResetENDINIT();
  P6_PDR         =  0x00000000;  // load pad driver mode register
  MAIN_vSetENDINIT();
  P6_IOCR0       =  0x20202020;  // load port control register 0


  // USER CODE BEGIN (IO_Function,3)

  // USER CODE END

} //  End of function IO_vInit




// USER CODE BEGIN (IO_General,10)

// USER CODE END

