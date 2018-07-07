#include <stdio.h>
#include "led.h"
#include "relay.h"

int
main(void)
{
	led_on();
	led_off();	
	relay_on();
	relay_off();	
	
	return 0;
}
