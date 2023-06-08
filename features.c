#include "features.h"

void clear_init(){
  SYSCTL_RCGCGPIO_R |= 0x01;
  while((SYSCTL_PRGPIO_R&0x1) == 0){}
  GPIO_PORTA_CR_R |= 0x04;
  GPIO_PORTA_DIR_R &= ~0x04;
  GPIO_PORTA_DEN_R |= 0x04;
  GPIO_PORTA_PUR_R |= 0x04;;
}

//clear all entered values
void clear(int *clear_pass){
    GPIO_PORTF_DATA_R &=~ 0xE;
    for(int i=0; i<4; i++){
      clear_pass[i] = 0;
    }
}

//1 second timer
void timer(){
  SysCtlPeripheralEnable(SYSCTL_PERIPH_TIMER0);
  while(!SysCtlPeripheralReady(SYSCTL_PERIPH_TIMER0)){}
  TimerDisable(TIMER0_BASE, TIMER_A);
  TimerConfigure(TIMER0_BASE, TIMER_CFG_A_PERIODIC);
  TimerLoadSet(TIMER0_BASE, TIMER_A, 15999999);
  TimerEnable(TIMER0_BASE, TIMER_A);
}
