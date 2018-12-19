/*
 * LedBar.h
 *
 * Created: 21.10.2018 13:21:04
 *  Author: Reinhard
 */ 


#ifndef LEDBAR_H_
#define LEDBAR_H_
#include <avr/io.h>
#include "MyGPIO.h"

//class MyGPIO;
class LedBar
{
	 public:
	 void init()
	 {
		 MyGPIO::DDR_port_to_output(&DDRA);
	 }
	 
	 void set_LED(uint8_t _pinNumber, bool flag)
	 {
		 MyGPIO::set_port_pin(&PORTA, _pinNumber, flag); 
	 }
	 
	 void switch_LEDs(char value)
	 {
		if(value <= 50)
		{
			MyGPIO::set_port_pin(&PORTA, PA4, false);
			MyGPIO::set_port_pin(&PORTA, PA5, false);
			MyGPIO::set_port_pin(&PORTA, PA6, false);
			MyGPIO::set_port_pin(&PORTA, PA7, false);
		}
		if((value >= 51) && (value <= 100))
		{
			MyGPIO::set_port_pin(&PORTA, PA4, true);
			MyGPIO::set_port_pin(&PORTA, PA5, false);
			MyGPIO::set_port_pin(&PORTA, PA6, false);
			MyGPIO::set_port_pin(&PORTA, PA7, false);
		}
		if((value >= 101) && (value <= 150))
		{
			MyGPIO::set_port_pin(&PORTA, PA4, true);
			MyGPIO::set_port_pin(&PORTA, PA5, true);
			MyGPIO::set_port_pin(&PORTA, PA6, false);
			MyGPIO::set_port_pin(&PORTA, PA7, false);
		}
		if((value >= 151) && (value <= 200))
		{
			MyGPIO::set_port_pin(&PORTA, PA4, true);
			MyGPIO::set_port_pin(&PORTA, PA5, true);
			MyGPIO::set_port_pin(&PORTA, PA6, true);
			MyGPIO::set_port_pin(&PORTA, PA7, false);
		}
		if((value >= 201) && (value <= 255))
		{
			MyGPIO::set_port_pin(&PORTA, PA4, true);
			MyGPIO::set_port_pin(&PORTA, PA5, true);
			MyGPIO::set_port_pin(&PORTA, PA6, true);
			MyGPIO::set_port_pin(&PORTA, PA7, true);
		}
	 }	 
};



#endif /* LEDBAR_H_ */



