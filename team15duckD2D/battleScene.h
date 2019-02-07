#pragma once
#include "battle.h"
#include <list>
#include "gameNode.h"
//���ϸ����Ʋ
class battleScene : public gameNode
{
private:

	BattlePhase _phase;			//��Ʋ �ܰ� ����			
	BattleTurn _turn;			//��
	UINT _exp[6];				//����ġ �й� �� �� ����ġ ����
	list<UINT> _expList;		//����ġ ���� ���ϸ� ����Ʈ 
								//���� ���������� Ŭ����ǰ� ���� ���ϸ��� �߰���.

public:
	battleScene();
	~battleScene();


	HRESULT init();
	void release();
	void update();
	void render();

};

