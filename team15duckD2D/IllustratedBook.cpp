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

	//도감에 처음 진입하면 출력되는 화면은 리스트이다.

	_pbstate = BOOK_LIST;


	for (int i = 0; i < 151; i++)
	{
		_book[i].isCatch = false;

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

		if (_book[i].isCatch == false)
		{
			_book[i].weight = L"?????";
			_book[i].height = L"?????";
			_book[i].info = L" ";
		}


		_book[i].attr = L"???";

		_book[i].tagweight = L"무게 : ";
		_book[i].tagheight = L"키 :";
		_book[i].tagkg = L"kg";
		_book[i].tagcm = L"cm";


		_book[i].attrframeX = 0;
		_book[i].attrframeY = 0;


		_book[i].isDataSet = false;
	}

	_currentSelectNum = 0;
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
	if (_pbstate == BOOK_LIST)
	{
		//도감 목록 이동관련 
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
			if (_currentSelectNum < 150)
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

		//하위 상세정보 활성화 
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_pbstate = BOOK_INFO;
		}
	}
	//하위 상세정보 비활성화
	if (_pbstate == BOOK_INFO)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_pbstate = BOOK_LIST;
		}
	}
	//메인화면으로 돌아가기
	if (_pbstate == BOOK_LIST)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			UIMANAGER->selectUI(UI_MAIN);
		}
	}
}

void IllustratedBook::render()
{
	IMAGEMANAGER->findImage("도감")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);

	if (_pbstate == BOOK_LIST)
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
			D2DMANAGER->drawText(_book[i].number.c_str(), 100 + CAMERA->getPosX(), height + CAMERA->getPosY(), 50);

			if (!_isdataexist)
			{
				D2DMANAGER->drawText(_book[i].name.c_str(), 300 + CAMERA->getPosX(), height + CAMERA->getPosY() , 50);
			}
			else
			{
				D2DMANAGER->drawText(_book[i].name.c_str(), 300 + CAMERA->getPosX(), height + CAMERA->getPosY() , 50);
				if (_book[i].isDataSet)
				{
					IMAGEMANAGER->findImage("포켓몬속성")->frameRender(600 + CAMERA->getPosX(), height + CAMERA->getPosY(), _book[i].attrframeX, _book[i].attrframeY);
					D2DMANAGER->drawText(_book[i].attr.c_str(), 640 + CAMERA->getPosX(), height + CAMERA->getPosY(), 45);
				}

			}

			//만약에 i가 선택한 번호라면 
			if (i == _currentSelectNum)
			{
				IMAGEMANAGER->findImage("화살표")->render(76 + CAMERA->getPosX(), height + 9 + CAMERA->getPosY());
			}
		}
	}
	else if (_pbstate == BOOK_INFO)
	{
		IMAGEMANAGER->findImage("도감")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
	
		int i = _currentSelectNum;

		int index;
		int frameX;
		int frameY;

		index = _currentSelectNum * 2;
		frameX = index % (IMAGEMANAGER->findImage("pokemon_ingame")->GetMaxFrameX() + 1);
		frameY = index / (IMAGEMANAGER->findImage("pokemon_ingame")->GetMaxFrameX() + 1);

		IMAGEMANAGER->findImage("pokemon_ingame")->frameRender(650 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), frameX, frameY);

		D2DMANAGER->drawText(_book[i].number.c_str(), 50 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 38);
		D2DMANAGER->drawText(_book[i].name.c_str(), 200 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 38);

		D2DMANAGER->drawText(_book[i].tagheight.c_str(), 50 + CAMERA->getPosX(), 200 + CAMERA->getPosY(), 38);
		D2DMANAGER->drawText(_book[i].height.c_str(), 150 + CAMERA->getPosX(), 200 + CAMERA->getPosY(), 38);
		D2DMANAGER->drawText(_book[i].tagcm.c_str(), 300 + CAMERA->getPosX(), 200 + CAMERA->getPosY(), 38);
		D2DMANAGER->drawText(_book[i].tagweight.c_str(), 50 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 38);
		D2DMANAGER->drawText(_book[i].weight.c_str(), 200 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 38);
		D2DMANAGER->drawText(_book[i].tagkg.c_str(), 400 + CAMERA->getPosX(), 250 + CAMERA->getPosY(), 38);

		D2DMANAGER->drawText(_book[i].info.c_str(), 50 + CAMERA->getPosX(), 400 + CAMERA->getPosY(), 22);

	}


	WCHAR pokemon_book[1024];
	swprintf_s(pokemon_book, L"포켓몬 도감 목록");
	D2DMANAGER->drawText(pokemon_book, 285 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(160, 160, 160));
	swprintf_s(pokemon_book, L"포켓몬 도감 목록");
	D2DMANAGER->drawText(pokemon_book, 280 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(255, 255, 255));
	swprintf_s(pokemon_book, L"도감뭐하니?:%d", _pbstate);
	D2DMANAGER->drawText(pokemon_book, 750 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 20, RGB(255, 255, 255));

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
		_book[i].height = to_wstring(info->getHeight());
		_book[i].weight = to_wstring( info->getWeight());
		_book[i].info = string2wstring(*info->getPokemonDescription());
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

void IllustratedBook::uiInfoSet()
{
	pokemonDataSet();
}
