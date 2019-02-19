#pragma once
#include "centerMap.h"
#include "gameNode.h"
#include "npc.h"


class centerScene : public gameNode
{
private:
	mapData* _centerMap;
	npc*	_npc;


public:
	centerScene();
	~centerScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

