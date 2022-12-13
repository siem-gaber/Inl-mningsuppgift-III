//Skapar ett eget biblotek
#ifndef HEADERH
#define HEADERH

/* Klockfrekvens (behövs för fördröjningsrutiner): */
#define F_CPU 16000000UL    /* 16 MHz. */

/* Inkluderingsdirektiv: */
#include <avr/interrupt.h>  /* Innehåller avbrottsrutiner såsom PCINT0_vect. */
#include <avr/io.h>         /* Innehåller information om I/O-register såsom PORTB. */
#include <util/delay.h>     /* Innehåller funktionalitet för fördröjningsgenerering. */



/* Makrodefinitioner för vart komponenterna är kopplade på ATmega328P samt motsvarande pin-nummer på Arduino Uno: */
#define LED1 PORTB0                /* led 1 på PORTB0 / pin 8. */
#define LED2 PORTB1                /* led 2 på PORTB1 / pin 9. */
#define LED3 PORTB2                /* led 3 på PORTB2 / pin 10. */
#define FORWARD_BUTTON PORTB5      /* Knapp för byte till nästa tillstånd ansluten till pin PORTB5 / 13 . */


//Ger knappar och dioer sin angiven port
#define LED1_ON PORTB |= (1 << LED1)  /* Tänder lysdiod 1. */
#define LED2_ON PORTB |= (1 << LED2)  /* Tänder lysdiod 2. */
#define LED3_ON PORTB |= (1 << LED3)  /* Tänder lysdiod 3. */

#define LED1_OFF PORTB &= (1 << LED1)  /* Släcker lysdiod 1. */
#define LED2_OFF PORTB &= (1 << LED2)  /* Släcker lysdiod 2. */
#define LED3_OFF PORTB &= (1 << LED3)  /* Släcker lysdiod 3. */

#define FORWARD_BUTTON_PRESSED (PINB &(1 << FORWARD_BUTTON))  /* Indikerar byte till nästa tillstånd */

#define LEDS_ON PORTB |= (1 << LED1) | (1 << LED2) | (1 << LED3)      /* Tänder lysdioderna. */
#define LEDS_OFF PORTB &= ~((1 << LED1) | (1 << LED2) | (1 << LED3))  /* Tänder lysdioderna. */
/********************************************************************************
* bool: Datatyp som indikerar sant eller falskt. Denna datatyp är vanlig i
*       flertalet programmeringsspråk. I C utgör bool dock inte en primitiv
*       datatyp, men kan implementeras via en enumeration som här eller via
*       inkludering av standardbiblioteket stdbool.h (för C99 och senare).
********************************************************************************/
typedef enum { false, true } bool;

/********************************************************************************
* led_state_t: Datatyp för lagring av lysdiodernas tillstånd.
********************************************************************************/
typedef enum
{
	STATE_LED_OFF,
	STATE_LED_BINK

} led_state_t;

extern led_state_t LED; // Global variabel, synlig överallt.

/********************************************************************************
* setup: Initierar mikrodatorn vid start.
********************************************************************************/
void setup(void);


void delay_ms(const uint16_t delay_time_ms);
/********************************************************************************
* update_smf: Uppdaterar tillståndsmaskinen utefter nuvarande tillstånd samt
*              vilken tryckknapp som trycks ned.
********************************************************************************/
void update_smf(void);


void blink_led();
/********************************************************************************
* set_smf_out: Uppdaterar tillståndsmaskinens utsignaler utefter aktuellt
*                 tillstånd.
*
*                 blink_speed_ms: Lysdiodernas blinkhastighet vid blinkning.
********************************************************************************/
void set_smf_out(void);

/********************************************************************************
* fsm_reset: Återställer tillståndsmaskinen till startläget, vilket innebär
*            att lysdioderna släcks.
********************************************************************************/
void fsm_reset(void);






#endif /* HEADERH */