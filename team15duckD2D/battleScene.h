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

	pokemon* _myPms[6];			// �÷��̾� ���ϸ�
	pokemon* _pokemon;			// �߻����ϸ�

	BattleStep _battleStep;			// ��Ʋ ����
	PlayerActive _active;			// �÷��̾� �ൿ

	pokemon* _pms[TURN_MAX + 1];	// �������� ���ϸ�

	battleUI* _battleUI;	// ui
	image* _background;		// ���
	int _frameX;			// ��� �̹��� ������
	int _frameY;			// ��� �̹��� ������

	EVOLUTIONPOKEMON _evPokemon;	// ��ȭ�ϴ� ����
	image* _pokemonImg;
	int _evolFrameX;
	int _evolFrameY;

	bool _isAwakeMyPokemon;
	bool _isAwakeEnemyPokemon;

	float _evolutionDisTime;	// ��ȭ ����� �ð�
	int _evolutionDisCount;		// ��ȭ ���� �� ī��Ʈ

	bool _isEvolution;			// 
	bool _isGetPokemon;			// ������� ����
	
	float _delayTime;

	UINT _selectSkillIdx;	// ���� �� ��ų ���� ��ȣ
	UINT _selPokemon;		// �������� ���ϸ� ���� ��ȣ

	bool _isBattleFin;		// ��Ʋ ����
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
