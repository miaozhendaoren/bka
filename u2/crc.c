#include "crc.h"

unsigned short crc(unsigned char * bytes, int len)
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