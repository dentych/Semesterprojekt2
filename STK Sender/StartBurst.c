#include "StartBurst.h"

void startBurst(void){
	TCCR1A = 0b01000000;
	TCCR1B = 0b00001001;
	OCR1A = 14;
	_delay_ms(1);
	TCCR1A = 0x00;
}