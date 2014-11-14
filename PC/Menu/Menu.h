/*! 
@mainpage Documentation for console Menu system

@section what_is What is this?

This is the documentation for the Menu system that we will be using for our semester project.

The system is a Menu system, which we will use for controlling our home automation system.

@section source Source code

The source code for this project can be found at https://bitbucket.org/coolkids0016/menutest.
Please note, it's a private repository. Only people working on the project have access to the source code.
*/

#pragma once
#include <vector>
#include <conio.h>
#include <Windows.h>
#include "MenuItem.h"

typedef void(*fPtr)();

/*!
Class to manage menu item holding and drawing on screen.
*/
class Menu {
public:
	/*!
	Destructor for Menu.
	The destructor makes sure to call the next function to load the next menu.

	All menu functions are defined in Menuer.h
	*/
	~Menu();

	/*!
	Used to set the top title of the menu. Displaying shizzle

	@param	title	The title to be displayed
	*/
	Menu & setTitle(std::string title);

	/*!
	Adds a menu item to the menu.

	@param	id			The number that will choose this item in the menu
	@param	text		Text shown when the menu is drawn in console
	@param	nextMenu	Next function that holds the menu to be called when this item is picked.
	*/
	Menu & addMenuItem(std::string id, std::string text, fPtr nextMenu);

	/*!
	Simply draws the menu in the console.
	*/
	void drawMenu();

	/*!
	Should be called after drawMenu() has been called. The method will wait for the user's input.

	When user input is received it will be validated and if validating correctly, it will pick
	a menu item.

	@returns	The menu item ID will be returned when user input is received.
	*/
	int getChoice();
	
	/*!
	Add data to be displayed before the menu. (Currently isn't displayed).
	*/
	Menu & addData(const std::string &data);

	/*!
	Used to test if q (for quit) has been pressed in the "Main menu".

	The method is called by issuing 'Menu::running()'.

	@returns	True as long as q has NOT been pressed in the "Main menu".
	*/
	static bool running();
private:
	// Methods
	void setCursor(int posX, int posY);
	void setChoice(int choice);
	std::string getTitle() const;

	// Variables
	std::string title;
	std::vector<std::string> data;
	std::vector<MenuItem> menuList;
	int choice = 0;

	static bool run;
};