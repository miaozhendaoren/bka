//****************************************************************************
// @Module        General Purpose Timer Array 0 (GPTA0)
// @Filename      GPTA0.h
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains all function prototypes and macros for 
//                the GPTA0 module.
//
//----------------------------------------------------------------------------
// @Date          21.03.2012 15:56:00
//
//****************************************************************************

// USER CODE BEGIN (GPTA0_Header,1)

// USER CODE END



#ifndef _GPTA0_H_
#define _GPTA0_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (GPTA0_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (GPTA0_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

// USER CODE BEGIN (GPTA0_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (GPTA0_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (GPTA0_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (GPTA0_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void GPTA0_vInit(void);


// USER CODE BEGIN (GPTA0_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         GPTA0_ubGetFPCGlitchState(CELL_NAME, CELL_NUMBER, GLITCH_NAME) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the state of the selected 'Glitch Flag' 
//                (GLITCH_NAME) of the choosen FPC cell. Use the macro 
//                GPTA0_vResetFPCGlitchState to reset the 'Glitch Flag' 
//                (GLITCH_NAME). 
//                The following definitions for CELL_NAME are available:
//                GPTA0_FPC       (FPC Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 5          (FPC Cells)
//                
//                The following definitions for GLITCH_NAME are available:
//                REG            (rising edge glitch flag)
//                FEG            (falling edge glitch flag)
//
//----------------------------------------------------------------------------
// @Returnvalue   State of the 'Glitch Flag'
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
// @Parameters    GLITCH_NAME: 
//                Type of glitch to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_ubGetFPCGlitchState(CELL_NAME, CELL_NUMBER, GLITCH_NAME) _GetFPCGlitchState##CELL_NAME##_##GLITCH_NAME(CELL_NUMBER)
#define _GetFPCGlitchStateGPTA0_FPC_REG(CELL_NUMBER) GPTA0_FPCSTAT_REG##CELL_NUMBER
#define _GetFPCGlitchStateGPTA0_FPC_FEG(CELL_NUMBER) GPTA0_FPCSTAT_FEG##CELL_NUMBER


//****************************************************************************
// @Macro         GPTA0_vResetFPCGlitchState(CELL_NAME, CELL_NUMBER, GLITCH_NAME) 
//
//----------------------------------------------------------------------------
// @Description   This macro resets the state of the 'Glitch Flag' 
//                (GLITCH_NAME) of the choosen FPC cell. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_FPC       (FPC Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 5          (FPC Cells)
//                
//                The following definitions for GLITCH_NAME are available:
//                REG            (rising edge glitch flag)
//                FEG            (falling edge glitch flag)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
// @Parameters    GLITCH_NAME: 
//                Type of glitch to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vResetFPCGlitchState(CELL_NAME, CELL_NUMBER, GLITCH_NAME) _ResetFPCGlitchState##CELL_NAME##_##GLITCH_NAME(CELL_NUMBER)
#define _ResetFPCGlitchStateGPTA0_FPC_REG(CELL_NUMBER) GPTA0_FPCSTAT_REG##CELL_NUMBER = 0
#define _ResetFPCGlitchStateGPTA0_FPC_FEG(CELL_NUMBER) GPTA0_FPCSTAT_FEG##CELL_NUMBER = 0


//****************************************************************************
// @Macro         GPTA0_uwGetDCMCapture(CELL_NAME, CELL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the content of the capture register of 
//                the selected DCM cell.
//                The following definitions for CELL_NAME are available:
//                GPTA0_DCM        (24 bit DCM Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 3           (24 bit DCM Cells)
//                
//                Example:
//                // get the capture register of the DCM 3 cell
//                uwResult = GPTA0_uwGetDCMCapture(GPTA0_DCM, 3);
//
//----------------------------------------------------------------------------
// @Returnvalue   Current 24-bit value of the capture register
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_uwGetDCMCapture(CELL_NAME, CELL_NUMBER) _GetDCMCapture##CELL_NAME(CELL_NUMBER)
#define _GetDCMCaptureGPTA0_DCM(CELL_NUMBER) GPTA0_DCMCAV##CELL_NUMBER


