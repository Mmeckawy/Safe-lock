#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <driverlib/systick.h>
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "driverlib/timer.h"
#include "inc/hw_ints.h"
#include "inc/hw_types.h"
#include "features.h"
#include "tm4c123gh6pm.h"

void lock_init();
int get_button();
int check_password(int entered_pass[], int actual_pass[], int length);
void reset_pass();
void reset_interrupt(void);