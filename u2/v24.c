#include <termios.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/signal.h>
#include <string.h>
#include "fileio.h"

#define BAUDRATE    B38400
#define IODEVICE    "/dev/ttyS0"
#define SEND		0
#define RECEIVE	1
#define FDINIT		-1
#define MAXLEN		64
#define MAXRETRIES 100
#define MALE		3

#define SOURCE      "quelle.txt"
#define DESTINATION "ziel.txt"

#define _POSIX_SOURCE 1  


// Obwohl globale Variablen "verboten" sind, geht es hier nicht anders.
struct termios    oldtio, newtio;
int               fd = FDINIT;

// Restore old Modemsettings
void restore_tcsettings(){
  oldtio.c_cc[VMIN]=1;
  oldtio.c_cc[VTIME]=0;
  tcsetattr(fd, TCSANOW, &oldtio);
  tcflush(fd, TCIFLUSH); // flushes the input stream
}

// Interrupthandler for restoring the old settings
void int_handler(int s) {
	printf("int_handler: fd: %d\n", fd);
	fflush(stdout);
	if (fd != FDINIT) {
		restore_tcsettings();
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

unsigned short crc(char * bytes, int len)
{
   short crc = 0;
   int i;

   while (--len >= 0) {
      crc = crc^(int)*bytes++<<8;

      for (i=0; i<8; ++i)
         if (crc & 0x8000)
            crc = crc<<1^0x1021;
         else
            crc = crc<<1;
   }
  
   return (unsigned short)(crc & 0xffff);
}


int main(int argc, char **argv) {

	struct {
    unsigned char id;
		unsigned char len;
		char buffer[MAXLEN];
    unsigned short checksum;
	} paket;

  paket.id = 0;

	char ack = 6;

  struct sigaction  sa;
	int mode, len, retries;
  unsigned char expected_counter = 0;
  char error_case = 0;

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
			paket.len = myread(paket.buffer, MAXLEN);

      unsigned char payload[MAXLEN + 2];

      memcpy(payload, &paket.id, 1);
      memcpy(&payload[1], &paket.len, 1);
      memcpy(&payload[2], paket.buffer, MAXLEN);

      paket.checksum = crc(payload,MAXLEN + 2);

      do {
			  len = write(fd, &paket, sizeof(paket));
			  printf("%d bytes written in package #%d\n", len, paket.id);
        printf("Checksum: 0x%X\n", paket.checksum);
  			len = read(fd, &ack, 1);
        retries++;
	    } while (len < 1 && retries < MAXRETRIES);

      if(retries >= MAXRETRIES) {
        printf("Too many retries.\nProcess canceled.\n");
        restore_tcsettings();
        exit(1);
      } else {
        printf("%d bytes ACK read\n", len);
        printf("%d bytes in package\n\n", paket.len);
      }

      paket.id++;
		} while (paket.len == MAXLEN);
	}	else {
		do {
			do {
        error_case = 0;
				len = read(fd, &paket, sizeof(paket));
				if (len != sizeof(paket)) {
					printf("illegal package!\n");
          error_case = 1;
        }

        if ((expected_counter - 1) == paket.id) {
          write(fd, &ack, 1);
          printf("reacknowledged package #%d\n\n", paket.id);
          error_case = 1;
        } else if (expected_counter != paket.id) {
          printf("wrong package number!\nExpected: %d, Received: %d\n", expected_counter, paket.id);
          error_case = 1;
        }
        
        unsigned char payload[MAXLEN + 2];

        memcpy(payload, &paket.id, 1);
        memcpy(&payload[1], &paket.len, 1);
        memcpy(&payload[2], paket.buffer, MAXLEN);


        // Output the paket buffer
        printf("Payload:");

        printf("%d : %d | %d : %d", paket.id, payload[0], paket.len, payload[1]);
         

        printf("\n");


        unsigned short crcsum = crc(payload,MAXLEN + 2);
        if(crcsum != paket.checksum){
          printf("Wrong checksum! Got: 0x%X Expected: 0x%X\n", crcsum, paket.checksum);
          error_case = 1;
        } else{
          printf("Checksum: 0x%X\n", crcsum);
        }
			} while (error_case == 1);

			printf("%d bytes read from package #%d\n", len, paket.id);
			printf("gueltige Nutzdaten: %d byte\n", paket.len);
			
      // Output the paket buffer
      // int j;
      // for (j=0; j<paket.len; j++) {
			//	 printf("%c", paket.buffer[j]);
      // } 
      
			mywrite(paket.buffer, paket.len);
      write(fd, &ack, 1);
			
      printf("\n\n");

      expected_counter++; // increment the expected package number
		} while (paket.len == MAXLEN);
	}	
		
	restore_tcsettings();

	return 0;
}
