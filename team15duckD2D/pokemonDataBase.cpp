#include "stdafx.h"
#include "pokemonDataBase.h"


pokemonDataBase::pokemonDataBase()
{
	_pokemonMap.clear();
}


pokemonDataBase::~pokemonDataBase()
{
}

HRESULT pokemonDataBase::init()
{
	// �̻��ؾ�
	{
		POKEMON index = PM_BULBASAUR;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 45;
		kindStatus->attk = 49;
		kindStatus->dex = 49;
		kindStatus->spAttk = 65;
		kindStatus->spDex = 65;
		kindStatus->spAttk = 45;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(TACLE);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(LEECH_SEEd);
			skillMap.insert(make_pair(7, ids));
		}
		{
			vector<int> ids;
			ids.push_back(VINE_WHIP);
			skillMap.insert(make_pair(10, ids));
		}
		{
			vector<int> ids;
			ids.push_back(POISON_POWDER);
			ids.push_back(SLEEP_POWDER);
			skillMap.insert(make_pair(15, ids));
		}
		{
			vector<int> ids;
			ids.push_back(RAZOR_LEAF);
			skillMap.insert(make_pair(22, ids));
		}
		
		string text = "�¾ ������ � �Ĺ��� ������ �־� ���ݾ� ũ�� �ڶ���.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_GRASS, "�̻��ؾ�", kindStatus, text, 6.9f, 0.7f, 45, skillMap, 16, PM_IVYSAUR);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// �̻���Ǯ
	{
		POKEMON index = PM_IVYSAUR;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 60;
		kindStatus->attk = 62;
		kindStatus->dex = 63;
		kindStatus->spAttk = 80;
		kindStatus->spDex = 80;
		kindStatus->spAttk = 60;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(TACLE);
			ids.push_back(LEECH_SEEd);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(VINE_WHIP);
			skillMap.insert(make_pair(10, ids));
		}
		{
			vector<int> ids;
			ids.push_back(POISON_POWDER);
			ids.push_back(SLEEP_POWDER);
			skillMap.insert(make_pair(15, ids));
		}
		{
			vector<int> ids;
			ids.push_back(RAZOR_LEAF);
			skillMap.insert(make_pair(22, ids));
		}

		string text = "�ɺ������� � �پ� ������ ����� ����ذ��� Ŀ�ٶ� ���� �ɴٰ� �Ѵ�.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_GRASS, "�̻���Ǯ", kindStatus, text, 13.f, 1.f, 45, skillMap, 32, PM_VENUSAUR);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// �̻��ز�
	{
		POKEMON index = PM_VENUSAUR;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 80;
		kindStatus->attk = 82;
		kindStatus->dex = 83;
		kindStatus->spAttk = 100;
		kindStatus->spDex = 100;
		kindStatus->spAttk = 80;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(TACLE);
			ids.push_back(LEECH_SEEd);
			ids.push_back(VINE_WHIP);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(POISON_POWDER);
			ids.push_back(SLEEP_POWDER);
			skillMap.insert(make_pair(15, ids));
		}
		{
			vector<int> ids;
			ids.push_back(RAZOR_LEAF);
			skillMap.insert(make_pair(22, ids));
		}

		string text = "�ɿ��� ȲȦ�� ��Ⱑ �������� �ο�� ���� ����� �޷��� �Ѵ�.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_GRASS, "�̻��ز�", kindStatus, text, 100.f, 2.f, 45, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}


	// ���̸�
	{
		POKEMON index = PM_CHARMANDER;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 39;
		kindStatus->attk = 52;
		kindStatus->dex = 43;
		kindStatus->spAttk = 60;
		kindStatus->spDex = 50;
		kindStatus->spAttk = 65;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(SCRATCH);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(EMBER);
			skillMap.insert(make_pair(7, ids));
		}
		{
			vector<int> ids;
			ids.push_back(FLAMETHROWER);
			skillMap.insert(make_pair(31, ids));
		}
		{
			vector<int> ids;
			ids.push_back(DRAGON_RAGE);
			skillMap.insert(make_pair(43, ids));
		}


		string text = "�¾ ������ ������ �Ҳ��� Ÿ������ �ִ�. �Ҳ��� ������ �� ������ ���ϰ� ����.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_FIRE, "���̸�", kindStatus, text, 8.5f, 0.6f, 45, skillMap, 16, PM_CHARMELEON);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// ���ڵ�
	{
		POKEMON index = PM_CHARMELEON;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 58;
		kindStatus->attk = 64;
		kindStatus->dex = 58;
		kindStatus->spAttk = 80;
		kindStatus->spDex = 65;
		kindStatus->spAttk = 80;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(SCRATCH);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(EMBER);
			skillMap.insert(make_pair(7, ids));
		}
		{
			vector<int> ids;
			ids.push_back(FLAMETHROWER);
			skillMap.insert(make_pair(34, ids));
		}
		{
			vector<int> ids;
			ids.push_back(DRAGON_RAGE);
			skillMap.insert(make_pair(48, ids));
		}

		string text = "������ �ֵѷ� ��븦 ����Ʈ���� ��ī�ο� �������� ���Ⱕ�� ���������.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_FIRE, "���ڵ�", kindStatus, text, 19.f, 1.1f, 45, skillMap, 36, PM_CHARIZARD);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// ���ڸ�
	{
		POKEMON index = PM_CHARIZARD;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 78;
		kindStatus->attk = 84;
		kindStatus->dex = 78;
		kindStatus->spAttk = 109;
		kindStatus->spDex = 85;
		kindStatus->spAttk = 100;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(SCRATCH);
			ids.push_back(EMBER);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(FLAMETHROWER);
			skillMap.insert(make_pair(34, ids));
		}
		{
			vector<int> ids;
			ids.push_back(DRAGON_RAGE);
			skillMap.insert(make_pair(54, ids));
		}

		string text = "���� 1400���ͱ��� ������ ����� ���� ���� �����ϴ�. ���� �Ҳ��� ���մ´�.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_FIRE, "���ڸ�", kindStatus, text, 90.5f, 1.7f, 45, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}


	// ������
	{
		POKEMON index = PM_SQUIRTLE;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 44;
		kindStatus->attk = 48;
		kindStatus->dex = 65;
		kindStatus->spAttk = 50;
		kindStatus->spDex = 64;
		kindStatus->spAttk = 43;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(TACLE);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(BUBBLE);
			skillMap.insert(make_pair(7, ids));
		}
		{
			vector<int> ids;
			ids.push_back(WATER_GUN);
			skillMap.insert(make_pair(13, ids));
		}
		{
			vector<int> ids;
			ids.push_back(HYDRO_PUMP);
			skillMap.insert(make_pair(47, ids));
		}


		string text = "�� ���� ��� �ȿ� ���߸� �� ���� �������� �߻��Ѵ�.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_WATER, "������", kindStatus, text, 9.0f, 0.5f, 45, skillMap, 16, PM_WARTORTLE);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// ��Ϻ���
	{
		POKEMON index = PM_WARTORTLE;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 59;
		kindStatus->attk = 63;
		kindStatus->dex = 80;
		kindStatus->spAttk = 65;
		kindStatus->spDex = 80;
		kindStatus->spAttk = 58;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(TACLE);
			ids.push_back(BUBBLE);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(WATER_GUN);
			skillMap.insert(make_pair(13, ids));
		}
		{
			vector<int> ids;
			ids.push_back(HYDRO_PUMP);
			skillMap.insert(make_pair(53, ids));
		}

		string text = "�ֿϵ������μ� �αⰡ ����. �� �з� ������ ������ ����� ��¡�̴�.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_WATER, "��Ϻ���", kindStatus, text, 22.5, 1.f, 45, skillMap, 36, PM_BLASTOISE);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// �źϿ�
	{
		POKEMON index = PM_BLASTOISE;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 79;
		kindStatus->attk = 83;
		kindStatus->dex = 100;
		kindStatus->spAttk = 85;
		kindStatus->spDex = 105;
		kindStatus->spAttk = 78;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(TACLE);
			ids.push_back(BUBBLE);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(WATER_GUN);
			skillMap.insert(make_pair(13, ids));
		}
		{
			vector<int> ids;
			ids.push_back(HYDRO_PUMP);
			skillMap.insert(make_pair(68, ids));
		}

		string text = "���ſ� ������ ��븦 ���ļ� ������Ų��. ���⿡ ó�ϸ� ����� ���´�.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_WATER, "�źϿ�", kindStatus, text, 85.5, 1.6f, 45, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// ��ī��
	{
		POKEMON index = PM_PIKACHU;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 35;
		kindStatus->attk = 55;
		kindStatus->dex = 30;
		kindStatus->spAttk = 50;
		kindStatus->spDex = 40;
		kindStatus->spAttk = 90;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(THUNDERSHOCK);
			skillMap.insert(make_pair(1, ids));
		}
		{
			vector<int> ids;
			ids.push_back(THNDER_WAVE);
			skillMap.insert(make_pair(8, ids));
		}
		{
			vector<int> ids;
			ids.push_back(QUICK_ATTACK);
			skillMap.insert(make_pair(11, ids));
		}
		{
			vector<int> ids;
			ids.push_back(THUNDERBOLT);
			skillMap.insert(make_pair(26, ids));
		}
		{
			vector<int> ids;
			ids.push_back(THUNDER);
			skillMap.insert(make_pair(41, ids));
		}

		string text = "���� ���ʿ� ���� ���� �ָӴϰ� �ִ�. ���� ��Ȳ�� �� �����Ѵ�.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_ELECTRONIC, "��ī��", kindStatus, text, 6.0f, 0.4f, 190, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// ������
	{
		POKEMON index = PM_RAICHU;
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 60;
		kindStatus->attk = 90;
		kindStatus->dex = 55;
		kindStatus->spAttk = 90;
		kindStatus->spDex = 80;
		kindStatus->spAttk = 100;

		map<int, vector<int>> skillMap;
		{
			vector<int> ids;
			ids.push_back(THUNDERSHOCK);
			ids.push_back(QUICK_ATTACK);
			ids.push_back(THUNDERBOLT);
			skillMap.insert(make_pair(1, ids));
		}

		string text = "����� 10�� ��Ʈ�� �����ϴ� ���� �־� ���ɰῡ �����ٰ��� �ε��ڳ����� �����Ѵ�.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_ELECTRONIC, "������", kindStatus, text, 30.0f, 0.8f, 75, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	return S_OK;
}

void pokemonDataBase::release()
{
	for (auto iter = _pokemonMap.begin(); _pokemonMap.end() != iter;)
	{
		if (nullptr != iter->second)
		{
			pokemonInfo* info = iter->second;
			iter = _pokemonMap.erase(iter);

			SAFE_DELETE(info);
		}
		else
			++iter;
	}

	_pokemonMap.clear();
}

pokemonInfo* pokemonDataBase::getPokemonInfomation(POKEMON pokemonIndex)
{
	pokemonInfo* info = nullptr;

	if( _pokemonMap.end() != _pokemonMap.find(pokemonIndex))
		info = _pokemonMap[pokemonIndex];

	return info;
}

pokemonStatus pokemonDataBase::calculateStatus(int level, POKEMON pokemonId)
{
	pokemonStatus status;
	status.clear();
	if( _pokemonMap.end() == _pokemonMap.find(pokemonId))
		return status;

	const pokemonStatus* kindStatus = _pokemonMap[pokemonId]->getPokemonKindStatus();

	status.hp	 =	calculatorStatusType1(level, kindStatus->hp);
	status.attk  =  calculatorStatusType2(level, kindStatus->attk);
	status.dex	 =  calculatorStatusType2(level, kindStatus->dex);
	status.spAttk=	calculatorStatusType2(level, kindStatus->spAttk);
	status.spDex =  calculatorStatusType2(level, kindStatus->spDex);
	status.speed =  calculatorStatusType2(level, kindStatus->speed);

	return status;
}

int pokemonDataBase::calcuateExp(int level, POKEMON pokemonId)
{
	if(POKEMON151 == pokemonId)
		return ((1 * level * level * level) - (15 * level * level) + ( 100 * level) - 140);
	else
		return level * level * level;
}

float pokemonDataBase::calculateConflictValue(POKEMON myindex, POKEMON targetIndex)
{
	pokemonInfo* myinfo = getPokemonInfomation(myindex);
	pokemonInfo* targetInfo = getPokemonInfomation(targetIndex);

	POKEMON_TYPE myType = myinfo->getPokemonType();
	POKEMON_TYPE targetType = targetInfo->getPokemonType();

	return 1.0f;
}

int pokemonDataBase::calculatorStatusType1(int level, int kindValue)
{
	return static_cast<int>((kindValue + 50.f) * level / 50.f);
}

int pokemonDataBase::calculatorStatusType2(int level, int kindValue)
{
	return static_cast<int>((kindValue + 50.f) * level / 50.f + 5.f);
}
