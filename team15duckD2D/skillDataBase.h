#pragma once
#include "pokemonSkill.h"

class skillDataBase : public singletonBase<skillDataBase>
{
private:

	map<unsigned int, pokemonSkillInfo*> _skillMap;

public:
	skillDataBase();
	~skillDataBase();

	HRESULT init();
	void release();

	pokemonSkillInfo* getPokemonSkillinfo(int skillId);
};

