#include "stdafx.h"
#include "hayoungTestScene.h"


hayoungTestScene::hayoungTestScene()
{
}


hayoungTestScene::~hayoungTestScene()
{
}

HRESULT hayoungTestScene::init()
{
	frameImageinit();

	_cm._bottom = { 0, 490, 960, 640 };

	_cm._menu[0] = { 726, 33, 926, 93 };
	_cm._menu[1] = { 726, 93, 926, 153 };
	_cm._menu[2] = { 726, 153, 926, 213 };
	_cm._menu[3] = { 726, 213, 926, 273 };
	_cm._menu[4] = { 726, 273, 926, 333 };
	_cm._menu[5] = { 726, 333, 926, 393 };
	_cm._menu[6] = { 726, 393, 926, 453 };

 	_cm._cursor[0] = { 702, 43, 726, 83 };
	_cm._cursor[1] = { 702, 103, 726, 143 };
	_cm._cursor[2] = { 702, 163, 726, 203 };
	_cm._cursor[3] = { 702, 223, 726, 263 };
	_cm._cursor[4] = { 702, 283, 726, 323 };
	_cm._cursor[5] = { 702, 343, 726, 383 };
	_cm._cursor[6] = { 702, 403, 726, 443 };


	_rc = { 0 , 480, 960, 640 };
	MENUMANAGER->addFrame("�⺻�޴�", 670, 1, 9, 15);

	_cm._cstate = POKEMON_BOOK;

	_isCommonMenu = false;
	_isCussorDown = false;
	_isCussorUp = false;
	
	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{
	//���࿡ ����Ű�� ������ 
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isCommonMenu = true;
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_isCommonMenu = false;
	}

	//���࿡ �޴��� �������¿��� �Ʒ���ư�� ������

	if (_isCommonMenu)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_isCussorDown = true;
			switch (_cm._cstate)
			{
			case POKEMON_BOOK:
				_cm._cstate = POKEMON;
				break;
			case POKEMON:
				_cm._cstate = BAG;
				break;
			case BAG:
				_cm._cstate = PLAYER;
				break;
			case PLAYER:
				_cm._cstate = SAVE_REPORT;
				break;
			case SAVE_REPORT:
				_cm._cstate = SETTING;
				break;
			case SETTING:
				_cm._cstate = CLOSE;
				break;
			case CLOSE:
				_cm._cstate = POKEMON_BOOK;
				break;
			}

		}
		else if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_isCussorDown = false;
			switch (_cm._cstate)
			{
				case POKEMON_BOOK:
					_cm._cstate = CLOSE;
					break;
				case POKEMON:
					_cm._cstate = POKEMON_BOOK;
					break;
				case BAG:
					_cm._cstate = POKEMON;
					break;
				case PLAYER:
					_cm._cstate = BAG;
					break;
				case SAVE_REPORT:
					_cm._cstate = PLAYER;
					break;
				case SETTING:
					_cm._cstate = SAVE_REPORT;
					break;
				case CLOSE:
					_cm._cstate = SETTING;
					break;
			}
		}
	}

}

