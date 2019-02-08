#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	dataLoad();
	aniSetUp();

	return S_OK;
}

void player::release()
{
}

void player::update()
{
}

void player::render()
{
}

void player::aniSetUp()
{
}

void player::dataLoad()
{
}
