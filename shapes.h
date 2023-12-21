/*
 * shapes.h
 *
 *  Created on: Jun 2, 2022
 *      Author: fasih
 */

//abstract class which makes shapes by calling display function of the shape
//i couldnt figure out how to send color so i ended up not using this much

#ifndef SHAPES_H_
#define SHAPES_H_
#include<string>
#include<iostream>
#include"util.h"
using namespace std;

class shapes{
	int x;
	int y;
public:
	shapes();
	virtual void drawS(int x, int y) = 0;
	shapes(string c);
	virtual ~shapes();
};

class circle : public shapes{
	int size;
public:
	circle(int s);
	void setSize(int size);
	int getSize();
	void drawS(int x, int y);

};

class square : public shapes{
	int size;
public:
	square();
	square(int s);
	void setSize(int size);
	int getSize();
	void drawS(int x, int y);
};

class rectangle : public shapes{
	int width;
	int height;
public:
	rectangle();
	rectangle(int h, int w);
	void setValues(int h, int w);
	int getH();
	int getW();
	void drawS(int x, int y);
};

class triangle : public shapes{
	int x2, y2, x3, y3;
public:
	triangle(int xI, int yI, int xII, int yII);
	void setValues(int x2,int y2,int x3,int y3);
	int getX2();
	int getY2();
	int getX3();
	int getY3();
	void drawS(int x, int y);

};
#endif /* SHAPES_H_ */
