#pragma once
#include "pokemonInfo.h"
#include "pokemonSkill.h"


#define POKEMON_SKILL_MAX_COUNT 4

class pokemon
{
private:
	
	unsigned int _level;	// ����
	
	pokemonInfo* _info;

	tagPokemonStatus _defaultStatus;	// ���� ����
	tagPokemonStatus _currentStatus;	// ���� ����

	pokemonSkill* _skills[POKEMON_SKILL_MAX_COUNT];	// ��ų

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


};

