/*
 * car_test.c
 *
 * Created: 12/13/2022 8:00:36 PM
 * Author : osama
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include "Timer_Drive.h"
#include "MACROS.h"

unsigned char sec=0;
signed char counter;
int main(void)
{
    SET_BIT(DDRB,0);
	SET_BIT(DDRB,2);
	SET_BIT(DDRB,3);
	CLR_BIT(DDRB,1);
	char flag=0;
	timer1_COM_init_interrupt();
    while (1) 
    {
		CLR_BIT(TCCR0A,COM0A1);
		flag=0;
		while (READ_BIT(PINB, 1) == 1)
		{
			counter = sec;
			if (flag==0)
			{
				sec=0;
				flag=1;
			}
			timer0_wave_fastPWM(3);
			SET_BIT(PORTB, 2);
			if (sec >= 10)
			{
				CLR_BIT(PORTB, 2);
				while (READ_BIT(PINB, 1) == 1);
				counter=10;
				sec=0;
			}
		}
		if (flag==1)
		{
			timer0_wave_fastPWM(3);
			sec=0;
			while (counter>=0)
			{
				CLR_BIT(PORTB, 2);
				SET_BIT(PORTB, 3);
				if (sec >=1)
				{
					counter--;
					sec=0;
				}
			}
			CLR_BIT(PORTB, 3);
		}
		
    }
}

ISR(TIMER1_OVF_vect)
{
	sec++;
}
