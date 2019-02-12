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
	//���࿡ ������ ��ȣ�� 0���� ũ�ٸ�
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
	//���࿡ ������ ���ڰ� 150���� �۴ٸ�
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
		D2DMANAGER->drawText(_book[i].name.c_str(), 100, height, 50);

		//���࿡ i�� ������ ��ȣ��� 
		if (i == _currentSelectNum)
		{

			IMAGEMANAGER->findImage("ȭ��ǥ")->render(76 + CAMERA->getPosX(), height + 9 + CAMERA->getPosY());
		}
	}

}
