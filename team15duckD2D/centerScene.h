#pragma once
#include "centerMap.h"
#include "gameNode.h"
#include "player.h"

class centerScene : public gameNode
{
private:
	mapData* _centerMap;
	player* _player;


public:
	centerScene();
	~centerScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

