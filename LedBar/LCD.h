/*
 * LCD.h
 *
 * Created: 29.10.2018 09:17:42
 *  Author: Reinhard
 */ 


#ifndef LCD_H_
#define LCD_H_
#include <avr/io.h>
#include "MyGPIO.h"
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

#define D0 0x01
#define D1 0x02
#define D2 0x04
#define D3 0x08
#define D4 0x10
#define D5 0x20
#define D6 0x40
#define D7 0x80

#define CLEAR_DISPLAY 0x01

#define RETURN_HOME 0x02
#define POS_BEGIN_FIRST_LINE 0x00
#define POS_BEGIN_SECOND_LINE 0x40

class LCD
{	
	private:
	volatile uint8_t* m_DDR;
	volatile uint8_t* m_port;
	
	
	public:
	
	LCD(volatile uint8_t* _DDR, volatile uint8_t* _port)
	{
		m_DDR = _DDR;
		m_port = _port;
		init();
	}

	inline void set_EN()
	{
		//set EN to high
		MyGPIO::set_port_pin(m_port, PB3, true);
		_delay_us(50);
		//set EN to low
		MyGPIO::set_port_pin(m_port, PB3, false);
		_delay_us(10);
	}
	
	void write_8_bit_control_command(uint8_t nibble)
	{
		//send high nibble
		uint8_t command = 0x00;
		command |= (nibble & 0xF0);
		MyGPIO::set_port_multiple_pins_with_clear(m_port, command);
		set_EN();
		
		//send low nibble
		command = 0x00;
		command |= ((nibble<<4) & (0xF0));
		MyGPIO::set_port_multiple_pins_with_clear(m_port, command);
		set_EN();
		
		_delay_ms(2);
	}
	
	void write_8_bit_data_command(uint8_t nibble)
	{
		//send high nibble
		uint8_t command = 0x04;
		command |= (nibble & 0xF0);
		MyGPIO::set_port_multiple_pins_with_clear(m_port, command);
		set_EN();
		
		//send low nibble
		command = 0x04;
		command |= ((nibble<<4) & (0xF0));
		MyGPIO::set_port_multiple_pins_with_clear(m_port, command);
		set_EN();
		
		_delay_ms(2);
	}
	
	void init()
	{
		MyGPIO::DDR_port_to_output(&DDRB);
		MyGPIO::set_port_all_pins(m_port, false);	
		_delay_ms(150);
		
		MyGPIO::set_port_multiple_pins_with_clear(m_port,0x30);
		set_EN();
		_delay_ms(5);
		
		MyGPIO::set_port_multiple_pins_with_clear(m_port,0x30);
		set_EN();		
		_delay_us(200);
		
		MyGPIO::set_port_multiple_pins_with_clear(m_port,0x30);
		set_EN();
		_delay_us(200);
		
		//set 4-Bit-mode
		MyGPIO::set_port_multiple_pins_with_clear(m_port,0x20);
		set_EN();
		_delay_ms(200);
		
		//specify interface, number of lines and font
		write_8_bit_control_command(0x28);
		
		//Display,Cursor and blinking off
		write_8_bit_control_command(0x08);
		
		//Clear Display
		write_8_bit_control_command(0x01);
		_delay_ms(3);
		
		//Entry_Mode_set(how the cursor has to move)
		write_8_bit_control_command(0x06);
	
		
		//Display On + Cursor ON + Cursor blinking
		write_8_bit_control_command(0x0F);	
	}
	
	void print_text(const char* txt)
	{
		while(*txt != '\0')
			write_8_bit_data_command(*txt++);
	}
	
	void clear_display()
	{
		write_8_bit_control_command(CLEAR_DISPLAY);
		_delay_ms(3);
	}
	
	void return_home()
	{
		write_8_bit_control_command(RETURN_HOME);
	}
	
	//set cursor position
	void set_cursor(uint8_t pos)
	{
		pos |= 0x80;
		write_8_bit_control_command(pos);
	}
	
	void print_int16(int16_t int_)
	{
		char my_string[7];
		if(itoa(int_, my_string, 10) != NULL);	
			print_text(my_string);
	}
	
	void print_int32(int32_t int_)
	{ 
		char myString[11];
		if(ltoa(int_, myString, 10) != NULL);
			print_text(myString);

	}

	
	void print_double(double double_)
	{
		char my_string[16];
		dtostre(double_,my_string,3,false);
		print_text(my_string);
	}
	
	void print_all(uint16_t timeBetweenTwoFlagsUs, uint16_t rpm, uint8_t dutyTimePercent)
	{
		char Displayline1[17];
		char Displayline2[17];
		clear_display();
		sprintf(Displayline1, "%uus | Duty", timeBetweenTwoFlagsUs);
		if(rpm < 1000)
			sprintf(Displayline2, "%urpm  | %u%%", rpm, dutyTimePercent);
		else
			sprintf(Displayline2, "%urpm | %u%%", rpm, dutyTimePercent);
		print_text(Displayline1);
		set_cursor(POS_BEGIN_SECOND_LINE);
		print_text(Displayline2);
		_delay_ms(70);			
	}
	
};

#endif /* LCD_H_ */