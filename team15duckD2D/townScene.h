#pragma once
#include "townMap.h"
#include "gameNode.h"

class townScene : public gameNode
{
private:
	mapData* _townMap;
	
public:
	townScene();
	~townScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

