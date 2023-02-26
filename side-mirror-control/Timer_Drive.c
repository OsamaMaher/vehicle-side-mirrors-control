/*
 * Timer_Drive.c
 *
 * Created: 11/27/2022 12:45:01 AM
 *  Author: osama
 */ 

#include <avr/io.h>
#include "MACROS.h"
#include <avr/interrupt.h>




void timer1_COM_init_interrupt(void)
{
	
	OCR1A = 80;
	
	SET_BIT(TCCR1, CS10);
	SET_BIT(TCCR1, CS11);
	SET_BIT(TCCR1, CS13);
	
	sei();
	SET_BIT(TIMSK, TOIE1);
}



void timer0_wave_fastPWM(short value)
{
	/* set OC0 as output pin */
	SET_BIT(DDRB,0);
	/* select fast PWM mode*/
	SET_BIT(TCCR0A,WGM00);
	SET_BIT(TCCR0A,WGM01);
	/* load a value in OCR0 */
	OCR0A=value*64;
	/* select timer clock */
	SET_BIT(TCCR0B,CS00);
	SET_BIT(TCCR0B,CS02);
	/* Set OC0 on compare match, clear OC0 at BOTTOM,(inverting mode)*/
	//SET_BIT(TCCR0A,COM0A0);
	SET_BIT(TCCR0A,COM0A1);
}

