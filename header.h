//Skapar ett eget biblotek
#ifndef HEADERH
#define HEADERH

/* Klockfrekvens (beh�vs f�r f�rdr�jningsrutiner): */
#define F_CPU 16000000UL    /* 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/interrupt.h>  /* Inneh�ller avbrottsrutiner s�som PCINT0_vect. */
#include <avr/io.h>         /* Inneh�ller information om I/O-register s�som PORTB. */
#include <util/delay.h>     /* Inneh�ller funktionalitet f�r f�rdr�jningsgenerering. */



/* Makrodefinitioner f�r vart komponenterna �r kopplade p� ATmega328P samt motsvarande pin-nummer p� Arduino Uno: */
#define LED1 PORTB0                /* led 1 p� PORTB0 / pin 8. */
#define LED2 PORTB1                /* led 2 p� PORTB1 / pin 9. */
#define LED3 PORTB2                /* led 3 p� PORTB2 / pin 10. */
#define FORWARD_BUTTON PORTB5      /* Knapp f�r byte till n�sta tillst�nd ansluten till pin PORTB5 / 13 . */


//Ger knappar och dioer sin angiven port
#define LED1_ON PORTB |= (1 << LED1)  /* T�nder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2)  /* T�nder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3)  /* T�nder lysdiod 3. */

#define LED1_OFF PORTB &= (1 << LED1)  /* Sl�cker lysdiod 1. */
#define LED2_OFF PORTB &= (1 << LED2)  /* Sl�cker lysdiod 2. */
#define LED3_OFF PORTB &= (1 << LED3)  /* Sl�cker lysdiod 3. */

#define FORWARD_BUTTON_PRESSED (PINB &(1 << FORWARD_BUTTON))  /* Indikerar byte till n�sta tillst�nd */

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)      /* T�nder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3))  /* T�nder lysdioderna. */
/********************************************************************************
* bool: Datatyp som indikerar sant eller falskt. Denna datatyp �r vanlig i
*       flertalet programmeringsspr�k. I C utg�r bool dock inte en primitiv
*       datatyp, men kan implementeras via en enumeration som h�r eller via
*       inkludering av standardbiblioteket stdbool.h (f�r C99 och senare).
********************************************************************************/
typedef enum { false, true } bool;

/********************************************************************************
* led_state_t: Datatyp f�r lagring av lysdiodernas tillst�nd.
********************************************************************************/
typedef enum
{
	STATE_LED_OFF,
	STATE_LED_BINK

} led_state_t;

extern led_state_t LED; // Global variabel, synlig �verallt.

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup(void);


void delay_ms(const uint16_t delay_time_ms);
/********************************************************************************
* update_smf: Uppdaterar tillst�ndsmaskinen utefter nuvarande tillst�nd samt
*              vilken tryckknapp som trycks ned.
********************************************************************************/
void update_smf(void);


void blink_led();
/********************************************************************************
* set_smf_out: Uppdaterar tillst�ndsmaskinens utsignaler utefter aktuellt
*                 tillst�nd.
*
*                 blink_speed_ms: Lysdiodernas blinkhastighet vid blinkning.
********************************************************************************/
void set_smf_out(void);

/********************************************************************************
* fsm_reset: �terst�ller tillst�ndsmaskinen till startl�get, vilket inneb�r
*            att lysdioderna sl�cks.
********************************************************************************/
void fsm_reset(void);






#endif /* HEADERH */