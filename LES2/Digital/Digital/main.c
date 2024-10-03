/*
 * Digital.c
 *
 * Created: 19-9-2024 12:00:38
 * Author : Wietse Houwers
 */ 

#define F_CPU (16000000UL)
#include <avr/io.h>
int main(void)
{
	// Configure PB5 so it will be an output pin
	DDRB |= (1<<DDB5);

	// Configure PB7 so it will be an input pin
	// Notice that strictly speaking this instruction is redundant,
	// because after a reset, the initial value of this bit is already
	// logic 0.
	DDRB &= ~(1<<DDB7);

	while (1)
	{
		// Read the content from the PINB register and perform a bitwise-and
		// operation using the mask (1<<PINB7). Only if bit number 7 in the
		// PINB register is not set, the condition evaluates to True.
		//
		// Notice that when the switch is not pressed PB7 reads logic 1!
		// In other words: this if-statement checks if the switch is pressed.
		if((PINB & (1<<PINB7)) == 0)
		{
			// LED connected to PB5 on
			PORTB |= (1<<PORTB5);
		}
		else
		{
			// LED connected to PB5 off
			PORTB &= ~(1<<PORTB5);
		}
	}
}
