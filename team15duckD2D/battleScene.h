#pragma once
#include "battle.h"
#include "gameNode.h"
//포켓몬과배틀
class battleScene : public gameNode
{
private:

	BattlePhase _phase;
	int _turn;


public:
	battleScene();
	~battleScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

