/*
 * adc.h
 *
 *  Created on: 17.07.2010
 *      Author: brunql
 */

#ifndef ADC_H_INCLUDED
#define ADC_H_INCLUDED 1

// PINSEL1 P0.22 Bits 13:12
//0 0 GPIO Port 0.22
//1 0 Reserved
//0 0 Reserved
//1 1 AD0.0
#define PINSEL1_ADC0_BIT_VALUE	((1<<13) | (1<<12))

// ADCR SEL Bits 7:0 
// Selects which of the AD0.7:0 pins is (are) to be sampled and converted. 
// For AD0, bit 0 0x01 selects Pin AD0.0, and bit 7 selects pin AD0.7. 
#define ADCR_SEL_PIN0_BIT	0
#define ADCR_SEL_PIN1_BIT	1
#define ADCR_SEL_PIN2_BIT	2
// ...etc...				7

// ADCR CLKDIV Bits 15:8
// The APB clock (PCLK) is divided by (this value plus one) to produce 
//the clock for the A/D converter, which should be less than or equal to 4.5 MHz.
#define ADCR_CLKDIV_BIT	8


// ADCR_BURST_BIT == 1: 
//	The AD converter does repeated conversions at the rate selected by the CLKS field
//	Important: START bits must be 000 when BURST = 1 or conversions will not start.
// ADCR_BURST_BIT == 0: Conversions are software controlled and require 11 clocks.
#define ADCR_BURST_BIT	16

// ADCR CLKS Bits	19:17
//This field selects the number of clocks used for each conversion in Burst mode, and the 000
//number of bits of accuracy of the result in the RESULT bits of ADDR, between 11 clocks
//(10 bits) and 4 clocks (3 bits).
//000 11 clocks / 10 bits
//001 10 clocks / 9 bits
//010 8 clocks / 7 bits
//011 9 clocks / 8 bits
//100 7 clocks / 6 bits
//101 6 clocks / 5 bits
//110 5 clocks / 4 bits
//111 4 clocks / 3 bits
#define ADCR_CLKS_BIT		17

// ADC0 Control register Power Down BIT
// 	ADCR_PDN_BIT == 1: Power to ADC
// 	ADCR_PDN_BIT == 0: Power down mode ADC
#define ADCR_PDN_BIT		21

//  ADCR START Bits 26:24 
//When the BURST bit is 0, these bits control whether and when an A/D conversion is started:
//000 No start (this value should be used when clearing PDN to 0).
//001 Start conversion now.
//010 Start conversion when the edge selected by bit 27 occurs on P0.16/EINT0/MAT0.2 pin.
//011 Start conversion when the edge selected by bit 27 occurs on P0.22.
//100 Start conversion when the edge selected by bit 27 occurs on MAT0.1.
//101 Start conversion when the edge selected by bit 27 occurs on MAT0.3.
//110 Start conversion when the edge selected by bit 27 occurs on MAT1.0.
//111 Start conversion when the edge selected by bit 27 occurs on MAT1.1.

#define ADCR_START_BIT 	24 /* 24..26 */
#define ADCR_START_NOW	001  /* Start ADC: ADCR |= (ADCR_START_NOW << ADCR_START_BIT) */


//This bit is significant only when the START field contains 010-111. In these cases:
//1 Start conversion on a falling edge on the selected CAP/MAT signal.
//0 Start conversion on a rising edge on the selected CAP/MAT signal.
#define ADCR_EDGE_BIT		27

// AD0DR0 to AD0DR7

// ADDR RESULT Bits 15:6
//When DONE is 1, this field contains a binary fraction representing the voltage on the AD0 pin,
//divided by the voltage on the VREF pin (V/VREF). Zero in the field indicates that the voltage on
//the AD0 pin was less than, equal to, or close to that on VSSA, while 0x3FF indicates that the
//voltage on AD0 was close to, equal to, or greater than that on VREF.
#define ADDR_RESULT_BIT	6 


// This bit is set to 1 when an A/D conversion completes. It is cleared when this register is read. 
#define ADDR_DONE_BIT		31

#define ADSTAT_DONE0_BIT_VALUE	(1<<0)	

extern void ADC_Init(void);

#endif /* ADC_H_INCLUDED */
