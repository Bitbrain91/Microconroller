/*
 * PWM.h
 *
 * Created: 07.12.2018 23:21:15
 *  Author: Reinhard
 */ 


#ifndef PWM_H_
#define PWM_H_

class PWM
{
	public: 
	static void init_PWM()
	{
		MyGPIO::DDR_pin_to_output(&DDRD, PD7);
		//DDRD |= (1<<PD7);
		//Fast PWM Mode
		TCCR2 |= (1 << WGM20);
		TCCR2 |= (1 << WGM21);
		
		//Compare Mode, Fast PWM Mode -> COM21 = 1 & COM20 = 0 -> non-inverting Mode
		TCCR2 |= (1 << COM21);
		TCCR2 &= ~(1 << COM20);
		
		//Prescaler 256
		TCCR2 |= (1<<CS22) | (1<<CS21);
		TCCR2 &= ~(1<<CS20);
	}
	
	//Bsp.: set_Timer2_PWM_duty_time(210);
	static void set_PWM_duty_time(uint8_t _dutyTime)
	{
		OCR2 = _dutyTime;
	}
	
	//Bsp.: set_Timer2_PWM_duty_time_percent(50);
	static void set_PWM_duty_time_percent(uint8_t _dutyTimePercent)
	{
		uint8_t dutyTimeUint8_t;
		//convert to uint8_t value
		dutyTimeUint8_t = (_dutyTimePercent*255)/100;
		OCR2 = dutyTimeUint8_t;
	}
	
	static uint8_t get_PWM_duty_time()
	{
		return OCR2;
	}
	
	static uint8_t get_PWM_duty_time_percent()
	{
		return (OCR2*100)/255;
	}
	
};



#endif /* PWM_H_ */