/*
* Fan.h
*
* Created: 13.11.2018 09:42:58
* Author: Simone
*/


#ifndef __FAN_H__
#define __FAN_H__

class Fan
{
	private:
		
	uint16_t m_rpm;
	
	public:
	
	Fan()
	{
		m_rpm = 0;
		init();
	}
	
	uint16_t RPMCalc(uint16_t _timeBetweenTwoFlags)
	{
		return m_rpm = (uint16_t)((1000000*60)/((uint32_t)_timeBetweenTwoFlags*2));
	}
	
	uint16_t getRPM()
	{
		return m_rpm;
	}
	
	void init()
	{
		m_rpm = 0;
		//configure external interrupt on pin PD2
		GICR |= (1 << INT0);
		//using falling edge triggering
		MCUCR |= (1<<ISC01) | (0<<ISC00);
	}

}; //Fan

#endif //__FAN_H__
