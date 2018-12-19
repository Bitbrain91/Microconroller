/*
 * MyADC.h
 *
 * Created: 30.11.2018 20:35:15
 *  Author: Reinhard
 */ 


#ifndef MyADC_H_
#define MyADC_H_

#define test 6

class MyADC
{	 
	public:
	
	static void init()
	{
		//Internal Reference Voltage 
		ADMUX |= (1<<REFS1);
		ADMUX |= (1<<REFS0);
		
		//ADC left Adjust Result -> For 8bit-Resolution only ADCH Register is required
		ADMUX |= (1<<ADLAR);
		
		//Single Ended Input PA0
		MyGPIO::DDR_pin_to_input(&DDRA, PA0);
		ADMUX &= ~((1 << MUX0) | (1 << MUX1) | (1 << MUX2) | (1 << MUX3) | (1 << MUX4));

		
		//Enable ADC
		ADCSRA |= (1<<ADEN);
		
		//Enable ADC Interrupt
		//ADCSRA |= (1<<ADIE);
		
		//ADC AUTO Trigger Enable
		ADCSRA |= (1<<ADATE);
		
		//Prescaler 64
		ADCSRA |= (1 << ADPS2) | (1 << ADPS1);
		ADCSRA &= ~(1 << ADPS0);
		
		//Free Running Mode
		SFIOR &= ~((1 << ADTS0) | (1 << ADTS1) | (1 << ADTS2));
		
		//Start first conversion
		ADCSRA |= (1<<ADSC);
		
		//while(ADCSRA & (1<<ADSC))
		//{}		
	}
	
	static uint8_t get_ADC_input()
	{
		return ADCH;
	}
};





#endif /* MYADC_H_ */