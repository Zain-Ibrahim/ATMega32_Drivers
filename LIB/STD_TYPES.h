/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STD_TYPES.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Zain Ibrahim
 *  Layer  : LIB/UTILS
 *  SWC    : STD_TYPES
 *
 */
#ifndef STD_TYPES_h
#define STD_TYPES_h

/* unsigned Data Types */
typedef unsigned char		u8;    /*           0 .. 255                */
typedef unsigned short		u16;   /*           0 .. 65,535             */
typedef unsigned long int   u32;   /*           0 .. 4,294,967,295      */
typedef unsigned long		u64;   /*       0..18446744073709551615     */

/* signed Data Types */   
typedef signed char		    s8;    /*        -128 .. +127               */
typedef signed short        s16;   /*      -32,768 .. +32,767           */
typedef signed long int     s32;   /* -2,147,483,648 .. +2,147,483,647  */
typedef signed long		    s64;

/* floating point Data Types */
typedef float				f32;
typedef double			    f64;

/* Boolean Data Type */
typedef unsigned char bool;

/* Boolean Values */
#define FALSE       (0u)
#define TRUE        (1u)

/* Boolean Data Type */
#define NULL					(void *)0

#endif /* STD_TYPES_h */
