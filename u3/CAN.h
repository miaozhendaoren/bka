//****************************************************************************
// @Module        MultiCAN Controller 
// @Filename      CAN.h
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains all function prototypes and macros for 
//                the CAN module.
//
//----------------------------------------------------------------------------
// @Date          27.03.2012 17:23:26
//
//****************************************************************************

// USER CODE BEGIN (CAN_Header,1)

// USER CODE END



#ifndef _CAN_H_
#define _CAN_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (CAN_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (CAN_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (CAN_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

///  -------------------------------------------------------------------------
///  @Definition of a structure for the CAN data
///  -------------------------------------------------------------------------

// The following data type serves as a software message object. Each access to
// a hardware message object has to be made by forward a pointer to a software
// message object (CAN_SWObj). The data type has the following fields:
//
// usMOCfg:
// this byte contains the "Data Lenght Code" (DLC), the 
// "Extended Identifier" (IDE) and the "Message Direction" (DIR).
//
//
//         7     6     5      4    3     2     1     0
//      |------------------------------------------------|
//      |        DLC            | DIR | IDE |      |     |
//      |------------------------------------------------|
//
// uwID: 
// this field is four bytes long and contains either the 11-bit identifier 
// or the 29-bit identifier
//
// uwMask: 
// this field is four bytes long and contains either the 11-bit mask 
// or the 29-bit mask
//
// ubData[8]:
// 8 bytes containing the data of a frame
//
// usCounter:
// this field is two bytes long and contains the counter value 
//

typedef struct
  {
     ushort usMOCfg;    // message object configuration register
     uword  uwID;       // standard (11-bit)/extended (29-bit) identifier
     uword  uwMask;     // standard (11-bit)/extended (29-bit) mask
     ubyte  ubData[8];  // 8-bit data bytes
     ushort usCounter;  // frame counter
  }CAN_SWObj;

// USER CODE BEGIN (CAN_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (CAN_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void CAN_vInit(void);
void CAN_vGetMsgObj(ubyte ubObjNr, CAN_SWObj *pstObj);
ubyte CAN_ubRequestMsgObj(ubyte ubObjNr);
ubyte CAN_ubNewData(ubyte ubObjNr);
void CAN_vTransmit(ubyte ubObjNr);
void CAN_vConfigMsgObj(ubyte ubObjNr, CAN_SWObj *pstObj);
void CAN_vLoadData(ubyte ubObjNr, ubyte *pubData);
ubyte CAN_ubMsgLost(ubyte ubObjNr);
ubyte CAN_ubDelMsgObj(ubyte ubObjNr);
void CAN_vReleaseObj(ubyte ubObjNr);
void CAN_vSetMSGVAL(ubyte ubObjNr);
ubyte CAN_ubWriteFIFO(ubyte ubObjNr, CAN_SWObj *pstObj);
ubyte CAN_ubReadFIFO(ubyte ubObjNr, CAN_SWObj *pstObj);


// USER CODE BEGIN (CAN_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         CAN_ubGetTxErrorCounter(NODE_NAME) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the current value of the transmit error 
//                counter of the selected node. 
//                
//                The following definitions for NODE_NAME are available:
//                CAN_NODE0        (node 0)
//                CAN_NODE1        (node 1)
//                CAN_NODE2        (node 2)
//                
//
//----------------------------------------------------------------------------
// @Returnvalue   Value of the transmit error counter
//
//----------------------------------------------------------------------------
// @Parameters    NODE_NAME: 
//                Name of the node
//
//----------------------------------------------------------------------------
// @Date          27.03.2012
//
//****************************************************************************

#define CAN_ubGetTxErrorCounter(NODE_NAME) _GetTxErrorCounter##NODE_NAME()
#define _GetTxErrorCounterCAN_NODE0()  (ubyte)((CAN_NECNT0 & 0x0000FF00) >> 8)
#define _GetTxErrorCounterCAN_NODE1()  (ubyte)((CAN_NECNT1 & 0x0000FF00) >> 8)
#define _GetTxErrorCounterCAN_NODE2()  (ubyte)((CAN_NECNT2 & 0x0000FF00) >> 8)


