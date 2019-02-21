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

	//������ ó�� �����ϸ� ��µǴ� ȭ���� ����Ʈ�̴�.

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

		_book[i].tagweight = L"���� : ";
		_book[i].tagheight = L"Ű :";
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
		//���� ��� �̵����� 
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

		//���� ������ Ȱ��ȭ 
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_pbstate = BOOK_INFO;
		}
	}
	//���� ������ ��Ȱ��ȭ
	if (_pbstate == BOOK_INFO)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_pbstate = BOOK_LIST;
		}
	}
	//����ȭ������ ���ư���
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
	IMAGEMANAGER->findImage("����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);

	if (_pbstate == BOOK_LIST)
	{
		// �����ִ� ����� ���� ������ ��ȣ - 5
		int i = _currentSelectNum - 5;
		//  �ִ� �����ִ� ����� ���� ������ ��ȣ +5
		int iMax = _currentSelectNum + 5;
		// ���ִ� ����� ������ 0���� �۴ٸ� 0���� ���� 
		if (i < 0)
		{
			i = 0;
		}
		//���࿡ �����ִ� ��� ������ 0 �̶�� �ִ� �����ִ°Ŵ� 10�̴�.
		if (i == 0)
		{
			iMax = 10;
		}
		//���࿡ �ִ뺸���ִ� ����� 151 ���� ũ�ٸ�
		if (iMax > 151)
		{
			iMax = 151;			//�� ����
		}
		//���࿡ �ִ뺸���ִ� ����� 151�̶�� 
		if (iMax == 151)
		{
			i = 141;		// �����ִ� ��� ������ 141
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
					IMAGEMANAGER->findImage("���ϸ�Ӽ�")->frameRender(600 + CAMERA->getPosX(), height + CAMERA->getPosY(), _book[i].attrframeX, _book[i].attrframeY);
					D2DMANAGER->drawText(_book[i].attr.c_str(), 640 + CAMERA->getPosX(), height + CAMERA->getPosY(), 45);
				}

			}

			//���࿡ i�� ������ ��ȣ��� 
			if (i == _currentSelectNum)
			{
				IMAGEMANAGER->findImage("ȭ��ǥ")->render(76 + CAMERA->getPosX(), height + 9 + CAMERA->getPosY());
			}
		}
	}
	else if (_pbstate == BOOK_INFO)
	{
		IMAGEMANAGER->findImage("����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
	
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
	swprintf_s(pokemon_book, L"���ϸ� ���� ���");
	D2DMANAGER->drawText(pokemon_book, 285 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(160, 160, 160));
	swprintf_s(pokemon_book, L"���ϸ� ���� ���");
	D2DMANAGER->drawText(pokemon_book, 280 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(255, 255, 255));
	swprintf_s(pokemon_book, L"�������ϴ�?:%d", _pbstate);
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

			_book[i].attr = L"�븻";
			_book[i].attrframeX = 1;
			_book[i].attrframeY = 0;
			break;
		case PM_TYPE_FIRE:

			_book[i].attr = L"��";
			_book[i].attrframeX = 4;
			_book[i].attrframeY = 0;
			break;
		case PM_TYPE_WATER:
			_book[i].attr = L"��";
			_book[i].attrframeX = 0;
			_book[i].attrframeY = 1;
			break;
		case PM_TYPE_ELECTRONIC:
			_book[i].attr = L"����";
			_book[i].attrframeX = 5;
			_book[i].attrframeY = 0;
			break;
		case PM_TYPE_GRASS:
			_book[i].attr = L"Ǯ";
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
