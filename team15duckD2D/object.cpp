#include "stdafx.h"
#include "object.h"


object::object()
{
}


object::~object()
{
}

HRESULT object::init()
{
	//이거 나중에 옮기라
	IMAGEMANAGER->addFrameImage("healingBall", L"image/object/healing_Pokemon.png", 120, 24, 5, 1); //회복할때 쓰이는 포켓몬볼이미지

	_isBallUp = false;
	_isHealing = false; //회복중이니?
	_count = 0;			//프레임용
	_ballX = 0;			//프레임좌표
	_time = 120;
	_curPokemon = 6;	//우선 6마리있다고 치자
	_healedPokemon = 0;

	return S_OK;
}

void object::release()
{
}

void object::update()
{
	//다되면 이거 풀면된다
	//_curPokemon = PLAYERDATA->getPlayer()->getCurrentPokemonCnt();

	//테슷흐 버튼
	if (KEYMANAGER->isOnceKeyDown(VK_F9))
	{
		_isBallUp = true;
	}

	//if(_isBallUp && _sceneName == "centerScene")
		//centerHealing();

}

void object::render()
{
	//테슷흐
	if (_isBallUp)
	{
		for (int i = 1; i < _healedPokemon; i++)
		{

			if (i % 2 == 0)
				IMAGEMANAGER->findImage("healingBall")->frameRender((15 * TILE_SIZE + 64)
					, (8 * TILE_SIZE + 19) + i * 7
					, _ballX
					, 0);
			else
				IMAGEMANAGER->findImage("healingBall")->frameRender((15 * TILE_SIZE + 40)
					, (8 * TILE_SIZE + 26) + i * 7
					, _ballX
					, 0);
		}
	}


	WCHAR str[128];

	swprintf_s(str, L"시간: %d", _time);
	D2DMANAGER->drawText(str, 15 * TILE_SIZE, 5 * TILE_SIZE, 20, RGB(255, 0, 255));


}

void object::centerHealing()
{

	while (_healedPokemon <= _curPokemon)
	{
		Sleep(500);
		_healedPokemon++;
		break;
	}
	if (_healedPokemon == _curPokemon)
		_isHealing = true;

	if (_isHealing && _time >= 0)
	{
		_time--;
		aniSetting();
	}
	else if (_time <= 0)
	{
		this->init();
	}

}


void object::aniSetting()
{

	_count++;
	if (_count % 5 == 0)
	{
		_ballX++;
		if (_ballX >= 4) _ballX = 1;
		_count = 0;
	}
}

