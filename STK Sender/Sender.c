#include "Sender.h"

int checkForQ(char checkThis){
	if(checkThis == 'Q') {
		return 1;
	}
	else {
		SendChar(checkThis);
		return 0;
	}
}

void startRoutine(void){
	// Modtager ID_size
	ID_size = ReadChar();
	if(checkForQ(ID_size)){
		return;
	}
	
	// Modtager ID_list
	for(int i = 0; i < ID_size; i++){
		ID_list[i] = ReadChar();
		if(checkForQ(ID_list[i])){
			return;
		}
	}
	
	// Modtager delay
	delay = ReadChar();
	if(checkForQ(delay)){
		return;
	}
	
	// Sender "Vi er færdige nu, ikk'?"
	SendChar('0');
	
	// BEGYNDER X10 VÆRK !!!
	runRoutine();
}

void stopRoutine(void){
	// STOPPER X10 VÆRK !!!
}

void runRoutine(void) {
	int i;
	for (i = 0; i < ID_size; i++) {
		if (lysStatus == '0') {
			X10turnOn(ID_list[i]);
		}
		else
			X10turnOff(ID_list[i]);
	}
	
	lysStatus = (lysStatus > 0 ? 0 : 1); // Skifter lysStatus mellem 0 og 1.
}

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