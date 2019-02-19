#pragma once
#include "gymMap.h"
#include "gameNode.h"
#include "npc.h"

class gymScene : public gameNode
{
private:
	mapData* _gymMap;
	npc*	_npc;


public:
	gymScene();
	~gymScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

