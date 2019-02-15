#pragma once
#include "battle.h"
#include <set>
#include "gameNode.h"
#include "pokemon.h"
#include "battleUI.h"

//���ϸ����Ʋ
class battleScene : public gameNode
{
private:

	BattlePhase _phase;			//��Ʋ �ܰ� ����			
	BattleTurn _turn;			//��
	set<UINT> _expList;			//����ġ ���� ���ϸ� ����Ʈ 
								//���� ���������� Ŭ����ǰ� ���� ���ϸ��� �߰���.

	pokemon* _pokemon;

	pokemon* _pms[TURN_MAX + 1];	// �׽�Ʈ���� ���� �� ��
	int cnt;						// �׽�Ʈ���� ���� �� ��
	float termTime;

	battleUI* _battleUI;
public:
	battleScene();
	~battleScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

