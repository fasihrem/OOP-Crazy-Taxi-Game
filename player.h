/*
 * player.h
 *
 *  Created on: Jun 5, 2022
 *      Author: fasih
 */

//creates players 1 & 2 and their controls with arrow keys and WASD keys

#ifndef PLAYER_H_
#define PLAYER_H_
#include"util.h"
class player{
public:
	int xI;
	int yI;
	int x2;
	int y2;
	bool up, down, left, right;

	player();
	player(int, int, int, int);
	void GLUT_controls(unsigned char key);
	void WASD_controls(unsigned char key);
	void display(bool &t, bool &j);
	void display2(bool &t, bool &j);
	virtual ~player();
};

#endif /* PLAYER_H_ */
