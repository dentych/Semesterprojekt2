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
	//runRoutine(); MIDLERTIDIG UD
	unsigned char cmd[] = {1, 0, 1, 1};
	sendKommando(1, cmd);
}

void stopRoutine(void){
	// STOPPER X10 VÆRK !!!
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

void runRoutine(void) {
	int i;
	for (i = 0;i < ID_size;i++) {
		if (lysStatus == 0) {
			X10turnOn(ID_list[i]);
		}
		else
			X10turnOff(ID_list[i]);
	}
	
	lysStatus = (lysStatus > 0 ? 0 : 1); // Skifter lysStatus mellem 0 og 1.
}

void chtobin(char toBeConverted, char * bitwise) {
	int i;
	unsigned char allbits[8];
	for (i = 0; i < 8; i++) {
		allbits[7 - i] = !!(toBeConverted & (1 << i));
	}
	for (i = 0; i < 4; i++) {
		bitwise[i] = allbits[4 + i];
	}
}
