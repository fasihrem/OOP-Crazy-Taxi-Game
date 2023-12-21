/*
 * player.cpp
 *
 *  Created on: Jun 5, 2022
 *      Author: fasih
 */

#include "player.h"
#include "shapes.h"
#include "util.h"

player::player() {
	xI = 0;
	yI = 0;
	x2 = 0;
	y2 = 0;
}

player::player(int x, int y, int a, int b) {
	xI = x;
	yI = y;
	x2 = a;
	y2 = b;
}

void player::display(bool &t, bool &j){
	if(t = true){
		DrawSquare(xI, yI, 40, colors[BLACK]);
	}

	else
		DrawSquare(xI, yI, 40, colors[ORANGE]);
}

void player::display2(bool &t, bool &j){
	DrawSquare(x2, y2, 40, colors[MEDIUM_PURPLE]);
}

void player::WASD_controls(unsigned char key){
	if(key == 'w' || key == 'W'){
		y2 += 10;
		up = true;
	}
	else if(key == 'a' || key == 'A'){
		x2 -= 10;
		left = true;
	}

	else if(key == 's' || key == 'S'){
		y2 -= 10;
		down = true;
	}

	else if(key == 'd' || key == 'D'){
		x2 += 10;
		right = true;
	}

}

void player::GLUT_controls(unsigned char key){
	if(key == GLUT_KEY_UP){
		yI += 10;
		up = true;
	}
	else if(key == GLUT_KEY_LEFT){
		xI -= 10;
		left = true;
	}

	else if(key == GLUT_KEY_DOWN){
		yI -= 10;
		down = true;
	}

	else if(key == GLUT_KEY_RIGHT){
		xI += 10;
		right = true;
	}
}


player::~player() {
	cout<<"destructor"<<endl;
}
