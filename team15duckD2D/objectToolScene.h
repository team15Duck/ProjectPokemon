#pragma once
#include "gameNode.h"

class objectToolScene : public gameNode
{
private:

public:
	objectToolScene();
	~objectToolScene();

	HRESULT init();
	void release();
	void update();
	void render();
};

