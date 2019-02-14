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
	SKILL_INDEX id = SKILL_INDEX_NONE;
	POKEMON_TYPE type = PM_TYPE_NONE;
	POKEMON_SKILL_CATEGORY category = PMSC_NONE;
	string txt = "";
	string name = "";
	POKEMON_UPSET_CONDITION condition = PMUC_NONE;
	POKEMON_BUFF buff = PMB_NONE;

	int power = 0;
	int rate = 0;
	int pp = 0;


	// 몸통박치기
	{
		id = TACLE;
		type = PM_TYPE_NORMAL;
		category = PMSC_ATTACK;
		txt = "상대를 향해서 몸 전체를 부딪쳐가며 공격한다.";
		name = "몸통박치기";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 10;
		rate = 100;
		pp = 35;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 씨뿌리기
	{
		id = LEECH_SEEd;
		type = PM_TYPE_GRASS;
		category = PMSC_BUFF;
		txt = "씨가 뿌려진 상대의 HP를 매 턴 조금씩 흡수하여 자신의 HP를 회복한다.";
		name = "씨뿌리기";
		condition = PMUC_POISON;
		buff = PMB_ABSORB_HP;

		power = 0;
		rate = 90;
		pp = 10;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 덩쿨채찍
	{
		id = VINE_WHIP;
		type = PM_TYPE_GRASS;
		category = PMSC_ATTACK;
		txt = "채찍처럼 휘어지는 가늘고 긴 덩굴로 상대를 힘껏 쳐서 공격한다.";
		name = "덩쿨채찍";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 45;
		rate = 100;
		pp = 15;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 독가루
	{
		id = POISON_POWDER;
		type = PB_TYPE_POISION;
		category = PMSC_BUFF;
		txt = "독이 있는 가루를 많이 흩뿌려서 상대를 독 상태로 만든다.";
		name = "독가루";
		condition = PMUC_POISON;
		buff = PMB_NONE;

		power = 0;
		rate = 75;
		pp = 30;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 수면가루
	{
		id = SLEEP_POWDER;
		type = PM_TYPE_GRASS;
		category = PMSC_BUFF;
		txt = "잠이 오는 가루를 많이 흩뿌려서 상대를 잠듦 상태로 만든다.";
		name = "수면가루";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 0;
		rate = 75;
		pp = 15;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 잎날 가르기
	{
		id = RAZOR_LEAF;
		type = PM_TYPE_GRASS;
		category = PMSC_ATTACK;
		txt = "잎사귀를 날려 상대를 베어 공격한다. 급소에 맞을 확률이 높다.";
		name = "잎날 가르기";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 55;
		rate = 95;
		pp = 25;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

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
