#include "header.h"


/********************************************************************************
* ISR (PCINT0): Avbrottsrutin f�r PCI-avbrott p� I/O-port B, som anropas
*                    vid uppsl�ppning eller nedtryckning av tryckknappar
*                    anslutna till pin 12 - 13 (PORTB4 - PORTB4). Om n�gon av
*                    dessa knappar trycks ned s� uppdateras tillst�ndsmaskinen.
********************************************************************************/
ISR(PCINT0_vect)
{
	if (FORWARD_BUTTON_PRESSED)
	{
		update_smf();
	}
}