//****************************************************************************
// @Macro         GPTA0_uwGetDCMCapcom(CELL_NAME, CELL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the content of the capcom register of 
//                the selected DCM cell.
//                The following definitions for CELL_NAME are available:
//                GPTA0_DCM        (24 bit DCM Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 3           (24 bit DCM Cells)
//                
//                Example:
//                // get the capture register of the DCM 0 cell
//                uwResult = GPTA0_uwGetDCMCapcom(GPTA0_DCM, 0);
//
//----------------------------------------------------------------------------
// @Returnvalue   Current 24-bit value of the capcom register
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_uwGetDCMCapcom(CELL_NAME, CELL_NUMBER) _GetDCMCapcom##CELL_NAME(CELL_NUMBER)
#define _GetDCMCapcomGPTA0_DCM(CELL_NUMBER) GPTA0_DCMCOV##CELL_NUMBER


//****************************************************************************
// @Macro         GPTA0_vSetDCMCapcom(CELL_NAME, CELL_NUMBER, uwValue) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the capcom register of the selected DCM 
//                cell.
//                The following definitions for CELL_NAME are available:
//                GPTA0_DCM        (24 bit DCM Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 3           (24 bit DCM Cells)
//                
//                Example:
//                // set the capture register of the DCM 0 cell
//                GPTA0_vSetDCMCapcom(GPTA0_DCM, 0, 0x00FF00);
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
// @Parameters    uwValue: 
//                24-bit value with which the capcom register is to be loaded
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vSetDCMCapcom(CELL_NAME, CELL_NUMBER, uwValue) _SetDCMCapcom##CELL_NAME(CELL_NUMBER, uwValue)
#define _SetDCMCapcomGPTA0_DCM(CELL_NUMBER, uwValue) GPTA0_DCMCOV##CELL_NUMBER = uwValue


//****************************************************************************
// @Macro         GPTA0_vGenerateDCMClockPulse(CELL_NAME, CELL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro triggers a single clock pulse generation on the 
//                choosen DCM output signal line immediately. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_DCM        (24 bit DCM Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 3           (24 bit DCM Cells)
//                
//                Example:
//                // provide the DCM 3 output with a single clock pulse 
//                GPTA0_vGenerateDCMClockPulse(GPTA0_DCM, 3);
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vGenerateDCMClockPulse(CELL_NAME, CELL_NUMBER) _GenerateDCMClockPulse##CELL_NAME(CELL_NUMBER)
#define _GenerateDCMClockPulseGPTA0_DCM(CELL_NUMBER) GPTA0_DCMCTR##CELL_NUMBER##_QCK = 1


//****************************************************************************
// @Macro         GPTA0_vSetGTReload(CELL_NAME, CELL_NUMBER, uwValue) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the reload register of the selected GT 
//                timer. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_GT        (24 bit Global Timers)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 1          (24 bit Global Timers)
//                
//                Example:
//                // set the reload register of the GT 1 cell
//                GPTA0_vSetGTReload(GPTA0_GT, 1, 0xFF0000);
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
// @Parameters    uwValue: 
//                24-bit value with which the reload register is to be loaded
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vSetGTReload(CELL_NAME, CELL_NUMBER, uwValue) _SetGTReload##CELL_NAME(CELL_NUMBER, uwValue)
#define _SetGTReloadGPTA0_GT(CELL_NUMBER, uwValue) GPTA0_GTREV##CELL_NUMBER = uwValue


