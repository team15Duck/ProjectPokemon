#pragma once
#include "oLabMap.h"
#include "gameNode.h"
#include "npc.h"

class oLabScene : public gameNode
{
private:
	mapData* _oLabMap;
	npc*	_npc;


public:
	oLabScene();
	~oLabScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

