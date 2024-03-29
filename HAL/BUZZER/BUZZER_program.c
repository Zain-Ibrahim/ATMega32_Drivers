/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BUZZER_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Zain Ibrahim
 *  Layer  : HAL
 *  SWC    : BUZZER
 *
 */

#include "BUZZER_interface.h"
#include "BUZZER_private.h"
#include "BUZZER_config.h"
#include "DIO_interface.h"
#include <util/delay.h>

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function initilize the DIRECTION of the buzzer Pin as OUTPUT
 * Parameters : void
 * return : void
 */
void BUZZER_voidBuzzerInit(void)
{
	DIO_enumSetPinDirection(BUZZER_PORT, BUZZER_PIN, DIO_PIN_OUTPUT);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function turn on the buzzer according to it's active state
 * Parameters : void
 * return : void
 */
void BUZZER_voidBuzzerOn(void)
{
#if BUZZER_ACTIVE_STATE == BUZZER_ACTIVE_LOW

	DIO_enumSetPinValue(BUZZER_PORT, BUZZER_PIN, BUZZER_PIN_LOW);

#elif BUZZER_ACTIVE_STATE == BUZZER_ACTIVE_HIGH

	DIO_enumSetPinValue(BUZZER_PORT, BUZZER_PIN, BUZZER_PIN_HIGH);

#endif
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function turn off the buzzer according to it's active state
 * Parameters : void
 * return : void
 */
void BUZZER_voidBuzzerOff(void)
{
#if BUZZER_ACTIVE_STATE == BUZZER_ACTIVE_LOW

	DIO_enumSetPinValue(BUZZER_PORT, BUZZER_PIN, BUZZER_PIN_HIGH);

#elif BUZZER_ACTIVE_STATE == BUZZER_ACTIVE_HIGH

	DIO_enumSetPinValue(BUZZER_PORT, BUZZER_PIN, BUZZER_PIN_LOW);

#endif
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function turn TOGGLE the buzzer 
 * Parameters : void
 * return : void
 */
void BUZZER_voidBuzzerTog(void)
{
	
	DIO_enumTogglePinValue(BUZZER_PORT, BUZZER_PIN);
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function turn on the buzzer for while
 * Parameters : void
 * return : void
 */
void BUZZER_voidBuzzerOnOnce(void)
{
	DIO_voidTogglePinValue(BUZZER_PORT, BUZZER_PIN);
	_delay_ms(BUZZER_TIME_ON);
	DIO_voidTogglePinValue(BUZZER_PORT, BUZZER_PIN);
	
}