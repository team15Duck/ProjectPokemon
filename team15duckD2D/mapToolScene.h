#pragma once
#include "gameNode.h"
#include "mapTool.h"

class mapToolScene : public gameNode
{
private:

public:
	mapToolScene();
	~mapToolScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

