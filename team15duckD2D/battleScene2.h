#pragma once
#include "battle.h"
#include "gameNode.h"
//NPC�� ��Ʋ
class battleScene2 : public gameNode
{
private:

	BattlePhase _phase;
	int _turn;




public:
	battleScene2();
	~battleScene2();



	HRESULT init();
	void release();
	void update();
	void render();
};

