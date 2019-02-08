#pragma once
#include "pokemonInfo.h"
#include "pokemonSkill.h"


#define POKEMON_SKILL_MAX_COUNT 4

class pokemon
{
private:
	
	unsigned int _level;	// 레벨
	
	pokemonInfo* _info;

	tagPokemonStatus _defaultStatus;	// 원래 상태
	tagPokemonStatus _currentStatus;	// 현재 상태

	pokemonSkill* _skills[POKEMON_SKILL_MAX_COUNT];	// 스킬

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


};

