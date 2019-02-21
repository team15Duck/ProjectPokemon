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

	pokemon* _myPms[6];			// 플레이어 포켓몬
	pokemon* _pokemon;			// 야생포켓몬

	BattleStep _battleStep;			// 배틀 스텝
	PlayerActive _active;			// 플레이어 행동

	pokemon* _pms[TURN_MAX + 1];	// 출전중인 포켓몬

	battleUI* _battleUI;	// ui
	image* _background;		// 배경
	int _frameX;			// 배경 이미지 프레임
	int _frameY;			// 배경 이미지 프레임

	EVOLUTIONPOKEMON _evPokemon;	// 진화하는 정보
	image* _pokemonImg;
	int _evolFrameX;
	int _evolFrameY;

	bool _isAwakeMyPokemon;
	bool _isAwakeEnemyPokemon;

	float _evolutionDisTime;	// 진화 연출용 시간
	int _evolutionDisCount;		// 진화 연출 용 카운트

	bool _isEvolution;			// 
	bool _isGetPokemon;			// 포멧몬을 잡음
	
	float _delayTime;

	UINT _selectSkillIdx;	// 선택 된 스킬 슬롯 번호
	UINT _selPokemon;		// 출전중인 포켓몬 슬롯 번호

	bool _isBattleFin;		// 배틀 종료
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
