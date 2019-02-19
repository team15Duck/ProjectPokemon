#pragma once
#include "storeMap.h"
#include "gameNode.h"
#include "npc.h"

class storeScene : public gameNode
{
private:
	mapData* _storeMap;
	npc*	_npc;


public:
	storeScene();
	~storeScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

