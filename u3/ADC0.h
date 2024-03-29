//****************************************************************************
// @Module        Analog Digital Converter 0 (ADC0)
// @Filename      ADC0.h
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains all function prototypes and macros for 
//                the ADC0 module.
//
//----------------------------------------------------------------------------
// @Date          21.03.2012 17:30:41
//
//****************************************************************************

// USER CODE BEGIN (ADC0_Header,1)

// USER CODE END


#ifndef _ADC0_H_

#define _ADC0_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (ADC0_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (ADC0_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   This parameter identifies ADC0 analog channel 0
#define ADC0_ANA_0 0

//   This parameter identifies ADC0 analog channel 1
#define ADC0_ANA_1 1

//   This parameter identifies ADC0 analog channel 2
#define ADC0_ANA_2 2

//   This parameter identifies ADC0 analog channel 3
#define ADC0_ANA_3 3

//   This parameter identifies ADC0 analog channel 4
#define ADC0_ANA_4 4

//   This parameter identifies ADC0 analog channel 5
#define ADC0_ANA_5 5

//   This parameter identifies ADC0 analog channel 6
#define ADC0_ANA_6 6

//   This parameter identifies ADC0 analog channel 7
#define ADC0_ANA_7 7

//   This parameter identifies ADC0 analog channel 8
#define ADC0_ANA_8 8

//   This parameter identifies ADC0 analog channel 9
#define ADC0_ANA_9 9

//   This parameter identifies ADC0 analog channel 10
#define ADC0_ANA_10 10

//   This parameter identifies ADC0 analog channel 11
#define ADC0_ANA_11 11

//   This parameter identifies ADC0 analog channel 12
#define ADC0_ANA_12 12

//   This parameter identifies ADC0 analog channel 13
#define ADC0_ANA_13 13

//   This parameter identifies ADC0 analog channel 14
#define ADC0_ANA_14 14

//   This parameter identifies ADC0 analog channel 15
#define ADC0_ANA_15 15

//   This parameter identifies ADC0 -Source 0
#define ADC0_SOURCE_0 0

//   This parameter identifies ADC0 -Source 1
#define ADC0_SOURCE_1 1

//   This parameter identifies ADC0 -Source 2
#define ADC0_SOURCE_2 2

//   This parameter identifies ADC0 -Source 3
#define ADC0_SOURCE_3 3

//   This parameter identifies ADC0 -Source 4
#define ADC0_SOURCE_4 4


// USER CODE BEGIN (ADC0_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************


// USER CODE BEGIN (ADC0_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (ADC0_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (ADC0_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void ADC0_vInit(void);
void ADC0_vStartSeq0ReqChNum(ubyte ubExtTrg, ubyte ubEnIntr, ubyte ubRFill, ubyte ubChannelNum);
void ADC0_vStartSeq2ReqChNum(ubyte ubExtTrg, ubyte ubEnIntr, ubyte ubRFill, ubyte ubChannelNum);
void ADC0_vStartSeq4ReqChNum(ubyte ubExtTrg, ubyte ubEnIntr, ubyte ubRFill, ubyte ubChannelNum);
void ADC0_vClearPendingBits(ubyte ubSourceNum);
void ADC0_vStartParReqChNum(uword uwChannelNum, ubyte ubSrc);


