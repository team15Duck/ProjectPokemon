#pragma once
#include "gameNode.h"
#include "objectTool.h"

class objectToolScene : public gameNode
{
private:
	objectTool* _objectTool;

public:
	objectToolScene();
	~objectToolScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

