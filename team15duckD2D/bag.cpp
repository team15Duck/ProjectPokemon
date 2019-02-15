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
	_currentSelectNum = 0;
	_currentitemamount	= 0  ;
	_maxitemamount		= 0  ;

	_selectNumMoveCount = 0;
	_selectNumMoveDelay = 0.1f;


	return S_OK;
}

void bag::release()
{
}

void bag::update()
{
	//가방 이동관련

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
}

void bag::render()
{
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
	for (;  i < iMax; ++i, height += 63)
	{
		D2DMANAGER->drawText(_bag[i].name.c_str(), 400, height, 40);
		D2DMANAGER->drawText(_bag[i].amount.c_str(), 870, height, 40);
		//만약에 i가 선택한 번호라면 
		if (i == _currentSelectNum)
		{

			int frameX;
			frameX = _currentSelectNum % IMAGEMANAGER->findImage("items")->GetMaxFrameX();

			IMAGEMANAGER->findImage("화살표")->render(370 + CAMERA->getPosX(), height+ CAMERA->getPosY());
			IMAGEMANAGER->findImage("items")->frameRender(30 + CAMERA->getPosX(), 495 + CAMERA->getPosY(), frameX, 0);



			D2DMANAGER->drawText(_bag[i].info.c_str(), 100, 495, 38);
		}
	}
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
		_bag[i].type = to_wstring(bagItem.getItemType());
		_bag[i].info = string2wstring(bagItem.getItemInfo());
		_bag[i].amount = to_wstring(bagItem.getItemNum());
	}

}
