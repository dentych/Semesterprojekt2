#include "Sender.h"
#include "LysTilTest.h"

void confirmingLights(void) {
	writeAllLEDs(ledPort, 0xff);
	_delay_ms(200);
	writeAllLEDs(ledPort, 0x00);
}

void showoff(void){
	for(int i = 0; i < 8; i++) {
		toggleLED(ledPort,i);
		_delay_ms(100);
	}
	for(int i = 7; i >= 0;i--) {
		toggleLED(ledPort,i);
		_delay_ms(100);
	}
}

void wupwup(void){
	for(int i = 0; i < 8; i+2) {
		toggleLED(ledPort,i);
		_delay_ms(100);
	}
	for(int i = 1; i < 8; i+2) {
		toggleLED(ledPort,i);
		_delay_ms(100);
	}
	writeAllLEDs(ledPort,0x00);
}