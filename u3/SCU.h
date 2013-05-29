//****************************************************************************
// @Module        System Control Unit (SCU)
// @Filename      SCU.h
// @Project       motencpot.dav
//----------------------------------------------------------------------------
// @Controller    Infineon TC1782
//
// @Compiler      Tasking 3.5r1
//
// @Codegenerator 1.0
//
// @Description   This file contains all function prototypes and macros for 
//                the SCU module.
//
//----------------------------------------------------------------------------
// @Date          21.03.2012 15:50:36
//
//****************************************************************************

// USER CODE BEGIN (SCU_Header,1)

// USER CODE END



#ifndef _SCU_H_
#define _SCU_H_

//****************************************************************************
// @Project Includes
//****************************************************************************

// USER CODE BEGIN (SCU_Header,2)

// USER CODE END


//****************************************************************************
// @Macros
//****************************************************************************

// USER CODE BEGIN (SCU_Header,3)

// USER CODE END


//****************************************************************************
// @Defines
//****************************************************************************

//   period in normal watchdog mode =  728,18 us
//   period in time-out mode =  728,18 us
#define SCU_WDT_RELOAD 0xFFFC

  ///  - No reset is generated for a trigger of software reset
  ///  - HWCFG is not updated with SWCFG upon on Application Reset
#define SCU_RESET_OPTIONS 0x0000C000

// USER CODE BEGIN (SCU_Header,4)

// USER CODE END


//****************************************************************************
// @Typedefs
//****************************************************************************

// USER CODE BEGIN (SCU_Header,5)

// USER CODE END


//****************************************************************************
// @Imported Global Variables
//****************************************************************************

// USER CODE BEGIN (SCU_Header,6)

// USER CODE END


//****************************************************************************
// @Global Variables
//****************************************************************************

// USER CODE BEGIN (SCU_Header,7)

// USER CODE END


//****************************************************************************
// @Prototypes Of Global Functions
//****************************************************************************

void SCU_vInit(void);
void SCU_vSetIdle(void);
void SCU_vSetSleep(void);
void SCU_vServiceWDT(ushort usReload, ubyte ubPassword);
void SCU_vDisableWDT(void);
void SCU_vEnableWDT(void);
void SCU_vSoftReset(uword uwOptions);


// USER CODE BEGIN (SCU_Header,8)

// USER CODE END


//****************************************************************************
// @Macro         SCU_uwWDTStatus() 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the current status of the watchdog 
//                timer. The possible values for the returned status are: 
//                Bit 0 = 1   ->  watchdog access error 
//                Bit 1 = 1   ->  watchdog overflow error 
//                Bit 2 = 1   ->  watchdog input clock = fFPI / 256 
//                Bit 2 = 0   ->  watchdog input clock = fFPI / 16384 
//                Bit 3 = 1   ->  watchdog timer is disabled 
//                Bit 4 = 1   ->  watchdog is operating in time-out mode 
//                Bit 5 = 1   ->  watchdog error (reset prewarning)
//
//----------------------------------------------------------------------------
// @Returnvalue   Current status of the watchdog timer
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define SCU_uwWDTStatus() (WDT_SR & 0x0000003F)


//****************************************************************************
// @Macro         SCU_uwResetStatus() 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the status of the reset cause register 
//                RSTSTAT. This register indicates after a reset which type 
//                of reset had occurred and which part of the chip have been 
//                affected by that reset. 
//                The possible values for the returned status are: 
//                Bit 0 = 1    ->  the last reset was a ESR0 reset 
//                Bit 1 = 1    ->  the last reset was a ESR1 reset 
//                Bit 3 = 1    ->  the last reset was a WDT reset 
//                Bit 4 = 1    ->  the last reset was a SW reset 
//                Bit 16 = 1   ->  the last reset was a power on reset 
//                Bit 17 = 1   ->  the last reset was a OCDS reset 
//                Bit 18 = 1   ->  the last reset was a Cerberus system reset 
//                Bit 19 = 1   ->  the last reset was a Cerberus debug reset 
//                Bit 20 = 1   ->  the last reset was a Cerberus application 
//                reset 
//                Bit 21 = 1   ->  the last reset was a Tuning protection 
//                reset.
//
//----------------------------------------------------------------------------
// @Returnvalue   Value of the reset status register RST_SR
//
//----------------------------------------------------------------------------
// @Parameters    None
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define SCU_uwResetStatus() SCU_RSTSTAT


//****************************************************************************
// @Macro         SCU_vERUSetINTF(CHANNEL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro sets the INTFx bit of the choosen input channel. 
//                This bit can taken into consideration for the pattern 
//                detection. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CHANNEL_NUMBER: 
//                Number of the ERU input channel (0-3)
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define SCU_vERUSetINTF(CHANNEL_NUMBER) SCU_FMR_FS##CHANNEL_NUMBER = 1


//****************************************************************************
// @Macro         SCU_vERUResetINTF(CHANNEL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro resets the INTFx bit of the choosen input 
//                channel. This bit can taken into consideration for the 
//                pattern detection. 
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CHANNEL_NUMBER: 
//                Number of the ERU input channel (0-3)
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define SCU_vERUResetINTF(CHANNEL_NUMBER) SCU_FMR_FC##CHANNEL_NUMBER = 1


//****************************************************************************
// @Macro         SCU_ubERUGetINTF(CHANNEL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the INTFx bit of the choosen input 
//                channel. 
//
//----------------------------------------------------------------------------
// @Returnvalue   State of the INTFx bit
//
//----------------------------------------------------------------------------
// @Parameters    CHANNEL_NUMBER: 
//                Number of the ERU input channel (0-3)
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define SCU_ubERUGetINTF(CHANNEL_NUMBER) SCU_EIFR_INTF##CHANNEL_NUMBER


//****************************************************************************
// @Macro         SCU_ubERUGetPDR(CHANNEL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro returns the PDRx bit (pattern detection result) 
//                of the choosen input channel. 
//
//----------------------------------------------------------------------------
// @Returnvalue   State of the PDRx bit
//
//----------------------------------------------------------------------------
// @Parameters    CHANNEL_NUMBER: 
//                Number of the ERU input channel (0-3)
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define SCU_ubERUGetPDR(CHANNEL_NUMBER) SCU_PDRR_PDR##CHANNEL_NUMBER


//****************************************************************************
// @Macro         SCU_vSetTrapBit(CHANNEL_NUMBER) 
//
//----------------------------------------------------------------------------
// @Description   This macro triggers the NMI trap generation by software for 
//                ESRx source. 
//                Note: NMI Trap generation can be triggered in two ways:
//                      1) By calling this macro SCU_vSetTrapBit.
//                      2) By ESRx Trap event trigger.
//
//----------------------------------------------------------------------------
// @Returnvalue   None
//
//----------------------------------------------------------------------------
// @Parameters    CHANNEL_NUMBER: 
//                Number of the ESR channel (0-1)
//
//----------------------------------------------------------------------------
// @Date          21.03.2012
//
//****************************************************************************

#define SCU_vSetTrapBit(CHANNEL_NUMBER) MAIN_vResetENDINIT();\
SCU_TRAPSET_ESR##CHANNEL_NUMBER##T = 1; MAIN_vSetENDINIT()


//****************************************************************************
// @Interrupt Vectors
//****************************************************************************

#define SCU_SRN0INT    0x03

#define SCU_NMITRAP_CLASS    0x07

// USER CODE BEGIN (SCU_Header,9)

// USER CODE END


#endif  // ifndef _SCU_H_
