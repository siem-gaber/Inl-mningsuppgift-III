#include "header.h"

/* Statiska funktioner: */
static inline void init_ports(void);
static inline void init_interrupts(void);

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup()
{
	init_ports();
	init_interrupts();
	return;
}



/********************************************************************************
* init_interrupts: Aktiverar PCI-avbrott samt externt avbrott INT0 på stigande
*                  flank.
*
*                  PCI-avbrotten har avbrottsvektor PCINT0_vect.
*                  Externt avbrott INT0 har avbrottsvektor INT0_vect.
********************************************************************************/
static inline void init_interrupts()
{
	asm("SEI"); 
	PCICR = (1 << PCIE0);
	EIMSK = (1 << INT0);

	EICRA = (1 << ISC00) | (1 << ISC01); 
	PCMSK0 = (1 << FORWARD_BUTTON);
	return;
}


led_state_t LED = STATE_LED_OFF;



/********************************************************************************
* init_ports: Sätter lysdiodernas pinnar till utportar och sätter tryckknapparnas
*             pinnar till aktiva inportar (insignalerna blir alltid 0 eller 1).
********************************************************************************/
static inline void init_ports()
{
	DDRB = (1 << LED1) | (1 << LED2) | (1 << LED3);
	PORTB = (1 << FORWARD_BUTTON);

	return;
}

