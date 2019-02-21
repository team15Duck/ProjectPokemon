#include "stdafx.h"
#include "trainerNpc.h"


trainerNPC::trainerNPC()
	: _img(nullptr)
	, _isBeat(false)
	, _prizeGold(0)
	, _pokemonCnt(0)
{
	_name.clear();
}

trainerNPC::~trainerNPC()
{
}

HRESULT trainerNPC::init(string imgName, string name, int prizeGold)
{
	_img = IMAGEMANAGER->findImage(imgName);
	assert(_img != nullptr);

	_name = name;
	_prizeGold = prizeGold;

	return S_OK;
}

void trainerNPC::release()
{
	_img = nullptr;
	_name.clear();
}

void trainerNPC::render()
{
	_img->render(CAMERA->getPosX() + 576.f, CAMERA->getPosY() + 42.f);
}

void trainerNPC::update()
{
}

void trainerNPC::pushbackPokemon(pokemon* pm)
{
	if (_pokemonCnt < 6)
	{
		_pokemons[_pokemonCnt] = pm;
		++_pokemonCnt;
	}
}

void trainerNPC::loseBattle()
{
	_isBeat = true;
}

void trainerNPC::winBattle()
{
	_isBeat = false;
}

bool trainerNPC::isChangePokemon()
{
	if (!isPossibleChangePokemon())
		return false;

	int rate = 10;
	if (_pokemons[_enterPokemon]->getHp() < _pokemons[_enterPokemon]->getMaxHp() * 0.5f)
	{
		rate - 50;
	}

	int value = RND->getFromIntTo(1, 100);

	if (value <= rate)
		return true;
	else
		return false;
}

void trainerNPC::changePokemon()
{
	while (true)
	{
		int value = RND->getInt(_pokemonCnt);

		if (_enterPokemon == value)
			continue;

		if (!_pokemons[value]->isAwake())
			continue;

		_enterPokemon = value;
		break;
	}
}

bool trainerNPC::isPossibleChangePokemon()
{
	if (_pokemonCnt < 2)
		return false;

	bool isAwake = false;
	for (int ii = 0; ii < _pokemonCnt; ++ii)
	{
		if (ii == _enterPokemon)
			continue;

		isAwake = _pokemons[ii]->isAwake();
		if (isAwake)
			break;
	}

	return isAwake;
}
