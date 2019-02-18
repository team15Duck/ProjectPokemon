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


	// 할퀴기
	{
		id = SCRATCH;
		type = PM_TYPE_NORMAL;
		category = PMSC_ATTACK;
		txt = "단단하고 뾰족한 날카로운 손톱으로 상대를 할퀴어서 공격한다.";
		name = "할퀴기";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 35;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 불꽃세례
	{
		id = EMBER;
		type = PM_TYPE_FIRE;
		category = PMSC_SPECAIL;
		txt = "작은 불꽃을 상대에게 발사하여 공격한다. 화상 상태로 만들 때가 있다.";
		name = "불꽃세례";
		condition = PMUC_BURN;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 25;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 화염방사
	{
		id = FLAMETHROWER;
		type = PM_TYPE_FIRE;
		category = PMSC_SPECAIL;
		txt = "세찬 불꽃을 상대에게 발사하여 공격한다. 화상 상태로 만들 때가 있다.";
		name = "화염방사";
		condition = PMUC_BURN;
		buff = PMB_NONE;

		power = 90;
		rate = 100;
		pp = 15;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 용의 분노
	{
		id = DRAGON_RAGE;
		type = PB_TYPE_DRAGON;
		category = PMSC_SPECAIL;
		txt = "충격파를 상대에게 부딪쳐서 공격한다. 언제나 40의 데미지를 준다.";
		name = "용의분노";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 0;
		rate = 100;
		pp = 10;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 거품
	{
		id = BUBBLE;
		type = PM_TYPE_WATER;
		category = PMSC_SPECAIL;
		txt = "매우 많은 거품을 상대에게 내뿜어 공격한다. 상대의 스피드를 떨어뜨릴 때가 있다.";
		name = "거품";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 20;
		rate = 100;
		pp = 30;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 물대포
	{
		id = WATER_GUN;
		type = PM_TYPE_WATER;
		category = PMSC_SPECAIL;
		txt = "물을 기세 좋게 상대에게 발사하여 공격한다.";
		name = "물대포";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 25;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 하이드로펌프
	{
		id = HYDRO_PUMP;
		type = PM_TYPE_WATER;
		category = PMSC_SPECAIL;
		txt = "대량의 물을 세찬 기세로 상대에게 발사하여 공격한다.";
		name = "하이드로펌프";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 120;
		rate = 80;
		pp = 5;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}


	// 전광석화
	{
		id = QUICK_ATTACK;
		type = PM_TYPE_NORMAL;
		category = PMSC_ATTACK;
		txt = "눈에 보이지 않는 굉장한 속도로 상대에게 돌진한다. 반드시 선제 공격할 수 있다.";
		name = "전광석화";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 30;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 전기쇼크
	{
		id = THUNDERSHOCK;
		type = PM_TYPE_ELECTRONIC;
		category = PMSC_SPECAIL;
		txt = "전기 자극을 상대에게 날려서 공격한다. 마비 상태로 만들 때가 있다.";
		name = "전기쇼크";
		condition = PMUC_PALALYSIS;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 30;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 10만볼트
	{
		id = THUNDERBOLT;
		type = PM_TYPE_ELECTRONIC;
		category = PMSC_SPECAIL;
		txt = "강한 전격을 상대에게 날려서 공격한다. 마비 상태로 만들 때가 있다.";
		name = "10만볼트";
		condition = PMUC_PALALYSIS;
		buff = PMB_NONE;

		power = 90;
		rate = 100;
		pp = 15;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 번개
	{
		id = THUNDER;
		type = PM_TYPE_ELECTRONIC;
		category = PMSC_SPECAIL;
		txt = "강한 번개를 상대에게 떨어뜨려 공격한다. 마비 상태로 만들 때가 있다.";
		name = "번개";
		condition = PMUC_PALALYSIS;
		buff = PMB_NONE;

		power = 110;
		rate = 70;
		pp = 10;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 전기자석파
	{
		id = THNDER_WAVE;
		type = PM_TYPE_ELECTRONIC;
		category = PMSC_SPECAIL;
		txt = "약한 전격을 날려서 상대를 마비 상태로 만든다.";
		name = "전기자석파";
		condition = PMUC_PALALYSIS;
		buff = PMB_NONE;

		power = 0;
		rate = 90;
		pp = 20;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 튀어오르기
	{
		id = SPLASH;
		type = PM_TYPE_NORMAL;
		category = PMSC_SPECAIL;
		txt = "공격도 하지 않고 팔딱팔딱 튈 뿐 아무 일도 일어나지 않는다...";
		name = "튀어오르기";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 0;
		rate = 0;
		pp = 40;

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
