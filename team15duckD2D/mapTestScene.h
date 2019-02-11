#pragma once
#include "testMap.h"
#include "gameNode.h"

class mapTestScene : public gameNode
{
private:
	mapData* _testMap;



public:
	mapTestScene();
	~mapTestScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

