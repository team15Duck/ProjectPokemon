#include "stdafx.h"
#include "testMap.h"


testMap::testMap()
{
}


testMap::~testMap()
{
}

void testMap::setPokemon()
{
	_minLevel = 3;
	_maxLevel = 5;

	_pokemon.push_back(PM_CHARIZARD);
	_pokemon.push_back(PM_IVYSAUR);

}

void testMap::potalLoad()
{
	{
		//potalInfo* info;


	}

}

void testMap::fieldItemLoad()
{
	tagFieldItem field;
	field.x = 13;
	field.y = 7;
	field.itemType = SUPER_POTION;
	field.isEat = false;
	_fieldItems.push_back(field);

	field.x = 22;
	field.y = 11;
	field.itemType = SUPER_BALL;
	field.isEat = false;
	_fieldItems.push_back(field);

	field.x = 58;
	field.y = 38;
	field.itemType = ANTIDOTE;
	field.isEat = false;
	_fieldItems.push_back(field);

	field.x = 57;
	field.y = 25;
	field.itemType = NORMAL_ETHER;
	field.isEat = false;
	_fieldItems.push_back(field);
}
