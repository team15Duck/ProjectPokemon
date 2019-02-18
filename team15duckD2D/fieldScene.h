#pragma once
#include "fieldMap.h"
#include "gameNode.h"
#include "player.h"

class fieldScene : public gameNode
{
private:
	mapData* _fieldMap;
	player* _player;


public:
	fieldScene();
	~fieldScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

