#include "stdafx.h"
#include "battleScene.h"


battleScene::battleScene()
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init()
{
	_pokemon = PLAYERDATA->getPokemon();
	PLAYERDATA->setPokemon(nullptr);

	return S_OK;
}

void battleScene::release()
{
	SAFE_DELETE(_pokemon);
}

void battleScene::update()
{
}

void battleScene::render()
{
}
