#include "fire.h"
#include "Draw.h"//this is a test at drawing things
#include <vector>
#include "Enemies.h"
#include "action.h"
#include "score.h"
#include "movement.h"
#include "MyDirectX.h"
#include "wav.h"

void shoot();


using namespace std;
#include <ctime>
const string APPTITLE = "Scetch Book Shooter";
const int SCREENW = 1024;
const int SCREENH = 768;

const int SC = 10;
const int e=5;
const int ft=5;
const int gt=50;
int level=1;

Wave sound;

vector<Draw> ar;
vector<Draw*> chap;
vector<Draw*>::iterator it;

Draw *bullet = NULL;
Draw *monster1 = NULL;
Draw *ME = NULL;
Draw *pap = NULL;
Draw *tat = NULL;
Draw *SCORE = NULL;

Draw *TILES = NULL;

LPDIRECT3DSURFACE9 Space=NULL;
LPDIRECT3DSURFACE9 Island=NULL;
LPDIRECT3DSURFACE9 Queen=NULL;
LPDIRECT3DSURFACE9 back5 = NULL;

LPDIRECT3DTEXTURE9 tiles = NULL;
LPDIRECT3DTEXTURE9 crazy=NULL;
LPDIRECT3DTEXTURE9 Alpha=NULL;
LPDIRECT3DTEXTURE9 thing=NULL;
LPDIRECT3DTEXTURE9 blet = NULL;

D3DCOLOR color=D3DCOLOR_XRGB(255,255,255);
int score=0;
int count=9;
bool check=true;
//side Plat;
const int bell = 10;

///this will change into vector later
Score t;
Score level1;
Score level2;
Score level3;
Fire  prj;
Fire spa;


