#pragma once
#include "pokemonInfo.h"


class pokemonDataBase : public singletonBase<pokemonDataBase>
{
private:
	typedef map<POKEMON, pokemonInfo*> pokemonMap;

	pokemonMap _pokemonMap;

public:
	pokemonDataBase();
	~pokemonDataBase();

	HRESULT init();
	void release();

	const pokemonInfo* getPokemonInfomation(POKEMON pokemonIndex);

	// 능력치 계산 (레벨, 포켓몬 번호)
	pokemonStatus calculateStatus(int level, POKEMON pokemonId);
	// 레벨 level이 되는데 필요한 경험치
	int calcuateExp(int level, POKEMON pokemonId);

	// 전투 경험치
	//int calcuateBattleExp(int myLeve, int targetLevel, )

	// 타입 상성
	float calculateConflictValue(POKEMON myindex, POKEMON targetIndex);

private:
	// 능력치 계산 : HP
	int calculatorStatusType1(int level, int kindValue);
	// 능력치 계산 : HP외 전부
	int calculatorStatusType2(int level, int kindValue);
};

