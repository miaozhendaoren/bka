//****************************************************************************
// @Module        Asynchronous Synchronous Serial Interface 1 (ASC1)
// @Filename      ASC1.c
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains functions that use the ASC1 module.
//
//----------------------------------------------------------------------------
// @Date          19.04.2012 13:49:05
//
//****************************************************************************

// USER CODE BEGIN (ASC1_General,1)

// USER CODE END



//****************************************************************************
// @Project Includes
//****************************************************************************

#include "MAIN.h"

// USER CODE BEGIN (ASC1_General,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (ASC1_General,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (ASC1_General,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (ASC1_General,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (ASC1_General,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (ASC1_General,7)

// USER CODE END


//****************************************************************************
// @External Prototypes
//****************************************************************************

// USER CODE BEGIN (ASC1_General,8)

// USER CODE END


//****************************************************************************
// @Prototypes Of Local Functions
//****************************************************************************

// USER CODE BEGIN (ASC1_General,9)

// USER CODE END


//****************************************************************************
// @Function      void ASC1_vInit(void) 
//
//----------------------------------------------------------------------------
// @Description   This is the initialization function of the ASC1 function 
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
// @Date          19.04.2012
//
//****************************************************************************

// USER CODE BEGIN (Init,1)

// USER CODE END

void ASC1_vInit(void)
{

  volatile unsigned int uwTemp;

  // USER CODE BEGIN (Init,2)

  // USER CODE END

  ///  -----------------------------------------------------------------------
  ///  Configuration of the Module Clock:
  ///  -----------------------------------------------------------------------
  ///  - enable the ASC1 module
  ///  - clock divider for normal operation mode: System clock / 1 (= 90,00 
  ///    MHz; 11,11 ns )
  ///  - the ASC1 module is not stopped during sleep mode

  MAIN_vResetENDINIT();
  ASC0_CLC       =  0x00000108;  // load clock control register
  uwTemp         =  ASC0_CLC;    // dummy read to avoid pipeline effects
  MAIN_vSetENDINIT();

  ///  -----------------------------------------------------------------------
  ///  Configuration of the ASC1 Baudrate Generator:
  ///  -----------------------------------------------------------------------
  ///  - additionally reduce serial clock to 2
  ///  - required baud rate = 9600 baud
  ///  - real baud rate     = 9599 baud
  ///  - deviation          = -0 %

  ASC1_BG        =  0x00000124;  // load ASC1 baud rate time reload register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the ASC1 Operation Mode:
  ///  -----------------------------------------------------------------------
  ///  - 8-bit data asychronous operation with one stop bit
  ///  - receiver is enabled

  ASC1_CON       =  0x00000011;  // load ASC1 control register

  ///  -----------------------------------------------------------------------
  ///  Configuration of the used ASC1 Port Pins:
  ///  -----------------------------------------------------------------------
  ASC1_PISEL     =  0x0000;      // load peripheral input selection register

  ///  - P3.9 is used as  ASC1 receive input signal 1 ( ASC1_RX)
  ///  - the pull-up device is assigned
  ///  - output driver characteristic: medium driver

  P3_IOCR8       = (P3_IOCR8 & ~0x0000F000) | 0x00002000; // load control 
                                                          // register

  ///  - P3.8 is used as  ASC1 output signal 1 ( ASC1_TX)
  ///  - the push/pull function is activated
  ///  - output driver characteristic: medium driver
  ///  - the emergency stop function is disabled

  MAIN_vResetENDINIT();
  P3_PDR        |=  0x04000000;  // load driver mode register
  MAIN_vSetENDINIT();
  P3_IOCR8       = (P3_IOCR8 & ~0x000000F0) | 0x000000A0; // load control 
                                                          // register


  ///  -----------------------------------------------------------------------
  ///  Configuration of the used ASC1 Interrupts:
  ///  -----------------------------------------------------------------------

  //   -----------------------------------------------------------------------
  //   Default Settings for Service Request Flags:
  //   -----------------------------------------------------------------------
  ASC1_TBSRC_SETR  =  1;         // indicates that the transmit buffer is 
                                 // empty
  ASC1_TSRC_SETR  =  1;          // indicates that the transmit register is 
                                 // empty

  // USER CODE BEGIN (ASC1_Function,3)

  // USER CODE END

  ASC1_CON_R     =  1;           // enable baud rate generator


} //  End of function ASC1_vInit


//****************************************************************************
// @Function      void ASC1_vSendData(ushort usData) 
//
//----------------------------------------------------------------------------
// @Description   This function writes a send data initialization word into 
//                the transmit buffer register.
//                
//                Note: 
//                In a multiprocessor system the master with this function 
//                has the possibility to send data to the selected slave. To 
//                achieve this, the 9th bit must set on zero.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    usData: 
//                Data to be send
//
//----------------------------------------------------------------------------
// @Date          19.04.2012
//
//****************************************************************************

// USER CODE BEGIN (SendData,1)

// USER CODE END

void ASC1_vSendData(ushort usData)
{
  ASC1_TBSRC_CLRR  =  1;         // reset transmit buffer interrupt request
  ASC1_TBUF      =  usData;      // load transmit buffer register

} //  End of function ASC1_vSendData


//****************************************************************************
// @Function      ushort ASC1_usGetData(void) 
//
//----------------------------------------------------------------------------
// @Description   This function reads out the content of the receive buffer 
//                register which contains the received data.
//
//----------------------------------------------------------------------------
// @Returnvalue   data that has been received
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          19.04.2012
//
//****************************************************************************

// USER CODE BEGIN (GetData,1)

// USER CODE END

ushort ASC1_usGetData(void)
{
  ASC1_RSRC_CLRR = 1;    // reset receive interrupt request
  return(ASC1_RBUF & 0x1FF);     // return receive buffer register

} //  End of function ASC1_usGetData


//****************************************************************************
// @Function      ubyte ASC1_ubTxDataReady(void) 
//
//----------------------------------------------------------------------------
// @Description   This function can be used for checking up the status of the 
//                ASC1 transmit interrupt flags. This shows when the sending 
//                of data has terminated. By continuously polling this flag 
//                after the function ASC1_vSendData has been called, it is 
//                possible to establish when the ASC1 has terminated its task.
//
//----------------------------------------------------------------------------
// @Returnvalue   0 if transmitter is busy, else 1
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          19.04.2012
//
//****************************************************************************

// USER CODE BEGIN (TxDataReady,1)

// USER CODE END

ubyte ASC1_ubTxDataReady(void)
{
  ubyte ubReturnValue;

  ubReturnValue = 0;

  if(ASC1_TSRC_SRR)              // if sending of data is terminated
  {
    ubReturnValue = 1;
    ASC1_TSRC_CLRR = 1;
  }
  return(ubReturnValue);

} //  End of function ASC1_ubTxDataReady


//****************************************************************************
// @Function      void ASC1_vReceiverOn(void) 
//
//----------------------------------------------------------------------------
// @Description   This function releases the receive function of the ASC1. 
//                After initialization this function does not need to be 
//                recalled. 
//                Note: 
//                This function must be called everytime data is to be 
//                received in synchronous mode.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          19.04.2012
//
//****************************************************************************

// USER CODE BEGIN (ReceiverOn,1)

// USER CODE END

void ASC1_vReceiverOn(void)
{
  ASC1_WHBCON_SETREN = 1;         // enable the receiver

} //  End of function ASC1_vReceiverOn




// USER CODE BEGIN (ASC1_General,10)

// USER CODE END

