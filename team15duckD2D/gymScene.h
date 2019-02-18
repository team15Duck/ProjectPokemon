#pragma once
#include "gymMap.h"
#include "gameNode.h"
#include "player.h"

class gymScene : public gameNode
{
private:
	mapData* _gymMap;
	player* _player;


public:
	gymScene();
	~gymScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

