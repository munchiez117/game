#include "Draw.h"
class Fire
{
private:
	int pic;

	int timer;
public:
	void setTime(int pic);
	void Spawn(Draw *sprite1);
	void shoot(Draw *sprite, Draw *sprite1);
	void setCol(Draw *sprite, Draw *sprite1);
	int Collision(Draw *sprite, Draw *sprite1);
	int testCol(Draw *sprite, Draw  *sprite1, const int a, const int q);
};



int  pCollision(Draw *sprite, Draw *sprite1);
