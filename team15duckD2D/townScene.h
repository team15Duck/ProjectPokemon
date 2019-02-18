#pragma once
#include "townMap.h"
#include "gameNode.h"
#include "player.h"

class townScene : public gameNode
{
private:
	mapData* _townMap;
	player* _player;

public:
	townScene();
	~townScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

