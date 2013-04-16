#ifndef _TRANSFER__H_
#define _TRANSFER__H_

extern struct termios    oldtio, newtio;
extern int               fd;

struct package {
  unsigned char id;
  unsigned char len;
  char buffer[MAXLEN];
  unsigned short checksum;
};

unsigned short generate_crc(struct package* paket);
void restore_tcsettings();
void set_flags(int flags, int vmin, int vtime);

#endif /* _TRANSFER__H_ */