//****************************************************************************
// @Macro         CAN_ubGetRxErrorCounter(NODE_NAME) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the current value of the receive error 
//                counter of the selected node. 
//                
//                The following definitions for NODE_NAME are available:
//                CAN_NODE0        (node 0)
//                CAN_NODE1        (node 1)
//                CAN_NODE2        (node 2)
//                
//
//----------------------------------------------------------------------------
// @Returnvalue   Value of the receive error counter
//
//----------------------------------------------------------------------------
// @Parameters    NODE_NAME: 
//                Name of the node
//
//----------------------------------------------------------------------------
// @Date          27.03.2012
//
//****************************************************************************

#define CAN_ubGetRxErrorCounter(NODE_NAME) _GetRxErrorCounter##NODE_NAME()
#define _GetRxErrorCounterCAN_NODE0()  (ubyte)(CAN_NECNT0 & 0x000000FF)
#define _GetRxErrorCounterCAN_NODE1()  (ubyte)(CAN_NECNT1 & 0x000000FF)
#define _GetRxErrorCounterCAN_NODE2()  (ubyte)(CAN_NECNT2 & 0x000000FF)


//****************************************************************************
// @Macro         CAN_ubGetErrorTransferDirection(NODE_NAME) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the current value of the Last Error 
//                Transfer Direction flag. 0 indicates that the last error 
//                occurred while the selected CAN node was receiving a 
//                message. The receive error counter has been incremented. 1 
//                indicates that the last error occurred while the selected 
//                CAN node was transmitting a message. The transmit error 
//                counter has been incremented. 
//                
//                The following definitions for NODE_NAME are available:
//                CAN_NODE0        (node 0)
//                CAN_NODE1        (node 1)
//                CAN_NODE2        (node 2)
//                
//
//----------------------------------------------------------------------------
// @Returnvalue   0 receive error, else transmit error
//
//----------------------------------------------------------------------------
// @Parameters    NODE_NAME: 
//                Name of the node
//
//----------------------------------------------------------------------------
// @Date          27.03.2012
//
//****************************************************************************

#define CAN_ubGetErrorTransferDirection(NODE_NAME) _GetErrorTransferDirection##NODE_NAME()
#define _GetErrorTransferDirectionCAN_NODE0()  (ubyte)((CAN_NECNT0 & CAN_NECNT0_LETD) >> 24)
#define _GetErrorTransferDirectionCAN_NODE1()  (ubyte)((CAN_NECNT1 & CAN_NECNT1_LETD) >> 24)
#define _GetErrorTransferDirectionCAN_NODE2()  (ubyte)((CAN_NECNT2 & CAN_NECNT2_LETD) >> 24)


//****************************************************************************
// @Macro         CAN_ubGetErrorIncrement(NODE_NAME) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the current value of the Last Error 
//                Increment flag. If the Bit Stream Processor itself detects 
//                an error while a transmit operation is running, the 
//                Transmit Error Counter is incremented by 8. An increment of 
//                1 is used, when the error condition was reported by an 
//                external CAN node via an error frame generation. 
//                
//                The following definitions for NODE_NAME are available:
//                CAN_NODE0        (node 0)
//                CAN_NODE1        (node 1)
//                CAN_NODE2        (node 2)
//                
//
//----------------------------------------------------------------------------
// @Returnvalue   0 counter is incrementd by 1, counter is incremented by 8
//
//----------------------------------------------------------------------------
// @Parameters    NODE_NAME: 
//                Name of the node
//
//----------------------------------------------------------------------------
// @Date          27.03.2012
//
//****************************************************************************

#define CAN_ubGetErrorIncrement(NODE_NAME) _GetErrorIncrement##NODE_NAME()
#define _GetErrorIncrementCAN_NODE0()  (ubyte)((CAN_NECNT0 & CAN_NECNT0_LEINC) >> 25)
#define _GetErrorIncrementCAN_NODE1()  (ubyte)((CAN_NECNT1 & CAN_NECNT1_LEINC) >> 25)
#define _GetErrorIncrementCAN_NODE2()  (ubyte)((CAN_NECNT2 & CAN_NECNT2_LEINC) >> 25)


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************


// USER CODE BEGIN (CAN_Header,9)

// USER CODE END


#endif  // ifndef _CAN_H_
