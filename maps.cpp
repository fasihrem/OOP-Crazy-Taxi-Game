/*
 * maps.cpp
 *
 *  Created on: Jun 6, 2022
 *      Author: fasih
 */

#include "maps.h"

maps::maps(){
	cout<<"cons called"<<endl;
}

void maps::display(int c){

}

void maps::level1(){
	s1.drawS(450, 500);
	s1.drawS(450, 200);
}

void maps::level2(){
	level1();
	s1.drawS(180, 500);
	s1.drawS(720, 200);
}

void maps::level3(){
	level2();
	s1.drawS(180, 200);
	s1.drawS(720, 500);
}

maps::~maps(){
	cout<<"destructor called"<<endl;
}
