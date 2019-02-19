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
	_pokemon = nullptr;
	return S_OK;
}

void playerDataBase::release()
{
	_currentPlayer->release();
	delete _currentPlayer;
	_currentPlayer = nullptr;
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
	itemDataLoad(data);
	objectDataLoad(data);
	playerDataLoad(data);
}

void playerDataBase::dataSave(DATA data)
{
	bankPokemonSave(data);
	currentPokemonSave(data);
	fieldItemDataSave(data);
	npcDataSave(data);
	itemDataSave(data);
	objectDataSave(data);
	playerDataSave(data);
}

void playerDataBase::bankPokemonLoad(DATA data)
{
}

void playerDataBase::currentPokemonLoad(DATA data)
{
	switch (data)
	{
		case playerDataBase::DATA_DEFAULT:
			
		break;
		case playerDataBase::DATA_1:
		break;
		case playerDataBase::DATA_2:
		break;
		case playerDataBase::DATA_3:
		break;
		case playerDataBase::DATA_4:
		break;
		case playerDataBase::DATA_5:
		break;
		case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::fieldItemDataLoad(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::npcDataLoad(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::itemDataLoad(DATA data)
{
}

void playerDataBase::objectDataLoad(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::playerDataLoad(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::bankPokemonSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::currentPokemonSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::fieldItemDataSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::npcDataSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::itemDataSave(DATA data)
{
}

void playerDataBase::objectDataSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}

void playerDataBase::playerDataSave(DATA data)
{
	switch (data)
	{
	case playerDataBase::DATA_DEFAULT:

		break;
	case playerDataBase::DATA_1:
		break;
	case playerDataBase::DATA_2:
		break;
	case playerDataBase::DATA_3:
		break;
	case playerDataBase::DATA_4:
		break;
	case playerDataBase::DATA_5:
		break;
	case playerDataBase::DATA_6:
		break;
	}
}
