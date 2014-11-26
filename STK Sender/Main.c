/*
* SemesterProjekt2.c
*
* Created: 21-11-2014 14:36:57
*  Author: Bjørn Nørgaard
*/

#include <avr/io.h>
#include <avr/delay.h>
#include "UART.h"
#include "Led.h"
#include "Switch.h"

unsigned char ledPort = 1;
unsigned char switchPort = 0;

void confirmingLights(void);
void showoff(void);

unsigned char receivedFromPc;	// latest char received from PC
unsigned char locked = '0';		// 0 = unlocked

int main(void) {
	initLEDport(ledPort);
	initSwitchPort(switchPort);
	InitUART(9600,8);
	
	while(1) {
		receivedFromPc = ReadChar();
		
		if(receivedFromPc == '1' && locked == '0') {
			confirmingLights();
			SendString("Ready fuckers!");
			
			do{
				receivedFromPc = ReadChar();
				
				switch(receivedFromPc){
					
					case '1':
					if(locked == '0'){
						SendChar('0');
						confirmingLights();
					}
					break;
					
					case '2':
					SendChar(receivedFromPc);
					showoff();
					break;
					
					case 'q':
					SendChar(receivedFromPc);
					confirmingLights();
					confirmingLights();
					break;
					
					default:
					SendChar(receivedFromPc);
					break;
					
				}
			}while(receivedFromPc != 'q');
		}
	}
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
