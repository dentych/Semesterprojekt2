#include "Modtager.h"

int main(void) {
	ledPort = 2;
	
	// Enable INT0 på rising edge.
	MCUCR |= (1<<ISC01) | (1<<ISC00);
	GICR |= (1<<INT0);
	sei();
	
	DDRD = 0b00000010;
	
	initLEDport(ledPort);
	
	interrupt = 0;
	unsigned char receivedBits[20];
	
	while (1) {
		receiveBitSequence(receivedBits);
	}
}

ISR(INT0_vect) {
	interrupt = 1;
}