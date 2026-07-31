#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "inc/userFncFile.h"
#include "inc/systemTimer.h"
#include "inc/led_led.h"
#include "inc/timer_api1.h"
#include "inc/timer_api2.h"
#include "inc/timer_api3.h"
#include "inc/timer_api4.h"
#include "inc/timer_api5.h"
#include "inc/timer_api6.h"
#include "inc/conversionFunctions.h"
#include "inc/USB_API.h"
#include "inc/frame_MSG.h"
#include "inc/emicbus2_core.h"
#include "inc/Persist.h"

void onReset()
{
    LEDs_led_blink(100, 200, 3);
}


void eI2C(char* tag, const streamIn_t* const msg)
{
    LEDs_led_blink(100, 101, 1);
    pUSB("$s\t$r", tag, msg);
}


void eUSB(char* tag, const streamIn_t* const msg)
{
    LEDs_led_blink(100, 101, 2);
    pI2C("$s\t$r", tag, msg);
}



