#include "stdafx.h"
#include "pokemonInfo.h"


pokemonInfo::pokemonInfo()
: _index(POKEMON_NONE)
, _type(PM_TYPE_NONE)
{
	_defaultStatus.clear();
	_name.clear();
	_description.clear();
}

pokemonInfo::~pokemonInfo()
{
}


HRESULT pokemonInfo::init(POKEMON index, POKEMON_TYPE type, string name, pokemonStatus* status, string text)
{
	_index = index;
	_type = type;
	_name = name;
	_defaultStatus = *status;
	_description = text;

	return S_OK;
}

void pokemonInfo::clear()
{
	_index = POKEMON_NONE;
	_type = PM_TYPE_NONE;
	_defaultStatus.clear();
	_name.clear();
	_description.clear();
}
