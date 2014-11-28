#include "X10commands.h"

void startBurst(void){
	TCCR1A = 0b01000000;
	TCCR1B = 0b00001001;
	OCR1A = 14;
	_delay_ms(1);
	TCCR1A = 0x00;
}

void startKommando(	unsigned char* unitCode, unsigned char* command){
	
}

void X10turnOff(unsigned char ID_element){
	
}

void X10turnOn(unsigned char ID_element){
	
}