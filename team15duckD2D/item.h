#pragma once
#include "gameNode.h"
class item : public gameNode
{
public:
	item();
	~item();

	HRESULT init();
	void release();
	void update();
	void render();
};

