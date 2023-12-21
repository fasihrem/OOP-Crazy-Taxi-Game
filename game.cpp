//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <fstream>
#include "Menu.h"
#include "shapes.h"
#include "player.h"
#include "maps.h"
#include "collision.h"
#include "NPC.h"
#include <stdlib.h>
#include<string>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}


//int xI = 400, yI = 400;
static player p1(10, 415, 970, 415);
collision c1;
static Menu m1;
NPC n;

int score = 0;
int score2 = 0;
int x2 = p1.xI;
int y2 = p1.yI;
int Bx1 = p1.x2;
int By1 = p1.y2;
int p1x = 800, p1y = 680;
int p2x = 450, p2y = 160;

bool tank_check;
bool jet_check;
bool bullet1_flag = false;
bool bullet2_flag = false;
bool lv2, lv3;
bool oneplayer;
bool twoplayer;
bool page2, inGame;
bool power1, power2;
bool game_end;
bool pl1, pl2;

void FileWrite();
void PrintableKeys(unsigned char key, int x, int y);

void drawBullet(int size){ //draws bullet of player 1
	DrawCircle(x2, y2, size, colors[BLACK]);
	DrawCircle(x2, y2, size-2, colors[WHITE]);
}

void drawBullet2(int size){ //draws bullet of player 2
	DrawCircle(Bx1, By1, size, colors[BLACK]);
	DrawCircle(Bx1, By1, size-2, colors[WHITE]);
}


void drawCar1() { //draws player1 vehicle
	//DrawSquare(xI, yI, 20, colors[WHITE]);
	p1.display(tank_check, jet_check);
	glutPostRedisplay();
}

void drawCar2(){ //draws player 2 vehicle
	p1.display2(tank_check, jet_check);
	glutPostRedisplay();
}

void menu(){ //draws menu
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
				1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	m1.main_menu_display();

	glutSwapBuffers();
}

void select(){ //gives choice between 1 or 2 player mode
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
					1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	m1.selection();

	glutSwapBuffers();
}

void highscore(){ //highscore menu
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
					1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	m1.highscore_display();

	glutSwapBuffers();
}

void pause_menu(){ //pause menu
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
						1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	m1.pause_menu_display();
	glutSwapBuffers();
}

void settings(){
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
							1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	m1.settings_display();

	glutSwapBuffers();
}

void endgame(){ //endscreen with credits
	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
								1/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors

	m1.game_end();
	if(pl1 == true){
		DrawRectangle(300, 400, 450, 100, colors[AQUA_MARINE]);
		DrawString(450, 440, "Player 1 WINS!", colors[BLACK]);
	}

	if(pl2 == true){
		DrawRectangle(300, 400, 450, 100, colors[AQUA_MARINE]);
		DrawString(450, 440, "Player 2 WINS!", colors[BLACK]);
	}

	glutSwapBuffers();

}

bool flag = true;
void moveCar() {
	
	//n.level1_auto(flag);

	/*if (xI > 10 && flag) {
		xI -= 10;
		cout << "going left";
		if(xI < 100)
			
			flag = false;

	}
	else if (xI < 1010 && !flag) {
		cout << "go right";
		xI += 10;
		if (xI > 900)
			flag = true;
	}
	*/
}

/*
 * Main Canvas drawing function.
 * */

void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.

	glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	glClear (GL_COLOR_BUFFER_BIT); //Update the colors


	DrawString(150, 700, "Score P1 = "+to_string(score), colors[BLACK]); //draws score of player 1

	if(twoplayer == true)
	DrawString(750, 700, "Score P2 = "+to_string(score2), colors[BLACK]); //draws score of player 2 if two player mode active

	/*circle c1(50); //circle c1(radius)
	square s1(150); //square s1(size)
	square s2(50);
	triangle t1(340, 450, 320, 490); //triangle t1(x2, y2, x3, y3)
	*/

	int s = 6; //size of bullet

	//system("mplayer radioactive.wav");

	//system("canberra-gtk-play -f radioactive.wav");

	//displays score on game display



