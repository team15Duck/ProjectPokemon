#pragma once
#include "storeMap.h"
#include "gameNode.h"
#include "npc.h"

class storeScene : public gameNode
{
private:
	mapData* _storeMap;
	npc*	_npc;

	bool	_test;


public:
	storeScene();
	~storeScene();

	HRESULT init();
	void release();
	void update();
	void render();

	//�������� ��ȭ
	void activeShopOwner();

};

