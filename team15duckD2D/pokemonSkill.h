#pragma once
#include "pokemonInfo.h"

enum POKEMON_SKILL_CATEGORY
{
	PMSC_ATTACK,
	PMSC_SPECAIL,
	PMSC_BUFF,

	PMSC_NONE,
	PMSC_COUNT = PMSC_NONE,
};


typedef struct tagPokemonSkill
{
	int _skillId;	// ��ų ��ȣ
	int _currentPP;	// ���� ���� ��ų�� ��
	int _maxPP;		// �ִ� ��ų�� ��

	void operator= (tagPokemonSkill skill)
	{
		_skillId = skill._skillId;
		_currentPP = skill._currentPP;
		_maxPP = skill._maxPP;
	}

	void clear()
	{
		_skillId = -1;
		_currentPP = 0;
		_maxPP = 0;
	}

}pmSkill;


class pokemonSkillInfo
{
private:
	int						_skillId;		// ��ų ��ȣ
	POKEMON_TYPE			_type;			// Ÿ��
	POKEMON_SKILL_CATEGORY	_category;		// �з�
	string					_description;	// ����

	POKEMON_UPSET_CONDITION _upsetConditionType;	// ���º�ȭ ȿ��

	int _power;			// ����
	int _accuracyRate;	// ���߷�
	int _defaultPP;		// pp

	// effect* _effect // ��ų ����


public:
	pokemonSkillInfo();
	~pokemonSkillInfo();

	// ��ų ��ȣ
	int						getSkillID() { return _skillId; }
	// Ÿ��
	POKEMON_TYPE			getSkillType() { return _type; }
	// �з�
	POKEMON_SKILL_CATEGORY	getSkillCategory() { return _category; }
	// ����
	string					getDescription() { return _description; }

	// ����
	int getPower() { return _power; }
	// ���߷�
	int getAccuracyRate() { return _accuracyRate; }
	// pp
	int getDefaultPP() { return _defaultPP; }
	// �����̻� ȿ��
	POKEMON_UPSET_CONDITION getUpsetConditionType() { return _upsetConditionType; }
};

class pokemonSkill
{
private:

	int						_skillId;		// ��ų ��ȣ
	pokemonSkillInfo		_info;			// ��ų ����

	int						_currentPP;		// ���� �ܿ���

	bool					_isPlayingEffect;// �������ΰ�

public:
	pokemonSkill();
	~pokemonSkill();

	// ��ų id
	HRESULT init(int skillId);
	void release();
	void update();
	void render();
	
	// ��ų �ܿ��� ���� : ex pp ȸ�� ������ ���
	void increaseCurrentPP(int value);
	// ��ų �ܿ��� ����
	void setCurrentPP(int value);

	// ��ų ��� : ��ų �ܿ��� �Ҹ�, ��ų ����Ʈ �ߵ�
	void useSkill();
	
	// ��ų ��� ����?
	bool isUsableSkill();
	// ���� ������ Ȯ��
	bool isPlayingEffect()	{ return _isPlayingEffect;}
	
	// �����̻� ȿ��
	pokemonUC* getUpsetCondition();
	
	// ��ų ���̵�
	int getSkillID() {return _skillId;}
	// ���� ��ų �ܿ���
	int getCurrentPP() { return _currentPP; }
	// ��ų ����
	const pokemonSkillInfo* getSkillInfomation() { return &_info;}

private:
	void playEffect();

};