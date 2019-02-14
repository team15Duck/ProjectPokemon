#include "stdafx.h"
#include "pokemonInfo.h"


pokemonInfo::pokemonInfo()
: _index(POKEMON_NONE)
, _type(PM_TYPE_NONE)
, _weight(0.f)
, _height(0.f)
, _captureRate(0)
, _evolutionLv(0)
, _evolutionIndex(POKEMON_NONE)
{
	_kindStatus.clear();
	_name.clear();
	_description.clear();
}

pokemonInfo::~pokemonInfo()
{
}


HRESULT pokemonInfo::init(POKEMON index, POKEMON_TYPE type, string name, pokemonStatus* status
						  , string text, float weight, float height, int captureRate, map<int, vector<int>> skillMap)
{
	_index = index;
	_type = type;
	_name = name;
	_kindStatus = *status;
	_description = text;
	_weight = weight;
	_height = height;
	_captureRate = captureRate;
	_skillMap = skillMap;

	return S_OK;
}

HRESULT pokemonInfo::init(	POKEMON index
						  , POKEMON_TYPE type
						  , string name
						  , pokemonStatus* status
						  , string text
						  , float weight
						  , float height
						  , int captureRate
						  , map<int, vector<int>> skillMap
						  , int evolutionLv
						  , POKEMON evolutionIndex)
{

	init(index, type, name, status, text, weight, height, captureRate, skillMap);
	_evolutionLv = evolutionLv;
	_evolutionIndex = evolutionIndex;

	return S_OK;
}

void pokemonInfo::clear()
{
	_index = POKEMON_NONE;
	_type = PM_TYPE_NONE;
	_kindStatus.clear();
	_name.clear();
	_description.clear();
	_weight = 0.f;
	_height = 0.f;
	_captureRate = 0;
}