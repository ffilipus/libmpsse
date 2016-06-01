#ifndef __I2C_BMP180_HPP__
#define __I2C_BMP180_HPP__

#include <cstdio>

extern "C" {
 #include <mpsse.h>
}

using namespace std;

unsigned short extractUS(char* array, int index);
short extractS(char* array, int index);

#endif

