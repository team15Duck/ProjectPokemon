#pragma once
#include "pokemonSkill.h"

class skillDataBase : public singletonBase<skillDataBase>
{
private:
public:
	skillDataBase();
	~skillDataBase();

	const pokemonSkillInfo* getPokemonSkillinfo(int skillId);
};

