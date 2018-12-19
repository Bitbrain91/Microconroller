/*
 * MyGPIO.h
 *
 * Created: 20.10.2018 16:57:31
 *  Author: Reinhard
 */ 

#ifndef MYGPIO_H_
#define MYGPIO_H_

#define PIN0h 0x01
#define PIN1h 0x02
#define PIN2h 0x04
#define PIN3h 0x08
#define PIN4h 0x10
#define PIN5h 0x20
#define PIN6h 0x40
#define PIN7h 0x80

class MyGPIO
{
	public:

	//Bsp.: DDR_port_to_output(&DDRA)
	static void DDR_port_to_output(volatile uint8_t* _register)
	{
		*_register = 0xFF;
	}
	
	//Bsp.: DDR_pin_to_output(&DDRA, PA2)
	static void DDR_pin_to_output(volatile uint8_t* _register, int _pinNumber)
	{
		(*_register) |= (1 << _pinNumber);
	}
	
	//Bsp.: DDR_port_to_input(&DDRA)
	static void DDR_port_to_input(volatile uint8_t* _register)
	{
		*_register = 0x00;
	}
	
	//Bsp.: DDR_pin_to_input(&DDRA, PA2)
	static void DDR_pin_to_input(volatile uint8_t* _register, int _pinNumber)
	{
		(*_register) &= ~(1 << _pinNumber);
	}
	
	//Bsp.: set_port_pin(&PORTA, PA2)
	static void set_port_pin(volatile uint8_t* _register, uint8_t _pinNumber, bool _flag)
	{
		if(_flag)
			(*_register) |= (1 << _pinNumber);
		else
			(*_register) &= ~(1 << _pinNumber);
	}
	
	//Bsp.: set_port_pins(&PORTA, PA2)
	static void set_port_all_pins(volatile uint8_t* _register, bool _flag)
	{
		if(_flag)
		(*_register) |= (0xFF);
		else
		(*_register) &= (0x00);
	}
	
	//Bsp.: set_port_multiple_pins(&PORTA, PIN1h + PIN2h + PIN4h, true)
	static void set_port_multiple_pins(volatile uint8_t* _register, uint8_t value, bool _flag)
	{
		if(_flag)
		(*_register) |= (value);
		else
		(*_register) &= ~(value);
	}
	
	//clears all other Bits 
	//Bsp.: set_port_multiple_pins_with_clear(&PORTA, PIN1h + PIN2h + PIN4h)
	static void set_port_multiple_pins_with_clear(volatile uint8_t* _register, uint8_t _value)
	{
		(*_register) &= (_value);
		(*_register) |= (_value);	
	}
	
	
	//Bsp.: toggle_port_pin(&PORTA, PA2)
	static void toggle_port_pin(volatile uint8_t* _register, uint8_t _pinNumber)
	{
		*_register ^= ( 1 << _pinNumber );
	}
	
	//Bsp.: read_port_pin(&PINA, PA2)
	static bool read_port_pin(volatile uint8_t* _register, int _pinNumber)
	{
		return (*_register) & (1<<PINC1);
	}
	
	//Bsp.: read_port(&PINA)
	static uint8_t read_port(volatile uint8_t* _register)
	{
		return (uint8_t)*_register;
	}	
	
};

#endif /* MYGPIO_H_ */
