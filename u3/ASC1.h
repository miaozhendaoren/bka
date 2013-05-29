//****************************************************************************
// @Module        Asynchronous Synchronous Serial Interface 1 (ASC1)
// @Filename      ASC1.h
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains all function prototypes and macros for 
//                the ASC1 module.
//
//----------------------------------------------------------------------------
// @Date          19.04.2012 13:49:05
//
//****************************************************************************

// USER CODE BEGIN (ASC1_Header,1)

// USER CODE END



#ifndef _ASC1_H_
#define _ASC1_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (ASC1_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (ASC1_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (ASC1_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (ASC1_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (ASC1_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (ASC1_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void ASC1_vInit(void);
void ASC1_vSendData(ushort usData);
ushort ASC1_usGetData(void);
ubyte ASC1_ubTxDataReady(void);
void ASC1_vReceiverOn(void);


// USER CODE BEGIN (ASC1_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         ASC1_ubTxBufFree() 
//
//----------------------------------------------------------------------------
// @Description   This macro can be used for checking the status of the 
//                transmit buffer register. The transmit buffer may only be 
//                written to if it is empty, this implies that the previous 
//                content of the transmit buffer have been loaded into the 
//                transmit shift register.
//
//----------------------------------------------------------------------------
// @Returnvalue   0 if buffer is not empty, else 1
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          19.04.2012
//
//****************************************************************************

#define ASC1_ubTxBufFree() ASC1_TBSRC_SRR


//****************************************************************************
// @Macro         ASC1_ubRxDataReady() 
//
//----------------------------------------------------------------------------
// @Description   This macro can be used for calling the status of the ASC1 
//                receiver interrupt flag. This is to recognize that the ASC1 
//                received a byte. If a byte has been received, the function 
//                ASC1_usGetData must be called.
//
//----------------------------------------------------------------------------
// @Returnvalue   0 receive data is invalid, else 1
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          19.04.2012
//
//****************************************************************************

#define ASC1_ubRxDataReady() ASC1_RSRC_SRR


//****************************************************************************
// @Macro         ASC1_vReceiverOff() 
//
//----------------------------------------------------------------------------
// @Description   This macro disables the receive function of the ASC1. A 
//                data that is currently being received is received to 
//                completion, including generation of the receive interrupt 
//                request.
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

#define ASC1_vReceiverOff() ASC1_WHBCON_CLRREN = 1


//****************************************************************************
// @Macro         ASC1_vSetBaudrate(Value) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the reload register of the baud rate 
//                generator. The baud rate generator is loaded immediately 
//                with the new value.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    Value: 
//                13 bit value for the baud rate reload register
//
//----------------------------------------------------------------------------
// @Date          19.04.2012
//
//****************************************************************************

#define ASC1_vSetBaudrate(Value) ASC1_BG = Value


//****************************************************************************
// @Macro         ASC1_vStopBaudGen() 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the baud rate generator (ASC1 inactive).
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

#define ASC1_vStopBaudGen() ASC1_CON_R = 0


//****************************************************************************
// @Macro         ASC1_vStartBaudGen() 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the baud rate generator (ASC1 active).
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

#define ASC1_vStartBaudGen() ASC1_CON_R = 1


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************


// USER CODE BEGIN (ASC1_Header,9)

// USER CODE END


#endif  // ifndef _ASC1_H_
