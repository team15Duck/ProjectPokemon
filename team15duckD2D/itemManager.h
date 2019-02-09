#pragma once
#include "gameNode.h"
class itemManager :
	public gameNode
{
public:
	itemManager();
	~itemManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

