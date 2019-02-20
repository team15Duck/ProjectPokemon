#pragma once
#include "gameNode.h"
class loadScene : public gameNode
{
private:



public:
	loadScene();
	~loadScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

