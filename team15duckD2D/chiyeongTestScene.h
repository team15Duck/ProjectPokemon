#pragma once
#include "gameNode.h"

class chiyeongTestScene : public gameNode
{
public:
	chiyeongTestScene();
	~chiyeongTestScene();

	HRESULT init();
	void release();
	void update();
	void render();
	
};

