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

	
	/////////////이건나중에지울거야/////////
	_tileX = 15	;
	_tileY = 10;
	_posX = (float)_tileX * 64 + 32;
	_posY = (float)_tileY * 64 + 32;
	_isMan = true;
	_state = PS_IDLE_DOWN;
	_playTime = 5461;
	_isRight = false;
	_posZ = 0;
	_moveDistance = 0;
	_jumpPower = 0;
	_gravity = GRAVITY;
	_currentFishingTime = 0.0f;
	_maxFishingTime = 0.0f;
	_currentPokemon = 0;
	//////////////////////////////////////

	//성별따라 키값 셋팅해줌
	if (_isMan)
		_key = "playerM";
	else
		_key = "playerF";


	aniSetUp();

	EFFECTMANAGER->addEffect("grassEffect", "image/player/grassSprite.png", 256, 56, 64, 56, 7, 0.01, 20);
	EFFECTMANAGER->addEffect("footLeft", "image/player/footLeft.png", 256, 64, 64, 64, 7, 0.01, 20);
	EFFECTMANAGER->addEffect("footUp", "image/player/footUp.png", 256, 64, 64, 64, 7, 0.01, 20);
	EFFECTMANAGER->addEffect("footRight", "image/player/footRight.png", 256, 64, 64, 64, 7, 0.01, 20);
	EFFECTMANAGER->addEffect("footDown", "image/player/footDown.png", 256, 64, 64, 64, 7, 0.01, 20);
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
	EFFECTMANAGER->update();
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


	if (_state != PS_JUMP_DOWN || _state != PS_JUMP_RIGHT || _state != PS_JUMP_LEFT)
	{
		if (_isRight)
			IMAGEMANAGER->findImage(_key)->aniRenderReverseX(_posX - 75, _posY - 68 + _posZ, _playerAni);
		else
			IMAGEMANAGER->findImage(_key)->aniRender(_posX - 75, _posY - 68 + _posZ, _playerAni);
	}



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
	swprintf_s(str, L"Z : %.1f", _posZ);
	D2DMANAGER->drawText(str, 700 + CAMERA->getPosX(), 90 + CAMERA->getPosY());
}

void player::shadowRender()
{
	if (_state == PS_JUMP_DOWN || _state == PS_JUMP_RIGHT || _state == PS_JUMP_LEFT)
	{
		IMAGEMANAGER->findImage("shadow")->render(_posX - 32, _posY);
		if (_isRight)
			IMAGEMANAGER->findImage(_key)->aniRenderReverseX(_posX - 75, _posY - 68 + _posZ, _playerAni);
		else
			IMAGEMANAGER->findImage(_key)->aniRender(_posX - 75, _posY - 68 + _posZ, _playerAni);
	}
}

