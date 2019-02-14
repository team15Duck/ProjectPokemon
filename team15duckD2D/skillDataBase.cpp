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


	// �����ġ��
	{
		id = TACLE;
		type = PM_TYPE_NORMAL;
		category = PMSC_ATTACK;
		txt = "��븦 ���ؼ� �� ��ü�� �ε��İ��� �����Ѵ�.";
		name = "�����ġ��";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 10;
		rate = 100;
		pp = 35;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ���Ѹ���
	{
		id = LEECH_SEEd;
		type = PM_TYPE_GRASS;
		category = PMSC_BUFF;
		txt = "���� �ѷ��� ����� HP�� �� �� ���ݾ� ����Ͽ� �ڽ��� HP�� ȸ���Ѵ�.";
		name = "���Ѹ���";
		condition = PMUC_POISON;
		buff = PMB_ABSORB_HP;

		power = 0;
		rate = 90;
		pp = 10;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ����ä��
	{
		id = VINE_WHIP;
		type = PM_TYPE_GRASS;
		category = PMSC_ATTACK;
		txt = "ä��ó�� �־����� ���ð� �� ������ ��븦 ���� �ļ� �����Ѵ�.";
		name = "����ä��";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 45;
		rate = 100;
		pp = 15;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ������
	{
		id = POISON_POWDER;
		type = PB_TYPE_POISION;
		category = PMSC_BUFF;
		txt = "���� �ִ� ���縦 ���� ��ѷ��� ��븦 �� ���·� �����.";
		name = "������";
		condition = PMUC_POISON;
		buff = PMB_NONE;

		power = 0;
		rate = 75;
		pp = 30;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ���鰡��
	{
		id = SLEEP_POWDER;
		type = PM_TYPE_GRASS;
		category = PMSC_BUFF;
		txt = "���� ���� ���縦 ���� ��ѷ��� ��븦 ��� ���·� �����.";
		name = "���鰡��";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 0;
		rate = 75;
		pp = 15;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// �ٳ� ������
	{
		id = RAZOR_LEAF;
		type = PM_TYPE_GRASS;
		category = PMSC_ATTACK;
		txt = "�ٻ�͸� ���� ��븦 ���� �����Ѵ�. �޼ҿ� ���� Ȯ���� ����.";
		name = "�ٳ� ������";
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
