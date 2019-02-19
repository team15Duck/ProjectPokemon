#pragma once
#include "storeMap.h"
#include "gameNode.h"

class storeScene : public gameNode
{
private:
	mapData* _storeMap;
	


public:
	storeScene();
	~storeScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

