/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    BUZZER_config.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Zain Ibrahim
 *  Layer  : HAL
 *  SWC    : BUZZER
 *
 */

#ifndef BUZZER_CONFIG_H_
#define BUZZER_CONFIG_H_

/* MACROS for configuring BUZZER port and pin */
#define BUZZER_PORT  DIO_PORTC
#define BUZZER_PIN	 DIO_PIN6

#define BUZZER_ACTIVE_HIGH 1
#define BUZZER_ACTIVE_LOW  0

/*
 choose between :
				    BUZZER_ACTIVE_HIGH
				    BUZZER_ACTIVE_LOW

*/
#define BUZZER_ACTIVE_STATE   BUZZER_ACTIVE_HIGH

/* MACROS for pin value */
#define BUZZER_PIN_HIGH   1
#define BUZZER_PIN_LOW    0


/*
 * SELECT buzzer blinking time in Ms
 */
#define BUZZER_TIME_ON    1000



#endif /* BUZZER_CONFIG_H_ */