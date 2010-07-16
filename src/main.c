/*
 * main.c
 *
 *  Created on: 16.07.2010
 *      Author: brunql
 */

#include "main.h"
#include "delay.h"

int main(void)
{
	IODIR = LED_BIT_VALUE; // Led initialize
	IOPIN = 0x00000000; // Led OFF

	for(;;){ 
		IOSET = LED_BIT_VALUE;
		delay_ms(1);
		IOCLR = LED_BIT_VALUE;
		delay_us(1000);
	}
}
