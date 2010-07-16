/*
 * rtc.c
 *
 *  Created on: 15.07.2010
 *      Author: brunql
 */

#include "main.h"
#include "rtc.h"

void RTC_Init(void)
{
	// Power control for peripheral registers.
	PCONP |= (1<<PCRTC_BIT); /* If PCRTC bit is clear, then RTC register cannot be written */

	// Clock control register
	/* Clock enable, clock source - RTCX1-2 (32.768 kHz) */
	/* While CTCRST bit is set clock tick counter is reset */
 	CCR = ((1<<CLKEN_BIT) | (1<<CTCRST_BIT) | (1<<CLKSRC_BIT)); 
	
	// Counter interrupt increment register
	CIIR = (1<<IMSEC_BIT); /* Interrupt each second */
	
	// Alarm mask register
	AMR = 0xff; /* Alarm disabled, all bits masked */

	// Set now time:
	SEC = 0;
	MIN = 46;
	HOUR = 18;
	DOM = 15; // Day of mounth
	DOW = 3; // Day of week
	DOY = 1; // Day of year
	MONTH = 7;
	YEAR = 2010;

	CCR &= ~(1<<CTCRST_BIT); /* Release clock tick counter from reset */
}
