#include "RoutineList.h"

RoutineList::RoutineList() {
	loadRoutines();
}

RoutineList::~RoutineList() {
	saveRoutines();
}

bool RoutineList::addRoutine(Routine & routine) {
	if (getListSize() >= 5) {
		return 0;
	}
	else {
		list.push_back(routine);
		return 1;
	}
}

bool RoutineList::removeRoutine(int index) {
	if (index < getListSize()) {
		list.erase(list.begin()+index);
		return true;
	}
	else {
		return false;
	}
}

Routine * RoutineList::getRoutinePtr(int index) {
	try {
		return &(list.at(index));
	}
	catch (out_of_range & err) {
		return NULL;
	}
}

bool RoutineList::saveRoutines() {
	ofstream file("routines.txt");
	if (file.is_open() && getListSize() > 0) {
		for (int i = 0; i < list.size(); i++) {
			// Name of routine
			string name = list.at(i).getName();
			for (int i = 0; i < name.length(); i++) {
				if (name[i] == ' ')
					name[i] = '_';
			}
			file << name << " ";
			//std::cout << "Name: " << list.at(i).getName() << endl; // Debugging

			// Amount of IDs in routine
			int numberOfIDs = list.at(i).getIDSize();
			file << numberOfIDs << " ";
			//std::cout << "ID amount: " << numberOfIDs << endl; // Debugging

			// Each ID in routine ID list
			for (int j = 0; j < numberOfIDs; j++) {
				file << list.at(i).getIDData(j) << " ";
				//cout << "ID data: " << list.at(i).getIDData(j) << endl; // Debugging
			}

			// Delay in routine + new line, ready for next routine
			file << list.at(i).getDelay() << endl;
			//cout << "Delay: " << list.at(i).getDelay() << endl; // Debugging
		}
		cout << "Routines saved on harddisk!" << endl;
		return true;
	}
	cout << "ERROR: Routines couldn't be saved to harddisk!";
	return false;
	// Save to harddrive
}

bool RoutineList::loadRoutines() {
	ifstream file("routines.txt");
	if (file.is_open()) {
		while (!file.eof()) {
			string name;
			int IDsize;
			file >> name >> IDsize;
			if (name.length() > 0) {
				for (int i = 0; i < name.length(); i++) {
					if (name[i] == '_') {
						name[i] = ' ';
					}
				}
				Routine r;
				r.setName(name);
				for (int i = 0; i < IDsize; i++) {
					int ID;
					file >> ID;
					r.addID(ID);
				}
				int delay;
				file >> delay;
				r.setDelay(delay);

				addRoutine(r);
			}
		}
		return true;
	}
	return false;
}

int RoutineList::getListSize() const {
	return list.size();
}