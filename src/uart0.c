/*
 * uart0.c
 *
 *  Created on: 15.07.2010
 *      Author: brunql
 */

#include "main.h"
#include "uart0.h"

void UART0_Init(void)
{
	// Line control register
	U0LCR = U0LCR_VALUE; /* 8 bit data, no parity, 1 stop bit */	
	U0LCR |= U0LCR_DLAB_BIT_VALUE; /* Open write access to divider registers */

	// Auto baud control register
	U0ACR = 0x00000000; /* Auto baud off */

	// Divisor latch LSB and MSB
	U0DLM = U0DLM_VALUE; // See uart0.h for definition of xxxx_VALUE macroses
	U0DLL = U0DLL_VALUE; // 9600 bit/s

	// Fractional divider register
	U0FDR = 0x10;	/* |4-bit MulVal : 4-bit DivAddVal|, 0x10 - default */
	
	// UART FIFO Control register 
	//   Enable or disable FIFO buffer in transmit doesn't matter as i think, 
	// but in UM: This bit must be set for proper UART0 operation 
	U0FCR = (1<<0); /* Enable FIFO */ 
	
	// UART Transmit enable register
	U0TER = (1<<7); /* Enable transmit U0THR or Tx FIFO */

	U0LCR &= ~U0LCR_DLAB_BIT_VALUE; /* Close write access to divider registers */
}

void UART0_PutChar(uint8_t ch)
{
	if(ch == '\n'){
		UART0_PutChar( '\r' );
	}
	while(! TRANSMIT_FINISHED ){ /* Wait until transmit ends */ }
	U0THR = ch;	
}

void UART0_PutString(uint8_t *strPtr)
{
	while(*strPtr){
		UART0_PutChar( *strPtr++ );
	}
}

void UART0_PutNumberUInt8Decimal(uint8_t num)
{
	uint8_t i0 = num % 10;
	num /= 10;
	uint8_t i1 = num % 10;
	num /= 10;
	uint8_t i2 = num % 10;

	if(i2 != 0){
		UART0_PutChar( i2 + 0x30 );
	}
	if(i1 != 0){
		UART0_PutChar( i1 + 0x30 );
	}
	UART0_PutChar( i0 + 0x30 );
}
