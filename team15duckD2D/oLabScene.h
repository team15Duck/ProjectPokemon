#pragma once
#include "oLabMap.h"
#include "gameNode.h"

class oLabScene : public gameNode
{
private:
	mapData* _oLabMap;


public:
	oLabScene();
	~oLabScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

