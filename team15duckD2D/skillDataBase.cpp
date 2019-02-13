#include "stdafx.h"
#include "skillDataBase.h"


skillDataBase::skillDataBase()
{
}


skillDataBase::~skillDataBase()
{
}

HRESULT skillDataBase::init()
{
	int id = -1;
	POKEMON_TYPE type = PM_TYPE_NONE;
	POKEMON_SKILL_CATEGORY category = PMSC_NONE;
	string txt = "";
	string name = "";
	POKEMON_UPSET_CONDITION condition = PMUC_NONE;

	int power = 0;
	int rate = 0;
	int pp = 0;


	// 몸통박치기
	{
		id = 33;
		type = PM_TYPE_NORMAL;
		category = PMSC_ATTACK;
		txt = "상대를 향해서 몸 전체를 부딪쳐가며 공격한다.";
		name = "몸통박치기";
		condition = PMUC_NONE;

		power = 10;
		rate = 100;
		pp = 35;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}



	return S_OK;
}

void skillDataBase::release()
{
	for (auto iter = _skillMap.begin(); _skillMap.end() != iter;)
	{
		if (nullptr != iter->second)
		{
			pokemonSkillInfo* info = iter->second;
			iter = _skillMap.erase(iter);

			SAFE_DELETE(info);
		}
		else
			++iter;
	}

	_skillMap.clear();

}

pokemonSkillInfo* skillDataBase::getPokemonSkillinfo(int skillId)
{
	pokemonSkillInfo* info = nullptr;

	if(_skillMap.end() != _skillMap.find(skillId))
		info = _skillMap[skillId];

	return info;
}
