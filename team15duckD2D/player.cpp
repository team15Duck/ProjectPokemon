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
	_isMan = true;
	_state = PS_IDLE_LEFT;
	dataLoad();
	aniSetUp();

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	KEYANIMANAGER->update("player");
}

void player::render()
{
	IMAGEMANAGER->findImage("playerM")->aniRender(0, 0, _playerAni);
}

void player::aniSetUp()
{
	KEYANIMANAGER->addAnimationType("player");

	string gender;
	if (_isMan)
		gender = "M";
	else
		gender = "F";
	int idleLeft[1] = { 21 };
	KEYANIMANAGER->addArrayFrameAnimation("player", "idle_left", ("player" + gender).c_str(), idleLeft, 1, 10, true);

	_playerAni = KEYANIMANAGER->findAnimation("player", "idle_left");
	_playerAni->start();
}

void player::dataLoad()
{
}

void player::keyUpdate()
{
}

void player::stateUpdate()
{
}
