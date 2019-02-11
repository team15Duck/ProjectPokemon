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
	int _skillId;	// 스킬 번호
	int _currentPP;	// 현재 남은 스킬의 수
	int _maxPP;		// 최대 스킬의 수

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

	int						_skillId;		// 스킬 번호
	POKEMON_TYPE			_type;			// 타입
	POKEMON_SKILL_CATEGORY	_category;		// 분류
	string					_description;	// 설명

	int _power;			// 위력
	int _accuracyRate;	// 명중률
	int _defaultPP;		// pp

	image* _effectImg;		// 이팩트 이미지
	animation* _effectAnim;	// 이펙트 애니메이션

public:
	pokemonSkill();
	~pokemonSkill();

	HRESULT init();
	void release();
	void update();
	void render();

	// 스킬 번호
	int						getSkillID()		{ return _skillId;		}
	// 타입
	POKEMON_TYPE			getSkillType()		{ return _type;			}	
	// 분류
	POKEMON_SKILL_CATEGORY	getSkillCategory()	{ return _category;		}	
	// 설명
	string					getDescription()	{ return _description;	}	

	// 위력
	int getPower()			{ return _power; }			
	// 명중률
	int getAccuracyRate()	{ return _accuracyRate; }	
	// pp
	int getDefaultPP()		{ return _defaultPP; }		


private:
	void playEffect();

};

