
/*
* MICLB3_Fan.cpp
*
* Created: 13.11.2018 09:19:11
* Author : Simone
* Pulse counter of the fan: External interrupt
* Pulse length measurement: Timer
* RPM calculation: integer arithmetic
*/


#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>#include "MyGPIO.h"#include "LedBar.h"#include <string.h>#include "LCD.h"
#include <stdio.h>
#include <stdlib.h>
#include "Fan.h"
#include <avr/interrupt.h>
#include <string.h>
#include "Timer.h"
#include "MyADC.h"
#include "PWM.h"

uint16_t g_timeBetweenTwoFlagsUs;

int main(void)
{	
	Fan fan;
	LCD lcd(&DDRB,&PORTB);	
	MyADC::init();
	Timer::init_timer1();
	PWM::init_PWM();
		
	sei();

	while (1)
	{
		PWM::set_PWM_duty_time(MyADC::get_ADC_input());
		fan.RPMCalc(g_timeBetweenTwoFlagsUs);
		lcd.print_all(g_timeBetweenTwoFlagsUs, fan.getRPM(), PWM::get_PWM_duty_time_percent());		
	}
}

ISR(INT0_vect)
{	
		g_timeBetweenTwoFlagsUs = TCNT1;
		TCNT1 = 0;
}

