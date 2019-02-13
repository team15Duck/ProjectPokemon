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
			_book[i].number = L"No.00" + to_wstring(i + 1);
		}
		else if (i < 99)
		{
			_book[i].number = L"No.0" + to_wstring(i + 1);
		}
		else
		{
			_book[i].number = L"No." + to_wstring(i + 1);
		}
		//if (!_isdataexist)
		{
			_book[i].name = L" _ _ _ _ _";
		}

		_book[i].attr   = L"???";

		_book[i].attrframeX = 0;
		_book[i].attrframeY = 0;

		_book[i].weight = L"???";
		_book[i].height = L"???";
		
		
		_book[i].isDataSet = false;
	}

	_currentSelectNum  = 0;
	_selectNumMoveCount = 0;
	_selectNumMoveDelay = 0.1f;

	

	_isdataexist = true;
	_isdetaileinfo = false;

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

	for (int i = 0; i < 151; ++i)
	{
		if (_currentSelectNum == i)
		{
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_isdetaileinfo = true;
			}

			if (_isdetaileinfo)
			{
				if (KEYMANAGER->isOnceKeyDown('X'))
				{
					_isdetaileinfo = false;
				}
			}
		}
	}
}

void IllustratedBook::render()
{
	IMAGEMANAGER->findImage("도감")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
	WCHAR pokemon_book[1024];
	swprintf_s(pokemon_book, L"포켓몬 도감 목록");
	D2DMANAGER->drawText(pokemon_book, 285 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(160, 160, 160));
	swprintf_s(pokemon_book, L"포켓몬 도감 목록");
	D2DMANAGER->drawText(pokemon_book, 280 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(255, 255, 255));

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
		D2DMANAGER->drawText(_book[i].number.c_str(), 100, height, 50);

		if (!_isdataexist)
		{
			D2DMANAGER->drawText(_book[i].name.c_str(), 300, height, 50);
		}
		else
		{
			D2DMANAGER->drawText(_book[i].name.c_str(), 300, height, 50);
			if (_book[i].isDataSet)
			{
				IMAGEMANAGER->findImage("포켓몬속성")->frameRender(600 + CAMERA->getPosX(), height + CAMERA->getPosY(), _book[i].attrframeX, _book[i].attrframeY);
				D2DMANAGER->drawText(_book[i].attr.c_str(), 640, height, 45);
			}
			
		}

		//만약에 i가 선택한 번호라면 
		if (i == _currentSelectNum)
		{

			IMAGEMANAGER->findImage("화살표")->render(76 + CAMERA->getPosX(), height + 9 + CAMERA->getPosY());
		}
	}

	if (_isdetaileinfo)
	{
		IMAGEMANAGER->findImage("도감")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
	}
	
}

void IllustratedBook::pokemonDataSet()
{
	locale("kor");
	
	for (int i = 0; i < 151; ++i)
	{
		pokemonInfo* info = POKEMONDATA->getPokemonInfomation((POKEMON)i);
		
		if (info == nullptr) continue;
		_book[i].isDataSet = true;
		_book[i].name.clear();

		_book[i].name = string2wstring(*info->getPokemonName());

		switch (info->getPokemonType())
		{
			case PM_TYPE_NORMAL:
			
				_book[i].attr = L"노말";
				_book[i].attrframeX = 1;
				_book[i].attrframeY = 0;
			break;
			case PM_TYPE_FIRE:

				_book[i].attr = L"불";
				_book[i].attrframeX = 4;
				_book[i].attrframeY = 0;
			break;
			case PM_TYPE_WATER:
				_book[i].attr = L"물";
				_book[i].attrframeX = 0;
				_book[i].attrframeY = 1;
			break;
			case PM_TYPE_ELECTRONIC:
				_book[i].attr = L"전기";
				_book[i].attrframeX = 5;
				_book[i].attrframeY = 0;
			break;
			case PM_TYPE_GRASS:
				_book[i].attr = L"풀";
				_book[i].attrframeX = 6;
				_book[i].attrframeY = 1;
			break;
		}
	}
}
