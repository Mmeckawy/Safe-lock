#include "tm4c123gh6pm.h"
#include "bitwise.h"
#include "DIO.h"


void DIO_Init(enum Port p , uint32_t dir, uint32_t CR , uint32_t DEN ,uint32_t PUR)
{
     switch (p)
    {
        case portA:
            set_bit(SYSCTL_RCGCGPIO_R,0);
            while((SYSCTL_PRGPIO_R&0x1) == 0){}
            GPIO_PORTA_CR_R |= CR;
            GPIO_PORTA_DIR_R |= dir;
            GPIO_PORTA_DEN_R |= DEN;
            GPIO_PORTA_PUR_R |= PUR;
        break;

        case portB:
            set_bit(SYSCTL_RCGCGPIO_R,1);
            while((SYSCTL_PRGPIO_R& 0x2) == 0){}
            GPIO_PORTB_CR_R |= CR;
            GPIO_PORTB_DIR_R |= dir;
            GPIO_PORTB_DEN_R |= DEN;
            GPIO_PORTB_PUR_R |= PUR;
        break;

        case portC:
            set_bit(SYSCTL_RCGCGPIO_R,2);
            while((SYSCTL_PRGPIO_R&0x4) == 0){}
            GPIO_PORTC_CR_R |= CR;
            GPIO_PORTC_DIR_R |= dir;
            GPIO_PORTC_DEN_R |= DEN;
            GPIO_PORTC_PUR_R |= PUR;
        break;

        case portD:
            set_bit(SYSCTL_RCGCGPIO_R,3);
            while((SYSCTL_PRGPIO_R&0x8) == 0){}
            GPIO_PORTD_CR_R |= CR;
            GPIO_PORTD_DIR_R |= dir;
            GPIO_PORTD_DEN_R |= DEN;
            GPIO_PORTD_PUR_R |= PUR;
        break;

        case portE:
            set_bit(SYSCTL_RCGCGPIO_R,4);
            while((SYSCTL_PRGPIO_R&0x10) == 0){}
            GPIO_PORTE_CR_R |= CR;
            GPIO_PORTE_DIR_R |= dir;
            GPIO_PORTE_DEN_R |= DEN;
            GPIO_PORTE_PUR_R |= PUR;
        break;

        case portF:
            set_bit(SYSCTL_RCGCGPIO_R,5);
            while((SYSCTL_PRGPIO_R&0x20) == 0){}
            GPIO_PORTF_LOCK_R = 0x4C4F434B;
            GPIO_PORTF_CR_R |= CR;
            GPIO_PORTF_DIR_R = dir;
            GPIO_PORTF_PUR_R = PUR;
            GPIO_PORTF_DEN_R = DEN;
            
        break; 
    }


}
void DIO_WritePort(enum Port p , uint32_t value)
{
    switch (p)
    {
        case portA:
            GPIO_PORTA_DATA_R = value;
        break;

        case portB:
            GPIO_PORTB_DATA_R = value;
        break;
            GPIO_PORTC_DATA_R = value;
        case portC:
        break;
        case portD:
            GPIO_PORTD_DATA_R = value;
        break;
        case portE:
            GPIO_PORTE_DATA_R = value;
        break;
        case portF:
            GPIO_PORTF_DATA_R = value;
        break;
    }
}
void DIO_WritePin(enum Port p , uint8_t pin , uint8_t value)
{
    switch (p)
    {
        case portA:
            if(value){set_bit(GPIO_PORTA_DATA_R,pin);}
            else{clear_bit(GPIO_PORTA_DATA_R,pin);}
        break;
        case portB:
            if(value){set_bit(GPIO_PORTB_DATA_R,pin);}
            else{clear_bit(GPIO_PORTB_DATA_R,pin);}
        break;
            if(value){set_bit(GPIO_PORTC_DATA_R,pin);}
            else{clear_bit(GPIO_PORTC_DATA_R,pin);}
        case portC:
        break;
        case portD:
            if(value){set_bit(GPIO_PORTD_DATA_R,pin);}
            else{clear_bit(GPIO_PORTD_DATA_R,pin);}
        break;
        case portE:
            if(value){set_bit(GPIO_PORTE_DATA_R,pin);}
            else{clear_bit(GPIO_PORTE_DATA_R,pin);}
        break;
        case portF:
            if(value){set_bit(GPIO_PORTF_DATA_R,pin);}
            else{clear_bit(GPIO_PORTF_DATA_R,pin);}
        break;
    }
}
uint32_t DIO_Readport(enum Port p)
{
    switch (p)
    {
        case portA:
            return(GPIO_PORTA_DATA_R);
        break;
        case portB:
            return(GPIO_PORTB_DATA_R);
        break;
            return(GPIO_PORTC_DATA_R);
        case portC:
        break;
        case portD:
            return(GPIO_PORTD_DATA_R);
        break;
        case portE:
            return(GPIO_PORTE_DATA_R);
        break;
        case portF:
            return(GPIO_PORTF_DATA_R);
        break;
    }
}
uint8_t DIO_ReadPin(enum Port p ,uint8_t pin)
{
    switch (p)
    {
        case portA:
            return get_bit(&GPIO_PORTA_DATA_R, pin);
        break;
        case portB:
            return get_bit(&GPIO_PORTB_DATA_R, pin);
        break;
            return get_bit(&GPIO_PORTC_DATA_R, pin);
        case portC:
        break;
        case portD:
            return get_bit(&GPIO_PORTD_DATA_R, pin);
        break;
        case portE:
            return get_bit(&GPIO_PORTE_DATA_R, pin);
        break;
        case portF:
            return get_bit(&GPIO_PORTF_DATA_R, pin);
        break;
    }
}