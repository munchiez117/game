#include "MyDirectX.h"
const int hal=5;
int ing=0;
class action
{
private:
	//const int pal;
	bool lve[hal];
	bool live;

	bool r;
	bool l;
	bool u;
	bool d;

	int bullet;
	 int timer;//this is the timer for the bullets
	static const int bu;
//	SPRITE* bill[];
	// SPRITE qs[bu];
	 //const int ww;
public:
	void setBullet(const int number);
	int fd();//not used in the game
	void playerShoot(SPRITE sprite[], SPRITE* player);//this spawn and launches bullets from the player postion 
	void projectile(SPRITE sprite[]);// this erases the bullets to false
	int Direction();//does nothing 
	//SPRITE qw;
	//SPRITE b[];
	action();
	~action();
	
	//SPRITE al;
};


//this sets the timer to 0
//this is being used so that not all bullets spawn at once
 void action::setBullet(const int number)
{
	bullet = number;
	timer=0;
	//pal=number;
}

 //this is not being used and will probably replaced with something else
int action::fd()
{
	return 0;
}



///this allows the player to shoot bullets in all directions
//this works
void action::playerShoot(SPRITE sprite[], SPRITE* player)
{
	if ((int)timeGetTime() < timer + 100) return;
    timer = timeGetTime();
	for(int a=0;a <hal;a++)
	{
	
		if(Key_Down(DIK_SPACE)&&player->frame==1)
	{
		if(!sprite[a].alive)
		{
			//sprite[a].x = player->x +player->width/2;
           // sprite[a].y =player->y + player->height/2 - sprite[a].height/2;
			//sprite[a].alive=true;
				sprite[a].x= player->x +player-> width/4;
				sprite[a].y= player->y +player-> height/4;
			//	sprite[a].vely=sprite[a].vely*0;
				sprite[a].velx=1.;
				sprite[a].vely=0;
				sprite[a].alive=true;
			break;
		}
	}
		

		

		else	if(Key_Down(DIK_SPACE)&&player->frame==0)
	{
		//sprite[a].alive=true;
		if(!sprite[a].alive)
		{
			//sprite[a].x = player->x +player->width/2;
           // sprite[a].y =player->y + player->height/2 - sprite[a].height/2;
			//sprite[a].alive=true;
				sprite[a].x= player->x +player-> width/4;
				sprite[a].y= player->y +player-> height/4;
				sprite[a].velx=0;
				sprite[a].vely=-1.;
				sprite[a].alive=true;
			break;
		}
	}

	

		else	if(Key_Down(DIK_SPACE)&&player->frame==2)
	{
		//sprite[a].alive=true;
		if(!sprite[a].alive)
		{
			//sprite[a].x = player->x +player->width/2;
           // sprite[a].y =player->y + player->height/2 - sprite[a].height/2;
			//sprite[a].alive=true;
				sprite[a].x= player->x +player-> width/4;
				sprite[a].y= player->y +player-> height/4;
				sprite[a].velx=0;
				sprite[a].vely=1.;
				sprite[a].alive=true;
			break;
		}
	}

		else	if(Key_Down(DIK_SPACE)&&player->frame==3)
	{
		//sprite[a].alive=true;
		if(!sprite[a].alive)
		{
			//sprite[a].x = player->x +player->width/2;
            //sprite[a].y =player->y + player->height/2 - sprite[a].height/2;
			//sprite[a].alive=true;
				sprite[a].x= player->x +player-> width/4;
				sprite[a].y= player->y +player-> height/4;
				sprite[a].velx=-1.;
				sprite[a].vely=0;
				sprite[a].alive=true;
			break;
		}
	}
}
		
}
//this is not being used in the main game as of right now
int action::Direction()
{
	return -1;
}

//this is used when anything need to be destroyed once it leaves the screen 
void action::projectile(SPRITE sprite[])
{
	for(int a =0;a<hal;a++)
	{
		if(sprite[a].x<0)	sprite[a].alive=false;
		if(sprite[a].x>SCREENW-64)  sprite[a].alive=false;
		if(sprite[a].y<0)	sprite[a].alive=false;
		if(sprite[a].y>SCREENH-64)	sprite[a].alive=false;
	}
}

action::action()
{
	
	//bullet=100;
}
action::~action()
{
}
