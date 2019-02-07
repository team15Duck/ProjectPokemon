#pragma once
#include "gameNode.h"

class chiyeongTestScene : public gameNode
{
private:
	D2D1_RECT_F _rc[9];
	int _count;
	bool _start;
	float _angle[9];
public:
	chiyeongTestScene();
	~chiyeongTestScene();

	HRESULT init();
	void release();
	void update();
	void render();
	
};

