/*
 * main.c
 *
 *  Created on: 16.07.2010
 *      Author: brunql
 */

#include "main.h"
#include "delay.h"
#include "uart0.h"

enum SEND_ME{
	SEND_STR,
	SEND_STUFF,	
};

// Global variables
uint8_t *sendMeStr = "brunql: Hello, World!\n";
uint8_t state = SEND_STR;

// Default ISR vector
void DefVectAddr_ISR(void) __irq
{
	__disable_irq();
	VICIntEnClr = 0xffffffff;
	UART0_PutString("Error: Hello from DefVectAddr_ISR...\n");
	for(;;){ 
		LED_BLINK( 50 );
	}
}

void ExInt1_Button_ISR(void) __irq 
{
	delay_ms(20); // Anti rattle delay

	if(!(IOPIN & EXINT1_PIN_BIT_VALUE)){ // falling-edge?
		 
		switch(state++){
			case SEND_STR: 
				UART0_PutString(sendMeStr);
				break;
			case SEND_STUFF:
				for(uint8_t i=0; i < 10; i++){
					UART0_PutNumberUInt8Decimal(i);
					UART0_PutChar(' ');
		 		}
				UART0_PutChar('\n');
				break;
			default:
				state = SEND_STR;
				UART0_PutString("Inline string test.\n");
				break;
		}

	}

	// Clear interrupt flag
	EXTINT = EXTINT_EINT1_FLAG_BIT_VALUE;

	// Clear VIC vector. 
	// From UM: "Rather, this register should be written near the end of an ISR, 
	//           to update the priority hardware."
	VICVectAddr = 0x00000000;
}

void ButtonIRQ_Init(void)
{
 	EXTMODE = EXTMODE_EINT1_BIT_VALUE;
	EXTPOLAR = EXTPOLAR_EINT1_VALUE; // Falling-edge sensitive
}

void VIC_IRQs_Init(void)
{
	VICIntEnClr 	= 0xffffffff; // Clear all interrupts
	VICSoftIntClr 	= 0xffffffff; // Disable all software interrupts 
	VICProtection 	= 0x00000000; // VIC registers can be accessed in User or Privileged mode
	VICDefVectAddr  = (unsigned long)DefVectAddr_ISR; // Default interrupt vector

	VICVectAddr1   = (unsigned long)ExInt1_Button_ISR;
	VICVectCntl1 = IRQ_SLOT_EN_BIT_VALUE | EINT1_VIC_BIT_NUMBER; // IRQ Slot enable on button
	
	VICIntSelect = 0x00000000; // All IRQ
	VICIntEnable = EINT1_VIC_BIT_VALUE; // External interrupt EINT1 P0.14 ON

	VICVectAddr = 0x00000000; // Clear interrupt address	

	// Clear interrupt flag
	EXTINT = EXTINT_EINT1_FLAG_BIT_VALUE;
}

void GPIO_Init(void)
{
	SCS = 0; // Disable FastIO

	PINSEL0 = PINSEL0_EINT1_VALUE | PINSEL0_UART0_BIT_VALUE; 
	PINSEL1 = 0x00000000;
	
	IODIR = LED_BIT_VALUE; // Led initialize
	IOPIN = 0x00000000; // Led OFF
}

int main(void)
{
	GPIO_Init();		// Led ON, UART0, EINT1
	ButtonIRQ_Init(); 	// Button interrupt on falling edge
	UART0_Init(); 			// Baud rate 9600, 8N1
	VIC_IRQs_Init(); 	// RTC, ExInt1 P0.14

	for(;;){  		
		/* Wait interrupts */ 
	}
}
