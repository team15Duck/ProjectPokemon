#include "stdafx.h"
#include "IllustratedBook.h"


IllustratedBook::IllustratedBook()
{
}


IllustratedBook::~IllustratedBook()
{
}

HRESULT IllustratedBook::init()
{
	for (int i = 0; i < 151; i++)
	{
		if (i < 9)
		{
			_book[i].name = L"No.00" + to_wstring(i + 1);
		}
		else if (i < 99)
		{
			_book[i].name = L"No.0" + to_wstring(i + 1);
		}
		else
		{
			_book[i].name = L"No." + to_wstring(i + 1);
		}
		_book[i].attr   = L"???";
		_book[i].weight = L"???";
		_book[i].height = L"???";
	}

	_currentSelectNum  = 0;
	_selectNumMoveCount = 0;
		_selectNumMoveDelay = 0.1f;
	return S_OK;
}

void IllustratedBook::release()
{
}

void IllustratedBook::update()
{
	//만약에 선택한 번호가 0보다 크다면
	if (_currentSelectNum >= 0)
	{
		
		if (KEYMANAGER->isStayKeyDown(VK_UP))
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
		else if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_currentSelectNum += 9;
			if (_currentSelectNum > 150)
			{
				_currentSelectNum = 150;
			}
		}
	}
	//만약에 선택한 숫자가 150보다 작다면
	if (_currentSelectNum < 150)
	{
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
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
		else if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_currentSelectNum -= 9;

			if (_currentSelectNum < 0) 
			  {
				_currentSelectNum = 0;
			}
		}
	}
}

void IllustratedBook::render()
{
	// 보여주는 목록은 현재 선택한 번호 - 5
	int i = _currentSelectNum - 5;
	//  최대 보여주는 목록은 현재 선택한 번호 +5
	int iMax = _currentSelectNum + 5;
	// 모여주는 목록이 시작이 0보다 작다면 0으로 고정 
	if (i < 0)
	{
		i = 0;
	}
	//만약에 보여주는 목록 시작이 0 이라면 최대 보여주는거는 10이다.
	if (i == 0)
	{
		iMax = 10;
	}
	//만약에 최대보여주는 목록이 151 보다 크다면
	if (iMax > 151)
	{
		iMax = 151;			//값 고정
	}
	//만약에 최대보여주는 목록이 151이라면 
	if (iMax == 151)
	{
		i = 141;		// 보여주는 목록 시작은 141
	}


	int height = 70;
	for (; i < iMax; i++, height += 48)
	{
		D2DMANAGER->drawText(_book[i].name.c_str(), 100, height, 50);

		//만약에 i가 선택한 번호라면 
		if (i == _currentSelectNum)
		{

			IMAGEMANAGER->findImage("화살표")->render(76 + CAMERA->getPosX(), height + 9 + CAMERA->getPosY());
		}
	}

}
