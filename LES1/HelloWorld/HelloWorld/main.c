/*
* Wietse Houwers (2132653)
* Week 1. Basics
*/

#define F_CPU (16000000UL)
#include <avr/io.h>
#include <util/delay.h>

int main(void)
{	
	//Setup
	//Configure PB0-5 so it will be an output pin
	//DDRB |= (1<<DDB0);
	//DDRB |= (1<<DDB1);
	//DDRB |= (1<<DDB2);
	//DDRB |= (1<<DDB3);
	//DDRB |= (1<<DDB4);
	//DDRB |= (1<<DDB5);

	DDRB |= 0b00111111;

	//Loop
	while (1)
	{
		// LED connected to PB0 on and wait
		PORTB |= (1<<PORTB0);
		_delay_ms(100);
		// LED connected to PB0 off
		PORTB &= ~(1<<PORTB0);
		
		// LED connected to PB1 on and wait
		PORTB |= (1<<PORTB1);
		_delay_ms(100);
		// LED connected to PB1 off
		PORTB &= ~(1<<PORTB1);
		
		// LED connected to PB2 on and wait
		PORTB |= (1<<PORTB2);
		_delay_ms(100);
		// LED connected to PB2 off
		PORTB &= ~(1<<PORTB2);
		
		// LED connected to PB3 on and wait
		PORTB |= (1<<PORTB3);
		_delay_ms(100);
		// LED connected to PB3 off
		PORTB &= ~(1<<PORTB3);
		
		// LED connected to PB4 on and wait
		PORTB |= (1<<PORTB4);
		_delay_ms(100);
		// LED connected to PB4 off
		PORTB &= ~(1<<PORTB4);
		
		// LED connected to PB5 on and wait
		PORTB |= (1<<PORTB5);
		_delay_ms(100);
		// LED connected to PB5 off
		PORTB &= ~(1<<PORTB5);
	}
}