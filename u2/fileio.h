#ifndef _FILEIO__H_
#define _FILEIO__H_

#define FILEIO_SUCCESS 0
#define FILEIO_EQUELLE -1
#define FILEIO_EZIEL   -2

/******************************************************************************
*
* myopen
* ======
*
* oeffnet die Quelldatei und erzeugt eine noch leere Zieldatei mit den selben
* Zugriffsrechten wie die Quelldatei
*
* Parameter: (E) Adresse des ersten Zeichens des Strings mit dem Namen der
*                Quelldatei (ggf. inkl. Pfadangabe)
*
*            (E) Adresse des ersten Zeichens des Strings mit dem Namen der
*                Zieldatei (ggf. inkl. Pfadangabe)
*
* Rueckgabe:     Fehlercode (s.o.)
*
******************************************************************************/
int myopen(char *quelle, char *ziel);


/******************************************************************************
*
* myread
* ======
*
* liest die naechsten lange Zeichen aus der Quelldatei und legt sie in
* puffer ab
*
* Parameter: (A) Adresse der ersten Zeichens in puffer
*
*            (E) Anzahl der zu lesenden Zeichen (puffer muss mindestens diese
*                laenge haben)
*
* Rueckgabe:     Anzahl der gelesenen Zeichen bzw. -1 im Fehlerfall
*
******************************************************************************/
int myread(char *puffer, int laenge);


/******************************************************************************
*
* mywrite
* =======
*
* schreibt laenge Zeichen aus dem puffer in die Zieldatei (ihinten angefuegt 
* an den bisherigen Inhalt)
* 
*
* Parameter: (A) Adresse der ersten Zeichens in puffer
*
*            (E) Anzahl der zu schreibenden Zeichen (puffer muss mindestens
*                diese laenge haben)
*
* Rueckgabe:     Anzahl der geschriebenen Zeichen bzw. -1 im Fehlerfall
*
******************************************************************************/
int mywrite(char *puffer, int laenge);


/******************************************************************************
*
* myclose
* =======
*
* schliesst die Quell- und Zieldatei
* 
*
* Parameter:     keine
*
* Rueckgabe:     keiner
*
******************************************************************************/
void myclose(void);


#endif /* _FILEIO__H_ */
