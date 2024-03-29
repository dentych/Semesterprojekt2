﻿#include "LysTilTest.h"

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
	for(int i = 0; i < 5; i++) {
		for(int i = 0; i < 8; i++) {
			toggleLED(ledPort, i);
			_delay_ms(10);
			toggleLED(ledPort, i);
		}
	}
	for(int i = 0; i < 8; i++) {
		toggleLED(ledPort, i);
		_delay_ms(50);
		toggleLED(ledPort, i);
	}
	writeAllLEDs(ledPort, 0);
}