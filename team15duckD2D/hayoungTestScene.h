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

	//					가로개수	  새로개수		크기				위치			위치		
	D2D1_RECT_F uiframeMake(int width, int height, float size, float positionX, float positionY);
	void uiframeRender(int width, int height, float left, float top);
	void frameImageinit();

};

