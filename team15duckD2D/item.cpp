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
	return S_OK;
}

HRESULT item::init(string name, ITEM_TYPE type, int value, int buyPrice, int sellPrice, int num)
{
	_img = IMAGEMANAGER->findImage("items");
	_itemName = name;											//아이템이름
	_itemValue = value;											//적용값
	_itemType = type;											//종류
	_buyPrice = buyPrice;										//구입가
	_sellPrice = sellPrice;										//매매가
	_rcPos = { 80, WINSIZEY - 100 };							//렉트위치
	_imgPos.x = _rcPos.x - _img->GetFrameWidth() / 2;			//이미지 그릴위치 (X)
	_imgPos.y = _rcPos.y - _img->GetFrameWidth() / 2;			//이미지 그릴위치 (Y)


	switch (type)
	{
		case MONSTER_BALL:
		case SUPER_BALL:
		case HYPER_BALL:
		case MASTER_BALL:
		{
			_imgSize = { 72, 72 };
			break;
		}
		case NORMAL_POTION:
		case SUPER_POTION:
		case HYPER_POTION:
		{

			_imgSize = { 60, 84 };
			break;
		}
		case MAX_POTION:
		{
			_imgSize = { 64, 88 };
			break;
		}
		case FULL_RESTORE:
		{
			//여기서 상태이상을 가져와서 바꾸면 어떨까?
			_imgSize = { 64, 88 };
			break;
		}
		case NORMAL_ETHER:
		case MAX_ETHER:
		case NORMAL_ELIXIR:
		case MAX_ELIXIR:
		{
			_imgSize = { 64, 88 };
			break;
		}

		case ANTIDOTE:
		case PARLYZE_HEAL:
		case BURN_HEAL:
		case ICE_HEAL:
		case AWAKENING:
		case FULL_HEAL:
		{
			_imgSize = { 52, 84 };
			break;
		}
		case RARE_CANDY:
		{
			_imgSize = { 84, 84 };
			break;
		}
		case ESCAPE_ROPE:
		{
			_imgSize = { 84, 68 };
			break;
		}
		case REVIVE:
		{
			_imgSize = { 40, 60 };
			break;
		}
		case BICYCLE:
		{
			_imgSize = { 84, 88 };
			break;
		}
		case FISHING_ROD:
		{
			_imgSize = { 88, 84 };
			break;
		}
		case TOWN_MAP:
		{
			_imgSize = { 84, 76 };
			break;
		}
		case TM_CASE:
		{
			_imgSize = { 88, 72 };
			break;
		}
	}

	return S_OK;
}

void item::release()
{
	_img = nullptr;
}

void item::update()
{
}

void item::render()
{
	_img->frameRender(_imgPos.x + CAMERA->getPosX(), _imgPos.y + CAMERA->getPosY(), _itemType, 0, 1.0f);
}