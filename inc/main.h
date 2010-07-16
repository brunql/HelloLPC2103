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

#endif /* MAIN_H_INCLUDED */
