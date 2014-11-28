#include <vector>
#include "Routine.h"

class RoutineList {
public:
	bool addRoutine(Routine & routine);
	bool removeRoutine(int index);
	Routine & getRoutine(int index);
	bool saveRoutines();
	bool loadRoutines();
	int getListSize() const;
private:
	vector<Routine> list;
};
