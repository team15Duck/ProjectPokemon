#include "stdafx.h"
#include "mainUi.h"


mainUi::mainUi()
{
}


mainUi::~mainUi()
{
}

HRESULT mainUi::init()
{
	_uiType = UI_MAIN;
	_menu_Select = POKEMON_BOOK;

	//���θ޴� �ʱ�ȭ 
	MENUMANAGER->addFrame("���θ޴�", 670, 1, 9, 15);

	return S_OK;
}

void mainUi::release()
{
}

void mainUi::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		//=========================== ����
		//�޴����� �̵��� ���θ޴������� �����ϴ�
		//===============================
		switch (_menu_Select)
		{
		case POKEMON_BOOK:
			_menu_Select = MY_POKEMON;
			break;
		case MY_POKEMON:
			_menu_Select = BAG_ITEM;
			break;
		case BAG_ITEM:
			_menu_Select = PLAYER;
			break;
		case PLAYER:
			_menu_Select = SAVE_REPORT;
			break;
		case SAVE_REPORT:
			_menu_Select = SETTING;
			break;
		case SETTING:
			_menu_Select = CLOSE;
			break;
		case CLOSE:
			_menu_Select = POKEMON_BOOK;
			break;
		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		//=========================== ����
		//�޴����� �̵��� ���θ޴������� �����ϴ�
		//===============================
		switch (_menu_Select)
		{
			case POKEMON_BOOK:
				_menu_Select = CLOSE;
			break;
			case MY_POKEMON:
				_menu_Select = POKEMON_BOOK;
			break;
			case BAG_ITEM:
				_menu_Select = MY_POKEMON;
			break;
			case PLAYER:
				_menu_Select = BAG_ITEM;
			break;
			case SAVE_REPORT:
				_menu_Select = PLAYER;
			break;
			case SETTING:
				_menu_Select = SAVE_REPORT;
			break;
			case CLOSE:
				_menu_Select = SETTING;
			break;
		}
	}

	if (KEYMANAGER->isOnceKeyDown('Z'))
	{
		switch (_menu_Select)
		{
		case POKEMON_BOOK:
			UIMANAGER->selectUI(UI_ILLUST);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case MY_POKEMON:
			UIMANAGER->selectUI(UI_POKEMON);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case BAG_ITEM:
			UIMANAGER->selectUI(UI_BAG);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case PLAYER:
			UIMANAGER->selectUI(UI_PLAYER);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case SAVE_REPORT:
			UIMANAGER->selectUI(UI_REPORT);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case SETTING:
			UIMANAGER->selectUI(UI_SETTING);
			UIMANAGER->selecBeforeUI(UI_MAIN);
			break;
		case CLOSE:
			UIMANAGER->selectUI(UI_NONE);
			break;
		}
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		UIMANAGER->selectUI(UI_NONE);
	}
}

void mainUi::render()
{
	// ������ ����ֱ�
	MENUMANAGER->findMenuFrame("���θ޴�")->render();
	//�ϴ��ؽ�Ʈ ��¿� bg��� 
	IMAGEMANAGER->findImage("�⺻�ϴ�")->render(0 + CAMERA->getPosX(), 480 + CAMERA->getPosY());

	//�ؽ�Ʈ ���-
	WCHAR str[1024];

	swprintf_s(str, L"����");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 33 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"���ϸ�");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 93 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"����");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 153 + CAMERA->getPosY(), 40);

	swprintf_s(str, L"����");
	D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getName()).c_str(), 726 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"����Ʈ");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 273 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"����");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 333 + CAMERA->getPosY(), 40);
	swprintf_s(str, L"�ݱ�");
	D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 393 + CAMERA->getPosY(), 40);

	switch (_menu_Select)
	{
	case POKEMON_BOOK:
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(702 + CAMERA->getPosX(), 33 + CAMERA->getPosY());
		swprintf_s(str, L"������ ��ϵ� ���ϸ��� �� ������ Ȯ���մϴ�. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case MY_POKEMON:
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(702 + CAMERA->getPosX(), 93 + CAMERA->getPosY());
		swprintf_s(str, L"���� �ִ� ���ϸ��� ���¸� Ȯ���ϰ� �����մϴ�.");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case BAG_ITEM:
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(702 + CAMERA->getPosX(), 153 + CAMERA->getPosY());
		swprintf_s(str, L"������ Ȯ���ϰ� ����� �� �ֽ��ϴ�.");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case PLAYER:
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(702 + CAMERA->getPosX(), 213 + CAMERA->getPosY());
		swprintf_s(str, L"����� Ʈ���̳� ī�带 Ȯ���մϴ�. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case SAVE_REPORT:
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(702 + CAMERA->getPosX(), 273 + CAMERA->getPosY());
		swprintf_s(str, L"���ݱ����� ������ ����Ʈ�� ����մϴ�. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case SETTING:
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(702 + CAMERA->getPosX(), 333 + CAMERA->getPosY());
		swprintf_s(str, L"����, �ӵ����� ������ �����մϴ�. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	case CLOSE:
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(702 + CAMERA->getPosX(), 393 + CAMERA->getPosY());
		swprintf_s(str, L"�� �޴��� �ݰ� ������ ����մϴ�. ");
		D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		break;
	}
}
