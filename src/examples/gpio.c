#include <stdio.h>
#ifdef _WIN32
#include <windows.h>
#define SLEEP(sec) Sleep(sec*1000)
#else
#include <stdlib.h>
#define SLEEP(sec) sleep(sec)
#endif
#include <mpsse.h>

int main(void)
{
	struct mpsse_context *io = NULL;
	int i = 0, retval = EXIT_FAILURE;

	io = MPSSE(GPIO, 0, 0);
	
	if(io && io->open)
	{
		for(i=0; i<10; i++)
		{
			PinHigh(io, GPIOL0);
			printf("GPIOL0 State: %d\n", PinState(io, GPIOL0, -1));
			SLEEP(1);
			
			PinLow(io, GPIOL0);
			printf("GPIOL0 State: %d\n", PinState(io, GPIOL0, -1));
			SLEEP(1);
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
