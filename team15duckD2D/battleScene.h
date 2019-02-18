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

	BattleStep _battleStep;			// ��Ʋ ����
	PlayerActive _active;			// �÷��̾� �ൿ

	pokemon* _pms[TURN_MAX + 1];	// �׽�Ʈ���� ���� �� ��

	battleUI* _battleUI;

	UINT _selectSkillIdx;
public:
	battleScene();
	~battleScene();


	HRESULT init();
	void release();
	void update();
	void render();


	void keyControl();


private:

	// ��Ʋ ����
	void battleStart();
	// ��Ʋ
	void battle();
	// ��Ʋ ����
	void battleEnd();
	// ��ü
	void battleChange();
	// ��ȭ
	void battleEvolution();
};
