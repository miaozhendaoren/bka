#include <termios.h>
#include <string.h>

#include "v24.h"
#include "transfer.h"
#include "crc.h"

int fd = FDINIT;
struct termios oldtio, newtio;

unsigned short generate_crc(struct package* paket)
{
  int size_id = sizeof(paket->id);
  int size_len = sizeof(paket->len);
  int size_buffer = sizeof(paket->buffer);
  int size_payload = size_buffer + size_id + size_len;

  unsigned char payload[size_payload];

  memcpy(payload, &paket->id, size_id);
  memcpy(&payload[1], &paket->len, size_len);
  memcpy(&payload[2], paket->buffer, size_buffer);

  return crc(payload, size_payload);
}

// Restore old Modemsettings
void restore_tcsettings()
{
  oldtio.c_cc[VMIN]=1;
  oldtio.c_cc[VTIME]=0;
  tcsetattr(fd, TCSANOW, &oldtio);
  tcflush(fd, TCIFLUSH); // flushes the input stream
}

/* CSTOPB : if set, 2 stopbits are used, otherwise 1 stopbit
   PARENB : if set, parity generation ist enabled for outgoing characters
            and parity check is performed on incoming characters
   CLOCAL : if set, the modem status lines are ignored 
   CREAD  : if set, the receiver is enabled and characters can be received */

void set_flags(int flags, int vmin, int vtime) 
{
  newtio.c_cflag = flags;

  /* raw input and output */
  newtio.c_iflag = 0;
  newtio.c_oflag = 0;

  /* clear lflag (no lflag settings needed) */
  newtio.c_lflag = 0;
 
  /* set timeout values */
  newtio.c_cc[VMIN]  = vmin;
  newtio.c_cc[VTIME] = vtime;
}