//	n.car_level2(300, 400);



	maps m;

	//c1.setSize(20);
	//c1.drawS(250, 250);
	//c1.drawS(600, 200);

	//r1.setValues(100, 400);


	//level 1
	//s1.setSize(50);
	/*
	s1.drawS(450, 500);
	s1.drawS(450, 200);
	*/

	rectangle r1(100, 1050); //rectangle r1(height, width)
	rectangle r2(1050, 100);

	//EXIT/ENTRY points
	r1.drawS(0, 0);
	r1.drawS(0,750);
	r2.drawS(0,0);
	r2.drawS(930,0);
	DrawSquare(460, 0, 102, colors[WHITE]);
	DrawSquare(460, 750, 102, colors[WHITE]);
	DrawSquare(0, 380, 102, colors[WHITE]);
	DrawSquare(920, 380, 102, colors[WHITE]);

	if(power1 == true && oneplayer == true && twoplayer == false){ //powerups
		s +=4;
		system("canberra-gtk-play -f powerup.wav");
		power1 = false;
	}

	if(power2 == true && oneplayer == true && twoplayer == false){ //powerups
		s +=4;
		system("canberra-gtk-play -f powerup.wav");
		power2 = false;
	}

	if(bullet1_flag == true){ //draws bullet
		drawBullet(s);
	}

	if(bullet2_flag == true){ //draws bullet
		drawBullet2(s);
	}

	//collision of boundry and infinite runout
	c1.runout(p1.xI, p1.yI, p1.x2, p1.y2);
	c1.collide_boundry(p1.xI, p1.yI, p1.x2, p1.y2, Bx1, By1, bullet2_flag);


	//settings of one player mode, including levels and how game ends
	if(oneplayer == true){

		DrawCircle(p1x, p1y, 10, colors[GREEN]);
		DrawCircle(p2x, p2y, 10, colors[GREEN]);

		drawCar1();


		if(score < 10 && score >= 0){
		m.level1();
		n.car_level1(660); //starting value of auto car 1
		c1.collide_l1(p1.xI, p1.yI, score, score2, p1.x2, p1.y2);
	}

		else if(score >= 10 && score < 20){
			lv2 = true;
			m.level2();
			n.car_level2(400); //starting value of auto car 1
			c1.collide_l2(p1.xI, p1.yI, score, score2, p1.x2, p1.y2);
		}

		else if(score >= 20 && score < 30){
			m.level3();
			n.car_level3(160); //starting value of auto car 1
			c1.collide_l3(p1.xI, p1.yI, score, score2, p1.x2, p1.y2);
		}

		else if(score >= 30){
			glutDisplayFunc(endgame);
			game_end = true;
		}

		//collision with bots
		c1.bot1_collision(x2, y2, n.iCar1x, n.iCar1y, score, bullet1_flag);
		c1.bot2_collision(x2, y2, n.iCar2x, n.iCar2y, score, bullet1_flag);
		c1.bot3_collision(x2, y2, n.iCar3x, n.iCar3y, score, bullet1_flag);

	}

	//settings of two player mode
	if(twoplayer == true){

		drawCar1();
		drawCar2();

	/*	if(x2 >= p1.xI-20 && x2 <= p1.xI+20 && y2 >= p1.yI-40 && y2 <= p1.yI+40){
			score+=1;
			x2+=1000;
			y2+=1000;
			bullet1_flag = false;
		}*/

		/*if(score < 10 && score >= 0){
		m.level1();
		//n.car_level1(200); //starting value of auto car 1
		c1.collide_l1(p1.xI, p1.yI, score, score2, p1.x2, p1.y2);
	}

		else if(score >= 10 && score < 20){
			m.level2();
			//n.car_level2(500); //starting value of auto car 1
			c1.collide_l2(p1.xI, p1.yI, score, score2, p1.x2, p1.y2);
		}

		else if(score >= 20 && score < 30){
			m.level3();
			//n.car_level3(160); //starting value of auto car 1
			c1.collide_l3(p1.xI, p1.yI, score, score2,  p1.x2, p1.y2);
		}
*/
		m.level3();
		c1.collide_l3(p1.xI, p1.yI, score, score2,  p1.x2, p1.y2);

		if(score >= 30){
			FileWrite();
			glutDisplayFunc(endgame);
			game_end = true;
			pl1 = true;
		}

		else if(score2 >= 30){
			FileWrite();
			glutDisplayFunc(endgame);
			game_end = true;
			pl2 = true;
		}

		c1.player1_collision(x2, y2, p1.x2, p1.y2, bullet1_flag, score);
		c1.player2_collision(Bx1, By1, p1.xI, p1.yI, bullet2_flag, score2);

	}

	//level 2
	//s1.drawS(180, 500);
	//s1.drawS(720, 200);

	//level3
	//s1.drawS(180, 200);
	//s1.drawS(720, 500);

	//t1.setValues(340, 450, 320, 490);
	//t1.drawS(300, 450);

	//m1.display();

	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]);
	
	//Display Score
	//DrawString( 50, 800, "Score=0", colors[MISTY_ROSE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[MISTY_ROSE] );
	


	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	//DrawLine( 550 , 50 ,  550 , 480 , 10 , colors[MISTY_ROSE] );
	
	//DrawCircle(50,670,10,colors[RED]);
	//DrawCircle(70,670,10,colors[RED]);
	//DrawCircle(90,670,10,colors[RED]);
	//DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	//DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);
	//DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	//DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	//DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);

	glutSwapBuffers(); // do not modify this line..

}

