#pragma once
#include "fieldMap.h"
#include "gameNode.h"

class fieldScene : public gameNode
{
private:
	mapData* _fieldMap;



public:
	fieldScene();
	~fieldScene();

	HRESULT init();
	void release();
	void update();
	void render();


};

