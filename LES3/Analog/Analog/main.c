/*
 * Analog.c
 *
 * Created: 3-10-2024 11:13:09
 * Author : Wietse Houwers
 */ 

#define F_CPU (16000000UL)
#include <avr/io.h>
int main(void)
{
	// PB0 - PB5 output, rest input
	DDRB = 0b00111111;
	
	// Initialize the ADC peripheral
	// ADC Multiplexer Selection Register:
	// REFS[1:0] = 01 : AV_CC with external capacitor at AREF pin
	// ADLAR = 0 : Right adjust result
	// MUX[3:0] = 0000 : Select channel ADC0
	//ADMUX = (1<<REFS0);
	ADMUX = (1<<REFS0);
	
	// set adc pin A1
	ADMUX |= (1<<MUX0); 
	
	// ADC Control and Status Register A:
	// ADEN = 1 : ADC enable
	// ADSC = 0 : Do not start a conversion
	// ADATE = 0 : Auto triggering disabled
	// ADIF = 0 : Do not clear the interrupt flag
	// ADIE = 0 : Do not enable interrupts
	// ADPS[2:0] = 111 : Prescaler division factor 128
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1) | (1<<ADPS0);
	while (1)
	{
		// Start a conversion (making sure all other bits do not change)
		ADCSRA |= (1<<ADSC);
		
		// Wait for the conversion to complete by polling the ADSC bit
		while((ADCSRA & (1<<ADSC)) != 0)
		{;}
		
		// Read the result
		uint16_t val = ADC;
		
		// Visualize the result
		if (val < 146) { PORTB = 0b00000000; }
		else if (val < 293) { PORTB = 0b00000001; }
		else if (val < 439) { PORTB = 0b00000011; }
		else if (val < 585) { PORTB = 0b00000111; }
		else if (val < 731) { PORTB = 0b00001111; }
		else if (val < 878) { PORTB = 0b00011111; }
		else { PORTB = 0b00111111; }
	}
}