//file handling for score
void FileWrite(){
	ofstream fout("Score.txt", ios::app);

	//fout<<"Player 1: "<<"\t"<<"Player 2:"<<endl;

	if(fout){
		fout<<score<<"\t\t\t"<<score2<<endl;
		fout.close();
	}

	else{
		cout<<"File not opened\n";
	}
}

string FileRead(){
	ifstream fin("Score.txt");
	string s ="";

	if(fin){
		getline(fin,s,'\n');
		fin.close();
	}

	else{
		cout<<"file not opened\n";
	}

	return s;
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	//if (key
		//	== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		//xI -= 10;

//	} else if (key
//			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
//		xI += 10;
//	} else if (key
//			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
//		yI += 10;
//	}

//	else if (key
//			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
//		yI -= 10;
//	}
	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/
	p1.GLUT_controls(key); //class controlling arrow keys
	//p1.control((unsigned char)key);
	glutPostRedisplay();

}

/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * all functionality of keyboard
 */
void PrintableKeys(unsigned char key, int x, int y) {
	int s = 6;

	if (key == 27/* Escape key ASCII*/ && game_end == false) {
		FileWrite();
		exit(1); // exit the program when escape key is pressed.
	}

	p1.WASD_controls(key);

	if(key == 'e' || key == 'E'){
			glutDisplayFunc(select);
			page2 = true;
	}

	if ((key == 'b' || key == 'B'))//Key for placing the bomb
			{
		//do something if b is pressed
			glutDisplayFunc(settings);
			}

	if((key == '1') && (page2 == true) && (twoplayer == false)){
			oneplayer = true;
			glutDisplayFunc(GameDisplay);
			inGame = true;
	}
	if((key == '2') && (page2 == true) && (oneplayer == false)){
			twoplayer = true;
			glutDisplayFunc(GameDisplay);
			inGame = true;
	}

	else if(key == 'r' || key == 'R'){
		glutDisplayFunc(menu);
	}

	if(key == 'h' || key == 'H'){
		glutDisplayFunc(highscore);
	}

	if(key == 13 && game_end == true){
		exit(1);
	}

	if(power1 == true){
		s += 4;
	}

	if(power2 == true){
		s += 4;
	}

	if((key == 'm' || key == 'M') && (inGame == true)){
		//if(p1.up == true;){
			//drawBullet(s);
			x2 = p1.xI+50;
			y2 = p1.yI+20;
			bullet1_flag = true;
	}
		//}



		/*if(p1.down == true;){
			drawBullet(s);
			//x2 = p1.xI+50;
			y2 = p1.yI-50;
			bullet1_flag = true;
		}

		if(p1.left == true;){
			drawBullet(s);
			x2 = p1.xI-50;
			//y2 = p1.yI-50;
			bullet1_flag = true;
		}

		if(p1.right == true;){
			drawBullet(s);
			x2 = p1.xI+50;
			//y2 = p1.yI-50;
			bullet1_flag = true;
		}
	*/

	if((key == 'q' || key == 'Q')&& (inGame == true) && (twoplayer == true)){
		drawBullet2(s);
		Bx1 = p1.x2-10;
		By1 = p1.y2+20;
		bullet2_flag = true;
	}

	if(p1.xI >= 700 && p1.xI <= 900 && p1.yI >= 580 && p1.yI <= 780){
		if(key == 32 || key == ' '){
			p1x +=1000;
			p1y +=1000;
			power1 = true;
		}
	}

	if(p1.xI >= 350 && p1.xI <= 450 && p1.yI >= 60 && p1.yI <= 260){
		if(key == 32 || key == ' '){
			p2x +=1000;
			p2y +=1000;
			power2 = true;
		}
	}

	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {
	int s = 6;
	// implement your functionality here
	//moveCar();

	if(power1 == true){
		s += 4;
	}

	if(power2 == true){
		s += 4;
	}


	if(oneplayer == true){
	n.level1_auto();
	n.level2_auto();
	n.level3_auto();
	}

	if(bullet1_flag == true){
		drawBullet(s);
			x2 +=20;
	}


		/*if(p1.down == true){
		drawBullet(s);
		//x2 +=10;
		y2 -=10;
		}

		if(lv2 == true){
		drawBullet(s+6);
		x2 +=10;
		y2 +=10;
		}
		*/

	//movement of bullet
	if(bullet2_flag == true){
		drawBullet2(s);
		Bx1 -= 20;
		//By1 += 10;

		/*if(lv2 = true){
			drawBullet2(s+6);
			Bx1 += 10;
			By1 += 10;
		}
		*/
	}

	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}

/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {


	//pause and play using mouse press
	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
	glutDisplayFunc(GameDisplay);

	}
	else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
	{
		glutDisplayFunc(pause_menu);
	}
	glutPostRedisplay();
}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("made by fasih, barely"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...
	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(menu); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);

	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
