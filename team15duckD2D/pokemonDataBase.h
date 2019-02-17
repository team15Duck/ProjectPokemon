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

	pokemonInfo* getPokemonInfomation(POKEMON pokemonIndex);

	// �ɷ�ġ ��� (����, ���ϸ� ��ȣ)
	pokemonStatus calculateStatus(int level, POKEMON pokemonId);
	// ���� level�� �Ǵµ� �ʿ��� ����ġ
	int calcuateExp(int level, POKEMON pokemonId);

	// ���� ����ġ
	//int calcuateBattleExp(int myLeve, int targetLevel, )

	// Ÿ�� �� Ȯ��
	SKILL_INFLUENCE checkConflict(POKEMON_TYPE skillType, POKEMON targetIndex);

private:
	// �ɷ�ġ ��� : HP
	int calculatorStatusType1(int level, int kindValue);
	// �ɷ�ġ ��� : HP�� ����
	int calculatorStatusType2(int level, int kindValue);
};

