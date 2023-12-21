/*
 * collision.cpp
 *
 *  Created on: Jun 6, 2022
 *      Author: fasih
 */

#include "collision.h"

collision::collision(){
	cout<<"cons"<<endl;
}

void collision::runout(int &xI, int &yI, int &x2, int &y2){
	//player1
	if(xI == 0){
		xI = 970;
	}

	if(xI == 1000){
		xI = 10;
	}

	if(yI == 0){
		yI = 790;
	}

	if(yI == 800){
		yI = 10;
	}

	//player 2
	if(x2 == 0){
		x2 = 970;
	}

	if(x2 == 1000){
		x2 = 10;
	}

	if(y2 == 0){
		y2 = 790;
	}

	if(y2 == 800){
		y2 = 10;
	}
}

void collision::collide_boundry(int &xI, int &yI, int &x2, int &y2, int &Bx, int &By, bool &bullet2_flag){
	//player1
	//left wall
	if(xI == 100 && yI >= 100 && yI <= 380){
		xI += 10;
	}

	if(xI == 100 && yI >= 440 && yI <= 950){
		xI += 10;
	}


	if(xI > 0 && xI < 100 && yI == 440){
		yI -= 10;
	}

	if(xI > 0 && xI < 100 && yI == 380){
		yI += 10;
	}

	//right wall
	if(xI == 890 && yI >= 100 && yI <= 380){
		xI -= 10;
	}

	if(xI == 890 && yI >= 440 && yI <= 950){
		xI -= 10;
	}

	if(xI > 890 && yI == 440){
		yI -= 10;
	}

	if(xI > 890 && yI == 380){
		yI += 10;
	}

	//top wall
	if(yI == 710 && xI >= 100 && xI <= 460){
		yI -= 10;
	}

	if(yI == 710 && xI >= 530 && xI <= 950){
		yI -= 10;
	}

	if(xI == 460 && yI > 710){
		xI += 10;
	}

	if(xI == 520 && yI > 710){
		xI -= 10;
	}

	//bottom wall
	if(yI == 100 && xI >= 100 && xI <= 460){
		yI += 10;
	}

	if(yI == 100 && xI >= 530 && xI <= 950){
		yI += 10;
	}

	if(xI == 460 && yI < 100){
		xI += 10;
	}

	if(xI == 520 && yI < 100){
		xI -= 10;
	}

	//player 2
	if(x2 == 100 && y2 >= 100 && y2 <= 380){
		x2 += 10;
	}

	if(x2 == 100 && y2 >= 440 && y2 <= 950){
		x2 += 10;
	}

	if(x2 > 0 && x2 < 100 && y2 == 440){
		y2 -= 10;
	}

	if(x2 > 0 && x2 < 100 && y2 == 380){
		y2 += 10;
	}

	//right wall
	if(x2 == 890 && y2 >= 100 && y2 <= 380){
		x2 -= 10;
	}

	if(x2 == 890 && y2 >= 440 && y2 <= 950){
		x2 -= 10;
	}

	if(x2 > 890 && y2 == 440){
		y2 -= 10;
	}

	if(x2 > 890 && y2 == 380){
		y2 += 10;
	}

	//top wall
	if(y2 == 710 && x2 >= 100 && x2 <= 460){
		y2 -= 10;
	}

	if(y2 == 710 && x2 >= 530 && x2 <= 950){
		y2 -= 10;
	}

	if(x2 == 460 && y2 > 710){
		x2 += 10;
	}

	if(x2 == 520 && y2 > 710){
		x2 -= 10;
	}

	//bottom wall
	if(y2 == 100 && x2 >= 100 && x2 <= 460){
		y2 += 10;
	}

	if(y2 == 100 && x2 >= 530 && x2 <= 950){
		y2 += 10;
	}

	if(x2 == 460 && y2 < 100){
		x2 += 10;
	}

	if(x2 == 520 && y2 < 100){
		x2 -= 10;
	}

	/*
	//bullet
	//right wall
	if(Bx == 890 && By >= 100 && By <= 380){
		Bx += 1000;
	}

	if(xI == 890 && yI >= 440 && yI <= 950){
		xI -= 10;
	}

	if(xI > 890 && yI == 440){
		yI -= 10;
	}

	if(xI > 890 && yI == 380){
		yI += 10;
	}
	*/

}

