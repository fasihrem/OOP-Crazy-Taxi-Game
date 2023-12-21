/*
 * Menu.cpp
 *
 *  Created on: Jun 1, 2022
 *      Author: fasih
 */

#include <fstream>
#include "Menu.h"

using namespace std;

Menu::Menu(){
	cout<<"something"<<endl;
}

void Menu::main_menu_display(){
	DrawRectangle(300, 560, 450, 105, colors[MAGENTA]);
	DrawString(410, 600, "Press [E] to Enter Game", colors[BLACK]);

	DrawRectangle(300, 460, 450, 105, colors[PINK]);
	DrawString(380, 500, "Press [H] to see the High Score", colors[BLACK]);

	DrawRectangle(300, 310, 450, 155, colors[CYAN]);
	DrawString(370, 400, "Press [R] to return to Main Menu", colors[BLACK]);
	DrawString(460, 350, "when in game", colors[BLACK]);

	DrawRectangle(300, 215, 450, 105, colors[CORN_SILK]);
	DrawString(370, 260, "Press [B] to access the Settings", colors[BLACK]);

}

void Menu::selection(){
	DrawRectangle(300, 560, 450, 105, colors[MAGENTA]);
	DrawString(400, 600, "Press [1] for Single Player", colors[BLACK]);

	DrawRectangle(300, 460, 450, 105, colors[PINK]);
	DrawString(410, 500, "Press [2] for Two Player", colors[BLACK]);
}

void Menu::pause_menu_display(){
	DrawRectangle(350, 430, 300, 200, colors[CYAN]);
	DrawString(410, 510, "GAME PAUSED", colors[BLACK]);
	DrawRectangle(350, 230, 300, 200, colors[PINK]);
	DrawString(430, 350, "[LEFT CLICK]", colors[BLACK]);
	DrawString(400, 300, "to return to the game", colors[BLACK]);
}

void Menu::highscore_display(){
	DrawString(410, 780, "High scores", colors[BLACK]);
	//DrawString(410,400,"H",colors[BLACK]);
	ifstream fin("Score.txt");
	string s="hello";
	int i=70;
	if(fin)
	{
	//cout << "\nHellllllllllllllllllllllllllllllll\n";
		while(!fin.eof())
		{
			cout << "\nhell\n";
			getline(fin,s,'\n');
			cout << s<<endl;
			DrawString(410,780-i,s,colors[BLACK]);
			i += 70;
		}
		fin.close();
	}
	else
	{
		cout << "file not opened\n";
	}

	DrawString(410, 100, "Press [R] to exit to Main Menu", colors[BLACK]);
}

void Menu::settings_display(){
	DrawRectangle(300, 350, 450, 200, colors[PINK]);
	DrawString(330, 450, "Settings not available, check back later!", colors[BLACK]);
	DrawString(520, 410, ":)", colors[BLACK]);
}

void Menu::game_end(){
	DrawRectangle(300, 500, 450, 200, colors[PINK]);
	DrawString(350, 600, "Congratulations! Game Finished!", colors[BLACK]);
	DrawString(520, 560, ":)", colors[BLACK]);

	DrawRectangle(300, 300, 450, 100, colors[CORN_SILK]);
	DrawString(390, 340, "Made by Fasih Ur Rehman", colors[BLACK]);

	DrawRectangle(300, 200, 450, 100, colors[TURQUOISE]);
	DrawString(370, 240, "Press [ENTER] to exit the Game", colors[BLACK]);
}

string Menu::FileRead(){
	ifstream fin("Score.txt");
	string s="hello";

	if(fin){
		while(fin.eof()){
			getline(fin,s,'\n');
			cout<<s<<endl;
			DrawString(410,350,"H",colors[BLACK]);
		}

		fin.close();
	}

	else{
		cout<<"file not opened\n";
	}

	return s;
}

Menu::~Menu() {
	cout<<"nothing"<<endl;
}
