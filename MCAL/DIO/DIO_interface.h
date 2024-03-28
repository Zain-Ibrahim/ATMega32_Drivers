/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_interface.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Zain Ibrahim
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */


#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_


/* DIO ERROR STATEs enum*/
typedef enum
{
	DIO_OK,
	DIO_NOT_OK
} DIO_ErrorStates;

/*************** MACROS FOR PORT ***************/
/* macros for port id */
#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3


/* macros for port direction */
#define DIO_PORT_INPUT 0x00
#define DIO_PORT_OUTPUT 0xff


/* macros for port value */
#define DIO_PORT_LOW 0x00
#define DIO_PORT_HIGH 0xff


/*************** MACROS FOR PIN ***************/
/* macros for pin id */
#define DIO_PIN0 0
#define DIO_PIN1 1
#define DIO_PIN2 2
#define DIO_PIN3 3
#define DIO_PIN4 4
#define DIO_PIN5 5
#define DIO_PIN6 6
#define DIO_PIN7 7


/* macros for pin direction */
#define DIO_PIN_INPUT 0
#define DIO_PIN_OUTPUT 1


/* macros for pin value */
#define DIO_PIN_LOW 0
#define DIO_PIN_HIGH 1

/* pull up pin value macro */
#define PUD_PIN  2

/*************** APIS PROTOTYPES ***************/
/* Pin Apis */
DIO_ErrorStates DIO_enumSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection);
DIO_ErrorStates DIO_enumSetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue);
DIO_ErrorStates DIO_enumGetPinValue(u8 copy_u8PortId, u8 copy_u8PinId, u8 *copy_pu8PinValue);
DIO_ErrorStates DIO_enumTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId);
DIO_ErrorStates DIO_enumActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId);

/* Port Apis */
DIO_ErrorStates DIO_enumSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection);
DIO_ErrorStates DIO_enumSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue);
DIO_ErrorStates DIO_enumGetPortValue(u8 copy_u8PortId, u8 *copy_pu8PortValue);
DIO_ErrorStates DIO_enumTogglePortValue(u8 copy_u8PortId);
DIO_ErrorStates DIO_enumActivePortInPullUpResistance(u8 copy_u8PortId);

#endif /* DIO_INTERFACE_H_ */
