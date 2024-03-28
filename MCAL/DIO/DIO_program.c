/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    DIO_program.c    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Zain Ibrahim
 *  Layer  : MCAL
 *  SWC    : DIO/GPIO
 *
 */


/* Inclusions  */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "DIO_Private.h"
#include "DIO_interface.h"


//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function set the DIRECTION of the Pin  (INPUT || OUTPUT)
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>copy_u8PinId  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>copy_u8PinDirection --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumSetPinDirection(u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinDirection)
{
    DIO_ErrorStates local_enumState = DIO_OK;

    /* Make sure that pin value in the valid range */
    if ( copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7 )
    {
        
    switch (copy_u8PinDirection)
    {
        case DIO_PIN_INPUT:
            switch (copy_u8PortId)
            {
                case DIO_PORTA: CLR_BIT(DDRA_REG, copy_u8PinId); break;
                case DIO_PORTB: CLR_BIT(DDRB_REG, copy_u8PinId); break;
                case DIO_PORTC: CLR_BIT(DDRC_REG, copy_u8PinId); break;
                case DIO_PORTD: CLR_BIT(DDRD_REG, copy_u8PinId); break;
                default: local_enumState = DIO_NOT_OK;           break;
            }
            break;
            
        case DIO_PIN_OUTPUT:
            switch (copy_u8PortId)
            {
                case DIO_PORTA: SET_BIT(DDRA_REG, copy_u8PinId); break;
                case DIO_PORTB: SET_BIT(DDRB_REG, copy_u8PinId); break;
                case DIO_PORTC: SET_BIT(DDRC_REG, copy_u8PinId); break;
                case DIO_PORTD: SET_BIT(DDRD_REG, copy_u8PinId); break;
                default: local_enumState = DIO_NOT_OK;           break;
            }
            break;
            
        default: local_enumState = DIO_NOT_OK;                   break;
    }
    }
    else
    {
        local_enumState = DIO_NOT_OK;
    }

    return local_enumState;
    

}


