#include "Sender.h"

int main(void) {
	lysStatus = 0;
	ledPort = 2;
	switchPort = 0;
	lysStatus = '0';
	locked = '1';
	interrupt = '0';
	
	// initialisering af LED, Switch og UART
	initLEDport(ledPort);
	initSwitchPort(switchPort);
	InitUART(9600,8);
	
	// Routine running stuff
	unsigned char runningRoutine = 0;

	GICR  = ( (1<<INT0)  | (1<<INT1 ) );		// enable both interrupts
	MCUCR |= ( (1<<ISC00) | (1<<ISC01) );		// INT0 = rising til ZERO-CROSS
	MCUCR |= (1<<ISC11);						// INT1 = falling til DE2
	sei();										// enable global interrupts
	
	DDRD |= 0b00110010;		//PD5 til 120kHz output

	while(1) {
		while (!runningRoutine) {
			while(locked == '1') {
				if (CharReady()) {
					ReadChar();
					SendChar('1');
					confirmingLights();
				}
			}
			
			while(locked == '0') {
				if(!CharReady()){
					continue;
				}
				receivedFromPc = ReadChar();
				
				switch(receivedFromPc) {
					
					case '1':
					SendChar(locked);
					break;
					
					case '2':
					SendChar(receivedFromPc);
					runningRoutine = 1;
					startRoutine();
					showoff();
					break;
					
					case '3':
					SendChar(receivedFromPc);
					stopRoutine();
					showoff();
					break;
					
				}
			}
		}
		
		while (runningRoutine) {
			if (CharReady()) {
				if (locked == '1') {
					ReadChar();
					SendChar(locked);
				}
				else {
					receivedFromPc = ReadChar();
					
					switch (receivedFromPc) {
						case '1':
						SendChar(locked);
						break;
						
						case '3':
						SendChar('3');
						stopRoutine();
						break;
						
						default:
						SendChar(locked);
						break;
					}
				}
			}
			else {
				if ((TIFR & (1<<TOV1)) != 0) {
					delayStatus++;
					if (delay == delayStatus) {
						runRoutine();
						TIFR = 1<<TOV1; 
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
		turnOffLED(ledPort, 0);
	}
}
