/*!
* THIS HEADER FILE DOES NOT HAVE A CPP FILE
*/

#pragma once
#include <iostream>

typedef void(*fPtr)();

// Global variable
SerialProtocol sp;
RoutineList routines;

void MainMenu();
void RoutineManager();
void RemoveRoutine();
void EditRoutine();
void TurnOnRoutine();
void Quit();
void WaitForEnter();

void MainMenu() {
	Menu menu("Main menu");

	menu.addMenuItem("1", "Turn system on", &TurnOnRoutine)
		.addMenuItem("2", "Turn system off", &MainMenu)
		.addMenuItem("3", "Routine manager", &RoutineManager)
		.addMenuItem("q", "Quit", &Quit)
		.drawMenu();

	int c = menu.getChoice();

	switch (c) {
	case 2:
		std::cout << "Turning system off!" << std::endl;
		if (sp.stopRoutine()) {
			std::cout << "Routine successfully turned off!" << std::endl;
			WaitForEnter();
		}
		else {
			std::cout << "There was a problem stopping the routine." << std::endl;
			WaitForEnter();
		}
		break;
	}
}

void RoutineManager() {
	Menu menu("Routine Manager");

	menu.addMenuItem("1", "Add routine", &RoutineManager)
		.addMenuItem("2", "Remove routine", &RemoveRoutine)
		.addMenuItem("3", "Edit routine", &EditRoutine)
		.addMenuItem("q", "Back to main menu", &MainMenu)
		.drawMenu();

	int choice = menu.getChoice();

	switch (choice) {
	case 1:
		cout << "Adding routine..." << endl;
		cout << "Name of new routine: ";
		fflush(stdin);
		string name;
		getline(cin, name);
		if (name.length() > 0) {
			Routine r;
			r.setName(name);
			r.setDelay(0);
			cout << endl << "Adding routine to list..." << endl;
			if (routines.addRoutine(r)) {
				cout << "Routine was successfully added!" << endl;
			}
			else {
				cout << "ERROR: The routine could not be added." << endl <<
					"This can be caused by a full routine list. " <<
					"Please try again." << endl;
			}
		}
		else {
			cout << "ERROR: Can't add routines with empty name." << endl;
		}
		WaitForEnter();
		break;
	}
}

void RemoveRoutine() {
	Menu menu("Choose a routine to remove");

	if (routines.getListSize() == 0) {
		menu.addMenuItem("0", "Routine list is empty", &RoutineManager);
	}
	else {
		for (int i = 0; i < routines.getListSize(); i++) {
			menu.addMenuItem(to_string(i + 1), routines.getRoutinePtr(i)->getName(), &RoutineManager);
		}
	}
	menu.addMenuItem("q", "Back to Routine Manager", &RoutineManager)
		.drawMenu();

	int choice = menu.getChoice();

	if (choice <= routines.getListSize() && choice > 0) {
		cout << "Removing routine..." << endl;
		if (routines.removeRoutine(choice-1)) {
			cout << "Routine successfully removed!" << endl;
		}
		else {
			cout << "ERROR:" << endl <<
				"Routine could not be deleted. Please try again" << endl;
		}
		WaitForEnter();
	}
	else {
		if (!(choice == routines.getListSize()+1)) {
			cout << "Routine not on the list!" << endl;
			WaitForEnter();
		}
	}
}

void EditRoutine() {
	Menu menu("Choose routine to edit");
	int listSize = routines.getListSize();

	if (listSize == 0) {
		menu.addMenuItem("0", "Routine list is empty", &RoutineManager);
	}
	else {
		for (int i = 0; i < listSize; i++) {
			menu.addMenuItem(to_string(i + 1), routines.getRoutinePtr(i)->getName(), &EditRoutine);
		}
	}
	menu.addMenuItem("q", "Back to Routine Manager", &RoutineManager)
		.drawMenu();

	menu.getChoice();
}

void TurnOnRoutine() {
	int listSize = routines.getListSize();
	Menu menu("Turn on routine");

	if (listSize == 0) {
		menu.addMenuItem("0", "There are no routines on the list", &MainMenu);
	}
	else {
		for (int i = 0; i < listSize; i++) {
			menu.addMenuItem(to_string(i + 1), routines.getRoutinePtr(i)->getName(), &MainMenu);
		}
	}
	menu.addMenuItem("q", "Back to main menu", &Quit)
		.drawMenu();

	int choice = menu.getChoice();

	if (choice > 0 && choice <= listSize) {
		cout << "Starting routine..." << endl;
		if (sp.startRoutine(*routines.getRoutinePtr(choice))) {
			cout << "Routine was successfully started!" << endl;
			WaitForEnter();
		}
		else {
			cout << "ERROR: Could not start routine. " <<
				"Is the system unlocked?" << endl;
			WaitForEnter();
		}
	}
	else {
		if (!(choice == listSize + 1)) {
			cout << "ERROR: Routine not on the list. Try again." << endl;
			WaitForEnter();
		}
	}
}

void Quit() {
	return;
}

void WaitForEnter() {
	cout << endl << "Press Enter to continue..." << endl;

	while (!_kbhit());
	while (_kbhit()) getch();
	fflush(stdin);
}