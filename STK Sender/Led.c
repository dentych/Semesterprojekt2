#include <avr/io.h>
#include "Led.h"
#define MAX_LED_NR 7

void initLEDport(unsigned char hvilkenPort){
	if (hvilkenPort == 0){
		DDRA = 0xFF;	// 1 for OUTPUT
		PORTC = 0xFF;	// LEDs slukket
	}
	else if (hvilkenPort == 1){
		DDRB = 0xFF;
		PORTB = 0xFF;
	}
	else if (hvilkenPort == 2){
		DDRC = 0xFF;
		PORTC = 0xFF;
	}
	else if (hvilkenPort == 3){
		DDRD = 0xFF;
		PORTD = 0xFF;
	}
}
void writeAllLEDs(unsigned char hvilkenPort, unsigned char pattern){
	if(hvilkenPort == 0){
		PORTA = ~pattern;
	}
	else if(hvilkenPort == 1){
		PORTB = ~pattern;
	}
	else if(hvilkenPort == 2){
		PORTC = ~pattern;
	}
	else if(hvilkenPort == 3){
		PORTD = ~pattern;
	}
}
void turnOnLED(unsigned char hvilkenPort, unsigned char led_nr){
	unsigned char mask;
	
	if(hvilkenPort == 0){
		if (led_nr <= MAX_LED_NR)
		{
			mask = ~(0b00000001 << led_nr);
			PORTA = PINA & mask;
		}
	}
	if(hvilkenPort == 1){
		if (led_nr <= MAX_LED_NR)
		{
			mask = ~(0b00000001 << led_nr);
			PORTB = PINB & mask;
		}
	}
	if(hvilkenPort == 2){
		if (led_nr <= MAX_LED_NR)
		{
			mask = ~(0b00000001 << led_nr);
			PORTC = PINC & mask;
		}
	}
	if(hvilkenPort == 3){
		if (led_nr <= MAX_LED_NR)
		{
			mask = ~(0b00000001 << led_nr);
			PORTD = PIND & mask;
		}
	}
}
void turnOffLED(unsigned char hvilkenPort, unsigned char led_nr){
	unsigned char mask;
	
	if(hvilkenPort == 0){
		if (led_nr <= MAX_LED_NR)
		{
			mask = ~(0b00000001 << led_nr);
			PORTA = PINA | mask;
		}
	}
	if(hvilkenPort == 1){
		if (led_nr <= MAX_LED_NR)
		{
			mask = ~(0b00000001 << led_nr);
			PORTB = PINB | mask;
		}
	}
	if(hvilkenPort == 2){
		if (led_nr <= MAX_LED_NR)
		{
			mask = ~(0b00000001 << led_nr);
			PORTC = PINC | mask;
		}
	}
	if(hvilkenPort == 3){
		if (led_nr <= MAX_LED_NR)
		{
			mask = ~(0b00000001 << led_nr);
			PORTD = PIND | mask;
		}
	}
}
void toggleLED(unsigned char hvilkenPort, unsigned char led_nr){
		unsigned char mask;
		
		if(hvilkenPort == 0){
			if (led_nr <= MAX_LED_NR)
			{
				mask = (0b00000001 << led_nr);
				PORTA = PINA ^ mask;
			}
		}
		if(hvilkenPort == 1){
			if (led_nr <= MAX_LED_NR)
			{
				mask = (0b00000001 << led_nr);
				PORTB = PINB ^ mask;
			}
		}
		if(hvilkenPort == 2){
			if (led_nr <= MAX_LED_NR)
			{
				mask = (0b00000001 << led_nr);
				PORTC = PINC ^ mask;
			}
		}
		if(hvilkenPort == 3){
			if (led_nr <= MAX_LED_NR)
			{
				mask = (0b00000001 << led_nr);
				PORTD = PIND ^ mask;
			}
		}
}