//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function set the VALUE of the Pin  (LOW || HIGH)
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>copy_u8PinId  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>copy_u8PinDirection --> Pin Direction [ DIO_PIN_OUTPUT , DIO_PIN_INPUT ]
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumSetPinValue (u8 copy_u8PortId, u8 copy_u8PinId, u8 copy_u8PinValue)
{

    DIO_ErrorStates local_enumState = DIO_OK;

    /* Make sure that pin value in the valid range */
    if (copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
    {
        switch (copy_u8PinValue)
    {
        case DIO_PIN_LOW:
            switch (copy_u8PortId)
            {
                case DIO_PORTA: CLR_BIT(PORTA_REG, copy_u8PinId); break;
                case DIO_PORTB: CLR_BIT(PORTB_REG, copy_u8PinId); break;
                case DIO_PORTC: CLR_BIT(PORTC_REG, copy_u8PinId); break;
                case DIO_PORTD: CLR_BIT(PORTD_REG, copy_u8PinId); break;
                default: local_enumState = DIO_NOT_OK;           break;
            }
            break;
            
        case DIO_PIN_HIGH:
            switch (copy_u8PortId)
            {
                case DIO_PORTA: SET_BIT(PORTA_REG, copy_u8PinId); break;
                case DIO_PORTB: SET_BIT(PORTB_REG, copy_u8PinId); break;
                case DIO_PORTC: SET_BIT(PORTC_REG, copy_u8PinId); break;
                case DIO_PORTD: SET_BIT(PORTD_REG, copy_u8PinId); break;
                default: local_enumState = DIO_NOT_OK;           break;
            }
            break;
            
        default: local_enumState = DIO_NOT_OK;           break;
    }
    }
    else
    {
       local_enumState = DIO_NOT_OK;
    }
    
    return local_enumState;
    
    
    
}


//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function GET the value of the Pin  
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>copy_u8PinId  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
  	  =>copy_pu8PinValue --> Pointer to receive pin value
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumGetPinValue (u8 copy_u8PortId, u8 copy_u8PinId, u8* copy_pu8PinValue)
{
    DIO_ErrorStates local_enumState = DIO_OK;

    /* Make sure that pin value in the valid range */
    if (copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
    {
        switch (copy_u8PortId)
    {
        case DIO_PORTA: *copy_pu8PinValue = GET_BIT(PINA_REG, copy_u8PinId); break;
        case DIO_PORTB: *copy_pu8PinValue = GET_BIT(PINB_REG, copy_u8PinId); break;
        case DIO_PORTC: *copy_pu8PinValue = GET_BIT(PINC_REG, copy_u8PinId); break;
        case DIO_PORTD: *copy_pu8PinValue = GET_BIT(PIND_REG, copy_u8PinId); break;
        default: local_enumState = DIO_NOT_OK;                               break;
    }
    }
    else
    {
        local_enumState = DIO_NOT_OK;
    }
    
    return local_enumState;
    
}


//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function TOGGLE the value of the Pin  
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>copy_u8PinId  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumTogglePinValue(u8 copy_u8PortId, u8 copy_u8PinId)
{
    DIO_ErrorStates local_enumState = DIO_OK;
    if (copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
    {
            switch (copy_u8PortId)
        {
            case DIO_PORTA: TOG_BIT(PORTA_REG, copy_u8PinId); break;
            case DIO_PORTB: TOG_BIT(PORTB_REG, copy_u8PinId); break;
            case DIO_PORTC: TOG_BIT(PORTC_REG, copy_u8PinId); break;
            case DIO_PORTD: TOG_BIT(PORTD_REG, copy_u8PinId); break;
            default: local_enumState = DIO_NOT_OK;            break;
        }
    }
    else
    {
        local_enumState = DIO_NOT_OK;
    }

    return local_enumState;
    

    
}


//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function Activate PULL-Up Resistance for specific Pin
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>copy_u8PinId  --> Pin Number [ DIO_PIN0 , DIO_PIN1 , DIO_PIN2 , DIO_PIN3 , DIO_PIN4 , DIO_PIN5 , DIO_PIN6 , DIO_PIN7 ]
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumActivePinInPullUpResistance(u8 copy_u8PortId, u8 copy_u8PinId)
{
    DIO_ErrorStates local_enumState = DIO_OK;

    if (copy_u8PinId >= DIO_PIN0 && copy_u8PinId <= DIO_PIN7)
    {
        {
            switch (copy_u8PortId)
            {
            case DIO_PORTA:
                CLR_BIT(SFIOR_REG, PUD_PIN);
                CLR_BIT(DDRA_REG, copy_u8PinId);
                SET_BIT(PORTA_REG, copy_u8PinId);
                break;
            case DIO_PORTB:
                CLR_BIT(SFIOR_REG, PUD_PIN);
                CLR_BIT(DDRB_REG, copy_u8PinId);
                SET_BIT(PORTB_REG, copy_u8PinId);
                break;
            case DIO_PORTC:
                CLR_BIT(SFIOR_REG, PUD_PIN);
                CLR_BIT(DDRC_REG, copy_u8PinId);
                SET_BIT(PORTC_REG, copy_u8PinId);
                break;
            case DIO_PORTD:
                CLR_BIT(SFIOR_REG, PUD_PIN);
                CLR_BIT(DDRD_REG, copy_u8PinId);
                SET_BIT(PORTD_REG, copy_u8PinId);
                break;
            default:
                local_enumState = DIO_NOT_OK;
                break;
            }
        }
    }
    else
    {
        local_enumState = DIO_NOT_OK;
    }

    return local_enumState;

    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function set the DIRECTION of the Port  (INPUT || OUTPUT)
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>copy_u8PortDirection --> Port Direction [ DIO_PORT_INPUT , DIO_PORT_OUTPUT ]
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumSetPortDirection(u8 copy_u8PortId, u8 copy_u8PortDirection)

{
    DIO_ErrorStates local_enumState = DIO_OK;

    switch (copy_u8PortDirection)
    {
        /* Case that DIO port INPUT */
    case DIO_PORT_INPUT:
        switch (copy_u8PortId)
        {
        case DIO_PORTA: DDRA_REG = DIO_PORT_INPUT;  break;
        case DIO_PORTB: DDRB_REG = DIO_PORT_INPUT;  break;
        case DIO_PORTC: DDRC_REG = DIO_PORT_INPUT;  break;
        case DIO_PORTD: DDRD_REG = DIO_PORT_INPUT;  break; 
        default: local_enumState = DIO_NOT_OK;      break;
        }

        break;

          /* Case that DIO port OUTPUT */
    case DIO_PORT_OUTPUT:
        switch (copy_u8PortId)
        {
        case DIO_PORTA: DDRA_REG = DIO_PORT_OUTPUT;  break;
        case DIO_PORTB: DDRB_REG = DIO_PORT_OUTPUT;  break;
        case DIO_PORTC: DDRC_REG = DIO_PORT_OUTPUT;  break;
        case DIO_PORTD: DDRD_REG = DIO_PORT_OUTPUT;  break; 
        default: local_enumState = DIO_NOT_OK;       break;
        }

        break;
    
    default:   local_enumState = DIO_NOT_OK;          break;
    }

    return local_enumState;
    
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function set the VALUE of the PORT  (HIGH || LOW)
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>copy_u8PortValue --> Port Direction [ DIO_PORT_HIGH , DIO_PORT_LOW ]
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumSetPortValue(u8 copy_u8PortId, u8 copy_u8PortValue)
{

    DIO_ErrorStates local_enumState = DIO_OK;

    switch (copy_u8PortValue)
    {
        /* Case that DIO port LOW */
    case DIO_PORT_INPUT:
        switch (copy_u8PortId)
        {
        case DIO_PORTA: PORTA_REG = DIO_PORT_LOW;  break;
        case DIO_PORTB: PORTB_REG = DIO_PORT_LOW;  break;
        case DIO_PORTC: PORTC_REG = DIO_PORT_LOW;  break;
        case DIO_PORTD: PORTD_REG = DIO_PORT_LOW;  break; 
        default: local_enumState = DIO_NOT_OK;     break;
        }

        break;

          /* Case that DIO port HIGH */
    case DIO_PORT_OUTPUT:
        switch (copy_u8PortId)
        {
        case DIO_PORTA: PORTA_REG = DIO_PORT_HIGH;  break;
        case DIO_PORTB: PORTB_REG = DIO_PORT_HIGH;  break;
        case DIO_PORTC: PORTC_REG = DIO_PORT_HIGH;  break;
        case DIO_PORTD: PORTD_REG = DIO_PORT_HIGH;  break; 
        default: local_enumState = DIO_NOT_OK;      break;
        }

        break;
    
    default:   local_enumState = DIO_NOT_OK;          break;
    }

    return local_enumState;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function GET the VALUE of the PORT  
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
  	  =>copy_pu8PortValue --> Pointer to receive port value 
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumGetPortValue(u8 copy_u8PortId, u8 *copy_pu8PortValue)
{
    DIO_ErrorStates local_enumState = DIO_OK;

    switch (copy_u8PortId)
    {

    case DIO_PORTA: *copy_pu8PortValue = PINA_REG;  break;
    case DIO_PORTB: *copy_pu8PortValue = PINB_REG;  break;
    case DIO_PORTC: *copy_pu8PortValue = PINC_REG;  break;
    case DIO_PORTD: *copy_pu8PortValue = PIND_REG;  break;
    default: local_enumState = DIO_NOT_OK;          break;

    }

    return local_enumState;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function TOGGLE the VALUE of the PORT  
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA , DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumTogglePortValue(u8 copy_u8PortId)
{

    DIO_ErrorStates local_enumState = DIO_OK;

      switch (copy_u8PortId)
    {

    case DIO_PORTA: PORTA_REG = ~PORTA_REG;  break;
    case DIO_PORTB: PORTB_REG = ~PORTB_REG;  break;
    case DIO_PORTC: PORTC_REG = ~PORTC_REG;  break;
    case DIO_PORTD: PORTD_REG = ~PORTD_REG;  break;
    default: local_enumState = DIO_NOT_OK;   break;

    }

    return local_enumState;
}

//---------------------------------------------------------------------------------------------------------------------------------------------------
/*
 * Breif : This Function Activate PULL-Up Resistance for entire Port
 * Parameters :
  	  =>copy_u8PortId --> Port Name [ DIO_PORTA ,	DIO_PORTB , DIO_PORTC , DIO_PORTD ]
 * return : its status --> enum [ DIO_OK, DIO_NOT_OK]
 */
DIO_ErrorStates DIO_enumActivePortInPullUpResistance(u8 copy_u8PortId)
{
    
    DIO_ErrorStates local_enumState = DIO_OK;

    
        if (copy_u8PortId >= DIO_PORTA && copy_u8PortId <= DIO_PORTD  )
        {
            CLR_BIT(SFIOR_REG, PUD_PIN);
            DIO_enumSetPortDirection(copy_u8PortId,DIO_PORT_INPUT);
            DIO_enumSetPortValue(copy_u8PortId,DIO_PORT_HIGH);

        }
        else 
        {
            local_enumState=DIO_NOT_OK;
        }
        
      

    return local_enumState;

}
