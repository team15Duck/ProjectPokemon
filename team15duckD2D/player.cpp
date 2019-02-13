#include "stdafx.h"
#include "player.h"
#include "mapData.h"

player::player()
{
}


player::~player()
{
}

HRESULT player::init()
{
	dataLoad();

	
	/////////////�̰ǳ��߿�����ž�/////////
	_tileX = 25;
	_tileY = 22;
	_posX = _tileX * 64 + 32;
	_posY = _tileY * 64 + 32;
	_isMan = true;
	_state = PS_IDLE_DOWN;
	_playTime = 5461;
	_isRight = false;
	_posZ = 0;
	_moveDistance = 0;
	//////////////////////////////////////

	//�������� Ű�� ��������
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
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			D2D_RECT_F tile = { j * 64, i * 64, j * 64 + 64, i * 64 + 64 };
			D2DMANAGER->drawRectangle(tile);
		}
	}




	if (_isRight)
		IMAGEMANAGER->findImage(_key)->aniRenderReverseX(_posX - 75, _posY - 118 - _posZ, _playerAni);
	else
		IMAGEMANAGER->findImage(_key)->aniRender(_posX - 75, _posY - 118 - _posZ, _playerAni);

	WCHAR str[128];
	int min =  ((int)_playTime * 10) % 3600 / 60;
	int hour = ((int)_playTime * 10) / 3600;
	swprintf_s(str, L"playTime - %d %d : %d %d", hour / 10, hour % 10, min / 10, min % 10);
	D2DMANAGER->drawText(str, 700 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 25);


	D2D_RECT_F left = { 600 + CAMERA->getPosX(),500 + CAMERA->getPosY(),700 + CAMERA->getPosX(),570 + CAMERA->getPosY() };
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		D2DMANAGER->fillRectangle(RGB(50, 50, 255), left);
	else
		D2DMANAGER->fillRectangle(RGB(180, 180, 180), left);
	swprintf_s(str, L"LEFT");
	D2DMANAGER->drawText(str, left.left + 17, left.top + 20, 30);

	D2D_RECT_F down = { 710 + CAMERA->getPosX(),500 + CAMERA->getPosY(),810 + CAMERA->getPosX(),570 + CAMERA->getPosY() };
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		D2DMANAGER->fillRectangle(RGB(50, 50, 255), down);
	else
		D2DMANAGER->fillRectangle(RGB(180, 180, 180), down);
	swprintf_s(str, L"DOWN");
	D2DMANAGER->drawText(str, down.left + 17, down.top + 20, 30);

	D2D_RECT_F right = { 820 + CAMERA->getPosX(),500 + CAMERA->getPosY(),920 + CAMERA->getPosX(),570 + CAMERA->getPosY() };
	if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		D2DMANAGER->fillRectangle(RGB(50, 50, 255), right);
	else
		D2DMANAGER->fillRectangle(RGB(180, 180, 180), right);
	swprintf_s(str, L"RIGHT");
	D2DMANAGER->drawText(str, right.left + 10, right.top + 20, 30);
	
	D2D_RECT_F up = { 710 + CAMERA->getPosX(),420 + CAMERA->getPosY(),810 + CAMERA->getPosX(),490 + CAMERA->getPosY() };
	if (KEYMANAGER->isStayKeyDown(VK_UP))
		D2DMANAGER->fillRectangle(RGB(50, 50, 255), up);
	else
		D2DMANAGER->fillRectangle(RGB(180, 180, 180), up);
	swprintf_s(str, L"UP");
	D2DMANAGER->drawText(str, up.left + 33, up.top + 20, 30);


	D2D_RECT_F z = { 100 + CAMERA->getPosX(),500 + CAMERA->getPosY(),200 + CAMERA->getPosX(),570 + CAMERA->getPosY() };
	if (KEYMANAGER->isStayKeyDown('Z'))
		D2DMANAGER->fillRectangle(RGB(50, 50, 255), z);
	else
		D2DMANAGER->fillRectangle(RGB(180, 180, 180), z);
	swprintf_s(str, L"Z");
	D2DMANAGER->drawText(str, z.left + 40, z.top + 20, 30);

	D2D_RECT_F x = { 210 + CAMERA->getPosX(),500 + CAMERA->getPosY(),310 + CAMERA->getPosX(),570 + CAMERA->getPosY() };
	if (KEYMANAGER->isStayKeyDown('X'))
		D2DMANAGER->fillRectangle(RGB(50, 50, 255), x);
	else
		D2DMANAGER->fillRectangle(RGB(180, 180, 180), x);
	swprintf_s(str, L"X");
	D2DMANAGER->drawText(str, x.left + 40, x.top + 20, 30);

	swprintf_s(str, L"moveDistance : %.1f", _moveDistance);
	D2DMANAGER->drawText(str, 700 + CAMERA->getPosX(), 30 + CAMERA->getPosY());
	swprintf_s(str, L"x : %d , y : %d", _tileX, _tileY);
	D2DMANAGER->drawText(str, 700 + CAMERA->getPosX(), 45 + CAMERA->getPosY());
	swprintf_s(str, L"x : %.1f , y : %.1f", _posX, _posY);
	D2DMANAGER->drawText(str, 700 + CAMERA->getPosX(), 60 + CAMERA->getPosY());
	swprintf_s(str, L"speed : %.1f", TIMEMANAGER->getElapsedTime() * PLAYER_SPEED);
	D2DMANAGER->drawText(str, 700 + CAMERA->getPosX(), 75 + CAMERA->getPosY());
}

