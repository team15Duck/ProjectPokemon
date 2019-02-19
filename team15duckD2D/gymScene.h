#pragma once
#include "gymMap.h"
#include "gameNode.h"

class gymScene : public gameNode
{
private:
	mapData* _gymMap;


public:
	gymScene();
	~gymScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

