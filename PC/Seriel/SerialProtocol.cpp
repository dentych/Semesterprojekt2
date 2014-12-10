#include "SerialProtocol.h"

bool SerialProtocol::openConnection(int baudRate) {
	for (int i = 1; i < 10; i++) {
		if (cs.Open(i, baudRate)) {
			return true;
		}
	}
	return false;
}

bool SerialProtocol::isUnlocked() {
	sendChar('1');

	while (!cs.ReadDataWaiting());

	char receiveData;
	receiveData = readData();

	if (receiveData == '0') {
		return true;
	}
	else {
		return false;
	}
}

bool SerialProtocol::startRoutine(Routine & routine) {
	// Protocol(1), check if STK is unlocked.
	if (!isUnlocked()){
		return false;
	}
	char receive = '0';

	// Start Protocol(2), start routine.
	// Send 2 for "Starting serial transmission of Routine data.
	sendChar('2');
	receive = readData();
	if (receive != '2') {
		sendChar('Q');
		return false;
	}

	// Send the Routine receiver array list size.
	sendChar(routine.getIDSize());
	receive = readData();
	if (receive != routine.getIDSize()) {
		sendChar('Q');
		return false;
	}

	// Send the Routine's ID array list data one by one.
	for (int i = 0; i < routine.getIDSize(); i++){
		char idData = routine.getIDData(i);
		sendChar(idData);
		receive = readData();
		if (receive != idData) {
			sendChar('Q');
			return false;
		}
	}

	// Send the Routine delay
	char delay = routine.getDelay();
	sendChar(delay);
	receive = readData();
	if (receive != delay) {
		sendChar('Q');
		return false;
	}

	receive = readData();
	if (receive == '0') {
		return true;
	}
	else {
		return false;
	}
}

bool SerialProtocol::stopRoutine() {
	if (!isUnlocked()) { 
		return false;
	}
	else {
		char receive;
		sendChar('3');
		receive = readData();
		if (receive == '3') {
			return true;
		}
		else {
			return false;
		}
	}
}

int SerialProtocol::sendChar(char data) {
	std::cout << "Sending -" << (int)data << "-" << std::endl; // Debugging purposes
	return cs.SendData(&data,1);
}

char SerialProtocol::readData() {
	while (!cs.ReadDataWaiting());

	char* lpBuffer = new char;

	cs.ReadData(lpBuffer, 1);

	char data = *lpBuffer;
	delete lpBuffer;

	cout << "Reading -" << (int)data << "-" << endl; // Debugging purposes
	return data;
}