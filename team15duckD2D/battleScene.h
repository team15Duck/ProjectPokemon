#pragma once
#include "battle.h"
#include <list>
#include "gameNode.h"
//포켓몬과배틀
class battleScene : public gameNode
{
private:

	BattlePhase _phase;			//배틀 단계 정보			
	BattleTurn _turn;			//턴
	UINT _exp[6];				//경험치 분배 전 총 경험치 저장
	list<UINT> _expList;		//경험치 받을 포켓몬 리스트 
								//적이 죽을때마다 클리어되고 현재 포켓몬이 추가됨.

public:
	battleScene();
	~battleScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

