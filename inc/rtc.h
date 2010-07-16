/*
 * rtc.h
 *
 *  Created on: 15.07.2010
 *      Author: brunql
 */

#ifndef RTC_H_INCLUDED
#define RTC_H_INCLUDED 1

// VBAT: Dedicated power supply pin can be connected to a battery or to the main 3.3 V.

#define RTC_VIC_BIT_NUMBER	13 /* Number of bit in VIC vectors */
#define RTC_VIC_BIT_VALUE	(1<<RTC_VIC_BIT_NUMBER)

/* Remark: Note that if the RTC is running from the 32 kHz signal and powered by VBAT, the
internal registers can be read. However, they cannot be written to unless the PCRTC bit in
the PCONP register is set to 1 (see Section 5–10.3). */
#define PCRTC_BIT	9

#define CLKEN_BIT	0 /* Clock enable */
#define CTCRST_BIT	1 /* Clock tick counter reset while whis bit set */
#define CLKSRC_BIT	4 /* Clock source. If set RTCX1/2 else System clock with prescaller. */

#define IMSEC_BIT	0
#define IMMIN_BIT	1
#define IMHOUR_BIT	2
// ... etc. ... 	7


extern void RTC_Init(void);

 #endif /* RTC_H_INCLUDED */
