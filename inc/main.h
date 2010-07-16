/*					
 * main.h
 *
 *  Created on: 16.07.2010
 *      Author: brunql
 */


#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED 1

// Default includes in all modules
#include <LPC2103.H>
#include <stdint.h>


#define XTAL	(18432000UL)

#define _BV( BIT )	(1UL<<(BIT))

#define LED_BIT_VALUE	_BV( 31 )
#define LED_BLINK( MS )	{ \
							IOSET = LED_BIT_VALUE;\
							delay_ms( MS ); \
							IOCLR = LED_BIT_VALUE; \
							delay_ms( MS ); \
						}

#define EXINT1_PIN_BIT_VALUE	_BV( 14 )

/*
  PINSEL0 for P0.0..P0.15, PINSEL1 for P0.15..P0.31
29:28 P0.14
0  0  GPIO Port 0.14 
0  1  EINT1 
1  0  SCK1 (SSP1) 
1  1  DCD1 (UART1) 
*/
#define PINSEL0_EINT1_VALUE		((0 << 29) | (1 << 28))
#define EINT1_VIC_BIT_NUMBER	15
#define EINT1_VIC_BIT_VALUE			_BV( EINT1_VIC_BIT_NUMBER )
#define EXTINT_EINT1_FLAG_BIT_VALUE	_BV( 1 ) /* EXTINT Flag */
#define EXTMODE_EINT1_BIT_VALUE		_BV( 1 ) /* Edge sensivity  (mb: level sensitive)*/
#define EXTPOLAR_EINT1_VALUE		0x00000000 /* Falling-edge sensitive (mb: low-level sensitive)*/

#define IRQ_SLOT_EN_BIT_VALUE	_BV( 5 )

#endif /* MAIN_H_INCLUDED */
