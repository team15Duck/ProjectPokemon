#pragma once
#include "battle.h"
#include <set>
#include "gameNode.h"
#include "pokemon.h"
#include "battleUI.h"

typedef struct tagEvolutionPokemon
{
	UINT index;
	int curFrameX;
	int curFrameY;

	int evolutionFrameX;
	int evolutionFrameY;

	void operator=(tagEvolutionPokemon pm)
	{
		index = pm.index;
		curFrameX = pm.curFrameX;
		curFrameY = pm.curFrameY;
		
		evolutionFrameX = pm.evolutionFrameX;
		evolutionFrameY = pm.evolutionFrameY;
	}

}EVOLUTIONPOKEMON;

//���ϸ����Ʋ
class battleScene : public gameNode
{
private:

	BattlePhase _phase;			//��Ʋ �ܰ� ����			
	BattleTurn _turn;			//��
	set<UINT> _expList;			//����ġ ���� ���ϸ� ����Ʈ 
								//���� ���������� Ŭ����ǰ� ���� ���ϸ��� �߰���.

	pokemon* _myPms[6];			// �÷��̾� ���ϸ�
	pokemon* _pokemon;			// �߻����ϸ�

	BattleStep _battleStep;			// ��Ʋ ����
	PlayerActive _active;			// �÷��̾� �ൿ

	pokemon* _pms[TURN_MAX + 1];	// �������� ���ϸ�

	battleUI* _battleUI;	// ui
	image* _background;		// ���
	int _frameX;			// ��� �̹��� ������
	int _frameY;			// ��� �̹��� ������

	EVOLUTIONPOKEMON _evPokemon;
	image* _pokemonImg;
	int _evolFrameX;
	int _evolFrameY;

	float _evolutionDisTime;	// ��ȭ ����� �ð�
	int _evolutionDisCount;		// ��ȭ ���� �� ī��Ʈ

	bool _isEvolution;
	bool _isEvolutinFin;

	UINT _selectSkillIdx;	// ���� �� ��ų ���� ��ȣ
	UINT _selPokemon;		// �������� ���ϸ� ���� ��ȣ
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
