#pragma once
#include "homeMap.h"
#include "gameNode.h"
#include "player.h"

class homeScene : public gameNode
{
private:
	mapData* _homeMap;
	player* _player;


public:
	homeScene();
	~homeScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

