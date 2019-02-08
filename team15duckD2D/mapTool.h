#pragma once
#include "tileNode.h"

class mapTool
{
private:
	//vector<vector<tagTile*> _tiles


public:
	mapTool();
	~mapTool();
	
	unsigned int TILEX;
	unsigned int TILEY;
	
	HRESULT init();
	void release();
	void update();
	void render();





};

