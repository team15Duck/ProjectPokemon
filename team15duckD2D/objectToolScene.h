#pragma once
#include "gameNode.h"
#include "objectTool.h"
#include "testMap.h"

class objectToolScene : public gameNode
{
private:
	objectTool* _objectTool;
	mapData* _testMap;

public:
	objectToolScene();
	~objectToolScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

