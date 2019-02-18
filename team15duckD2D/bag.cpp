#include "stdafx.h"
#include "bag.h"


bag::bag()
{
}


bag::~bag()
{
}

HRESULT bag::init()
{
	_bag_state = ITEM_LIST;

	_currentSelectNum = 0;
	_currentitemamount	= 0  ;
	_maxitemamount		= 0  ;

	_selectNumMoveCount = 0;
	_selectNumMoveDelay = 0.1f;


	_isitemUse = false;

	MENUMANAGER->addFrame("아이템사용", 700, 300, 8, 10);
	IMAGEMANAGER->addFrameImage("남여가방", L"image/common_menu/bag/item_bag.png", 472, 257, 2, 1);
	return S_OK;
}

void bag::release()
{
}

void bag::update()
{
	if (_bag_state == ITEM_LIST)
	{
		//가방 이동관련
		if (!_isitemUse)
		{
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				if (_currentSelectNum >= 0)
				{
					_selectNumMoveCount += TIMEMANAGER->getElapsedTime();
					if (_selectNumMoveCount >= _selectNumMoveDelay)
					{
						_selectNumMoveCount = 0;
						if (_currentSelectNum != 0)
						{
							_currentSelectNum--;
						}
					}
				}
			}
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				if (_currentSelectNum < 39)
				{
					_selectNumMoveCount += TIMEMANAGER->getElapsedTime();
					if (_selectNumMoveCount >= _selectNumMoveDelay)
					{
						_selectNumMoveCount = 0;
						if (_currentSelectNum != 150)
						{
							_currentSelectNum++;
						}
					}
				}
			}
			//아이템 사용관련 
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_isitemUse = true;
			}
		}

		if (_isitemUse)
		{
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				_isitemUse = false;
			}

			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				switch (_item_use)
				{
					case ITEM_USE:
						_item_use = ITEM_STATE_NONE;
					break;
					case ITEM_PASS:
						_item_use = ITEM_USE;
					break;
					case ITEM_THROW_AWAY:
						_item_use = ITEM_PASS;
					break;
					case ITEM_STATE_NONE:
						_item_use = ITEM_THROW_AWAY;
					break;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				switch (_item_use)
				{
					case ITEM_USE:
						_item_use = ITEM_PASS;
					break;
					case ITEM_PASS:
						_item_use = ITEM_THROW_AWAY;
					break;
					case ITEM_THROW_AWAY:
						_item_use = ITEM_STATE_NONE;
					break;
					case ITEM_STATE_NONE:
						_item_use = ITEM_USE;
					break;
				}
			}
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				switch (_item_use)
				{
				case ITEM_USE:
					UIMANAGER->selectUI(UI_POKEMON);
					break;
				case ITEM_PASS:
					UIMANAGER->selectUI(UI_POKEMON);
					break;
				case ITEM_THROW_AWAY:
					_item_use = ITEM_STATE_NONE;
					break;
				case ITEM_STATE_NONE:
					_item_use = ITEM_USE;
					break;
				}
			}
		}
		
		//메인메뉴로 이동하기
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			UIMANAGER->selectUI(UI_MAIN);
		}
	}
}

