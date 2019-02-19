#pragma once
#include "gameNode.h"

class hpBar : public gameNode
{
private:
	
	D2D1_RECT_F _hpBar;

	float _x;			//좌표
	float _y;			//크기
	float _width;		//가로크기
	float _maxwidht;	//최대가로크기
	float _height;		//세로크기

	string _imgName;
	bool _isbottomuse;
public:
	hpBar();
	~hpBar();

	HRESULT init(string imgname, int framX, int framY, int x, int y, int width, int height, bool isbottomuse);
	void release();
	void update();
	void render();

	void setHPbar(float currentHP, float maxHP);

	void setX(int x) { _x = x; }
	void setY(int y) { _y = y; }
};

