#pragma once

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
public:
	pokemonSkill();
	~pokemonSkill();
};

