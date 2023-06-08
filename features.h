#include "tm4c123gh6pm.h"
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <inttypes.h>
#include <driverlib/systick.h>
#include "driverlib/sysctl.h"
#include "inc/hw_memmap.h"
#include "driverlib/timer.h"

void clear_init();
void clear(int *clear_pass);
void timer();