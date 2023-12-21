/*
 * NPC.h
 *
 *  Created on: Jun 7, 2022
 *      Author: fasih
 */

//creates bots and their movement

#ifndef NPC_H_
#define NPC_H_
#include "util.h"
#include "shapes.h"

class NPC{
public:
	int iCar1x;
	int iCar1y;

	int iCar2y;
	int iCar2x;

	int iCar3x;
	int iCar3y;

	bool a,f,g;

	NPC();
	//NPC(int, int, int);
	void car_level1(int a);
	void level1_auto();

	void car_level2(int a);
	void level2_auto();

	void car_level3(int a);
	void level3_auto();
	virtual ~NPC();
};

#endif /* NPC_H_ */