//****************************************************************************
// @Macro         GPTA0_uwGetGTReload(CELL_NAME, CELL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the content of the reload register of 
//                the selected GT timer. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_GT        (24 bit Global Timers)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 1          (24 bit Global Timers)
//                
//                Example:
//                // get the reload register of the GT 1 cell
//                uwReload = GPTA0_uwGetGTReload(GPTA0_GT, 1);
//
//----------------------------------------------------------------------------
// @Returnvalue   Current 24-bit value of the reload register
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_uwGetGTReload(CELL_NAME, CELL_NUMBER) _GetGTReload##CELL_NAME(CELL_NUMBER)
#define _GetGTReloadGPTA0_GT(CELL_NUMBER) GPTA0_GTREV##CELL_NUMBER


//****************************************************************************
// @Macro         GPTA0_vWriteTmr(CELL_NAME, CELL_NUMBER, uwValue) 
//
//----------------------------------------------------------------------------
// @Description   This macro loads the timer register of the selected GPTA0 
//                cell. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_GT        (24 bit Global Timers)
//                GPTA0_GTC       (24 bit Global Timer Cells)
//                GPTA0_LTC       (16 bit Local Timer Cells)
//                GPTA0_LTC63_S   (16 bit Shadow Register of LTC63)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 1          (24 bit Global Timers)
//                00 - 31        (24 bit Global Timer Cells)
//                00 - 63        (16 bit Local Timer Cells)
//                
//                Example:
//                // write the timer register of the LTC 09 cell
//                GPTA0_vWriteTmr(GPTA0_LTC, 09, 0x1234);
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
// @Parameters    uwValue: 
//                16/24-bit value with which the timer is to be loaded
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vWriteTmr(CELL_NAME, CELL_NUMBER, uwValue) _WriteTmr##CELL_NAME(CELL_NUMBER, uwValue)
#define _WriteTmrGPTA0_GTC(CELL_NUMBER, uwValue) GPTA0_GTCXR##CELL_NUMBER = uwValue
#define _WriteTmrGPTA0_LTC(CELL_NUMBER, uwValue) GPTA0_LTCXR##CELL_NUMBER = (GPTA0_LTCXR##CELL_NUMBER & 0xFFFF0000) | (uwValue)
#define _WriteTmrGPTA0_LTC63_S(CELL_NUMBER, uwValue) GPTA0_LTCXR##CELL_NUMBER = (GPTA0_LTCXR##CELL_NUMBER & 0x0000FFFF) | ((uwValue) << 16)
#define _WriteTmrGPTA0_GT(CELL_NUMBER, uwValue) GPTA0_GTTIM##CELL_NUMBER = uwValue


//****************************************************************************
// @Macro         GPTA0_uwReadTmr(CELL_NAME, CELL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the content of the selected GPTA0 timer. 
//                Note:
//                The content of a GTC/LTC timer register is write protected 
//                for a 'capture after compare' in 'one shot mode'. Write 
//                protection is activated, when the compare value is reached 
//                and released after a software access to the timer register. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_GT        (24 bit Global Timers)
//                GPTA0_GTC       (24 bit Global Timer Cells)
//                GPTA0_LTC       (16 bit Local Timer Cells)
//                GPTA0_LTC63_S   (16 bit Shadow Register of LTC63)
//                
//                The following definitions for CELL_NUMBER are available:
//                0 - 1          (24 bit Global Timers)
//                00 - 31        (24 bit Global Timer Cells)
//                00 - 63        (16 bit Local Timer Cells)
//                
//                Example:
//                // read the timer register of the LTC 09 cell
//                uwResult = GPTA0_uwReadTmr(GPTA0_LTC, 09);
//
//----------------------------------------------------------------------------
// @Returnvalue   Current 16/24-bit value of the timer register
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_uwReadTmr(CELL_NAME, CELL_NUMBER) _ReadTmr##CELL_NAME(CELL_NUMBER)
#define _ReadTmrGPTA0_GTC(CELL_NUMBER) GPTA0_GTCXR##CELL_NUMBER
#define _ReadTmrGPTA0_LTC(CELL_NUMBER) (GPTA0_LTCXR##CELL_NUMBER & 0x0000FFFF)
#define _ReadTmrGPTA0_LTC63_S(CELL_NUMBER) (GPTA0_LTCXR##CELL_NUMBER >> 16)
#define _ReadTmrGPTA0_GT(CELL_NUMBER) GPTA0_GTTIM##CELL_NUMBER


