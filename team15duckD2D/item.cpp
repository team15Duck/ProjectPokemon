#include "stdafx.h"
#include "item.h"


item::item()
{
}


item::~item()
{
}

HRESULT item::init()
{
	initImg();
	return S_OK;
}

HRESULT item::init(int value, ITEM_TYPE type)
{
	//_img = IMAGEMANAGER->findImage()
	_itemValue = value;
	_itemType = type;


	switch (type)
	{
		case MONSTER_BALL:
		{

			break;
		}
		case SUPER_BALL:
		{

			break;
		}
		case HYPER_BALL:
		{

			break;
		}
		case NORMAL_POTION:
		{
			_frameNum = 0;
			break;
		}

	}


	return S_OK;
}

void item::release()
{
}

void item::update()
{
}

void item::render()
{
}

void item::initImg()
{
	//몬스터볼
	IMAGEMANAGER->addFrameImage("ball", L"image/monsterball_shop.png", 298, 72, 4, 1);

	//상처약
	IMAGEMANAGER->addFrameImage("potion", L"image/healing_HP.png", 186, 84, 3, 1);
	IMAGEMANAGER->addFrameImage("restore", L"image/restore.png", 132, 88, 2, 1);

	//PP회복
	IMAGEMANAGER->addFrameImage("elixir", L"image/healing_PP.png", 264, 88, 4, 1);

	//상태이상회복제
	IMAGEMANAGER->addFrameImage("stateError", L"image/healing_Condition.png", 324, 84, 6, 1);
}
