#include "stdafx.h"
#include "playerDataBase.h"


playerDataBase::playerDataBase()
{
}


playerDataBase::~playerDataBase()
{
}

HRESULT playerDataBase::init()
{
	_currentPlayer = new player;
	_currentPlayer->init();
	return S_OK;
}

void playerDataBase::release()
{
}

void playerDataBase::update()
{
}

void playerDataBase::render()
{
}

void playerDataBase::dataLoad(DATA data)
{
	bankPokemonLoad(data);
	currentPokemonLoad(data);
	fieldItemDataLoad(data);
	npcDataLoad(data);
	objectDataLoad(data);
	playerDataLoad(data);
}

void playerDataBase::dataSave(DATA data)
{
	bankPokemonSave(data);
	currentPokemonSave(data);
	fieldItemDataSave(data);
	npcDataSave(data);
	objectDataSave(data);
	playerDataSave(data);
}

void playerDataBase::bankPokemonLoad(DATA data)
{
}

void playerDataBase::currentPokemonLoad(DATA data)
{
}

void playerDataBase::fieldItemDataLoad(DATA data)
{
}

void playerDataBase::npcDataLoad(DATA data)
{
}

void playerDataBase::objectDataLoad(DATA data)
{
}

void playerDataBase::playerDataLoad(DATA data)
{
}

void playerDataBase::bankPokemonSave(DATA data)
{
}

void playerDataBase::currentPokemonSave(DATA data)
{
}

void playerDataBase::fieldItemDataSave(DATA data)
{
}

void playerDataBase::npcDataSave(DATA data)
{
}

void playerDataBase::objectDataSave(DATA data)
{
}

void playerDataBase::playerDataSave(DATA data)
{
}
