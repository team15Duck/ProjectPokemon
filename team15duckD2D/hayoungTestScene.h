#pragma once
#include "gameNode.h"
class hayoungTestScene : public gameNode
{

public:
	hayoungTestScene();
	~hayoungTestScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

