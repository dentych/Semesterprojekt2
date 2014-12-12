#include "X10commands.h"

void startBurst(void){
	TCCR1A = 0b01000000;
	TCCR1B = 0b00001001;
	OCR1A = 14;
	_delay_ms(1);
	TCCR1A = 0x00;
}

void sendKommando(unsigned char unitCode, unsigned char * command){
	toggleLED(ledPort, 7);
	unsigned char cmd[20] = { 1, 1, 1, 0 };

	unsigned char unitBin[4];
	chtobin(unitCode, unitBin);
	binComplimentary(unitBin, cmd, 4);
	binComplimentary(command, cmd, 12);
	
	interrupt = '0';
	
	unsigned char i;
	for (i = 0; i < 20; i++) {
		while (interrupt == '0') 
		{
			_delay_us(1);
		}
		
		if (cmd[i] == 0) {
			interrupt = '0';
			_delay_ms(1);
		}
		else {
			interrupt = '0';
			startBurst();
		}
	}
	for (i = 0; i < 6; i++) {
		while (interrupt == '0') {
			_delay_us(1);
		}
		interrupt = '0';
	}
	for (i = 0; i < 20; i++) {
		while (interrupt == '0') 
		{
			_delay_us(1);
		}
		
		if (cmd[i] == 0) {
			interrupt = '0';
			_delay_ms(1);
		}
		else {
			interrupt = '0';
			startBurst();
		}
	}
	
	// Vent 6 zero-crosses før sending af næste kommando kan foregå
	for (i = 0; i < 6; i++) {
		while (interrupt == '0') {
			_delay_us(1);
		}
		interrupt = '0';
	}
	
	toggleLED(ledPort, 7);
}

void X10turnOff(unsigned char ID_element){
	
}

void X10turnOn(unsigned char ID_element){
	
}

void binComplimentary(unsigned char * binary, unsigned char * cmd, unsigned char start) {
	unsigned char i;
	for (i = 0; i < 4; i++) {
		if (binary[i] == 0) {
			cmd[start + i * 2] = 0;
			cmd[start + i * 2 + 1] = 1;
		}
		else {
			cmd[start + i * 2] = 1;
			cmd[start + i * 2 + 1] = 0;
		}
	}
}
