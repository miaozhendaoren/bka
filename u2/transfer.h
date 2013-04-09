#ifndef _TRANSFER__H_
#define _TRANSFER__H_

int               fd = FDINIT;
struct termios    oldtio, newtio;

unsigned short generate_crc(struct package* paket);
void restore_tcsettings();
void set_flags(int flags, int vmin, int vtime);

#endif /* _TRANSFER__H_ */