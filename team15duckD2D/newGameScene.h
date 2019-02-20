#pragma once
#include "gameNode.h"

class newGameScene : public gameNode
{
public:
	newGameScene();
	~newGameScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

