#pragma once
#include "storeMap.h"
#include "gameNode.h"
#include "player.h"

class storeScene : public gameNode
{
private:
	mapData* _storeMap;
	player* _player;


public:
	storeScene();
	~storeScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

