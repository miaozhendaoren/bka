#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/signal.h>
#include "fileio.h"

#define BAUDRATE    B38400
#define IODEVICE    "/dev/ttyS0"
#define SEND		0
#define RECEIVE	1
#define FDINIT		-1
#define MAXLEN		128
#define MAXRETRIES 3
#define MALE		3

#define SOURCE      "/var/log/syslog"
#define DESTINATION "ziel.txt"

#define _POSIX_SOURCE 1  

// Obwohl globale Variablen "verboten" sind, geht es hier nicht anders.
struct termios    oldtio, newtio;
int               fd = FDINIT;

void int_handler(int s) {
	printf("int_handler: fd: %d\n", fd);
	fflush(stdout);
	if (fd != FDINIT) {
		oldtio.c_cc[VMIN]=1;
		oldtio.c_cc[VTIME]=0;
		tcsetattr(fd, TCSANOW, &oldtio);
		tcflush(fd, TCIFLUSH); // flushes the input stream
		printf("%s reset by signal SIGINT\n", IODEVICE);
		close(fd);
	}
	exit(0);
}

/* CSTOPB : if set, 2 stopbits are used, otherwise 1 stopbit
   PARENB : if set, parity generation ist enabled for outgoing characters
            and parity check is performed on incoming characters
   CLOCAL : if set, the modem status lines are ignored 
   CREAD  : if set, the receiver is enabled and characters can be received */

void set_flags(int flags, int vmin, int vtime) {
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



int main(int argc, char **argv) {
	struct {
		unsigned char len;
		char buffer[MAXLEN];
	} paket;
	char ack = 6;

  struct sigaction  sa;
	int mode, j, len, myreadlen, retries;


  // Checking Arguments
	if (argc != 2 || ((argv[1][0] != 's') && (argv[1][0] != 'r'))) { 
		printf("usage: v24 [s | r]\n");
		return 0;
	}	

	printf("mode = %c\n", argv[1][0]);
	mode = RECEIVE;
	if (argv[1][0] == 's') {
		mode = SEND;
  }

	if (mode == SEND) {
		printf("SEND-mode\n");
	} else {
		printf("RECEIVE-mode\n");
  }

 	if (myopen(SOURCE, DESTINATION) < 0) {
		return 1;
  }
 
  /* Setting the interrupt-handler */
  sa.sa_handler = int_handler;
	sa.sa_flags = 0;
	sigaction(SIGINT, &sa, NULL); 

  fd = open(IODEVICE, O_RDWR); // set filedescriptor to iodevice
  if (fd <0) {
    perror(IODEVICE); 
    return(1); 
  }

  printf("fd: %d\n", fd);
  fflush(stdout);

  /* save current IO-settings */
  tcgetattr(fd, &oldtio); 

  /* - set baud rate and hardware flow control to 8bit, no parity, 1 stopbit
     - enable reception of characters */

  int flags = (BAUDRATE | CS8 | CLOCAL | CREAD); // building bit-mask

  if (mode == SEND) {
    set_flags(flags, 0, 10);
  } else {
    set_flags(flags, sizeof(paket), 1);
  }
 
  /* now clean the modem line and activate the settings for modem */
  tcflush(fd, TCIFLUSH);
  tcsetattr(fd, TCSANOW, &newtio);

  

	if (mode == SEND) {
		do {
      retries = 0;
			myreadlen = myread(paket.buffer, MAXLEN);
			paket.len = myreadlen;

      do {
			  len = write(fd, &paket, sizeof(paket));
			  printf("%d bytes written\n", len);
  			len = read(fd, &ack, 1);
        retries++;
	    } while (len < 1 && retries <= MAXRETRIES);

      if(retries > MAXRETRIES) {
        printf("Too many retries.\nProcess canceled.\n");
        exit(1);
      } else {
        printf("%d bytes read\n\n", len);
      }
		} while (myreadlen == MAXLEN);
	}	else {
		do {
			do {
				len = read(fd, &paket, sizeof(paket));
				if (len != sizeof(paket)) {
					printf("time-out!\n");
        }
			} while (len != sizeof(paket));

			printf("%d bytes read\n", len);
			printf("gueltige Nutzdaten: %d byte\n", paket.len);
			for (j=0; j<paket.len; j++) {
				printf("%c", paket.buffer[j]);
      }

			mywrite(paket.buffer, paket.len);
			write(fd, &ack, 1);
			printf("\n\n");
		} while (paket.len == MAXLEN);
	}	
		
	oldtio.c_cc[VMIN]=1;
	oldtio.c_cc[VTIME]=0;
	tcsetattr(fd, TCSANOW, &oldtio);
  tcflush(fd, TCIFLUSH);

	return 0;
}
