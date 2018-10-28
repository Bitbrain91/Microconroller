/*
 * MyGPIO.h
 *
 * Created: 20.10.2018 16:57:31
 *  Author: Reinhard
 */ 

#ifndef MYGPIO_H_
#define MYGPIO_H_

class MyGPIO
{
	public:
	
	static void DDR_port_to_output(volatile uint8_t* _register)
	{
		*_register = 0xFF;
	}
	
	static void DDR_pin_to_output(volatile uint8_t* _register, int _pinNumber)
	{
		(*_register) |= (1 << _pinNumber);
		PORTB |= (1 << _pinNumber);
	}
	
	static void DDR_port_to_input(volatile uint8_t* _register)
	{
		*_register = 0x00;
	}
	
	static void DDR_pin_to_input(volatile uint8_t* _register, int _pinNumber)
	{
		(*_register) &= ~(1 << _pinNumber);
	}
	
	static void set_port_pin(volatile uint8_t* _register, uint8_t _pinNumber, bool flag)
	{
		if(flag)
			(*_register) |= (1 << _pinNumber);
		else
			(*_register) &= ~(1 << _pinNumber);
	}
	
	static void toggle_port_pin(volatile uint8_t* _register, uint8_t _pinNumber)
	{
		*_register ^= ( 1 << _pinNumber );
	}
	
	static bool read_port_pin(volatile uint8_t* _register, int _pinNumber)
	{
		return (*_register) & (1<<PINC1);
	}
};

#endif /* MYGPIO_H_ */
