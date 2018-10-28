/*
 * Lab1StartProject.cpp
 *
 * Created: 16.10.2018 10:01:53
 * Author : Reinhard
 */ 

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>#include "MyGPIO.h"#include "LedBar.h"

int main(void)
{
	LedBar ledBar;
	ledBar.init();

    while (1) 
    {		
		ledBar.set_LED(PA2, true);	
		ledBar.switch_LEDs(44);
		_delay_ms(1000);
		ledBar.switch_LEDs(70);
		_delay_ms(1000);
		ledBar.switch_LEDs(110);
		_delay_ms(1000);
		ledBar.switch_LEDs(160);
		_delay_ms(1000);
		ledBar.switch_LEDs(210);
		_delay_ms(1000);
		MyGPIO::toggle_port_pin(&PORTA, PA0);
		_delay_ms(1000);
		MyGPIO::toggle_port_pin(&PORTA, PA0);
		_delay_ms(1000);
		MyGPIO::toggle_port_pin(&PORTA, PA0);
		_delay_ms(1000);
		MyGPIO::toggle_port_pin(&PORTA, PA0);
    }
}

