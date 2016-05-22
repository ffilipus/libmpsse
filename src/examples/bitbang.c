#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#define SLEEP Sleep
#define SLEEP_FACTOR 1000
#elif
#include <stdlib.h>
#define SLEEP sleep
#define SLEEP_FACTOR 1
#endif
#include <mpsse.h>

int main(void)
{
	struct mpsse_context *io = NULL;
	int i = 0, retval = EXIT_FAILURE;

	io = MPSSE(BITBANG, 0, 0);

	if(io && io->open)
	{
		for(i=0; i<10; i++)
		{
			PinHigh(io, 0);
			printf("Pin 0 is: %d\n", PinState(io, 0, -1));
			SLEEP(1*SLEEP_FACTOR);
			
			PinLow(io, 0);
			printf("Pin 0 is: %d\n", PinState(io, 0, -1));
			SLEEP(1*SLEEP_FACTOR);
		}

		retval = EXIT_SUCCESS;
	}
	else
	{
		printf("Failed to open MPSSE: %s\n", ErrorString(io));
	}

	Close(io);

	return retval;
}
