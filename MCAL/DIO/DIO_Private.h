/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_private.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Zain Ibrahim
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */
#ifndef DIO_Private_h
#define DIO_Private_h

/* Group A Registers */
#define PINA_REG  *(volatile u8 *) 0x39
#define DDRA_REG  *(volatile u8 *) 0x3A
#define PORTA_REG *(volatile u8 *) 0x3B

/* Group B Registers */
#define PINB_REG  *(volatile u8 *) 0x36
#define DDRB_REG  *(volatile u8 *) 0x37
#define PORTB_REG *(volatile u8 *) 0x38

/* Group C Registers */
#define PINC_REG  *(volatile u8 *) 0x33
#define DDRC_REG  *(volatile u8 *) 0x34
#define PORTC_REG *(volatile u8 *) 0x35

/* Group D Registers */
#define PIND_REG  *(volatile u8 *) 0x30
#define DDRD_REG  *(volatile u8 *) 0x31
#define PORTD_REG *(volatile u8 *) 0x32

/* Registers used to active internal PULL-Up Resistance */
#define SFIOR_REG *(volatile u8 *) 0x50

#endif /* DIO_Private_h */
