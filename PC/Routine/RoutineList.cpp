#include "RoutineList.h"

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
	try {
		list.
	}
}

Routine & RoutineList::getRoutine(int index) {

}

bool RoutineList::saveRoutines() {

}

bool RoutineList::loadRoutines() {

}

int RoutineList::getListSize() const {

}