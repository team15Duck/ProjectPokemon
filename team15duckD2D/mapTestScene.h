#pragma once
#include "testMap.h"
#include "gameNode.h"
#include "player.h"

class mapTestScene : public gameNode
{
private:
	mapData* _testMap;
	player* _player;


public:
	mapTestScene();
	~mapTestScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

