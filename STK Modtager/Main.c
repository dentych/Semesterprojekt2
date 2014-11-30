#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "Led.h"

unsigned char ledPort = 2;

int main(void) {
	
	initLEDport(ledPort);
	ledPort = 2;
	DDRD = 0b00000010;
	GICR = (1<<INT0);
	MCUCR |= ((1<<ISC00) | (1<<ISC01));
	sei();
	
	writeAllLEDs(2, 0xFF);
	_delay_ms(200);
	writeAllLEDs(2, 0x00);
	
	while(1) {
		waitForStartNibble();
	}
}

ISR(INT0_vect) {
	writeAllLEDs(2, 0b11110000);
	_delay_ms(100);
	writeAllLEDs(2, 0b00001111);
	_delay_ms(100);
	writeAllLEDs(ledPort, 0);
}