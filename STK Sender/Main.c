#include "Sender.h"

int main(void) {
	ledPort = 2;
	switchPort = 0;
	lysStatus = 0;
	locked = '0';
	interrupt = '0';
	
	// initialisering af LED, Switch og UART
	initLEDport(ledPort);
	initSwitchPort(switchPort);
	InitUART(9600,8);
	
	// Routine running stuff
	unsigned char runningRoutine = 0;
	unsigned char delayStatus = 0;

	GICR  = ( (1<<INT0)  | (1<<INT1 ) );		// enable both interrupts
	MCUCR |= ( (1<<ISC00) | (1<<ISC01) );		// INT0 = rising til ZERO-CROSS
	MCUCR |= (1<<ISC11);						// INT1 = falling til DE2
	sei();										// enable global interrupts
	
	DDRD |= 0b00110010;		//PD5 til 120kHz output

	while(1) {
		while (runningRoutine == 0) {
			if (CharReady()) {
				receivedFromPc = ReadChar();
				
				if (receivedFromPc == 'Q') {
					continue;
				}
				
				if (locked == '1') {
					SendChar('L');
				}
				else {
					switch(receivedFromPc) {
						case '1':
						SendChar(locked);
						break;
						
						case '2':
						SendChar(receivedFromPc);
						startRoutine();
						runningRoutine = 1;
						break;
						
						case '3':
						SendChar(receivedFromPc);
						stopRoutine();
						break;
					}
				}
			}
		}
		
		while (runningRoutine == 1) {
			if (CharReady()) {
				receivedFromPc = ReadChar();
				if (locked == '1') {
					SendChar(locked);
				}
				else {
					switch (receivedFromPc) {
						case '1':
						SendChar(locked);
						break;
						
						case '3':
						SendChar(receivedFromPc);
						runningRoutine = 0;
						stopRoutine();
						break;
						
						default:
						SendChar('5');
					}
				}
			}
			else {
				if ((TIFR & (1<<TOV1)) > 0) {
					TIFR = (1<<TOV1);
					toggleLED(ledPort, 5);
					delayStatus++;
					if (delay == delayStatus) {
						runRoutine();
						delayStatus = 0;
					}
				}
			}
		}
	}
}

ISR(INT0_vect) {			//INT0 til Zero-Cross til interrupt
	interrupt = '1';
}

ISR(INT1_vect){
	if(locked == '1') {
		locked = '0';
		MCUCR |= (1<<ISC11) | (1<<ISC10);			// INT1 = rising til DE2
		turnOnLED(ledPort, 0);
	}
	else if(locked == '0') {
		locked = '1';
		MCUCR &= ~(1<<ISC10);						// INT1 = falling til DE2
		toggleLED(ledPort, 0);
	}
}