void collision::collide_l1(int &xI, int &yI, int &score, int &score2, int &x2, int &y2){
	//player1
	//top middle block
	if(xI == 410 && yI > 460 && yI < 650){
		xI -= 10;
		//score +=5;
	}

	if(xI == 600 && yI > 460 && yI < 650){
		xI += 10;
		//score +=5;
	}

	if(yI == 460 && xI > 410 && xI < 600){
		yI -= 10;
		//score +=5;
	}

	if(yI == 650 && xI > 410 && xI < 600){
		yI += 10;
		//score +=5;
	}

	//bottom middle block
	if(xI == 410 && yI > 160 && yI < 350){
		xI -= 10;
		//score +=5;
	}

	if(xI == 600 && yI > 160 && yI < 350){
		xI += 10;
		//score +=5;
	}

	if(yI == 160 && xI > 410 && xI < 600){
		yI -= 10;
		//score +=5;
	}

	if(yI == 350 && xI > 410 && xI < 600){
		yI += 10;
		//score +=5;
	}

	//player 2
	//top middle block
	if(x2 == 410 && y2 > 460 && y2 < 650){
		x2 -= 10;
		//score2 +=5;
	}

	if(x2 == 600 && y2 > 460 && y2 < 650){
		x2 += 10;
		//score2 +=5;
	}

	if(y2 == 460 && x2 > 410 && x2 < 600){
		y2 -= 10;
		//score2 +=5;
	}

	if(y2 == 650 && x2 > 410 && x2 < 600){
		y2 += 10;
		//score2 +=5;
	}

	//bottom middle block
	if(x2 == 410 && y2 > 160 && y2 < 350){
		x2 -= 10;
		//score2 +=5;
	}

	if(x2 == 600 && y2 > 160 && y2 < 350){
		x2 += 10;
		//score2 +=5;
	}

	if(y2 == 160 && x2 > 410 && x2 < 600){
		y2 -= 10;
		//score2 +=5;
	}

	if(y2 == 350 && x2 > 410 && x2 < 600){
		y2 += 10;
		//score2 +=5;
	}

}

void collision::collide_l2(int &xI, int &yI, int &score, int &score2,  int &x2, int &y2){
	collide_l1(xI, yI, score, score2, x2, y2);
	//player1
	//top left block
	if(xI == 140 && yI > 460 && yI < 650){
		xI -= 10;
		//score +=5;
	}

	if(xI == 330 && yI > 460 && yI < 650){
		xI += 10;
		//score +=5;
	}

	if(yI == 460 && xI > 140 && xI < 330){
		yI -= 10;
		//score +=5;
	}

	if(yI == 650 && xI > 140 && xI < 330){
		yI += 10;
		//score +=5;
	}

	//bottom right block
	if(xI == 680 && yI > 160 && yI < 350){
		xI -= 10;
		//score +=5;
	}

	if(xI == 870 && yI > 160 && yI < 350){
		xI += 10;
		//score +=5;
	}

	if(yI == 160 && xI > 680 && xI < 870){
		yI -= 10;
		//score +=5;
	}

	if(yI == 350 && xI > 680 && xI < 870){
		yI += 10;
		//score +=5;
	}

	//player2
	//top left block
	if(x2 == 140 && y2 > 460 && y2 < 650){
		x2 -= 10;
		//score2 +=5;
	}

	if(x2 == 330 && y2 > 460 && y2 < 650){
		x2 += 10;
		//score2 +=5;
	}

	if(y2 == 460 && x2 > 140 && x2 < 330){
		y2 -= 10;
		//score2 +=5;
	}

	if(y2 == 650 && x2 > 140 && x2 < 330){
		y2 += 10;
		//score2 +=5;
	}

	//bottom right block
	if(x2 == 680 && y2 > 160 && y2 < 350){
		x2 -= 10;
		//score2 +=5;
	}

	if(x2 == 870 && y2 > 160 && y2 < 350){
		x2 += 10;
		//score2 +=5;
	}

	if(y2 == 160 && x2 > 680 && x2 < 870){
		y2 -= 10;
		//score2 +=5;
	}

	if(y2 == 350 && x2 > 680 && x2 < 870){
		y2 += 10;
		//score2 +=5;
	}
}

