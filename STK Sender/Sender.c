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
	TCCR1B = 0;
}

void runRoutine(void) {
	unsigned char i;
	for (i = 0;i < ID_size;i++) {
		if (lysStatus == 0) {
			unsigned char cmd = {0, 0, 1, 0};
			sendKommando(ID_list[i], cmd);
		}
		else {
			unsigned char cmd = {0, 0, 1, 1};
			sendKommando(ID_list[i], cmd);
		}
	}
	
	lysStatus = (lysStatus > 0 ? 0 : 1); // Skifter lysStatus mellem 0 og 1.
	
	// Starter time1 til at lave overflow hvert sekund
	TIFR = (1<<TOV1);
	TCNT1H = 0x1F; 
	TCNT1L = 0;
	// Timer 1 i Normal Mode og PS = 64
	TCCR1A = 0b00000000;
	TCCR1B = 0b00000011;
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
