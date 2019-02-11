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
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 45;
		kindStatus->attk = 49;
		kindStatus->dex = 49;
		kindStatus->spAttk = 65;
		kindStatus->spDex = 65;
		kindStatus->spAttk = 45;

		string text = "태어날 때부터 등에 식물의 씨앗이 있어 조금씩 크게 자란다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(PM_BULBASAUR, PM_TYPE_GRASS, "이상해씨", kindStatus, text, 6.9f, 0.7f, 45);

		_pokemonMap.insert(make_pair(PM_BULBASAUR, info));

		SAFE_DELETE(info);
	}

	// 이상해풀
	{
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 60;
		kindStatus->attk = 62;
		kindStatus->dex = 63;
		kindStatus->spAttk = 80;
		kindStatus->spDex = 80;
		kindStatus->spAttk = 60;

		string text = "꽃봉오리가 등에 붙어 있으며 양분을 흡수해가면 커다란 꽃이 핀다고 한다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(PM_IVYSAUR, PM_TYPE_GRASS, "이상해풀", kindStatus, text, 13.f, 1.f, 45);

		_pokemonMap.insert(make_pair(PM_IVYSAUR, info));

		SAFE_DELETE(info);
	}

	// 이상해꽃
	{
		pokemonStatus* kindStatus = new pokemonStatus;
		kindStatus->hp = 80;
		kindStatus->attk = 82;
		kindStatus->dex = 83;
		kindStatus->spAttk = 100;
		kindStatus->spDex = 100;
		kindStatus->spAttk = 80;

		string text = "꽃에서 황홀한 향기가 퍼져나가 싸우는 자의 기분을 달래게 한다.";
		pokemonInfo* info = new pokemonInfo;
		info->init(PM_VENUSAUR, PM_TYPE_GRASS, "이상해꽃", kindStatus, text, 100.f, 2.f, 45);

		_pokemonMap.insert(make_pair(PM_VENUSAUR, info));

		SAFE_DELETE(info);
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

const pokemonInfo* pokemonDataBase::getPokemonInfomation(POKEMON pokemonIndex)
{
	pokemonInfo* info = nullptr;

	if( _pokemonMap.end() != _pokemonMap.find(pokemonIndex))
		info = _pokemonMap[pokemonIndex];

	return info;
}

pokemonStatus* pokemonDataBase::calculateStatus(int level, POKEMON pokemonId)
{
	if( _pokemonMap.end() == _pokemonMap.find(pokemonId))
		return nullptr;

	pokemonStatus* status = new pokemonStatus;
	const pokemonStatus* kindStatus = _pokemonMap[pokemonId]->getPokemonKindStatus();

	status->hp =	 calculatorStatusType1(level, kindStatus->hp);
	status->attk =   calculatorStatusType2(level, kindStatus->attk);
	status->dex =    calculatorStatusType2(level, kindStatus->dex);
	status->spAttk = calculatorStatusType2(level, kindStatus->spAttk);
	status->spDex =  calculatorStatusType2(level, kindStatus->spDex);
	status->speed =  calculatorStatusType2(level, kindStatus->speed);

	return status;
}

int pokemonDataBase::calcuateExp(int level, POKEMON pokemonId)
{
	if(POKEMON151 == pokemonId)
		return ((1.2f * level * level * level) - (15 * level * level) + ( 100 * level) - 140);
	else
		return level * level * level;
}

int pokemonDataBase::calculatorStatusType1(int level, int kindValue)
{
	return static_cast<int>((kindValue + 50.f) * level / 50.f);
}

int pokemonDataBase::calculatorStatusType2(int level, int kindValue)
{
	return static_cast<int>((kindValue + 50.f) * level / 50.f + 5.f);
}
