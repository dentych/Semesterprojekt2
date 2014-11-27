#define F_CPU 3686400
#include <avr/io.h>
#include <avr/delay.h>

int main(void){
	DDRD = 0xFF;
	
	TCCR1A = 0b01000000;
	TCCR1B = 0b00001001;
	
	OCR1A = 14;
	
}