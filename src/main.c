/*
 * main.c
 *
 *  Created on: 16.07.2010
 *      Author: brunql
 */

#include "main.h"
#include "delay.h"
#include "uart0.h"
#include "adc.h"

void GPIO_Init(void)
{
	SCS = 0; // Disable FastIO

	PINSEL0 = PINSEL0_UART0_BIT_VALUE; 
	PINSEL1 = PINSEL1_ADC0_BIT_VALUE;
	
	IODIR = LED_BIT_VALUE; // Led initialize
	IOPIN = 0x00000000; // Led OFF
}

int main(void)
{
	GPIO_Init();		// Led ON, UART0, EINT1, ADC0.0
	UART0_Init(); 		// Baud rate 9600, 8N1
	ADC_Init();			// ADC0.0 
	
	for(;;){
		ADCR |= (ADCR_START_NOW << ADCR_START_BIT); /* Start ADC */
		while(!(ADSTAT & ADSTAT_DONE0_BIT_VALUE)){ /* Wait ADC */ }

		/* Get 8 bit result from 10 bits 15:6 ADDR0 */
		uint8_t adc_result = (ADDR0 & (0xff<<(ADDR_RESULT_BIT+2))) >> (ADDR_RESULT_BIT+2);
		
		UART0_PutChar(adc_result); /* Send result by UART0 to PC */
		
		delay_ms(50); /* Convertions each 50ms */
	}
}
