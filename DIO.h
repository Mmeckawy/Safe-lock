#include <stdint.h>
enum Port
{
    portA,
    portB,
    portC,
    portD,
    portE,
    portF
};

void DIO_Init(enum Port p , uint32_t dir, uint32_t CR , uint32_t DEN,uint32_t PUR);
void DIO_WritePort(enum Port P ,uint32_t value);
void DIO_WritePin(enum Port p , uint8_t pin , uint8_t value);
uint32_t DIO_Readport(enum Port p);
uint8_t DIO_ReadPin(enum Port p ,uint8_t pin);