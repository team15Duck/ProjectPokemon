#pragma once
#include "caveMap.h"
#include "gameNode.h"
#include "player.h"

class caveScene : public gameNode
{
private:
	mapData* _caveMap;
	player* _player;


public:
	caveScene();
	~caveScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

