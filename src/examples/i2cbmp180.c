/* 
 * Example code to read the contents of an I2C BMP180 chip.
 */

#include <stdio.h>
#include <mpsse.h>
#include <unistd.h>

#define WCMD	"\xEE\xAB"	// Write start address command
#define RCMD	"\xEF"		// Read command
#define SIZE	2

int main(void)
{
	int retval = EXIT_FAILURE;
	char *data = NULL;
	struct mpsse_context *bmp180 = NULL;

	if((bmp180 = MPSSE(I2C, FOUR_HUNDRED_KHZ, LSB)) != NULL && bmp180->open)
	{
		printf("%s initialized at %dHz (I2C)\n", GetDescription(bmp180), GetClock(bmp180));
	
		/* Write the EEPROM start address */	
		Start(bmp180);
		Write(bmp180, WCMD, sizeof(WCMD) - 1);
		if(GetAck(bmp180) == ACK) {
			printf("Write OK\n");
			Write(bmp180, WCMD, sizeof(RCMD) - 1);
			usleep(5000);
			data = Read(bmp180, 100);
			if (data != NULL) {
				int i = 0;
				while (data[i] != 0) {
					printf("%x ", 0xff & data[i]);
					i++;
				}
			}
			SendNacks(bmp180);
			/* Read in one dummy byte, with a NACK */
			Read(bmp180, 1);
		}

		Stop(bmp180);
	}
	else
	{
		printf("Failed to initialize MPSSE: %s\n", ErrorString(bmp180));
	}

	Close(bmp180);
	return retval;
}