// USER CODE BEGIN (ADC0_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         void ADC0_vSetLoadEvent(ubyte ubSrc) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets software load event for parallel source 1 & 
//                3
//                Ex- ubSrc = SOURCE_1,for parallel source 1
//                    ubSrc = SOURCE_3,for parallel source 3
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    ubSrc: 
//                ubSrc: defines the parallel source number
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define ADC0_vSetLoadEvent(ubSrc)  (ADC0_vSetLoadEvent_##ubSrc)
#define ADC0_vSetLoadEvent_SOURCE_1  (ADC0_CRMR1 |= 0x00000200)
#define ADC0_vSetLoadEvent_SOURCE_3  (ADC0_CRMR3 |= 0x00000200)

//****************************************************************************
// @Macro         uword ADC0_uwBusy() 
//
//----------------------------------------------------------------------------
// @Description   This macro checks the conversion state of the current ADC 
//                channel by examination of the busy flag (BUSY).It returns 
//                '1' while a conversion is running.
//
//----------------------------------------------------------------------------
// @Returnvalue   Returns a 1 if A/D converter is active, else 0
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define ADC0_uwBusy()  (ADC0_GLOBSTR & 0x00000001)

//****************************************************************************
// @Macro         void ADC0_vSetSeq2QueueFlush() 
//
//----------------------------------------------------------------------------
// @Description   This macro Flushes the Sequential source 2 Queue
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

#define ADC0_vSetSeq2QueueFlush()  (ADC0_QMR2 |= 0x00000400)

//****************************************************************************
// @Macro         uword ADC0_uwGetSeq2QueueEmpty() 
//
//----------------------------------------------------------------------------
// @Description   This macro checks whether Sequential source 2 Queue depth 
//                is empty or not
//
//----------------------------------------------------------------------------
// @Returnvalue   Returns '1' if sequential 2 queue is empty, else '0'
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define ADC0_uwGetSeq2QueueEmpty()  ((ADC0_QSR2 & 0x00000020) >> 5)

//****************************************************************************
// @Macro         void ADC0_vSetSeq4QueueFlush() 
//
//----------------------------------------------------------------------------
// @Description   This macro Flushes the Sequential source 4 Queue
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

#define ADC0_vSetSeq4QueueFlush()  (ADC0_QMR4 |= 0x00000400)

//****************************************************************************
// @Macro         uword ADC0_uwGetResultData(RegNum) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the left aligned, 12-bit result data of 
//                the last conversion from requested result register
//                Ex- RegNum = RESULT_REG_0,for Result register 0
//                    RegNum = RESULT_REG_2,for Result register 2
//                  - For 8 bit resolution user has to right shift the result
//                    by 4 bits as shown below
//                    uwResult = ADC0_uwGetResultData(RESULT_REG_0);
//                    uwResult >>= 4;
//                  - For 10 bit resolution user has to right shift the result
//                    by 2 bits as shown below
//                    uwResult = ADC0_uwGetResultData(RESULT_REG_0);
//                    uwResult >>= 2;
//                NOTE -
//                If this macro is called before ADC0_uwGetResultChNum macro 
//                for the same result register then channel information will 
//                be lost.So always call ADC0_uwGetResultChNum macro before 
//                this macro if channel information is required.
//
//----------------------------------------------------------------------------
// @Returnvalue   Returns result data from requested result register
//
//----------------------------------------------------------------------------
// @Parameters    RegNum: 
//                RegNum: defines the result register number
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define ADC0_uwGetResultData(RegNum)  (ADC0_uwGetResultData_##RegNum)
#define ADC0_uwGetResultData_RESULT_REG_0 ((ADC0_RESRD0 & 0x80000000) ? ((ADC0_RESR0 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_1 ((ADC0_RESRD1 & 0x80000000) ? ((ADC0_RESR1 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_2 ((ADC0_RESRD2 & 0x80000000) ? ((ADC0_RESR2 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_3 ((ADC0_RESRD3 & 0x80000000) ? ((ADC0_RESR3 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_4 ((ADC0_RESRD4 & 0x80000000) ? ((ADC0_RESR4 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_5 ((ADC0_RESRD5 & 0x80000000) ? ((ADC0_RESR5 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_6 ((ADC0_RESRD6 & 0x80000000) ? ((ADC0_RESR6 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_7 ((ADC0_RESRD7 & 0x80000000) ? ((ADC0_RESR7 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_8 ((ADC0_RESRD8 & 0x80000000) ? ((ADC0_RESR8 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_9 ((ADC0_RESRD9 & 0x80000000) ? ((ADC0_RESR9 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_10 ((ADC0_RESRD10 & 0x80000000) ? ((ADC0_RESR10 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_11 ((ADC0_RESRD11 & 0x80000000) ? ((ADC0_RESR11 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_12 ((ADC0_RESRD12 & 0x80000000) ? ((ADC0_RESR12 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_13 ((ADC0_RESRD13 & 0x80000000) ? ((ADC0_RESR13 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_14 ((ADC0_RESRD14 & 0x80000000) ? ((ADC0_RESR14 & 0x00003fff) ) : 0)
#define ADC0_uwGetResultData_RESULT_REG_15 ((ADC0_RESRD15 & 0x80000000) ? ((ADC0_RESR15 & 0x00003fff) ) : 0)

//****************************************************************************
// @Macro         ubyte ADC0_ubGetResultChNum(RegNum) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns channel number from requested result 
//                register
//                Ex- RegNum = RESULT_REG_0,for Result register 0
//                    RegNum = RESULT_REG_2,for Result register 2
//                NOTE -
//                If only channel information is required then make sure that 
//                you call ADC0_vClearValidBit macro after reading the 
//                channel number.
//
//----------------------------------------------------------------------------
// @Returnvalue   Returns channel number from requested result register
//
//----------------------------------------------------------------------------
// @Parameters    RegNum: 
//                RegNum: defines the result register number
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define ADC0_ubGetResultChNum(RegNum)  (ADC0_ubGetResultChNum_##RegNum)
#define ADC0_ubGetResultChNum_RESULT_REG_0 ((ADC0_RESRD0 & 0x80000000) ? ((ADC0_RESRD0 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_1 ((ADC0_RESRD1 & 0x80000000) ? ((ADC0_RESRD1 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_2 ((ADC0_RESRD2 & 0x80000000) ? ((ADC0_RESRD2 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_3 ((ADC0_RESRD3 & 0x80000000) ? ((ADC0_RESRD3 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_4 ((ADC0_RESRD4 & 0x80000000) ? ((ADC0_RESRD4 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_5 ((ADC0_RESRD5 & 0x80000000) ? ((ADC0_RESRD5 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_6 ((ADC0_RESRD6 & 0x80000000) ? ((ADC0_RESRD6 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_7 ((ADC0_RESRD7 & 0x80000000) ? ((ADC0_RESRD7 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_8 ((ADC0_RESRD8 & 0x80000000) ? ((ADC0_RESRD8 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_9 ((ADC0_RESRD9 & 0x80000000) ? ((ADC0_RESRD9 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_10 ((ADC0_RESRD10 & 0x80000000) ? ((ADC0_RESRD10 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_11 ((ADC0_RESRD11 & 0x80000000) ? ((ADC0_RESRD11 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_12 ((ADC0_RESRD12 & 0x80000000) ? ((ADC0_RESRD12 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_13 ((ADC0_RESRD13 & 0x80000000) ? ((ADC0_RESRD13 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_14 ((ADC0_RESRD14 & 0x80000000) ? ((ADC0_RESRD14 & 0x0f000000) >> 24) : 0)
#define ADC0_ubGetResultChNum_RESULT_REG_15 ((ADC0_RESRD15 & 0x80000000) ? ((ADC0_RESRD15 & 0x0f000000) >> 24) : 0)

//****************************************************************************
// @Macro         void ADC0_vClearValidBit(RegNum) 
//
//----------------------------------------------------------------------------
// @Description   This macro clears valid bit flag for the requested result 
//                register
//                Ex- RegNum = RESULT_REG_0,for Result register 0
//                    RegNum = RESULT_REG_2,for Result register 2
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    RegNum: 
//                RegNum: defines the result register number
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define ADC0_vClearValidBit(RegNum)  (ADC0_vClearValidBit_##RegNum)
#define ADC0_vClearValidBit_RESULT_REG_0 (ADC0_VFR = 0x00000001)
#define ADC0_vClearValidBit_RESULT_REG_1 (ADC0_VFR = 0x00000002)
#define ADC0_vClearValidBit_RESULT_REG_2 (ADC0_VFR = 0x00000004)
#define ADC0_vClearValidBit_RESULT_REG_3 (ADC0_VFR = 0x00000008)
#define ADC0_vClearValidBit_RESULT_REG_4 (ADC0_VFR = 0x00000010)
#define ADC0_vClearValidBit_RESULT_REG_5 (ADC0_VFR = 0x00000020)
#define ADC0_vClearValidBit_RESULT_REG_6 (ADC0_VFR = 0x00000040)
#define ADC0_vClearValidBit_RESULT_REG_7 (ADC0_VFR = 0x00000080)
#define ADC0_vClearValidBit_RESULT_REG_8 (ADC0_VFR = 0x00000100)
#define ADC0_vClearValidBit_RESULT_REG_9 (ADC0_VFR = 0x00000200)
#define ADC0_vClearValidBit_RESULT_REG_10 (ADC0_VFR = 0x00000400)
#define ADC0_vClearValidBit_RESULT_REG_11 (ADC0_VFR = 0x00000800)
#define ADC0_vClearValidBit_RESULT_REG_12 (ADC0_VFR = 0x00001000)
#define ADC0_vClearValidBit_RESULT_REG_13 (ADC0_VFR = 0x00002000)
#define ADC0_vClearValidBit_RESULT_REG_14 (ADC0_VFR = 0x00004000)
#define ADC0_vClearValidBit_RESULT_REG_15 (ADC0_VFR = 0x00008000)

//****************************************************************************
// @Interrupt Vectors
//****************************************************************************



// USER CODE BEGIN (ADC0_Header,9)

// USER CODE END


#endif  // ifndef _ADC0_H_
