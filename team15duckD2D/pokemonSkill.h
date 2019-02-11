#pragma once
#include "pokemonInfo.h"

enum POKEMON_SKILL_CATEGORY
{
	PMS_ATTACK,
	PMS_SPECAIL,
	PMS_BUFF,

	PMS_NONE,
	PMS_COUNT = PMS_NONE,
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


class pokemonSkill
{
private:

	int						_skillId;		// ��ų ��ȣ
	POKEMON_TYPE			_type;			// Ÿ��
	POKEMON_SKILL_CATEGORY	_category;		// �з�
	string					_description;	// ����

	int _power;			// ����
	int _accuracyRate;	// ���߷�
	int _defaultPP;		// pp

	image* _effectImg;		// ����Ʈ �̹���
	animation* _effectAnim;	// ����Ʈ �ִϸ��̼�

public:
	pokemonSkill();
	~pokemonSkill();

	HRESULT init();
	void release();
	void update();
	void render();

	// ��ų ��ȣ
	int						getSkillID()		{ return _skillId;		}
	// Ÿ��
	POKEMON_TYPE			getSkillType()		{ return _type;			}	
	// �з�
	POKEMON_SKILL_CATEGORY	getSkillCategory()	{ return _category;		}	
	// ����
	string					getDescription()	{ return _description;	}	

	// ����
	int getPower()			{ return _power; }			
	// ���߷�
	int getAccuracyRate()	{ return _accuracyRate; }	
	// pp
	int getDefaultPP()		{ return _defaultPP; }		


private:
	void playEffect();

};

