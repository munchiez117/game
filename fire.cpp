#include "fire.h"
#include "Draw.h"
const int t = 50;
const int qw = 5;
void Fire::setTime(int pics)
{
	pic = pics;
	timer = 0;
}
void Fire::shoot(Draw *sprite, Draw *sprite1)
{
	if ((int)timeGetTime() < timer + 100)return;
	timer = timeGetTime();

	for (int i = 0; i < pic; i++)
	{

		if (Key_Down(DIK_SPACE)&&sprite1->frame==1)
		{

			if (!sprite[i].alive)
			{
				sprite[i].x = sprite1->x + sprite1->width / 4;
				sprite[i].y = sprite1->y + sprite1->height / 4;
				//sprite[i].x = rand() % 600 + 1;
				//sprite[i].y = rand() % 700 + 1;
				sprite[i].velx = 1.;
				sprite[i].vely = 0;
				sprite[i].alive = true;
				break;
			}

		}


		else	if (Key_Down(DIK_SPACE) && sprite1->frame == 3)
		{

			if (!sprite[i].alive)
			{
				sprite[i].x = sprite1->x + sprite1->width / 4;
				sprite[i].y = sprite1->y + sprite1->height / 4;
				//sprite[i].x = rand() % 600 + 1;
				//sprite[i].y = rand() % 700 + 1;
				sprite[i].velx = -1.;
				sprite[i].vely = 0;
				sprite[i].alive = true;
				break;
			}
		}


		else	if (Key_Down(DIK_SPACE) && sprite1->frame == 0)
		{

			if (!sprite[i].alive)
			{
				sprite[i].x = sprite1->x + sprite1->width / 4;
				sprite[i].y = sprite1->y + sprite1->height / 4;
				//sprite[i].x = rand() % 600 + 1;
				//sprite[i].y = rand() % 700 + 1;
				sprite[i].velx = 0;
				sprite[i].vely = -1.;
				sprite[i].alive = true;
				break;
			}
		}


		else	if (Key_Down(DIK_SPACE) && sprite1->frame == 2)
		{

			if (!sprite[i].alive)
			{
				sprite[i].x = sprite1->x + sprite1->width / 4;
				sprite[i].y = sprite1->y + sprite1->height / 4;

				//sprite[i].x = rand() % 600 + 1;
				//sprite[i].y = rand() % 700 + 1;
				sprite[i].velx = 0;
				sprite[i].vely = 1.;
				sprite[i].alive = true;
				break;
			}
		}

	}
}

void::Fire::setCol(Draw *sprite, Draw *sprite1)
{
	
}

int Fire::Collision(Draw *sprite, Draw *sprite1)
{
	for (int j = 0; j < qw; j++)
	{
		for (int i = 0; i < pic; i++)
		{
			RECT rect1;
			rect1.left = (long)sprite[i].x;
			rect1.top = (long)sprite[i].y;
			rect1.right = (long)sprite[i].x + sprite[i].width*sprite[i].scaling;
			rect1.bottom = (long)sprite[i].y + sprite[i].height*sprite[i].scaling;

			RECT rect2;
			rect2.left = (long)sprite1[j].x;
			rect2.top = (long)sprite1[j].y;
			rect2.right = (long)sprite1[j].x + sprite1[j].width*sprite1[j].scaling;
			rect2.bottom = (long)sprite1[j].y + sprite1[j].height*sprite1[j].scaling;
			RECT dest;
			return IntersectRect(&dest, &rect1, &rect2);
		}
	}

}


int  pCollision(Draw *sprite, Draw *sprite1)
{
	RECT rect1;
	rect1.left = (long)sprite->x;
	rect1.top = (long)sprite->y;
	rect1.right = (long)sprite->x + sprite->width*sprite->scaling;
	rect1.bottom = (long)sprite->y + sprite->height*sprite->scaling;

	RECT rect2;
	rect2.left = (long)sprite1->x;
	rect2.top = (long)sprite1->y;
	rect2.right = (long)sprite1->x + sprite1->width*sprite1->scaling;
	rect2.bottom = (long)sprite1->y + sprite1->height*sprite1->scaling;
	RECT dest;
	return IntersectRect(&dest,&rect1, &rect2);
}

void Fire::Spawn(Draw *sprite)
{
	if ((int)timeGetTime() < timer + 100)return;
	timer = timeGetTime();

	for (int i = 0; i < qw; i++)
	{

		if (!sprite[i].alive)
		{
			sprite[i].x =sprite[i].x =0;
			sprite[i].y = sprite[i].y = rand() % 600 + 1;
			//sprite[i].x = rand() % 600 + 1;
			//sprite[i].y = rand() % 700 + 1;
			sprite[i].velx = .5;
			sprite[i].vely = 0;
			sprite[i].alive = true;
			break;
		}
	}
		
}
int Fire::testCol(Draw *sprite, Draw  *sprite1, const int a, const int q)
{
	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < q; j++)
		{
			RECT rect1;
			rect1.left = (long)sprite[i].x;
			rect1.top = (long)sprite[i].y;
			rect1.right = (long)sprite[i].x + sprite[i].width*sprite[i].scaling;
			rect1.bottom = (long)sprite[i].y + sprite[i].height*sprite[i].scaling;

			RECT rect2;
			rect2.left = (long)sprite1[j].x;
			rect2.top = (long)sprite1[j].y;
			rect2.right = (long)sprite1[j].x + sprite1[j].width*sprite1[j].scaling;
			rect2.bottom = (long)sprite1[j].y + sprite1[j].height*sprite1[j].scaling;
			RECT dest;
			return IntersectRect(&dest, &rect1, &rect2);
		}
	}
}
