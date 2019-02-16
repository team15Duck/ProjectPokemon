#pragma once
#include "battle.h"
#include <set>
#include "gameNode.h"
#include "pokemon.h"
#include "battleUI.h"

//포켓몬과배틀
class battleScene : public gameNode
{
private:

	BattlePhase _phase;			//배틀 단계 정보			
	BattleTurn _turn;			//턴
	set<UINT> _expList;			//경험치 받을 포켓몬 리스트 
								//적이 죽을때마다 클리어되고 현재 포켓몬이 추가됨.

	pokemon* _pokemon;

	BattleStep _battleStep;			// 배틀 스텝
	PlayerActive _active;			// 플레이어 행동

	pokemon* _pms[TURN_MAX + 1];	// 테스트용임 삭제 될 것

	battleUI* _battleUI;
public:
	battleScene();
	~battleScene();


	HRESULT init();
	void release();
	void update();
	void render();


	void keyControl();


private:

	// 배틀 시작
	void battleStart();
	// 배틀
	void battle();
	// 배틀 종료
	void battleEnd();
	// 교체
	void battleChange();
	// 진화
	void battleEvolution();
};
