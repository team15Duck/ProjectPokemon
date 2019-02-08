#pragma once
#include "pokemonInfo.h"
#include "pokemonSkill.h"
#include "item.h"


#define POKEMON_SKILL_MAX_COUNT 4

typedef struct tagPokemonSkill
{
	int _skillId;	// ��ų ��ȣ
	int _currentPP;	// ���� ���� ��ų�� ��
	int _maxPP;		// �ִ� ��ų�� ��
}pmSkill;

// ���̺�� ������
typedef struct tagPokemonPackage
{
	unsigned int _idNo;				// ���� ��ȣ
	unsigned int _index;			// ���� ��ȣ

	string _name;					// �̸�
	string _trainerNote;			// Ʈ���̳� ��Ʈ

	unsigned int _level;			// ����
	unsigned int _currentExp;		// ���� ����ġ

	unsigned int _upsetCondition;	// �����̻�
	
	// ���� ���°���
	unsigned int _hp;			// ü��
	unsigned int _attk;			// ���ݷ�
	unsigned int _dex;			// ����
	unsigned int _spAttk;		// Ư�� ���ݷ�
	unsigned int _spDex;		// Ư�� ����

	unsigned int _speed;		// �ӵ�
	
	int _skillIds[POKEMON_SKILL_MAX_COUNT];		// ��ų ��ȣ
	int _currentPPs[POKEMON_SKILL_MAX_COUNT];	// ���� ���� ��ų�� ��
	int _maxPPs[POKEMON_SKILL_MAX_COUNT];		// �ִ� ��ų�� ��

}pmPack;

// ���ϸ�
class pokemon
{
private:
	
	unsigned int _idNo;							// ���� ��ȣ
	POKEMON _index;								// ���� ��ȣ

	string _name;								// �̸�
	string _trainerNote;						// Ʈ���̳� ��Ʈ
	
	unsigned int _level;						// ����
	unsigned int _currentExp;					// ���� ����ġ
	unsigned int _nextExp;						// ���� �������� �ʿ��� ����ġ

	bool _isAwake;								// ���� �ִ°�, �������� �ʾҴ°�
	
	POKEMON_UPSET_CONDITION _upsetCondition;	// �����̻�
	pokemonStatus			_defaultStatus;		// ���� status
	pokemonStatus			_currentStatus;		// ���� status

	pmSkill _skills[POKEMON_SKILL_MAX_COUNT];	// ��ų

	animation* _anim;	// �ִϸ��̼�

public:
	pokemon();
	~pokemon();

	//pokemonInfo* _info;
	//
	//unsigned int _level;	// ����
	//
	//int getHp;			// ü��
	//int getMaxHp() {return }
	//int getattk;			// ���ݷ�
	//int getdex;			// ����
	//int getspAttk;		// Ư�� ���ݷ�
	//int getspDex;			// Ư�� ����
	//	get
	//int getspeed;			// �ӵ�

	
	pmPack makeSavePack();
	void loadSavePack(pmPack* pack);

};

