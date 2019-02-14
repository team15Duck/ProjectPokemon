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
	// 이상해씨
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
		
		string text = "태어날 때부터 등에 식물의 씨앗이 있어 조금씩 크게 자란다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_GRASS, "이상해씨", kindStatus, text, 6.9f, 0.7f, 45, skillMap, 16, PM_IVYSAUR);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// 이상해풀
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

		string text = "꽃봉오리가 등에 붙어 있으며 양분을 흡수해가면 커다란 꽃이 핀다고 한다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_GRASS, "이상해풀", kindStatus, text, 13.f, 1.f, 45, skillMap, 32, PM_VENUSAUR);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// 이상해꽃
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

		string text = "꽃에서 황홀한 향기가 퍼져나가 싸우는 자의 기분을 달래게 한다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_GRASS, "이상해꽃", kindStatus, text, 100.f, 2.f, 45, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}


	// 파이리
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


		string text = "태어날 때부터 꼬리의 불꽃이 타오르고 있다. 불꽃이 꺼지면 그 생명이 다하고 만다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_FIRE, "파이리", kindStatus, text, 8.5f, 0.6f, 45, skillMap, 16, PM_CHARMELEON);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// 리자드
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

		string text = "꼬리를 휘둘러 상대를 쓰러트리고 날카로운 발톱으로 갈기갈기 찢어버린다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_FIRE, "리자드", kindStatus, text, 19.f, 1.1f, 45, skillMap, 36, PM_CHARIZARD);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// 리자몽
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

		string text = "지상 1400미터까지 날개를 사용해 나는 것이 가능하다. 고열의 불꽃을 내뿜는다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_FIRE, "리자몽", kindStatus, text, 90.5f, 1.7f, 45, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}


	// 꼬북이
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


		string text = "긴 목을 등껍질 안에 움추릴 때 강한 물대포를 발사한다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_WATER, "꼬북이", kindStatus, text, 9.0f, 0.5f, 45, skillMap, 16, PM_WARTORTLE);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// 어니북이
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

		string text = "애완동물으로서 인기가 높다. 또 털로 감싸진 꼬리는 장수의 상징이다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_WATER, "어니북이", kindStatus, text, 22.5, 1.f, 45, skillMap, 36, PM_BLASTOISE);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// 거북왕
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

		string text = "무거운 몸으로 상대를 덮쳐서 기절시킨다. 위기에 처하면 등껍질에 숨는다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_WATER, "거북왕", kindStatus, text, 85.5, 1.6f, 45, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// 피카츄
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

		string text = "뺨의 양쪽에 작은 전기 주머니가 있다. 위기 상황일 때 방전한다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_ELECTRONIC, "피카츄", kindStatus, text, 6.0f, 0.4f, 190, skillMap);

		_pokemonMap.insert(make_pair(index, info));

		SAFE_DELETE(kindStatus);
	}

	// 라이츄
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

		string text = "전기는 10만 볼트로 도달하는 때도 있어 무심결에 만졌다가는 인도코끼리라도 기절한다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(index, PM_TYPE_ELECTRONIC, "라이츄", kindStatus, text, 30.0f, 0.8f, 75, skillMap);

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
