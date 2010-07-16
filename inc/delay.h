/*
 * delay.h
 *
 *  Created on: 20.06.2010
 *      Author: brunql
 */

#ifndef DELAY_ME_H_INCLUDED
#define DELAY_ME_H_INCLUDED 1
	
// If PLL off (using Fosc (XTAL) as CCLK (System Clock))

// Disassembly: for(; ms-- ;){  }
// 0x000001D4  E2500001  SUBS      R0,R0,#0x00000001
// 0x000001D8  2AFFFFFD  BCS       0x000001D4 
#define MAGIC_TIME_EVAL_CYCLE	   4.01568627450980392 // == 4.096 / 1.02

#define TICKS_IN_ONE_MS		((XTAL / MAGIC_TIME_EVAL_CYCLE) / 1000) /* depend on time for eval ++ operations during 1 ms */
#define TICKS_IN_ONE_uS		(TICKS_IN_ONE_MS/1000)

#define	MAX_DELAY_MS_VALUE		(UINT32_MAX / TICKS_IN_ONE_MS)
#define	MAX_DELAY_uS_VALUE		(UINT32_MAX / TICKS_IN_ONE_uS)
#define MIN_DELAY_uS_VALUE		(17) /* Time to eval: us = (unsigned)((float)us * TICKS_IN_ONE_US); */

extern void delay_ms(unsigned ms);
extern void delay_us(unsigned us);

#endif /* DELAY_ME_H_INCLUDED */
