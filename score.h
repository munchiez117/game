#include "MyDirectX.h"
class Score
{
private:
	int score;
	LPDIRECT3DSURFACE9 bck;
	int hpOne;
	int hpTen;
public:
	void SetScore();
	void level();
	void Loadback(LPDIRECT3DSURFACE9 bc);
	void Draw();
	int GetScore(int frame);
};
void Score::SetScore()
{
	score=0;
}
int Score::GetScore(int frame)
{
	
	score=score+1;
	if(score>=10)
	{
		score=0;
	}
	return score;
}
void Score::level()
{
	//d3ddev->StretchRect(Space,NULL,backbuffer,NULL,D3DTEXF_NONE);
}

void Score::Loadback(LPDIRECT3DSURFACE9 bc)
{
	bck=bc;
}

void Score::Draw()
{
	d3ddev->StretchRect(bck,NULL,backbuffer,NULL,D3DTEXF_NONE);
}
