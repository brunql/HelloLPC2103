/*
 * uart0.h
 *
 *  Created on: 15.07.2010
 *      Author: brunql
 */

#ifndef UART0_H_INCLUDED
#define UART0_H_INCLUDED

#define PCLK	(XTAL / 4) /* APBDIV = 0x00 */

#define UART_BAUD_RATE	9600

#define PINSEL0_UART0_BIT_VALUE		((1<<0) | (1<<2)) /* P0.0 - TXD0, P0.1 - RXD0 */

#define U0DLL_VALUE		(PCLK / (16 * UART_BAUD_RATE)) /* Check it integer?... TODO: float dividers */
#define U0DLM_VALUE		0  /* U0DLL - low, U0DLM - high half */

#define DLAB_BIT 	7

#define U0LCR_WORD_LENGTH_SELECT	((1<<1) | (1<<0)) /* 8 bit character length */
#define U0LCR_STOP_BIT_SELECT		0 /* One stop bit */
#define U0LCR_PARITY_ENABLE			0 /* Disable parity generation and checking */
#define U0LCR_PARITY_SELECT			0x00 /* Doesn't matter */
#define U0LCR_BREAK_CONTROL			0 /* Disable break transmission */
#define U0LCR_DLAB_BIT_VALUE		_BV(DLAB_BIT) /* Enable access to Divisor Latches */

#define U0LCR_VALUE 	(	U0LCR_WORD_LENGTH_SELECT | \
							U0LCR_STOP_BIT_SELECT | \
							U0LCR_PARITY_ENABLE | \
							U0LCR_PARITY_SELECT | \
							U0LCR_BREAK_CONTROL )

#define U0ACR_VALUE				0x00000000 /* Auto baud control register */

//   THRE is set immediately upon detection of an empty UART0 THR and is
// cleared on a U0THR write
#define U0LSR_THRE_BIT_VALUE	(1<<5)	 
#define TRANSMIT_FINISHED (U0LSR & U0LSR_THRE_BIT_VALUE)


// Function prototypes
extern void UART0_Init(void);
extern void UART0_PutChar(uint8_t ch);
extern void UART0_PutString(uint8_t *strPtr);
extern void UART0_PutNumberUInt8Decimal(uint8_t num);


#endif /* UART0_H_INCLUDED */
