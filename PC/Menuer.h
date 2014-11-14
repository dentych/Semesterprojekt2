/*!
* THIS HEADER FILE DOES NOT HAVE A CPP FILE
*/

#pragma once
#include <iostream>

typedef void(*fPtr)();

void RoutineManager();
void EditRoutine();
void Quit();
void WaitForEnter();

void MainMenu() {
	Menu menu;

	menu.setTitle("Main menu")
		.addMenuItem("1", "Turn system on", &MainMenu)
		.addMenuItem("2", "Turn system off", &MainMenu)
		.addMenuItem("3", "Routine manager", &RoutineManager)
		.addMenuItem("q", "Quit", &Quit)
		.drawMenu();

	int c = menu.getChoice();

	switch (c) {
	case 1:
		std::cout << "Turning system on!" << std::endl;
		WaitForEnter();
		break;
	case 2:
		std::cout << "Turning system off!" << std::endl;
		WaitForEnter();
		break;
	}
}

void RoutineManager() {
	Menu menu;

	menu.setTitle("Routine Manager")
		.addMenuItem("1", "Add routine", &RoutineManager)
		.addMenuItem("2", "Remove routine", &RoutineManager)
		.addMenuItem("3", "Edit routine", &EditRoutine)
		.addMenuItem("q", "Back to main menu", &MainMenu)
		.drawMenu();

	menu.getChoice();
}

void EditRoutine() {
	Menu menu;

	menu.setTitle("Choose routine to edit")
		.addMenuItem("1", "Routine 1", &EditRoutine)
		.addMenuItem("2", "Routine 2", &EditRoutine)
		.addMenuItem("3", "Routine 3", &EditRoutine)
		.addMenuItem("4", "Routine 4", &EditRoutine)
		.addMenuItem("q", "Back to Routine Manager", &RoutineManager)
		.drawMenu();

	menu.getChoice();
}

void Quit() {
	return;
}

void WaitForEnter() {
	while (!_kbhit());
	while (_kbhit()) getch();
	fflush(stdin);
}