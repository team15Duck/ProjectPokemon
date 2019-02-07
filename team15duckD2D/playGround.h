#pragma once
#include "gameNode.h"


class playGround : public gameNode
{
private:
	int _count;
	int _index;

public:
	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();


	playGround();
	~playGround();
};