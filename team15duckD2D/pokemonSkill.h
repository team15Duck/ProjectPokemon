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


class pokemonSkillInfo
{
private:
	int						_skillId;		// 스킬 번호
	POKEMON_TYPE			_type;			// 타입
	POKEMON_SKILL_CATEGORY	_category;		// 분류
	string					_description;	// 설명

	POKEMON_UPSET_CONDITION _upsetConditionType;	// 상태변화 효과

	int _power;			// 위력
	int _accuracyRate;	// 명중률
	int _defaultPP;		// pp

	// effect* _effect // 스킬 연출


public:
	pokemonSkillInfo();
	~pokemonSkillInfo();

	// 스킬 번호
	int						getSkillID() { return _skillId; }
	// 타입
	POKEMON_TYPE			getSkillType() { return _type; }
	// 분류
	POKEMON_SKILL_CATEGORY	getSkillCategory() { return _category; }
	// 설명
	string					getDescription() { return _description; }

	// 위력
	int getPower() { return _power; }
	// 명중률
	int getAccuracyRate() { return _accuracyRate; }
	// pp
	int getDefaultPP() { return _defaultPP; }
	// 상태이상 효과
	POKEMON_UPSET_CONDITION getUpsetConditionType() { return _upsetConditionType; }
};

class pokemonSkill
{
private:

	int						_skillId;		// 스킬 번호
	pokemonSkillInfo		_info;			// 스킬 정보

	int						_currentPP;		// 현재 잔여량

	bool					_isPlayingEffect;// 연출중인가

public:
	pokemonSkill();
	~pokemonSkill();

	// 스킬 id
	HRESULT init(int skillId);
	void release();
	void update();
	void render();
	
	// 스킬 잔여량 증가 : ex pp 회복 아이템 사용
	void increaseCurrentPP(int value);
	// 스킬 잔여량 세팅
	void setCurrentPP(int value);

	// 스킬 사용 : 스킬 잔여량 소모, 스킬 이펙트 발동
	void useSkill();
	
	// 스킬 사용 가능?
	bool isUsableSkill();
	// 연출 중인지 확인
	bool isPlayingEffect()	{ return _isPlayingEffect;}
	
	// 상태이상 효과
	pokemonUC* getUpsetCondition();
	
	// 스킬 아이디
	int getSkillID() {return _skillId;}
	// 현재 스킬 잔여량
	int getCurrentPP() { return _currentPP; }
	// 스킬 정보
	const pokemonSkillInfo* getSkillInfomation() { return &_info;}

private:
	void playEffect();

};