/*
 * NPC.cpp
 *
 *  Created on: Jun 7, 2022
 *      Author: fasih
 */

#include "NPC.h"

NPC::NPC() {
	iCar1x = GetRandInRange(300,650);
	iCar1y = 300;
	iCar2y = GetRandInRange(300,650);
	iCar2x = 400;
	iCar3x = GetRandInRange(300,1150);
	iCar3y = 160;
	a = false;
	f = false;
	g = false;
}
/*
NPC::NPC(int a, int b, int c){
	iCar1 = a;
	iCar2 = b;
	iCar3 = c;
}
*/
void NPC::car_level1(int b){

	DrawCircle(b, iCar1x, 30, colors[SKY_BLUE]); //SIENNA FOR VIENNA
}

void NPC::level1_auto(){

	if (iCar1x > 100 && a) {
		iCar1x -= 10; //1 -> nothing yet
			cout << "going left";
			if(iCar1x < 300) //changes to 20 from 100

				a = false;

		}
		else if (iCar1x < 600 && !a) {
			cout << "go right";
			iCar1x += 10;
			if (iCar1x > 500)
				a = true;
	}
}

void NPC::car_level2(int a){
	car_level1(660);

	DrawCircle(a, iCar2y, 30, colors[HOT_PINK]);
}

void NPC::level2_auto(){
	level1_auto();

	if (iCar2y > 10 && f) {
		iCar2y -= 10;
			cout << "going left";
			if(iCar2y < 300)

				f = false;

		}
		else if (iCar2y < 600 && !f) {
			cout << "go right";
			iCar2y += 10;
			if (iCar2y > 500)
				f = true;
	}
}

void NPC::car_level3(int a){
	car_level2(400);

	DrawCircle(iCar3x, 420, 30, colors[THISTLE]);
}

void NPC::level3_auto(){
	level2_auto();

	if (iCar3x > 200 && f) {
		iCar3x -= 20;
			cout << "going left";
			if(iCar3x < 900)

				g = false;

		}
		else if (iCar3x < 1000 && !f) {
			cout << "go right";
			iCar3x += 20;
			if (iCar3x > 950)
				g = true;
	}
}

NPC::~NPC() {
	// TODO Auto-generated destructor stub
}

