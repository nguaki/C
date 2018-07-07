#include <stdio.h>
#include <led.h>
#include <relay.h>
#include <unistd.h>
int
main(void)
{
	int i =0;

	for( i=0; i<3; i++){
		led_on();
		led_off();	
		usleep(500000);
		relay_on();
		relay_off();	
		usleep(500000);
	}	
	return 0;
}
