/*
 * MyGPIO.cpp
 *
 * Created: 20.10.2018 16:29:33
 *  Author: Reinhard
 */ 
class MyGPIO
{
		
	static void DDR_to_output(uint8_t* _re_gister)
	{
		*_re_gister = 0xFF;
		PORTA &= ~(1 << PA7);
	}
	
};