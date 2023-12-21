/*
 * shapes.cpp
 *
 *  Created on: Jun 2, 2022
 *      Author: fasih
 */

#include "shapes.h"

shapes::shapes() {
	// TODO Auto-generated constructor stub

}
void shapes::drawS(int x, int y){

}

shapes::~shapes() {
	// TODO Auto-generated destructor stub
}

circle::circle(int s){
	size = s;
}
/*
void circle::setSize(int s1){
	size = s1;
}
*/
int circle::getSize(){
	return size;
}

void circle::drawS(int x, int y){
	DrawCircle(x,y,getSize(),colors[RED]);
}

square::square(){
	size = 150;
}

square::square(int s){
	size = s;
}

/*
void square::setSize(int s1){
	size = s1;
}
*/
int square::getSize(){
	return size;
}

void square::drawS(int x, int y){

	DrawSquare(x, y, getSize(), colors[AQUA_MARINE]);
}

rectangle::rectangle(){
	width = 450;
	height = 100;
}

rectangle::rectangle(int h, int w){
	width = w;
	height = h;
}
/*
void rectangle::setValues(int h, int w){
	height = h;
	width = w;
}
*/

int rectangle::getH(){
	return height;
}

int rectangle::getW(){
	return width;
}

void rectangle::drawS(int x, int y){
	DrawRectangle(x, y, getW(), getH(), colors[MINT_CREAM]); //SIENNA FOR VIENNA
}

triangle::triangle(int xI, int yI, int xII, int yII){
	x2 = xI;
	y2 = yI;
	x3 = xII;
	y3 = yII;
}

/*
void triangle::setValues(int xI, int yI, int xII, int yII){
	x2 = xI;
	y2 = yI;
	x3 = xII;
	y3 = yII;
}
*/

int triangle::getX2(){
	return x2;
}

int triangle::getY2(){
	return y2;
}
int triangle::getX3(){
	return x3;
}

int triangle::getY3(){
	return y3;
}

void triangle::drawS(int x, int y){
	DrawTriangle(x, y, getX2(), getY2(), getX3(), getY3(), colors[PINK]);
}