void hayoungTestScene::render()
{

	if (_isCommonMenu)
	{
		IMAGEMANAGER->findImage("�׽�Ʈ")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("�⺻�޴�")->render("Ÿ��1");

		//============================ üũ�� ��Ʈ ��� Ȯ�γ����� �����Ұ��� 
		//D2DMANAGER->fillRectangle(RGB(255, 0, 255), _cm._menu[0]);
		//D2DMANAGER->fillRectangle(RGB(0, 10, 255), _cm._menu[1]);
		//D2DMANAGER->fillRectangle(RGB(100, 20, 50), _cm._menu[2]);
		//D2DMANAGER->fillRectangle(RGB(12, 30, 25), _cm._menu[3]);
		//D2DMANAGER->fillRectangle(RGB(0, 30, 0), _cm._menu[4]);
		//D2DMANAGER->fillRectangle(RGB(110, 30, 110), _cm._menu[5]);
		//D2DMANAGER->fillRectangle(RGB(255, 255, 255), _cm._menu[6]);
		//
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[0]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[1]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[2]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[3]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[4]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[5]);
		//D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[6]);

		//===================================================================================
		IMAGEMANAGER->findImage("�⺻�ϴ�")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());

		WCHAR str[1024];
		swprintf_s(str, L"�޴����û���: %d" , _cm._cstate);
		D2DMANAGER->drawText(str, 100 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"����");
		D2DMANAGER->drawText(str, _cm._menu[0].left + CAMERA->getPosX(), _cm._menu[0].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"���ϸ�");
		D2DMANAGER->drawText(str, _cm._menu[1].left + CAMERA->getPosX(), _cm._menu[1].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"����");
		D2DMANAGER->drawText(str, _cm._menu[2].left + CAMERA->getPosX(), _cm._menu[2].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"�г������");
		D2DMANAGER->drawText(str, _cm._menu[3].left + CAMERA->getPosX(), _cm._menu[3].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"����Ʈ");
		D2DMANAGER->drawText(str, _cm._menu[4].left + CAMERA->getPosX(), _cm._menu[4].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"����");
		D2DMANAGER->drawText(str, _cm._menu[5].left + CAMERA->getPosX(), _cm._menu[5].top + 15 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"�ݱ�");
		D2DMANAGER->drawText(str, _cm._menu[6].left + CAMERA->getPosX(), _cm._menu[6].top + 15 + CAMERA->getPosY(), 40);
	
		switch (_cm._cstate)
		{
			case POKEMON_BOOK:
				IMAGEMANAGER->findImage("ȭ��ǥ")->render(_cm._cursor[0].left + CAMERA->getPosX(), _cm._cursor[0].top + CAMERA->getPosY());
				swprintf_s(str, L"������ ��ϵ� ���ϸ��� �� ������ Ȯ���մϴ�. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case POKEMON:
				IMAGEMANAGER->findImage("ȭ��ǥ")->render(_cm._cursor[1].left + CAMERA->getPosX(), _cm._cursor[1].top + CAMERA->getPosY());
				swprintf_s(str, L"���� �ִ� ���ϸ��� ���¸� Ȯ���ϰ� �����մϴ�.");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case BAG:
				IMAGEMANAGER->findImage("ȭ��ǥ")->render(_cm._cursor[2].left + CAMERA->getPosX(), _cm._cursor[2].top + CAMERA->getPosY());
				swprintf_s(str, L"������ Ȯ���ϰ� ����� �� �ֽ��ϴ�.");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255,255,255));
			break;
			case PLAYER:
				IMAGEMANAGER->findImage("ȭ��ǥ")->render(_cm._cursor[3].left + CAMERA->getPosX(), _cm._cursor[3].top + CAMERA->getPosY());
				swprintf_s(str, L"����� Ʈ���̳� ī�带 Ȯ���մϴ�. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case SAVE_REPORT:
				IMAGEMANAGER->findImage("ȭ��ǥ")->render(_cm._cursor[4].left + CAMERA->getPosX(), _cm._cursor[4].top + CAMERA->getPosY());
				swprintf_s(str, L"���ݱ����� ������ ����Ʈ�� ����մϴ�. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case SETTING:
				IMAGEMANAGER->findImage("ȭ��ǥ")->render(_cm._cursor[5].left + CAMERA->getPosX(), _cm._cursor[5].top + CAMERA->getPosY());
				swprintf_s(str, L"����, �ӵ����� ������ �����մϴ�. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
			case CLOSE:
				IMAGEMANAGER->findImage("ȭ��ǥ")->render(_cm._cursor[6].left + CAMERA->getPosX(), _cm._cursor[6].top + CAMERA->getPosY());
				swprintf_s(str, L"�� �޴��� �ݰ� ������ ����մϴ�. ");
				D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
		}
	
	}
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_bg.png", 960, 160);
	IMAGEMANAGER->addImage("ȭ��ǥ", L"image/pokemonMenu_cursor.png", 24, 40);
	IMAGEMANAGER->addImage("�׽�Ʈ", L"image/test/aaa.png", 960, 640);

}
