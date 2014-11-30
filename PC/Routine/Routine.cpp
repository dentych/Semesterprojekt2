#include "Routine.h"
#include <iostream>

void Routine::setName(string name) {
	name_ = name;
}

void Routine::setDelay(int delay) {
	delay_ = delay;
}
void Routine::addID(int ID) {
	modtagerID.push_back(ID);
}

string Routine::getName() const {
	return name_;
}

int Routine::getIDSize() const {
	return modtagerID.size();
}

int Routine::getIDData(int index) const {
	return modtagerID.at(index);
}

int Routine::getDelay() const {
	return delay_;
}