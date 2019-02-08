#pragma once
#include "gameNode.h"

enum MENU_DIRECTION
{
	MD_LT, MD_RT, MD_LB, MD_RB, MD_L, MD_R, MD_T, MD_B, MD_NONE
};



struct tagMenuFrameInfo
{
	D2D1_RECT_F rc;
	MENU_DIRECTION direction;
};

class hayoungTestScene : public gameNode
{
private:
	D2D1_RECT_F _rc;
	D2D1_RECT_F _test[150];

public:
	hayoungTestScene();
	~hayoungTestScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void frameImageinit();

};

