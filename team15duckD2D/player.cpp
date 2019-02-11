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

	
	/////////////이건나중에지울거야/////////
	_tileX = 14;
	_tileY = 3;
	_posX = _tileX * 64 + 32;
	_posY = _tileY * 64 + 32;
	_isMan = true;
	_state = PS_IDLE_DOWN;
	_isMoving = false;
	_playTime = 7784;
	//////////////////////////////////////

	//성별따라 키값 셋팅해줌
	if (_isMan)
		_key = "playerM";
	else
		_key = "playerF";


	aniSetUp();

	return S_OK;
}

void player::release()
{
}

void player::update()
{
	_playTime += TIMEMANAGER->getElapsedTime();
	KEYANIMANAGER->update(_key);
	keyUpdate();
	stateUpdate();
}

void player::render()
{
	IMAGEMANAGER->findImage(_key)->aniRender(_posX - 75, _posY - 150, _playerAni);

	WCHAR str[128];
	int min = (int)_playTime % 3600 / 60;
	int hour = (int)_playTime / 3600;
	swprintf_s(str, L"playTime - %d %d : %d %d", hour / 10, hour % 10, min / 10, min % 10);
	D2DMANAGER->drawText(str, 700, 0,25);

}

void player::aniSetUp()
{
	KEYANIMANAGER->addAnimationType(_key);

	//오른쪽은 왼쪽 반전시켜서 사용할거기때문에 안넣어도됨
	
	
	//가만히서있기
	int idleLeft[1] = { 21 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_left", _key.c_str(), idleLeft, 1, 10, true);
	int idleUp[1] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_up", _key.c_str(), idleUp, 1, 10, true);
	int idleDown[1] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_down", _key.c_str(), idleDown, 1, 10, true);

	//이동
	int moveLeft[4] = { 21,22,21,20 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_left", _key.c_str(), moveLeft, 4, 10, true);
	int moveUp[4] = { 11,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_up", _key.c_str(), moveUp, 4, 10, true);
	int moveDown[4] = { 1,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_down", _key.c_str(), moveDown, 4, 10, true);

	//빨리이동
	int fastMoveLeft[4] = { 24,25,24,23 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_left", _key.c_str(), fastMoveLeft, 4, 10, true);
	int fastMoveUp[4] = { 14,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_up", _key.c_str(), fastMoveUp, 4, 10, true);
	int fastMoveDown[4] = { 4,5,4,3 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_down", _key.c_str(), fastMoveDown, 4, 10, true);



	_playerAni = KEYANIMANAGER->findAnimation(_key, "idle_down");
	_playerAni->start();
}

void player::dataLoad()
{

}

void player::keyUpdate()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_playerAni = KEYANIMANAGER->findAnimation(_key, "move_left");
		_playerAni->start();
		_isMoving = true;
		_state = PS_MOVE_LEFT;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_isMoving = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{

	}
	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_isMoving = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_playerAni = KEYANIMANAGER->findAnimation(_key, "move_down");
		_playerAni->start();
		_isMoving = true;
		_state = PS_MOVE_DOWN;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	{
		_isMoving = false;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_playerAni = KEYANIMANAGER->findAnimation(_key, "move_up");
		_playerAni->start();
		_isMoving = true;
		_state = PS_MOVE_UP;
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		_isMoving = false;
	}

}

void player::stateUpdate()
{
	switch (_state)
	{
		case player::PS_IDLE_LEFT:
		break;
		case player::PS_IDLE_UP:
		break;
		case player::PS_IDLE_RIGHT:
		break;
		case player::PS_IDLE_DOWN:
		break;
		case player::PS_MOVE_LEFT:
			_posX -= 5;
			if (!_isMoving)
			{
				if (29 < (int)_posX % 64 && (int)_posX % 64 < 35)
				{
					_posX = (int)_posX / 64 * 64 + 32;
					_playerAni = KEYANIMANAGER->findAnimation(_key, "idle_left");
					_playerAni->start();
					_state = PS_IDLE_LEFT;
				}
			}
		break;
		case player::PS_MOVE_UP:
			_posY -= 5;
			if (!_isMoving)
			{
				if (29 < (int)_posY % 64 && (int)_posY % 64 < 35)
				{
					_posY = (int)_posY / 64 * 64 + 32;
					_playerAni = KEYANIMANAGER->findAnimation(_key, "idle_up");
					_playerAni->start();
					_state = PS_IDLE_UP;
				}
			}
		break;
		case player::PS_MOVE_RIGHT:
		break;
		case player::PS_MOVE_DOWN:
			_posY += 5;
			if (!_isMoving)
			{
				if (29 < (int)_posY % 64 && (int)_posY % 64 < 35)
				{
					_posY = (int)_posY / 64 * 64 + 32;
					_playerAni = KEYANIMANAGER->findAnimation(_key, "idle_down");
					_playerAni->start();
					_state = PS_IDLE_DOWN;
				}
			}
		break;
		case player::PS_FASTMOVE_LEFT:
		break;
		case player::PS_FASTMOVE_UP:
		break;
		case player::PS_FASTMOVE_RIGHT:
		break;
		case player::PS_FASTMOVE_DOWN:
		break;
		case player::PS_BICYCLE_IDLE_LEFT:
		break;
		case player::PS_BICYCLE_IDLE_UP:
		break;
		case player::PS_BICYCLE_IDLE_RIGHT:
		break;
		case player::PS_BICYCLE_IDLE_DOWN:
		break;
		case player::PS_BICYCLE_LEFT:
		break;
		case player::PS_BICYCLE_UP:
		break;
		case player::PS_BICYCLE_RIGHT:
		break;
		case player::PS_BICYCLE_DOWN:
		break;
		default:
		break;
	}
}
