#include "SerialProtocol.h"

bool SerialProtocol::openConnection(int baudRate) {
	for (int i = 1; i < 10; i++) {
		if (cs.Open(i, baudRate)) {
			return true;
		}
	}
	return false;
}


bool SerialProtocol::startRoutine(Routine & routine) {
	if (!isUnlocked()){
		return false;
	}
	sendChar('2');
	if (!(cs.ReadData == '2'))
		return false;
	else
		cs.SendData(routine.getIDSize());
	if (!(cs.ReadData == routine.getIDSize()))
		return false;

	for (int i = 0; i < routine.getIDSize(); i++){
		
	}
		

}

bool SerialProtocol::isUnlocked() {
	char sendData = '1';
	cs.SendData(&sendData, 1);

	while (!cs.ReadDataWaiting());

	char receiveData;
	cs.ReadData(&receiveData, 1);

	if (receiveData == '0') {
		return true;
	}
	else {
		return false;
	}
}

int SerialProtocol::sendChar(char data) {
	return cs.SendData(&data,1);
}

char SerialProtocol::readData() {
	while (!cs.ReadDataWaiting());

	char* lpBuffer = new char;

	cs.ReadData(lpBuffer, 1);

	char data = *lpBuffer;
	delete lpBuffer;

	return data;
}