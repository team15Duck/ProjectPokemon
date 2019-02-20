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
	//�̰� ���߿� �ű��
	IMAGEMANAGER->addFrameImage("healingBall", L"image/object/healing_Pokemon.png", 120, 24, 5, 1); //ȸ���Ҷ� ���̴� ���ϸ��̹���

	_isBallUp = false;
	_isHealing = false; //ȸ�����̴�?
	_count = 0;			//�����ӿ�
	_ballX = 0;			//��������ǥ
	_time = 120;
	_curPokemon = 6;	//�켱 6�����ִٰ� ġ��
	_healedPokemon = 0;

	return S_OK;
}

void object::release()
{
}

void object::update()
{
	//�ٵǸ� �̰� Ǯ��ȴ�
	//_curPokemon = PLAYERDATA->getPlayer()->getCurrentPokemonCnt();

	//�׽��� ��ư
	if (KEYMANAGER->isOnceKeyDown(VK_F9))
	{
		_isBallUp = true;
	}

	//if(_isBallUp && _sceneName == "centerScene")
		//centerHealing();

}

void object::render()
{
	//�׽���
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

	swprintf_s(str, L"�ð�: %d", _time);
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

