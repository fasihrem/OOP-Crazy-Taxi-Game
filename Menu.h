/*
 * Menu.h
 *
 *  Created on: Jun 1, 2022
 *      Author: fasih
 */

//creates all the different menus, then they are called into their respective places

#ifndef MENU_H_
#define MENU_H_
#include<iostream>
#include "shapes.h"
#include "util.h"
using namespace std;
class Menu{
public:
	Menu();
	void main_menu_display();
	void selection();
	void pause_menu_display();
	void highscore_display();
	void settings_display();
	void game_end();
	string FileRead();
	virtual ~Menu();
};

#endif /* MENU_H_ */