void player::aniSetUp()
{
	KEYANIMANAGER->addAnimationType(_key);

	//�������� ���� �������Ѽ� ����Ұű⶧���� �ȳ־��
	
	
	//���������ֱ�
	int idleLeft[1] = { 21 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_left", _key.c_str(), idleLeft, 1, 10, true);
	int idleUp[1] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_up", _key.c_str(), idleUp, 1, 10, true);
	int idleDown[1] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_down", _key.c_str(), idleDown, 1, 10, true);

	//�̵�
	int moveLeft[4] = { 21,22,21,20 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_left", _key.c_str(), moveLeft, 4, 10, true);
	int moveUp[4] = { 11,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_up", _key.c_str(), moveUp, 4, 10, true);
	int moveDown[4] = { 1,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_down", _key.c_str(), moveDown, 4, 10, true);

	//�����̵�
	int fastMoveLeft[4] = { 24,25,24,23 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_left", _key.c_str(), fastMoveLeft, 4, 10, true);
	int fastMoveUp[4] = { 14,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_up", _key.c_str(), fastMoveUp, 4, 10, true);
	int fastMoveDown[4] = { 4,5,4,3 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_down", _key.c_str(), fastMoveDown, 4, 10, true);

	//PS_BICYCLE ������ ����
	int bicycleIdleLeft[1] = { 51 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_idle_left", _key.c_str(), bicycleIdleLeft, 1, 10, true);
	int bicycleIdleUp[1] = { 41 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_idle_up", _key.c_str(), bicycleIdleUp, 1, 10, true);
	int bicycleIdleDown[1] = { 31 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_idle_down", _key.c_str(), bicycleIdleDown, 1, 10, true);

	//�������̵�
	int bicycleMoveLeft[4] = { 51,52,51,50 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_move_left", _key.c_str(), bicycleMoveLeft, 4, 10, true);
	int bicycleMoveUp[4] = { 41,42,41,40 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_move_up", _key.c_str(), bicycleMoveUp, 4, 10, true);
	int bicycleMoveDown[4] = { 31,32,31,30 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_move_down", _key.c_str(), bicycleMoveDown, 4, 10, true);


	aniSetStart("idle_down");
}

void player::dataLoad()
{

}

void player::keyUpdate()
{
	if (_moveDistance == 0)
	{
		if (KEYMANAGER->isStayKeyDown(VK_LEFT))
		{
			_playerAni = KEYANIMANAGER->findAnimation(_key, "move_left");
			_playerAni->start();
			_state = PS_MOVE_LEFT;
			_moveDistance = 64.0f;
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			_playerAni = KEYANIMANAGER->findAnimation(_key, "move_left");
			_playerAni->start();
			_state = PS_MOVE_RIGHT;
			_moveDistance = 64.0f;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_playerAni = KEYANIMANAGER->findAnimation(_key, "move_down");
			_playerAni->start();
			_state = PS_MOVE_DOWN;
			_moveDistance = 64.0f;
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_playerAni = KEYANIMANAGER->findAnimation(_key, "move_up");
			_playerAni->start();
			_state = PS_MOVE_UP;
			_moveDistance = 64.0f;
		}
	}


}

void player::stateUpdate()
{
	float speed = TIMEMANAGER->getElapsedTime() * PLAYER_SPEED;



	switch (_state)
	{
		case player::PS_IDLE_LEFT:
			_isRight = false;
		break;
		case player::PS_IDLE_UP:
			_isRight = false;
		break;
		case player::PS_IDLE_RIGHT:
			_isRight = true;
		break;
		case player::PS_IDLE_DOWN:
			_isRight = false;
		break;

		case player::PS_MOVE_LEFT:
			_isRight = false;
			_posX -= speed;
			_moveDistance -= speed;
			if (_moveDistance < speed)
			{
				_posX = (int)_posX / 64 * 64 + 32;
				_playerAni = KEYANIMANAGER->findAnimation(_key, "idle_left");
				_playerAni->start();
				_state = PS_IDLE_LEFT;
				_moveDistance = 0;
				_tileX = _posX / 64;
			}
		break;
		case player::PS_MOVE_UP:
			_isRight = false;
			_posY -= speed;
			_moveDistance -= speed;
			if (_moveDistance < speed)
			{
				_posY = (int)_posY / 64 * 64 + 32;
				_playerAni = KEYANIMANAGER->findAnimation(_key, "idle_up");
				_playerAni->start();
				_state = PS_IDLE_UP;
				_moveDistance = 0;
				_tileY = _posY / 64;
			}
		break;
		case player::PS_MOVE_RIGHT:
			_isRight = true;
			_posX += speed;
			_moveDistance -= speed;
			if (_moveDistance < speed)
			{
				_posX = (int)_posX / 64 * 64 + 32;
				_playerAni = KEYANIMANAGER->findAnimation(_key, "idle_left");
				_playerAni->start();
				_state = PS_IDLE_RIGHT;
				_moveDistance = 0;
				_tileX = _posX / 64;
			}
		break;
		case player::PS_MOVE_DOWN:
			_isRight = false;
			_posY += speed;
			_moveDistance -= speed;
			if (_moveDistance < speed)
			{
				_posY = (int)_posY / 64 * 64 + 32;
				_playerAni = KEYANIMANAGER->findAnimation(_key, "idle_down");
				_playerAni->start();
				_state = PS_IDLE_DOWN;
				_moveDistance = 0;
				_tileY = _posY / 64;
			}
		break;
		case player::PS_FASTMOVE_LEFT:
			_isRight = false;
		break;
		case player::PS_FASTMOVE_UP:
			_isRight = false;
		break;
		case player::PS_FASTMOVE_RIGHT:
			_isRight = true;
		break;
		case player::PS_FASTMOVE_DOWN:
			_isRight = false;
		break;
		case player::PS_BICYCLE_IDLE_LEFT:
			_isRight = false;
		break;
		case player::PS_BICYCLE_IDLE_UP:
			_isRight = false;
		break;
		case player::PS_BICYCLE_IDLE_RIGHT:
			_isRight = true;
		break;
		case player::PS_BICYCLE_IDLE_DOWN:
			_isRight = false;
		break;
		case player::PS_BICYCLE_LEFT:
			_isRight = false;
		break;
		case player::PS_BICYCLE_UP:
			_isRight = false;
		break;
		case player::PS_BICYCLE_RIGHT:
			_isRight = true;
		break;
		case player::PS_BICYCLE_DOWN:
			_isRight = false;
		break;
		default:
		break;
	}

	
}

void player::aniSetStart(string aniKeyName)
{
	_playerAni = KEYANIMANAGER->findAnimation(_key, aniKeyName);
	_playerAni->start();
}