void collision::collide_l3(int &xI, int &yI, int &score, int &score2, int &x2, int &y2){

	collide_l2(xI, yI, score, score2, x2, y2);
	//top right block
	if(xI == 680 && yI > 460 && yI < 650){
		xI -= 10;
		//score +=5;
	}

	if(xI == 870 && yI > 460 && yI < 650){
		xI += 10;
		//score +=5;
	}

	if(yI == 460 && xI > 680 && xI < 870){
		yI -= 10;
		//score +=5;
	}

	if(yI == 650 && xI > 680 && xI < 870){
		yI += 10;
		//score +=5;
	}

	//bottom left block
	if(xI == 140 && yI > 160 && yI < 350){
		xI -= 10;
		//score +=5;
	}

	if(xI == 330 && yI > 160 && yI < 350){
		xI += 10;
		//score +=5;
	}

	if(yI == 160 && xI > 140 && xI < 330){
		yI -= 10;
		//score +=5;
	}

	if(yI == 350 && xI > 140 && xI < 330){
		yI += 10;
		//score +=5;
	}

	//player2
	//top right block
	if(x2 == 680 && y2 > 460 && y2 < 650){
		x2 -= 10;
		//score2 +=5;
	}

	if(x2 == 870 && y2 > 460 && y2 < 650){
		x2 += 10;
		//score2 +=5;
	}

	if(y2 == 460 && x2 > 680 && x2 < 870){
		y2 -= 10;
		//score2 +=5;
	}

	if(y2 == 650 && x2 > 680 && x2 < 870){
		y2 += 10;
		//score2 +=5;
	}

	//bottom left block
	if(x2 == 140 && y2 > 160 && y2 < 350){
		x2 -= 10;
	//	score2 +=5;
	}

	if(x2 == 330 && y2 > 160 && y2 < 350){
		x2 += 10;
//		score2 +=5;
	}

	if(y2 == 160 && x2 > 140 && x2 < 330){
		y2 -= 10;
		//score2 +=5;
	}

	if(y2 == 350 && x2 > 140 && x2 < 330){
		y2 += 10;
		//score2 +=5;
	}
}

void collision::player1_collision(int &Bx, int &By, int &x2, int &y2, bool &bullet1_flag, int &score){
	if((Bx >= x2-20 && Bx <= x2+20) && (By >= y2-40 && By <= y2+40)){
		score +=1;
		Bx +=1000;
		By += 1000;

	}
}

void collision::player2_collision(int &B2x, int &B2y, int &xI, int &yI, bool &bullet2_flag, int &score2){
	if((B2x >= xI-20 && B2x <= xI+20) && (B2y >= yI-40 && B2y <= yI+40)){
		score2 +=1;
//		bullet2_flag = false;
		B2x +=1000;
		B2y +=1000;
	}
}

void collision::bot1_collision(int &Bx, int &By, int &xI, int &yI, int score, bool bullet2_flag){
	if(Bx >= xI-20 && Bx <= xI+20 && By >= yI-40 && By <= yI+40){
		score+=1;
		//bullet2_flag = false;
		Bx +=1000;
		By +=1000;
	}
}

void collision::bot2_collision(int &Bx, int &By, int &x2, int &y2, int score, bool bullet1_flag){
	if(Bx >= x2-20 && Bx <= x2+20 && By >= y2-40 && By <= y2+40){
		score+=1;
		//bullet2_flag = false;
		Bx +=1000;
		By +=1000;
	}
}

void collision::bot3_collision(int &Bx, int &By, int &x3, int &y3, int score, bool bullet1_flag){
	if(Bx >= x3-20 && Bx <= x3+20 && By >= y3-40 && By <= y3+40){
			score+=1;
			//bullet2_flag = false;
			Bx +=1000;
			By +=1000;
		}
}
