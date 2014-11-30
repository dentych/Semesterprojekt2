#include <vector>
#include <fstream>
#include <iostream>
#include "Routine.h"

class RoutineList {
public:
	RoutineList();
	~RoutineList();
	bool addRoutine(Routine & routine);
	bool removeRoutine(int index);
	Routine * getRoutinePtr(int index);
	bool saveRoutines();
	bool loadRoutines();
	int getListSize() const;
private:
	vector<Routine> list;
};
