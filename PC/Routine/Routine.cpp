#include "Routine.h"
#include <iostream>

Routine::Routine(string name) {
	name_ = name;
}

void Routine::setDelay(int delay) {
	delay_ = delay;
}
void Routine::setID(char ID) {
	modtagerID.push_back(ID);
}

<<<<<<< HEAD
int Routine::getIDSize() {
	return modtagerID.size();
}

int Routine::getIDList() {
	for (unsigned int i = 0; i < modtagerID.size(); i++)
		cout << modtagerID[i] << endl;
=======
char Routine::getIDSize() const {
	return modtagerID.size();
}

char Routine::getIDData(int index) const {
	return modtagerID.at(index);
}

char Routine::getDelay() const {
	return delay_;
>>>>>>> d-PC
}