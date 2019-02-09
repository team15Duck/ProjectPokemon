#pragma once

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
public:
	pokemonSkill();
	~pokemonSkill();
};

