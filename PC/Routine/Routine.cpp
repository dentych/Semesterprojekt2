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

char Routine::getIDSize() const {
	return modtagerID.size();
}

char Routine::getIDData(int index) const {
	return modtagerID.at(index);
}

char Routine::getDelay() const {
	return delay_;
}