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
}

void stopRoutine(void){
	// STOPPER X10 VÆRK !!!
}

void confirmingLights(void){
	writeAllLEDs(ledPort, 0xff);
	_delay_ms(200);
	writeAllLEDs(ledPort, 0x00);
}

void showoff(void){
	for(int i = 0; i<8;i++){
		toggleLED(ledPort,i);
		_delay_ms(100);
	}
	for(int i = 7; i>=0;i--){
		toggleLED(ledPort,i);
		_delay_ms(100);
	}
}