//****************************************************************************
// @Macro         GPTA0_vSetOutputMode(CELL_NAME, CELL_NUMBER, ubMode, IMMEDIATE) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the output mode for the selected GPTA0 
//                cell. The parameter IMMEDIATE chooses if the output is 
//                changed immediate or with the next timer event. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_GTC       (24 bit Global Timer Cells)
//                GPTA0_LTC       (16 bit Local Timer Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                00 - 31        (24 bit Global Timer Cells)
//                00 - 62        (16 bit Local Timer Cells)
//                
//                The following values for ubMode are possible: 
//                0  Hold the  output by an local event only
//                1  Toggle the  output by an local event only
//                2  Reset the  output by an local event only
//                3  Set the  output by an local event only
//                4  Hold the  output by an local event or copy the previous 
//                cell action
//                5  Toggle the  output by an local event or copy the 
//                previous cell action
//                6  Reset the  output by an local event or copy the previous 
//                cell action
//                7  Set the  output by an local event or copy the previous 
//                cell action
//                
//                Example:
//                // set the output state of the LTC 09 cell to 1 if the next 
//                cell event occurs
//                GPTA0_vSetOutputMode(GPTA0_LTC, 09, 2, 0);
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
// @Parameters    ubMode: 
//                Output mode for the selected cell
// @Parameters    IMMEDIATE: 
//                1 the action occurs immediate, else 0
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vSetOutputMode(CELL_NAME, CELL_NUMBER, ubMode, IMMEDIATE) _SetOutputMode##CELL_NAME(CELL_NUMBER, ubMode, IMMEDIATE)
#define _SetOutputModeGPTA0_GTC(CELL_NUMBER, ubMode, IMMEDIATE) GPTA0_GTCCTR##CELL_NUMBER = ((GPTA0_GTCCTR##CELL_NUMBER & ~0x3800) | (ubMode << 11)) + (IMMEDIATE << 14)
#define _SetOutputModeGPTA0_LTC(CELL_NUMBER, ubMode, IMMEDIATE) GPTA0_LTCCTR##CELL_NUMBER = ((GPTA0_LTCCTR##CELL_NUMBER & ~0x3800) | (ubMode << 11)) + (IMMEDIATE << 14)


//****************************************************************************
// @Macro         GPTA0_ubGetOutputMode(CELL_NAME, CELL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the output state bit of the choosen 
//                GPTA0 cell.
//                The following definitions for CELL_NAME are available:
//                GPTA0_GTC       (24 bit Global Timer Cells)
//                GPTA0_LTC       (16 bit Local Timer Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                00 - 31        (24 bit Global Timer Cells)
//                00 - 63        (16 bit Local Timer Cells)
//                
//                Example:
//                // read the output state of the GTC 18 cell
//                ubState = GPTA0_ubGetOutputMode(GPTA0_GTC, 18);
//
//----------------------------------------------------------------------------
// @Returnvalue   State of the output bit of the selected GPTA0 cell
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_ubGetOutputMode(CELL_NAME, CELL_NUMBER) _GetOutputMode##CELL_NAME(CELL_NUMBER)
#define _GetOutputModeGPTA0_GTC(CELL_NUMBER) ((GPTA0_GTCCTR##CELL_NUMBER & ~0x7FFF) >> 15)
#define _GetOutputModeGPTA0_LTC(CELL_NUMBER) ((GPTA0_LTCCTR##CELL_NUMBER & ~0x7FFF) >> 15)


