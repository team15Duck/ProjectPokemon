#pragma once
#include "gameNode.h"
#include "mapData.h"
#include "player.h"

class chiyeongTestScene : public gameNode
{
private:
	D2D1_RECT_F _rc[9];
	int _count;
	bool _start;
	float _angle[9];
	float _scale;
	D2D1_RECT_F _rc2;
public:
	chiyeongTestScene();
	~chiyeongTestScene();

	HRESULT init();
	void release();
	void update();
	void render();
	
};

