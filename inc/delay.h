/*
 * delay.h
 *
 *  Created on: 20.06.2010
 *      Author: brunql
 */

#ifndef DELAY_ME_H_INCLUDED
#define DELAY_ME_H_INCLUDED 1
	
// If PLL off (using Fosc (XTAL) as CCLK (System Clock))

// Disassembly: for(unsigned i=0; i < ms; i++){  }
//0x000001C8  E3A00000  MOV       R0,#0x00000000		; unsigned i=0;
//0x000001CC  E1500001  CMP       R0,R1				 	; i < ms;
//0x000001D0  32800001  ADDCC     R0,R0,#0x00000001		; i++
//0x000001D4  3AFFFFFC  BCC       0x000001CC			; goto (i < ms);
// This code takes 5 ticks of CCLK
#define TICKS_TO_EVAL_CYCLE		5

#define TICKS_IN_ONE_MS		((XTAL / TICKS_TO_EVAL_CYCLE) / 1000) /* depend on time for eval ++ operations during 1 ms */
#define TICKS_IN_ONE_uS		((float)TICKS_IN_ONE_MS/1000)

#define	MAX_DELAY_MS_VALUE		(UINT32_MAX / TICKS_IN_ONE_MS)
#define	MAX_DELAY_uS_VALUE		(UINT32_MAX / ((float)TICKS_IN_ONE_MS/1000))
#define MIN_DELAY_uS_VALUE		(10) /* Time to eval: us = (unsigned)((float)us * TICKS_IN_ONE_US); */

extern void delay_ms(unsigned ms);
extern void delay_us(unsigned us);

#endif /* DELAY_ME_H_INCLUDED */
