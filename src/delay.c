/*
 * delay.c
 *
 *  Created on: 20.06.2010
 *      Author: brunql
 */

#include "main.h"
#include "delay.h"

void delay_ms(unsigned ms)
{
	if(ms > MAX_DELAY_MS_VALUE){
		ms = 93; // show must go on
	}
	ms = (unsigned)((float)ms * TICKS_IN_ONE_MS);
	for(unsigned i=0; i < ms; i++){ 
		// lets do nothing
	}
}								

void delay_us(unsigned us)
{
	if(us > MAX_DELAY_uS_VALUE || us < MIN_DELAY_uS_VALUE){
		us = 93; // show must go on
	}
	us -= MIN_DELAY_uS_VALUE;
	us = (unsigned)((float)us * TICKS_IN_ONE_uS);
	for(unsigned i=0; i < us; i++){ 
		// lets do nothing
	}
}

