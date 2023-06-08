#include "Lock.h"

const int buttons_map[4] = {1,2,3,4}; //values of each button
int set_pass[4];
int password[4];
int button_count = 0;

void lock_init(){
  SYSCTL_RCGCGPIO_R |= 0x02;
  while((SYSCTL_PRGPIO_R& 0x2) == 0){}
  GPIO_PORTB_DIR_R &= ~0xCC;
  GPIO_PORTB_DEN_R |= 0xCC;
  GPIO_PORTB_PUR_R |= 0xCC;
  
  SYSCTL_RCGCGPIO_R |= 0x20;
  while((SYSCTL_PRGPIO_R&0x20) == 0){}
  GPIO_PORTF_LOCK_R = 0x4C4F434B;
  GPIO_PORTF_CR_R |= 0xB;
  GPIO_PORTF_DIR_R = 0xA;
  GPIO_PORTF_PUR_R = 0X01;
  GPIO_PORTF_DEN_R = 0xB;
}

//Assigning values for each button
//buttons are connected to port B
int get_button(){
  int P1,P2,P3,P4;
P1 = GPIO_PORTB_DATA_R & 0X04; //PB2
P2 = GPIO_PORTB_DATA_R & 0X08; //PB3
P3 = GPIO_PORTB_DATA_R & 0X80; //PB7
P4 = GPIO_PORTB_DATA_R & 0X40; //PB6
if(!P1) return buttons_map[0];
else if(!P2) return buttons_map[1];
else if(!P3) return buttons_map[2];
else if(!P4) return buttons_map[3];
else return -1;
}


//compare the pressed button value with the corresponding value of the actual password
int check_password(int entered_pass[], int actual_pass[], int length) {
  for (int i = 0; i < length; i++) {
    if (entered_pass[i] != actual_pass[i]) {
      return 1; // Incorrect password
    }
  }
  return 0; // Correct password
}


//reseting old password with a new one chosen by the user
void reset_pass(){
  int error;
  for(int i=0; i<4; i++){
        set_pass[i] = get_button();
        error = check_password(password,set_pass, 4);
        SysCtlDelay(10000); //Time delay to wait for the next button to be pressed
      }
      int enter = GPIO_PORTF_DATA_R & 0X01; //enter button to enter written password
      SysCtlDelay(600000); //Time delay to wait for user to press enter
       if(error==0)
       {
         //Turn the green led when the entered password pattern is correct
         GPIO_PORTF_DATA_R = 0x08;
         SysCtlDelay(50000000);
         for(int i=0; i<4; i++){
           password[i] = get_button();
           SysCtlDelay(10000); 
         }
       }
       else if(error>0){
         //Turn the red led on when the entered password is inncorrect
         GPIO_PORTF_DATA_R = 0x02;
         SysCtlDelay(5000000);
       }
}

//interrupt to reset old password
void reset_interrupt(){
  timer();
  volatile int count = 0;
  for(int i=0; i<5; i++)
  {
     while((TIMER0_RIS_R &= 0x01)==0){}
     TIMER0_ICR_R |= 0x01;
  }
  
  if(count == 5 && (GPIO_PORTF_DATA_R & 0X01)==0){
    reset_pass();
  }
}