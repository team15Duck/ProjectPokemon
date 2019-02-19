#pragma once
#include "caveMap.h"
#include "gameNode.h"

class caveScene : public gameNode
{
private:
	mapData* _caveMap;


public:
	caveScene();
	~caveScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

