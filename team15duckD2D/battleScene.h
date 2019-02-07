#pragma once
#include "battle.h"
#include <set>
#include "gameNode.h"
//���ϸ����Ʋ
class battleScene : public gameNode
{
private:

	BattlePhase _phase;			//��Ʋ �ܰ� ����			
	BattleTurn _turn;			//��
	set<UINT> _expList;			//����ġ ���� ���ϸ� ����Ʈ 
								//���� ���������� Ŭ����ǰ� ���� ���ϸ��� �߰���.

public:
	battleScene();
	~battleScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

