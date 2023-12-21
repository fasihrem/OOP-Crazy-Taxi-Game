/*
 * collision.h
 *
 *  Created on: Jun 6, 2022
 *      Author: fasih
 */

//collision class which checks all collision with boundry, obstacles and other players

#ifndef COLLISION_H_
#define COLLISION_H_
#include "player.h"

class collision{
public:
	collision();
	void runout(int &xI, int &yI, int &x2, int &y2);
	void collide_l1(int &xI, int &yI, int &score, int &score2, int &x2, int &y2);
	void bullet_collide_l1(int &BxI, int &ByI);
	void collide_l2(int &xI, int &yI, int &score, int &score2, int &x2, int &y2);
	void collide_l3(int &xI, int &yI, int &score, int &score2,  int &x2, int &y2);
	void collide_boundry(int &xI, int &yI, int &x2, int &y2, int &Bx, int &By, bool &bullet1_flag);

	void player1_collision(int &Bx, int &By, int &x2, int &y2, bool &bullet1_flag, int &score);
	void player2_collision(int &B2x, int &B2y, int &xI, int &yI, bool &bullet2_flag, int &score2);

	void bot1_collision(int &Bx, int &By, int &xI, int &yI, int score, bool bullet1_flag);
	void bot2_collision(int &Bx, int &By, int &x2, int &y2, int score, bool bullet1_flag);
	void bot3_collision(int &Bx, int &By, int &x3, int &y3, int score, bool bullet1_flag);
};
#endif /* COLLISION_H_ */
