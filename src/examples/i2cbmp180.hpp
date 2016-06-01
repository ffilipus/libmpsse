#ifndef __I2C_BMP180_HPP__
#define __I2C_BMP180_HPP__

#include <cstdio>
#include <unistd.h>

extern "C" {
 #include <mpsse.h>
}

#define WCMD	"\xEE\xAA"	// Write reading beginning from first register 
#define RCMD	"\xEF"		// Read command
#define RUT     "\xEE\xF4\x2E"
#define RUTR    "\xEE\xF6"
#define SIZE    22

using namespace std;

unsigned short extractUS(char* array, int index);
short extractS(char* array, int index);

#endif

