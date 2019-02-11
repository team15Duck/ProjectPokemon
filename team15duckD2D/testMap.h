#pragma once
#include "mapData.h"

class testMap : public mapData
{
private:
	mapData* _map;
public:
	testMap();
	~testMap();

	HRESULT init();
	void release();
	void update();
	void render();
};

