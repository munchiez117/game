#include"MyDirectX.h"
const int E=5;
const int bl=50;
class Monster
{
private:
	SPRITE hld[E];

	int timer;
public:
int	getMovement(float x,float y,float vx,float vy);
void setMovement(SPRITE sprite[]);
void spawn(SPRITE enemy[]);
void bullet(SPRITE bullet[],SPRITE enemy[]);
void setTimer();
};
int Monster::getMovement(float x,float y,float vx,float vy)
{
	
	return 0;
}

void Monster:: setMovement(SPRITE sprite[])
{
	for(int a=0;a<E;a++)
	{
		sprite[a].velx=getMovement(sprite[a].x,sprite[a].y,sprite[a].velx,sprite[a].vely);
	}
}


 void Monster:: spawn(SPRITE enemy[])
 {
	 for(int a=0;a<E;a++)
	 {
		 if(!enemy[a].alive)
		 {
			 enemy[a].counter=rand()%5+1;
			 if(enemy[a].counter==1)
			 {
			 enemy[a].y=rand()%700+1;
			 enemy[a].x=0;
			 enemy[a].vely=0;
			 enemy[a].velx=.2;
			 enemy[a].alive=true;
			 }
			 break;
		 }
	 }
 }
 

 void Monster::bullet(SPRITE bullet[],SPRITE enemy[])
 {
	 if ((int)timeGetTime() < timer + 100) return;
    timer = timeGetTime();
	for(int p=0;p<E;p++)
	{
	for(int a=0;a<bl;a++)
	{
		for(int q=0;q<E;q++)
		{
			hld[p].x=enemy[q].x;
			hld[p].y=enemy[q].y;
			hld[p].width=enemy[q].width;
			hld[p].height=enemy[q].height;
			if(enemy[q].counter==1)
		{
			if(!bullet[a].alive)
			{
			//bullet[a].x =enemy[q].x + enemy[q].width/4;
			//bullet[a].y =enemy[q].y + enemy[q].height/4;
				bullet[a].x=hld[p].x+hld[p].width/4;
				bullet[a].y=hld[p].y+hld[p].height/4;
			bullet[a].velx=-.3;
			bullet[a].alive=true;
			break;
			}
		}
			else if(enemy[q].counter==2)
			{
				if(!bullet[a].alive)
				{
					//bullet[a].x =enemy[q].x + enemy[q].width/4;
					//bullet[a].y =enemy[q].y + enemy[q].height/4;
					bullet[a].velx=.3;
					bullet[a].alive=true;
				}
			}
				
			}
		}
	}
	}
 void Monster::setTimer()
 {
	 timer=0;
 }
