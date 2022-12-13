#include "header.h"


/********************************************************************************
* ISR (PCINT0): Avbrottsrutin för PCI-avbrott på I/O-port B, som anropas
*                    vid uppsläppning eller nedtryckning av tryckknappar
*                    anslutna till pin 12 - 13 (PORTB4 - PORTB4). Om någon av
*                    dessa knappar trycks ned så uppdateras tillståndsmaskinen.
********************************************************************************/
ISR(PCINT0_vect)
{
	if (FORWARD_BUTTON_PRESSED)
	{
		update_smf();
	}
}