void bag::render()
{
	WCHAR itemuse[1024];
	if (_bag_state == ITEM_LIST)
	{
		IMAGEMANAGER->findImage("가방메뉴배경")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
		IMAGEMANAGER->findImage("남여가방")->frameRender(45 + CAMERA->getPosX(), 160 + CAMERA->getPosY(), 0, 0);
		//실제 게임으로 들어가면 이걸로바꿔야뎀
		//unordered_map<ITEM_TYPE, UINT> itemList = PLAYERDATA->getPlayet()->getItem();
		//imax 비교연산 녀석 size로 변경해야됨 
		//이거 사이즈이상하게나옴 ㅠ 수정필요 
		//unordered_map<ITEM_TYPE, UINT> itemList;

		int i = _currentSelectNum - 3;
		int iMax = _currentSelectNum + 3;

		if (i < 0)
		{
			i = 0;
		}
		if (i == 0)
		{
			iMax = 6;
		}
		if (iMax > 39)
		{
			iMax = 39;
		}
		if (iMax == 39)
		{
			i = 33;
		}

		int height = 48;
		for (; i < iMax; ++i, height += 63)
		{
			D2DMANAGER->drawText(_bag[i].name.c_str(), 400, height, 40);
			D2DMANAGER->drawText(_bag[i].amount.c_str(), 870, height, 40);
			//만약에 i가 선택한 번호라면 
			if (i == _currentSelectNum)
			{

				IMAGEMANAGER->findImage("화살표")->render(370 + CAMERA->getPosX(), height + CAMERA->getPosY());
				IMAGEMANAGER->findImage("items")->frameRender(30 + CAMERA->getPosX(), 495 + CAMERA->getPosY(), _bag[i].type, 0);

				if (!_isitemUse)
				{
					D2DMANAGER->drawText(_bag[i].info.c_str(), 100, 495, 38);
				}
			}
			if (_isitemUse)
			{
				MENUMANAGER->findMenuFrame("아이템사용")->render();

				swprintf_s(itemuse, L"사용하기");
				D2DMANAGER->drawText(itemuse, 760 + CAMERA->getPosX(), 330 + CAMERA->getPosY(), 40);
				swprintf_s(itemuse, L"건네주기");
				D2DMANAGER->drawText(itemuse, 760 + CAMERA->getPosX(), 400 + CAMERA->getPosY(), 40);
				swprintf_s(itemuse, L"버리기");
				D2DMANAGER->drawText(itemuse, 760 + CAMERA->getPosX(), 470 + CAMERA->getPosY(), 40);
				swprintf_s(itemuse, L"그만두기");
				D2DMANAGER->drawText(itemuse, 760 + CAMERA->getPosX(), 540 + CAMERA->getPosY(), 40);
			
				switch (_item_use)
				{
				case ITEM_USE:
					IMAGEMANAGER->findImage("화살표")->render(735 + CAMERA->getPosX(), 330 + CAMERA->getPosY());
					break;
				case ITEM_PASS:
					IMAGEMANAGER->findImage("화살표")->render(735 + CAMERA->getPosX(), 400 + CAMERA->getPosY());
					break;
				case ITEM_THROW_AWAY:
					IMAGEMANAGER->findImage("화살표")->render(735 + CAMERA->getPosX(), 470 + CAMERA->getPosY());
					break;
				case ITEM_STATE_NONE:
					IMAGEMANAGER->findImage("화살표")->render(735 + CAMERA->getPosX(), 540 + CAMERA->getPosY());
					break;
				}
			
			}
		}
	}
}

void bag::uiInfoSet()
{
	itemDataSet();
}

void bag::itemDataSet()
{
	locale("kor");

	//unordered_map<ITEM_TYPE, UINT> itemList = PLAYERDATA->getPlayet()->getItem();

	//=====================================================================테스트용 삭제할거임
	unordered_map<ITEM_TYPE, UINT> itemList;

	itemList.insert(make_pair((ITEM_TYPE)0, 1));
	itemList.insert(make_pair((ITEM_TYPE)1, 1));
	itemList.insert(make_pair((ITEM_TYPE)2, 1));
	itemList.insert(make_pair((ITEM_TYPE)3, 1));
	itemList.insert(make_pair((ITEM_TYPE)4, 1));
	itemList.insert(make_pair((ITEM_TYPE)5, 1));
	itemList.insert(make_pair((ITEM_TYPE)6, 1));
	itemList.insert(make_pair((ITEM_TYPE)7, 1));
	itemList.insert(make_pair((ITEM_TYPE)8, 1));
	itemList.insert(make_pair((ITEM_TYPE)9, 1));
	itemList.insert(make_pair((ITEM_TYPE)10, 1));
	itemList.insert(make_pair((ITEM_TYPE)11, 1));
	itemList.insert(make_pair((ITEM_TYPE)12, 1));

	//======================================================================================


	unordered_map<ITEM_TYPE, UINT>::iterator iter = itemList.begin();
	unordered_map<ITEM_TYPE, UINT>::iterator end = itemList.end();

	for (int i = 0; iter != end && i < 39; ++iter, ++i)
	{
		if (iter->second == 0) continue;
		
		_bag[i]._isDataset = true;
		_bag[i].name.clear();

		item bagItem;
		bagItem.init(iter->first);

		_bag[i].name = string2wstring(bagItem.getItemName());
		_bag[i].type = bagItem.getItemType();
		_bag[i].info = string2wstring(bagItem.getItemInfo());
		_bag[i].amount = to_wstring(bagItem.getItemNum());
	}

}
