/*
 * TIMER.h
 *
 * Created: 23.11.2018 20:41:53
 *  Author: Reinhard
 */ 

#include "MyGPIO.h"

#ifndef TIMER_H_
#define TIMER_H_

class Timer{
	
	public:
	static void init_timer1()
	{		
		//TCCR1A &= (0x00);
		//Timer/Counter Interrupt mask register -> CS10 = Prescaler 1/f
		TCCR1B |= (1 << CS11);
		TCCR1B &= ~((1 << CS10) | (1 << CS12));
		//Timer/Counter Interrupt mask register -> TOIE1 = Overflow Interrupt enable
		//TIMSK |= (1<<TOIE1);
	}
	
	static void init_timer0()
	{
		//Timer/Counter Control Register -> CS00 = 1/f
		TCCR0 &= (0x00);
		TCCR0 |= (1 << CS00);
		//Timer/Counter Interrupt Mask Register -> TOIE0 = enable Overflow Interrupt
		TIMSK |= (1 << TOIE0);
	}
	
	
};



#endif /* TIMER_H_ */