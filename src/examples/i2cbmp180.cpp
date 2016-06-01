/* 
 * Example code to read the contents of an I2C BMP180 chip.
 */

#include "i2cbmp180.hpp"

#define WCMD	"\xEE\xAA"	// Write start address command
#define RCMD	"\xEF"		// Read command
#define SIZE    22

int main(void)
{
	int retval = EXIT_FAILURE;
	char *data = NULL;
	struct mpsse_context *bmp180 = NULL;

	if((bmp180 = MPSSE(I2C, FOUR_HUNDRED_KHZ, MSB)) != NULL && bmp180->open)
	{
		printf("%s initialized at %dHz (I2C)\n", GetDescription(bmp180), GetClock(bmp180));
		/* Write the EEPROM start address */	
		Start(bmp180);
        Write(bmp180, WCMD, sizeof(WCMD) - 1);
        Stop(bmp180);
        Start(bmp180);
        Write(bmp180, RCMD, sizeof(RCMD) - 1);
        if(GetAck(bmp180) == ACK) {
			printf("Write OK\n");
			data = Read(bmp180, SIZE);
			if (data != NULL) {
				int i = 0;
				while (i < SIZE) {
					printf("%02x ", 0xff & data[i]);
					i++;
				}
                printf("\n");
			}
			SendNacks(bmp180);
			/* Read in one dummy byte, with a NACK */
			Read(bmp180, 1);
		} else {
            printf("Write FAILED\n");
        }

		Stop(bmp180);
        short ac1 = extractS(data, 0);
        short ac2 = extractS(data, 2);
        short ac3 = extractS(data, 4);
        unsigned short ac4 = extractUS(data, 6);
        unsigned short ac5 = extractUS(data, 8);
        unsigned short ac6 = extractUS(data, 10);
        short b1 = extractS(data, 12);
        short b2 = extractS(data, 14);
        short mb = extractS(data, 16);
        short mc = extractS(data, 18);
        short md = extractS(data, 20);
	    printf("ac1 %d ac2 %d ac3 %d\n", ac1, ac2, ac3);
	    printf("ac4 %d ac5 %d ac6 %d\n", ac4, ac5, ac6);
	    printf("b1 %d b2 %d mb %d mc %d md %d", b1, b2, mb, mc, md);
    }
	else
	{
		printf("Failed to initialize MPSSE: %s\n", ErrorString(bmp180));
	}

	Close(bmp180);
	return retval;
}

unsigned short extractUS(char* array, int index) {
    return (unsigned short)(((unsigned char)array[index]) << 8 | (unsigned char)array[index+1]);
}

short extractS(char* array, int index) {
    return (short)(((unsigned char)array[index]) << 8 | (unsigned char)array[index+1]);
}