D3DCOLOR fer = D3DCOLOR_XRGB(255, 255, 255);
bool Game_Init(HWND window)
{
    //initialize Direct3D
    Direct3D_Init(window, SCREENW, SCREENH, false);
	srand(time(NULL));

    //initialize DirectInput
    DirectInput_Init(window);

	tiles = LoadTexture("sprite_test.png");
	//load the background and the sprite sheet
Island=LoadSurface("background3.png");
Space=LoadSurface("background2.png");
Queen = LoadSurface("background4.png");
back5 = LoadSurface("background5.png");

level1.Loadback(back5);//this loads level 1 background
level2.Loadback(Island);//level 2 background
level3.Loadback(Queen);//level 3

thing=LoadTexture("ship.png");
blet=LoadTexture("bullet.png");
crazy=LoadTexture("Evil.png");
Alpha=LoadTexture("alpha.png");

prj.setTime(50);
spa.setTime(25);
t.SetScore();
TILES = new Draw[192];
bullet = new Draw[gt];
monster1 = new Draw[e];
for (int i = 0; i < 192; i++)
{
	TILES[i].setDraw(tiles,0,0,0,0,0,64,64,1,0,4,color,0,0,0,0,0,true);
	TILES[i].frame = rand() % 5 - 1;
	//TILES[i].x = 0;
	//TILES[i].y = 0;
	TILES[i].x += 64;
	if (TILES[i].x == TILES[i].x&&TILES[i].y==TILES[i].y)
	{
		//TILES[i].x += 64;
	}
	chap.push_back(&TILES[i]);
}
for (int i = 0; i < gt; i++)
{
	bullet[i].setDraw(blet,0,0,.1,.1,0,64,64,1,0,1,color,0,0,90,0,0,false);
	chap.push_back(&bullet[i]);
}


for (int i = 0; i < e; i++)
{
	monster1[i].setDraw(crazy, 0, 0, .1, .1, 0, 64, 64, 1, 0, 1, color, 0, 0, 90, 0, 0, false);
	//monster1[i].alive = false;
	//monster1[i].counter = rand() % 5 - 1;
	chap.push_back(&monster1[i]);
}
SCORE = new Draw[bell];
for (int i = 0; i < bell; i++)
{
	//SCORE[i].setDraw(Alpha, rand() % 400 + 1, 100, 1, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0);
	SCORE[0].setDraw(Alpha, 00, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0,0, true);
	SCORE[1].setDraw(Alpha, 40, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	SCORE[2].setDraw(Alpha, 80, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	SCORE[3].setDraw(Alpha, 120, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	SCORE[4].setDraw(Alpha, 160, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	SCORE[5].setDraw(Alpha, 200, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	SCORE[6].setDraw(Alpha, 240, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	SCORE[7].setDraw(Alpha, 280, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	SCORE[8].setDraw(Alpha, 320, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	SCORE[9].setDraw(Alpha, 360, 00, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	chap.push_back(&SCORE[i]);
}

//PDIRECT3DTEXTURE9 pic,float bx,float by,float bvelx,float bvely, int bframe, float bwidth, float bheight, float bscaling, float brotation,int bcolumns, D3DCOLOR bcolor, int bstartframe, int bendframe, int bdelay, int bstarttime, int bdirection

	tat = new Draw();
	pap = new Draw();
	ME = new Draw();

	tat->setDraw(Alpha, 300, 100, 0.00, 0.00, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);

	pap->setDraw(Alpha, 500, 100, 0, 0, 0, 64, 64, 1, 0, 10, color, 0, 0, 0, 0, 0, true);
	ME->setDraw(thing, 500, 500, .01, .01, 0, 64, 64, 1, 0, 4, color, 0, 0, 0, 0, 0, true);
	ME->player = true;

	chap.push_back(pap);
	chap.push_back(tat);
	chap.push_back(ME);
	return true;
}

void Game_Run(HWND window)
{
    //make sure the Direct3D device is valid
    if (!d3ddev) return;
    //update input devices
    DirectInput_Update();
    //clear the scene
    d3ddev->Clear(0, NULL, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, D3DCOLOR_XRGB(255,255,255), 1.0f, 0);	
	for (int i = 0; i < gt; i++)
	{
		ME->playerMove();
		//ME->rotation++;
		bullet[i].x += bullet[i].velx;
		bullet[i].y += bullet[i].vely;
		prj.shoot(bullet, ME);

		if (bullet[i].x < 0)bullet[i].alive = false;
		if (bullet[i].x>SCREENW - 64)bullet[i].alive = false;
		if (bullet[i].y < 0)bullet[i].alive = false;
		if (bullet[i].y>SCREENH - 64)bullet[i].alive = false;
	}
	for (int i = 0; i < e; i++)
	{
		monster1[i].x += monster1[i].velx;
		monster1[i].y += monster1[i].vely;
		if (monster1[i].x < 0)monster1[i].alive = false;
		if (monster1[i].x>SCREENW - 64)monster1[i].alive = false;
		if (monster1[i].y < 0)monster1[i].alive = false;
		if (monster1[i].y>SCREENH - 64)monster1[i].alive = false;
		spa.Spawn(monster1);
	}

	for (int i = 0; i < gt; i++)
	{
		for (int j = 0; j < e; j++)
		{
			if (monster1[i].alive&&bullet[i].alive)
			{
					if (prj.testCol(&bullet[i], &monster1[j], gt, e))
					{
						bullet[i].alive = false;
						monster1[j].alive = false;
						score+=5;
					}
			}
		}
	}

	for (int i = 0; i < bell; i++)
	{
		SCORE[9].frame = score;
		
		if (SCORE[9].frame >= 10)
		{
			SCORE[8].frame++;
			SCORE[9].frame = 0;
		}
		if (SCORE[8].frame >= 10)
		{
			SCORE[7].frame++;
			SCORE[8].frame = 0;
		}
		if (SCORE[7].frame >= 10)
		{
			SCORE[6].frame++;
			SCORE[7].frame = 0;
		}
		if (SCORE[6].frame >= 10)
		{
			SCORE[5].frame++;
			SCORE[6].frame = 0;
		}
		if (SCORE[5].frame >= 10)
		{
			SCORE[4].frame++;
			SCORE[5].frame = 0;
		}
		if (SCORE[4].frame >= 10)
		{
			SCORE[3].frame++;
			SCORE[4].frame = 0;
		}
		if (SCORE[3].frame >= 10)
		{
			SCORE[2].frame++;
			SCORE[3].frame = 0;
		}
		if (SCORE[2].frame >= 10)
		{
			SCORE[1].frame++;
			SCORE[2].frame = 0;
		}
		if (SCORE[1].frame >= 10)
		{
			SCORE[0].frame++;
			SCORE[1].frame = 0;
		}
		if (score >= 10)
		{
			score = 0;
		}
	}
		
	

	if(score==1)
	{
		level=2;
	}
	if (score == 2)
	{
		level = 3;
	}
    //start rendering
    if (d3ddev->BeginScene())
    {
		//d3ddev->StretchRect(Space,NULL,backbuffer,NULL,D3DTEXF_NONE);//background

		if(level==1)
		{
		level1.Draw();
		}
		else if(level==2)
		{
			level2.Draw();
		}
		else if (level == 3)
		{
			level3.Draw();
		}
        //*** insert sprite code here ***
		spriteobj->Begin(D3DXSPRITE_ALPHABLEND);





		//this draws all the objects in the vector
		for (it = chap.begin(); it != chap.end(); it++)
		{
			if ((*it)->alive)
			{
				(*it)->draw();
			}
		}


		spriteobj->End();
        //stop rendering
        d3ddev->EndScene();
        d3ddev->Present(NULL, NULL, NULL, NULL);
    }

    //exit when escape key is pressed
    if (KEY_DOWN(VK_ESCAPE)) gameover = true;

    //controller Back button also ends
    if (controllers[0].wButtons & XINPUT_GAMEPAD_BACK)
        gameover = true;
}

void Game_End()
{
    //free memory and shut down
	//delete Block,Pred,Prey,hp;
	chap.clear();
	for (unsigned int i = 0; i< chap.size(); i++){
		delete chap[i];
	}
    DirectInput_Shutdown();
    Direct3D_Shutdown();
}
