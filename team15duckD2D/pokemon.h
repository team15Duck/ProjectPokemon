#pragma once
#include "pokemonInfo.h"
#include "pokemonSkill.h"
#include "item.h"


#define POKEMON_SKILL_MAX_COUNT 4

typedef struct tagPokemonSkill
{
	int _skillId;	// 스킬 번호
	int _currentPP;	// 현재 남은 스킬의 수
	int _maxPP;		// 최대 스킬의 수
}pmSkill;

// 세이브용 데이터
typedef struct tagPokemonPackage
{
	unsigned int _idNo;				// 고유 번호
	unsigned int _index;			// 도감 번호

	string _name;					// 이름
	string _trainerNote;			// 트레이너 노트

	unsigned int _level;			// 레벨
	unsigned int _currentExp;		// 현재 경험치

	unsigned int _upsetCondition;	// 상태이상
	
	// 현재 상태값들
	unsigned int _hp;			// 체력
	unsigned int _attk;			// 공격력
	unsigned int _dex;			// 방어력
	unsigned int _spAttk;		// 특수 공격력
	unsigned int _spDex;		// 특수 방어력

	unsigned int _speed;		// 속도
	
	int _skillIds[POKEMON_SKILL_MAX_COUNT];		// 스킬 번호
	int _currentPPs[POKEMON_SKILL_MAX_COUNT];	// 현재 남은 스킬의 수
	int _maxPPs[POKEMON_SKILL_MAX_COUNT];		// 최대 스킬의 수

}pmPack;

// 포켓몬
class pokemon
{
private:
	
	unsigned int _idNo;							// 고유 번호
	POKEMON _index;								// 도감 번호

	string _name;								// 이름
	string _trainerNote;						// 트레이너 노트
	
	unsigned int _level;						// 레벨
	unsigned int _currentExp;					// 현재 경험치
	unsigned int _nextExp;						// 다음 레벨까지 필요한 경험치

	bool _isAwake;								// 깨어 있는가, 기절하지 않았는가
	
	POKEMON_UPSET_CONDITION _upsetCondition;	// 상태이상
	pokemonStatus			_defaultStatus;		// 원래 status
	pokemonStatus			_currentStatus;		// 현재 status

	pmSkill _skills[POKEMON_SKILL_MAX_COUNT];	// 스킬

	animation* _anim;	// 애니메이션

public:
	pokemon();
	~pokemon();

	//pokemonInfo* _info;
	//
	//unsigned int _level;	// 레벨
	//
	//int getHp;			// 체력
	//int getMaxHp() {return }
	//int getattk;			// 공격력
	//int getdex;			// 방어력
	//int getspAttk;		// 특수 공격력
	//int getspDex;			// 특수 방어력
	//	get
	//int getspeed;			// 속도

	
	pmPack makeSavePack();
	void loadSavePack(pmPack* pack);

};

