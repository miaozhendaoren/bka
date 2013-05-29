//****************************************************************************
// @Project       motencpot
// @Module        myboardinit.h
// @Author        (alphabet.) Andreas Doepkens, Brian Schueler
// @Filename      MAIN.c
// @Date          21.03.2012
//
// Alle Funktionen von DAvE erzeugt und aus MAIN.c nach hier ausgelagert
//
//****************************************************************************

#ifndef MYBOARDINIT_H_
#define MYBOARDINIT_H_

#include "MAIN.h"

//****************************************************************************
// @Defines
//****************************************************************************

#define RESET_INDICATOR     ((SCU_RSTSTAT & ((uword)(0x0001001B))))
#define WATCHDOG_RESET      ((uword)0x00000008)
#define SOFTWARE_RESET      ((uword)0x00000010)
#define ESR0_RESET          ((uword)0x00000001)
#define ESR1_RESET          ((uword)0x00000002)
#define POWERON_RESET       ((uword)0x00010000)

void MAIN_vInit(void);
void MAIN_vWriteWDTCON0(uword uwValue);
ubyte MAIN_vResetCheck(void);

#endif /* MYBOARDINIT_H_ */