//****************************************************************************
// @Macro         GPTA0_vReEnableTmr(CELL_NAME, CELL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   If the 'One Shot Mode' is enabled each GTC/LTC event 
//                disables the cell. The disable state is cleared by a write 
//                access to the control register. Use this macro only for a 
//                self-disabled cell in 'One Shot Mode'. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_GTC       (24 bit Global Timer Cells)
//                GPTA0_LTC       (16 bit Local Timer Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                00 - 31        (24 bit Global Timer Cells)
//                00 - 62        (16 bit Local Timer Cells)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vReEnableTmr(CELL_NAME, CELL_NUMBER) _ReEnableTmr##CELL_NAME(CELL_NUMBER)
#define _ReEnableTmrGPTA0_GTC(CELL_NUMBER) GPTA0_GTCCTR##CELL_NUMBER = GPTA0_GTCCTR##CELL_NUMBER
#define _ReEnableTmrGPTA0_LTC(CELL_NUMBER) GPTA0_LTCCTR##CELL_NUMBER = GPTA0_LTCCTR##CELL_NUMBER


//****************************************************************************
// @Macro         GPTA0_vEnableCoherentUpdate(CELL_NAME, CELL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro enables the coherent update for the selected LTC 
//                cell which is configured in reset timer mode. The LTC timer 
//                may be reset by the Ei input signal line triggered by an 
//                event ocurred in an adjacent LTC cell. After a LTC reset 
//                event the coherent update is automatically disabled. 
//                The following definitions for CELL_NAME are available:
//                GPTA0_LTC       (16 bit Local Timer Cells)
//                
//                The following definitions for CELL_NUMBER are available:
//                00 - 62        (16 bit Local Timer Cells)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CELL_NAME: 
//                Name of the GPTA0 cell to be used
// @Parameters    CELL_NUMBER: 
//                Number of the GPTA0 cell to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vEnableCoherentUpdate(CELL_NAME, CELL_NUMBER) _EnableCoherentUpdate##CELL_NAME(CELL_NUMBER)
#define _EnableCoherentUpdateGPTA0_LTC(CELL_NUMBER) GPTA0_LTCCTR##CELL_NUMBER |= 0x00000280


//****************************************************************************
// @Macro         GPTA0_vStartGTTimer(TIMER) 
//
//----------------------------------------------------------------------------
// @Description   This macro starts the selected global timer (GT).
//                The following definitions for TIMER are available:
//                0 - 1          (global timer of GPTA0)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TIMER: 
//                Number of the global timer of GPTA0 to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vStartGTTimer(TIMER) _StartGTTimerGPTA0_##TIMER()
#define _StartGTTimerGPTA0_0() GPTA0_EDCTR_GT00RUN = 1
#define _StartGTTimerGPTA0_1() GPTA0_EDCTR_GT01RUN = 1


//****************************************************************************
// @Macro         GPTA0_vStopGTTimer(TIMER) 
//
//----------------------------------------------------------------------------
// @Description   This macro stops the selected global timer (GT).
//                The following definitions for TIMER are available:
//                0 - 1          (global timer of GPTA0)
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    TIMER: 
//                Number of the global timer of GPTA0 to be used
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define GPTA0_vStopGTTimer(TIMER) _StopGTTimerGPTA0_##TIMER()
#define _StopGTTimerGPTA0_0() GPTA0_EDCTR_GT00RUN = 0
#define _StopGTTimerGPTA0_1() GPTA0_EDCTR_GT01RUN = 0


//****************************************************************************
// @Macro         GPTA0_vEnableTimerClock() 
//
//----------------------------------------------------------------------------
// @Description   This macro enables the timer clock of the GPTA0 module.
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

#define GPTA0_vEnableTimerClock() GPTA0_EDCTR_G0EN = 1


//****************************************************************************
// @Macro         GPTA0_vDisableTimerClock() 
//
//----------------------------------------------------------------------------
// @Description   This macro disables the timer clock of the GPTA0 module.
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

#define GPTA0_vDisableTimerClock() GPTA0_EDCTR_G0EN = 0


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define GPTA0_SRN5INT    0x04

// USER CODE BEGIN (GPTA0_Header,9)

// USER CODE END


#endif  // ifndef _GPTA0_H_
