//Använder mig av mitt egna biblotek
#include "header.h"

/********************************************************************************
* main: Initierar systemet vid start (konfigurerar I/O-portar samt aktiverar
*       avbrott på tryckknapparnas pinnar). Programmet hålls sedan igång
*       kontinuerligt så länge matningsspänning tillförs. Lysdioderna tillstånd
*       uppdateras via avbrottsrutiner. Tillstånsdmaskinens utsignaler
*       uppdateras kontinuerligt utefter aktuellt tillstånd.
********************************************************************************/
int main(void)
{
	setup();

	while (1)
	{
		blink_led(100);
		set_smf_out();
	}

	return 0;
}

