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

		_book[i].attr = L"???";

		_book[i].attrframeX = 0;
		_book[i].attrframeY = 0;

		_book[i].weight = L"������ :";
		_book[i].height = L"Ű :";


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
					IMAGEMANAGER->findImage("���ϸ�Ӽ�")->frameRender(600 + CAMERA->getPosX(), height + CAMERA->getPosY(), _book[i].attrframeX, _book[i].attrframeY);
					D2DMANAGER->drawText(_book[i].attr.c_str(), 640, height, 45);
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

		D2DMANAGER->drawText(_book[i].number.c_str(), 50, 100, 38); 
		D2DMANAGER->drawText(_book[i].name.c_str(), 200, 100, 38);

		D2DMANAGER->drawText(_book[i].height.c_str(), 50, 200, 38);
		D2DMANAGER->drawText(_book[i].weight.c_str(), 50, 250, 38);

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
