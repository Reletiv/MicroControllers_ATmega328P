/*
 * LoopLicht.c
 *
 * Created: 26-9-2024 10:50:19
 * Author : Wietse Houwers
 */ 

#define F_CPU (16000000UL)
#include <avr/io.h>
#include <util/delay.h>

// Variabelen
int direction = 1;
int delay_in_ms = 100;

//Setup
int main(void)
{
	// PB0 to PB5 output	
	DDRB |= (1<<DDB5) | (1<<DDB4) | (1<<DDB3) |
	(1<<DDB2) | (1<<DDB1) | (1<<DDB0);	
	// PD7 Output
	DDRD |= (1<<DDD7);
	
	// PD7 LOW
	PORTD &= ~(1<<PORTD7);
	
	// inputs PD3 to PD6 is by default an input pin and here enable pull up 
	PORTD |= (1<<PORTD6) | (1<<PORTD5) | (1<<PORTD4) | (1<<PORTD3);	
	
	
	// Loop
	while (1)
	{
		// Bitmask voor knoppen
		unsigned char switches = PIND & 0b01111000;
		
		// Check if K1 is pressed
		if((switches & (1<<PIND6)) == 0)
		{
			// Increment the delay
			delay_in_ms += 100;
			if(delay_in_ms > 1000)
			{
				delay_in_ms = 1000;
			}
			// Debounce the switch
			_delay_ms(50);
		} 

		// Check if K2 is pressed
		if((switches & (1<<PIND5)) == 0)
		{
			// Increment the delay
			delay_in_ms -= 100;
			if(delay_in_ms < 100)
			{
				delay_in_ms = 100;
			}
			// Debounce the switch
			_delay_ms(50);
		}	
		
		// Check if K3 is pressed
		if((switches & (1<<PIND4)) == 0)
		{
			// Set Direction
			direction = 1;
			// Debounce the switch
			_delay_ms(50);
		}
		
		// Check if K4 is pressed
		if((switches & (1<<PIND3)) == 0)
		{
			// Set Direction
			direction = 0;
			// Debounce the switch
			_delay_ms(50);
		}
		
		// Check Direction
		if(direction == 1)
		{
			for(int i = 0; i < 6; i++)
			{
				PORTB |= (1<<i);
				for(int i=0; i<delay_in_ms; i++)
				{
					_delay_ms(1);
				}
				PORTB &= ~(1<<i);
			}	
		} else
		{
			for(int i = 5; i >= 0; i--)
			{
				  PORTB |= (1<<i);
				  for(int i=0; i<delay_in_ms; i++)
				  {
					  _delay_ms(1);
				  }
				  PORTB &= ~(1<<i);
			 }
		}
	}
}