void player::aniSetUp()
{
	KEYANIMANAGER->addAnimationType(_key);

	//오른쪽은 왼쪽 반전시켜서 사용할거기때문에 안넣어도됨
	
	
	//가만히서있기
	int idleLeft[1] = { 21 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_left", _key.c_str(), idleLeft, 1, ANI_SPEED, true);
	int idleUp[1] = { 11 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_up", _key.c_str(), idleUp, 1, ANI_SPEED, true);
	int idleDown[1] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "idle_down", _key.c_str(), idleDown, 1, ANI_SPEED, true);

	//이동
	int moveLeft[4] = { 21,22,21,20 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_left", _key.c_str(), moveLeft, 4, ANI_SPEED, true);
	int moveUp[4] = { 11,12,11,10 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_up", _key.c_str(), moveUp, 4, ANI_SPEED, true);
	int moveDown[4] = { 1,2,1,0 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "move_down", _key.c_str(), moveDown, 4, ANI_SPEED, true);

	//빨리이동
	int fastMoveLeft[4] = { 24,25,24,23 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_left", _key.c_str(), fastMoveLeft, 4, ANI_SPEED, true);
	int fastMoveUp[4] = { 14,15,14,13 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_up", _key.c_str(), fastMoveUp, 4, ANI_SPEED, true);
	int fastMoveDown[4] = { 4,5,4,3 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fast_move_down", _key.c_str(), fastMoveDown, 4, ANI_SPEED, true);

	//PS_BICYCLE 자전거 멈춰
	int bicycleIdleLeft[1] = { 51 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_idle_left", _key.c_str(), bicycleIdleLeft, 1, ANI_SPEED, true);
	int bicycleIdleUp[1] = { 41 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_idle_up", _key.c_str(), bicycleIdleUp, 1, ANI_SPEED, true);
	int bicycleIdleDown[1] = { 31 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_idle_down", _key.c_str(), bicycleIdleDown, 1, ANI_SPEED, true);

	//자전거이동
	int bicycleMoveLeft[4] = { 51,52,51,50 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_move_left", _key.c_str(), bicycleMoveLeft, 4, ANI_SPEED, true);
	int bicycleMoveUp[4] = { 41,42,41,40 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_move_up", _key.c_str(), bicycleMoveUp, 4, ANI_SPEED, true);
	int bicycleMoveDown[4] = { 31,32,31,30 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "bicycle_move_down", _key.c_str(), bicycleMoveDown, 4, ANI_SPEED, true);


	//낚시이동
	int fishingDown[4] = { 33,34,35,36 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fishing_down", _key.c_str(), fishingDown, 4, ANI_SPEED, false);
	int fishingUp[4] = { 43,44,45,46 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fishing_up", _key.c_str(), fishingUp, 4, ANI_SPEED, false);
	int fishingLeft[4] = { 53,54,55,56 };
	KEYANIMANAGER->addArrayFrameAnimation(_key, "fishing_left", _key.c_str(), fishingLeft, 4, ANI_SPEED, false);





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
			if (_map->getTile(_tileX - 1, _tileY)->attr & ATTR_LEFT_JUMP)
			{
				aniSetStart("move_left");
				_state = PS_JUMP_LEFT;
				_moveDistance = 128.0f;
				_jumpPower = JUMP_POWER;
			}
			else
			{
				aniSetStart("move_left");
				_state = PS_MOVE_LEFT;
				_moveDistance = 64.0f;
			}
		}
		if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
		{
			if (_map->getTile(_tileX + 1, _tileY)->attr & ATTR_RIGHT_JUMP)
			{
				aniSetStart("move_left");
				_state = PS_JUMP_RIGHT;
				_moveDistance = 128.0f;
				_jumpPower = JUMP_POWER;
			}
			else
			{
				aniSetStart("move_left");
				_state = PS_MOVE_RIGHT;
				_moveDistance = 64.0f;
			}			
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			if (_map->getTile(_tileX, _tileY + 1)->attr & ATTR_DOWN_JUMP)
			{
				aniSetStart("move_down");
				_state = PS_JUMP_DOWN;
				_moveDistance = 128.0f;
				_jumpPower = JUMP_POWER;
			}
			else
			{
				aniSetStart("move_down");
				_state = PS_MOVE_DOWN;
				_moveDistance = 64.0f;
			}			
		}
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			aniSetStart("move_up");
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
			if (!(_map->getTile(_tileX - 1, _tileY)->attr & ATTR_UNMOVE))
			{
				_posX -= speed;
			}
			_moveDistance -= speed;
			if (_moveDistance < speed)
			{
				horizonSet();
				aniSetStart("idle_left");
				_state = PS_IDLE_LEFT;
				appearTileCheck();
				potalCheck();
			}
		break;
		case player::PS_MOVE_UP:
			_isRight = false;
			if (!(_map->getTile(_tileX, _tileY - 1)->attr & ATTR_UNMOVE))
			{
				_posY -= speed;
			}
			_moveDistance -= speed;
			if (_moveDistance < speed)
			{
				verticalSet();
				aniSetStart("idle_up");
				_state = PS_IDLE_UP;
				appearTileCheck();
				potalCheck();
			}
		break;
		case player::PS_MOVE_RIGHT:
			_isRight = true;
			if (!(_map->getTile(_tileX + 1, _tileY)->attr & ATTR_UNMOVE))
			{
				_posX += speed;
			}
			_moveDistance -= speed;
			if (_moveDistance < speed)
			{
				horizonSet();
				aniSetStart("idle_left");
				_state = PS_IDLE_RIGHT;
				appearTileCheck();
				potalCheck();
			}
		break;
		case player::PS_MOVE_DOWN:
			_isRight = false;
			if (!(_map->getTile(_tileX, _tileY + 1)->attr & ATTR_UNMOVE))
			{
				_posY += speed;	
			}
			_moveDistance -= speed;
			if (_moveDistance < speed)
			{
				verticalSet();
				aniSetStart("idle_down");
				_state = PS_IDLE_DOWN;
				appearTileCheck();
				potalCheck();
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

		case player::PS_JUMP_LEFT:
			_isRight = false;
			_posX -= speed;
			_moveDistance -= speed;
			_posZ -= _jumpPower * TIMEMANAGER->getElapsedTime();
			_jumpPower -= _gravity * TIMEMANAGER->getElapsedTime();
			if (_posZ > 0) _posZ = 0;
			if (_moveDistance < speed)
			{
				horizonSet();
				aniSetStart("idle_left");
				_state = PS_IDLE_LEFT;
				appearTileCheck();
				_jumpPower = 0;
				_posZ = 0;
			}
		break;
		case player::PS_JUMP_RIGHT:
			_isRight = true;
			_posX += speed;
			_moveDistance -= speed;
			_posZ -= _jumpPower * TIMEMANAGER->getElapsedTime();
			_jumpPower -= _gravity * TIMEMANAGER->getElapsedTime();
			if (_posZ > 0) _posZ = 0;
			if (_moveDistance < speed)
			{
				horizonSet();
				aniSetStart("idle_left");
				_state = PS_IDLE_RIGHT;
				appearTileCheck();
				_jumpPower = 0;
				_posZ = 0;
			}
		break;
		case player::PS_JUMP_DOWN:
			_isRight = false;
			_posY += speed;
			_moveDistance -= speed;
			_posZ -= _jumpPower * TIMEMANAGER->getElapsedTime();
			_jumpPower -= _gravity * TIMEMANAGER->getElapsedTime();
			if (_posZ > 0) _posZ = 0;
			if (_moveDistance < speed)
			{
				verticalSet();
				aniSetStart("idle_down");
				_state = PS_IDLE_DOWN;
				appearTileCheck();
				_jumpPower = 0;
				_posZ = 0;
			}
		break;
		case player::PS_FISHING_LEFT:
			_isRight = false;
			_currentFishingTime += TIMEMANAGER->getElapsedTime();
			if (_currentFishingTime > _maxFishingTime)
			{
				_currentFishingTime = 0;
				//잉어킹자리
				pokemon* enemy = new pokemon;
				enemy->init(NULL, PM_MAGIKARP, 5, false);
				PLAYERDATA->setPokemon(enemy);
				SCENEMANAGER->changeScene("battleScene");
			}

		break;
		case player::PS_FISHING_UP:
			_isRight = false;
			_currentFishingTime += TIMEMANAGER->getElapsedTime();
			if (_currentFishingTime > _maxFishingTime)
			{
				_currentFishingTime = 0;
				//잉어킹자리
				pokemon* enemy = new pokemon;
				enemy->init(NULL, PM_MAGIKARP, 5, false);
				PLAYERDATA->setPokemon(enemy);
				SCENEMANAGER->changeScene("battleScene");
			}

		break;
		case player::PS_FISHING_RIGHT:
			_isRight = true;
			_currentFishingTime += TIMEMANAGER->getElapsedTime();
			if (_currentFishingTime > _maxFishingTime)
			{
				_currentFishingTime = 0;
				//잉어킹자리
				pokemon* enemy = new pokemon;
				enemy->init(NULL, PM_MAGIKARP, 5, false);
				PLAYERDATA->setPokemon(enemy);
				SCENEMANAGER->changeScene("battleScene");
			}

		break;
		case player::PS_FISHING_DOWN:
			_isRight = false;
			_currentFishingTime += TIMEMANAGER->getElapsedTime();
			if (_currentFishingTime > _maxFishingTime)
			{
				_currentFishingTime = 0;
				//잉어킹자리
				pokemon* enemy = new pokemon;
				enemy->init(NULL, PM_MAGIKARP, 5, false);
				PLAYERDATA->setPokemon(enemy);
				SCENEMANAGER->changeScene("battleScene");
			}
		break;
		default:
		break;
	}

	
}

void player::horizonSet()
{
	_posX = (int)_posX / 64 * 64 + 32;
	_moveDistance = 0;
	_tileX = _posX / 64;
}

void player::verticalSet()
{
	_posY = (int)_posY / 64 * 64 + 32;
	_moveDistance = 0;
	_tileY = _posY / 64;
}

void player::aniSetStart(string aniKeyName)
{
	_playerAni = KEYANIMANAGER->findAnimation(_key, aniKeyName);
	_playerAni->start();
}

void player::appearTileCheck()
{
	if (_map->getTile(_tileX, _tileY)->attr & ATTR_APPEAR)
	{
		
		if (_currentSceneName == "caveScene")
		{
			if (_map->getTile(_tileX, _tileY)->attr & ATTR_FOOT_PRINT)
			{
				switch (_state)
				{
				case player::PS_IDLE_LEFT:
					EFFECTMANAGER->play("footLeft", _posX, _posY);
					break;
				case player::PS_IDLE_UP:
					EFFECTMANAGER->play("footUp", _posX, _posY);
					break;
				case player::PS_IDLE_RIGHT:
					EFFECTMANAGER->play("footRight", _posX, _posY);
					break;
				case player::PS_IDLE_DOWN:
					EFFECTMANAGER->play("footDown", _posX, _posY);
					break;

				}
			}
		}
		else if (_currentSceneName != "caveScene")
		{
			EFFECTMANAGER->play("grassEffect", _posX, _posY + 5);
		}
		bool meet = RND->getInt(10) < 0 ? true : false;
		if (meet)
		{
			pokemon* enemy = new pokemon;
			enemy->init(NULL, _map->getPokemon(), _map->getLevel(), false);
			PLAYERDATA->setPokemon(enemy);
			SCENEMANAGER->changeScene("battleScene");
		}
	}
	
}

void player::potalCheck()
{
	if (_map->getTile(_tileX, _tileY)->attr & ATTR_POTAL)
	{
		mapData::potalInfo potal;
		for (int i = 0; i < _map->getPotal().size(); i++)
		{	
			if (_map->getPotal()[i].x == _tileX && _map->getPotal()[i].y == _tileY)
			{
				potal = _map->getPotal()[i];
				break;
			}
		}
		_tileX = potal.nextX;
		_tileY = potal.nextY;

		_posX = (float)_tileX * 64 + 32;
		_posY = (float)_tileY * 64 + 32;

		switch (potal.nextDirection)
		{
			//왼
			case 0:
				_state = PS_MOVE_LEFT;
				_isRight = false;
				aniSetStart("move_left");
				_moveDistance = 64;
			break;
			//위
			case 1: 
				_state = PS_MOVE_UP;
				_isRight = false;
				aniSetStart("move_up");
				_moveDistance = 64;
			break;
			//오
			case 2:
				_state = PS_MOVE_RIGHT;
				_isRight = true;
				aniSetStart("move_left");
				_moveDistance = 64;
			break;
			//아래
			case 3:
				_state = PS_MOVE_DOWN;
				_isRight = false;
				aniSetStart("move_down");
				_moveDistance = 64;
			break;
		}

		SCENEMANAGER->changeScene(potal.nextScene);
	}
}

void player::fishingStart()
{
	_maxFishingTime = RND->getFromIntTo(5, 11);
	_currentFishingTime = 0.0f;
	switch (_state)
	{
		//IDLE 상태에서만 낚시 가능하겠져?
		case player::PS_IDLE_LEFT:
			if (_map->getTile(_tileX - 1, _tileY)->attr & ATTR_WATER)
			{
				aniSetStart("fishing_left");
				_state = PS_FISHING_LEFT;
			}
		break;
		case player::PS_IDLE_UP:
			if (_map->getTile(_tileX, _tileY - 1)->attr & ATTR_WATER)
			{
				aniSetStart("fishing_up");
				_state = PS_FISHING_UP;
			}
		break;
		case player::PS_IDLE_RIGHT:
			if (_map->getTile(_tileX + 1, _tileY)->attr & ATTR_WATER)
			{
				aniSetStart("fishing_left");
				_state = PS_FISHING_RIGHT;
			}
		break;
		case player::PS_IDLE_DOWN:
			if (_map->getTile(_tileX, _tileY + 1)->attr & ATTR_WATER)
			{
				aniSetStart("fishing_down");
				_state = PS_FISHING_DOWN;				
			}
		break;
	}
}
