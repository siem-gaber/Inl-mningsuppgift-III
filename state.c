#include "header.h"




/********************************************************************************
* set_smf_out: Uppdaterar tillståndsmaskinens utsignaler utefter aktuellt
*              tillstånd.
********************************************************************************/
void set_smf_out(void)
{
	LEDS_OFF;

	if (LED == STATE_LED_OFF)LEDS_OFF;
	else if (LED == STATE_LED_BINK) blink_led();


	return;
}

/********************************************************************************
* uppdate_smf: Uppdaterar tillståndsmaskinen utefter nuvarande tillstånd samt
*              vilken tryckknapp som trycks ned. För att avbryta eventuell
*              blinkning så nollställs lysdiodernas blinkhastighet temporärt
*              när aktuellt tillstånd övergår från blinkande till något annat.
*              Tillståndsmaskinens utsignaler uppdateras innan funktionen
*              avslutas (eventuell blinkning genomförs ej, utan kräver att
*              användaren kör tillståndsmaskinen via funktionen set_fsm_output).
********************************************************************************/
void update_smf(void)
{
	switch (LED)
	{
		case STATE_LED_OFF:
		{
			if (FORWARD_BUTTON_PRESSED)
			{
				LED = STATE_LED_BINK;
			}

			break;
		}
		case STATE_LED_BINK:
		{
			if (FORWARD_BUTTON_PRESSED)
			{
				LED = STATE_LED_OFF;
			}
			break;
		}
	}

}
/********************************************************************************
* delay_ms: Genererar fördröjning mätt i millisekunder. Fördröjningstiden
*           refereras till via en pekare för att direkt kunna uppdateras,
*           exempelvis för att avbrytas (åstadkommes genom att värdet på den
*           passerade adressen nollställs).
*
*           - delay_time_ms: Pekare till fördröjningstiden mätt i ms.
********************************************************************************/
void delay_ms(const uint16_t delay_time_ms)
{
	for (uint16_t i = 0; i < delay_time_ms; ++i)
	{
		_delay_ms(1);
	}

	return;
}


/********************************************************************************
* blink_led: bestämer hur ledsen ska blinka
********************************************************************************/
void blink_led(const uint16_t delay_time_ms)
{

	if (LED == STATE_LED_BINK)
	{
		LED3_OFF;
		LED1_ON;
		delay_ms(delay_time_ms);
		LED1_OFF;
		LED2_ON;
		delay_ms(delay_time_ms);
		LED2_OFF;
		LED3_ON;
		delay_ms(delay_time_ms);

		return;
	}
}