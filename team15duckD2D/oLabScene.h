#pragma once
#include "oLabMap.h"
#include "gameNode.h"
#include "player.h"

class oLabScene : public gameNode
{
private:
	mapData* _oLabMap;
	player* _player;


public:
	oLabScene();
	~oLabScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

