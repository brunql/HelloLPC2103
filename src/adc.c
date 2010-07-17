/*
 * adc.c
 *
 *  Created on: 17.07.2010
 *      Author: brunql
 */
#include "main.h"
#include "adc.h"

void ADC_Init(void)
{
	// ADC0 Control register
	/* Power to ADC */
	/* Source ADC0.0 */
	/* ADC Clock == APB div 8 */
	/* CLCKS == 000: 11 clocks / 10 bits */
	ADCR = (1<<ADCR_PDN_BIT) | (1<<ADCR_SEL_PIN0_BIT) | (8<<ADCR_CLKDIV_BIT);
}
