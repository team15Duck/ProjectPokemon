#pragma once
#include "centerMap.h"
#include "gameNode.h"


class centerScene : public gameNode
{
private:
	mapData* _centerMap;


public:
	centerScene();
	~centerScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

