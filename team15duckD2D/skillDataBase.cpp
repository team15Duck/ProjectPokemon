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


	// ������
	{
		id = SCRATCH;
		type = PM_TYPE_NORMAL;
		category = PMSC_ATTACK;
		txt = "�ܴ��ϰ� ������ ��ī�ο� �������� ��븦 ����� �����Ѵ�.";
		name = "������";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 35;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// �Ҳɼ���
	{
		id = EMBER;
		type = PM_TYPE_FIRE;
		category = PMSC_SPECAIL;
		txt = "���� �Ҳ��� ��뿡�� �߻��Ͽ� �����Ѵ�. ȭ�� ���·� ���� ���� �ִ�.";
		name = "�Ҳɼ���";
		condition = PMUC_BURN;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 25;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ȭ�����
	{
		id = FLAMETHROWER;
		type = PM_TYPE_FIRE;
		category = PMSC_SPECAIL;
		txt = "���� �Ҳ��� ��뿡�� �߻��Ͽ� �����Ѵ�. ȭ�� ���·� ���� ���� �ִ�.";
		name = "ȭ�����";
		condition = PMUC_BURN;
		buff = PMB_NONE;

		power = 90;
		rate = 100;
		pp = 15;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ���� �г�
	{
		id = DRAGON_RAGE;
		type = PB_TYPE_DRAGON;
		category = PMSC_SPECAIL;
		txt = "����ĸ� ��뿡�� �ε��ļ� �����Ѵ�. ������ 40�� �������� �ش�.";
		name = "���Ǻг�";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 0;
		rate = 100;
		pp = 10;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ��ǰ
	{
		id = BUBBLE;
		type = PM_TYPE_WATER;
		category = PMSC_SPECAIL;
		txt = "�ſ� ���� ��ǰ�� ��뿡�� ���վ� �����Ѵ�. ����� ���ǵ带 ����߸� ���� �ִ�.";
		name = "��ǰ";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 20;
		rate = 100;
		pp = 30;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ������
	{
		id = WATER_GUN;
		type = PM_TYPE_WATER;
		category = PMSC_SPECAIL;
		txt = "���� �⼼ ���� ��뿡�� �߻��Ͽ� �����Ѵ�.";
		name = "������";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 25;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ���̵������
	{
		id = HYDRO_PUMP;
		type = PM_TYPE_WATER;
		category = PMSC_SPECAIL;
		txt = "�뷮�� ���� ���� �⼼�� ��뿡�� �߻��Ͽ� �����Ѵ�.";
		name = "���̵������";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 120;
		rate = 80;
		pp = 5;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}


	// ������ȭ
	{
		id = QUICK_ATTACK;
		type = PM_TYPE_NORMAL;
		category = PMSC_ATTACK;
		txt = "���� ������ �ʴ� ������ �ӵ��� ��뿡�� �����Ѵ�. �ݵ�� ���� ������ �� �ִ�.";
		name = "������ȭ";
		condition = PMUC_NONE;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 30;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// �����ũ
	{
		id = THUNDERSHOCK;
		type = PM_TYPE_ELECTRONIC;
		category = PMSC_SPECAIL;
		txt = "���� �ڱ��� ��뿡�� ������ �����Ѵ�. ���� ���·� ���� ���� �ִ�.";
		name = "�����ũ";
		condition = PMUC_PALALYSIS;
		buff = PMB_NONE;

		power = 40;
		rate = 100;
		pp = 30;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// 10����Ʈ
	{
		id = THUNDERBOLT;
		type = PM_TYPE_ELECTRONIC;
		category = PMSC_SPECAIL;
		txt = "���� ������ ��뿡�� ������ �����Ѵ�. ���� ���·� ���� ���� �ִ�.";
		name = "10����Ʈ";
		condition = PMUC_PALALYSIS;
		buff = PMB_NONE;

		power = 90;
		rate = 100;
		pp = 15;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// ����
	{
		id = THUNDER;
		type = PM_TYPE_ELECTRONIC;
		category = PMSC_SPECAIL;
		txt = "���� ������ ��뿡�� ����߷� �����Ѵ�. ���� ���·� ���� ���� �ִ�.";
		name = "����";
		condition = PMUC_PALALYSIS;
		buff = PMB_NONE;

		power = 110;
		rate = 70;
		pp = 10;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// �����ڼ���
	{
		id = THNDER_WAVE;
		type = PM_TYPE_ELECTRONIC;
		category = PMSC_SPECAIL;
		txt = "���� ������ ������ ��븦 ���� ���·� �����.";
		name = "�����ڼ���";
		condition = PMUC_PALALYSIS;
		buff = PMB_NONE;

		power = 0;
		rate = 90;
		pp = 20;

		pokemonSkillInfo* info = new pokemonSkillInfo;
		info->init(id, type, category, txt, name, condition, buff, power, rate, pp);

		_skillMap.insert(make_pair(id, info));
	}

	// Ƣ�������
	{
		id = SPLASH;
		type = PM_TYPE_NORMAL;
		category = PMSC_SPECAIL;
		txt = "���ݵ� ���� �ʰ� �ȵ��ȵ� ƥ �� �ƹ� �ϵ� �Ͼ�� �ʴ´�...";
		name = "Ƣ�������";
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
