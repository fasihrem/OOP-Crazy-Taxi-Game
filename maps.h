/*
 * maps.h
 *
 *  Created on: Jun 6, 2022
 *      Author: fasih
 */

//creates maps of different levels

#ifndef MAPS_H_
#define MAPS_H_
#include "shapes.h"
#include<iostream>
using namespace std;
class maps{
	square s1;
public:
	maps();
	void display(int c);
	void level1();
	void level2();
	void level3();

	virtual ~maps();
};

#endif /* MAPS_H_ */
