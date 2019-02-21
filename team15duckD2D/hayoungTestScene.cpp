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
	UIMANAGER->uiDataSetting();
	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{
	UIMANAGER->update();
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		UIMANAGER->selectUI(UI_MAIN);
	}

	/*
	//���θ޴� Ȱ��ȭ�ϱ�
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_mmselect = MMS_YES;

	}
	//���θ޴� �̵��ϱ�

	if (_mmselect == MMS_YES && _smselect == SMS_NO)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			//=========================== ����
			//�޴����� �̵��� ���θ޴������� �����ϴ�
			//===============================
			switch (_cselect)
			{
			case POKEMON_BOOK:
				_cselect = POKEMON;
				break;
			case POKEMON:
				_cselect = BAG_ITEM;
				break;
			case BAG_ITEM:
				_cselect = PLAYER;
				break;
			case PLAYER:
				_cselect = SAVE_REPORT;
				break;
			case SAVE_REPORT:
				_cselect = SETTING;
				break;
			case SETTING:
				_cselect = CLOSE;
				break;
			case CLOSE:
				_cselect = POKEMON_BOOK;
				break;
			}

		}
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP))
	{
		//=========================== ����
		//�޴����� �̵��� ���θ޴������� �����ϴ�
		//===============================

		if (_mmselect == MMS_YES && _smselect == SMS_NO)
		{
			switch (_cselect)
			{
			case POKEMON_BOOK:
				_cselect = CLOSE;
				break;
			case POKEMON:
				_cselect = POKEMON_BOOK;
				break;
			case BAG_ITEM:
				_cselect = POKEMON;
				break;
			case PLAYER:
				_cselect = BAG_ITEM;
				break;
			case SAVE_REPORT:
				_cselect = PLAYER;
				break;
			case SETTING:
				_cselect = SAVE_REPORT;
				break;
			case CLOSE:
				_cselect = SETTING;
				break;
			}
		}
	}
	//�����޴� Ȱ��ȭ�ϱ�
	if (_mmselect == MMS_YES && _smselect != SMS_YES)
	{
		//============================= ����
		//�����޴� Ȱ��ȭ ����
		// ** ���θ޴��� ���õǰ� �����޴��� ������ �ȵǾ� �������� **
		//1. ����(����)�޴��� YES���¿����Ѵ�.
		//2. Ŀ���� ����Ű�� ���� ����ؾ��Ѵ�.
		//=============================

		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			//uimanager.selectUI(ui_bag);

			_smselect = SMS_YES;

			if (_ppokemon->getstate() == 1)
			{
				_smselect = SMS_YES;

			}
		}
	}
	//�����޴� ��Ȱ��ȭ �ϱ�
	if (_mmselect == MMS_YES && _smselect == SMS_YES)
	{
		if (_book->getState() == 0)
		{
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				_smselect = SMS_NO;
			}
		}
	}
	//���θ޴� ��Ȱ��ȭ�ϱ�
	if (_mmselect == MMS_YES && _smselect == SMS_NO)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_mmselect = MMS_NO;
		}
	}

	//======================= Ư�����̽�
	_book->update();
	_bag->update();

	// ������ ���� 
	if (_mmselect == MMS_YES && _smselect == SMS_YES && _cselect == SETTING)
	{
		_setting->update();
	}
	if (_mmselect == MMS_YES && _smselect == SMS_YES && _cselect == POKEMON)
	{
		_ppokemon->update();
	}
	//=================================
	*/
}

void hayoungTestScene::render()
{
	UIMANAGER->render();
}

void hayoungTestScene::frameImageinit()
{

}

void hayoungTestScene::setiteminit()
{
	ITEMDATA->settingItemInfo(MONSTER_BALL);
	ITEMDATA->settingItemInfo(SUPER_BALL);
	ITEMDATA->settingItemInfo(HYPER_BALL);
	ITEMDATA->settingItemInfo(MASTER_BALL);

	ITEMDATA->settingItemInfo(NORMAL_POTION);
	ITEMDATA->settingItemInfo(SUPER_POTION);
	ITEMDATA->settingItemInfo(HYPER_POTION);
	ITEMDATA->settingItemInfo(MAX_POTION);
	ITEMDATA->settingItemInfo(FULL_RESTORE);

	ITEMDATA->settingItemInfo(NORMAL_ETHER);
	ITEMDATA->settingItemInfo(MAX_ETHER);
	ITEMDATA->settingItemInfo(NORMAL_ELIXIR);
	ITEMDATA->settingItemInfo(MAX_ELIXIR);

	ITEMDATA->settingItemInfo(ANTIDOTE);
	ITEMDATA->settingItemInfo(PARLYZE_HEAL);
	ITEMDATA->settingItemInfo(BURN_HEAL);
	ITEMDATA->settingItemInfo(ICE_HEAL);
	ITEMDATA->settingItemInfo(AWAKENING);
	ITEMDATA->settingItemInfo(FULL_HEAL);

	ITEMDATA->settingItemInfo(RARE_CANDY);
	ITEMDATA->settingItemInfo(ESCAPE_ROPE);
	ITEMDATA->settingItemInfo(REVIVE);

	ITEMDATA->settingItemInfo(BICYCLE);
	ITEMDATA->settingItemInfo(FISHING_ROD);
	ITEMDATA->settingItemInfo(TOWN_MAP);

	ITEMDATA->settingItemInfo(HM_CUT);
	ITEMDATA->settingItemInfo(HM_FLASH);

	ITEMDATA->settingItemInfo(HM_FLASH);
	ITEMDATA->settingItemInfo(HM_FLASH);
	ITEMDATA->settingItemInfo(HM_FLASH);

	ITEMDATA->settingItemInfo(CHERI_BERRY);
	ITEMDATA->settingItemInfo(CHESTO_BERRY);
	ITEMDATA->settingItemInfo(PECHA_BERRY);
	ITEMDATA->settingItemInfo(RAWST_BERRY);
	ITEMDATA->settingItemInfo(ASPEAR_BERRY);
	ITEMDATA->settingItemInfo(LEPPA_BERRY);
	ITEMDATA->settingItemInfo(ORAN_BERRY);
	ITEMDATA->settingItemInfo(LUM_BERRY);
	ITEMDATA->settingItemInfo(SITRUS_BERRY);
}

void hayoungTestScene::commonMenurender()
{
	/*
	//���࿡ ���θ޴��� ���õ� ���¶�� �׸��� �׸�����
	if (_mmselect == MMS_YES)
	{
		//=================================================================���߿� �����ؾ��� �׽�Ʈ�� ���
		IMAGEMANAGER->findImage("�׽�Ʈ")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		//=============================================================================================

		//������ ����ֱ�
		MENUMANAGER->findMenuFrame("���θ޴�")->render();
		//�ϴ��ؽ�Ʈ ��¿� bg��� 
		IMAGEMANAGER->findImage("�⺻�ϴ�")->render(0 + CAMERA->getPosX(), 480 + CAMERA->getPosY());

		//�ؽ�Ʈ ���-
		WCHAR str[1024];
		swprintf_s(str, L"�޴����û���: %d", _cselect);
		D2DMANAGER->drawText(str, 100 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 40);

		swprintf_s(str, L"����");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 33 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"���ϸ�");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 93 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"����");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 153 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"�г������");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"����Ʈ");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 273 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"����");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 333 + CAMERA->getPosY(), 40);
		swprintf_s(str, L"�ݱ�");
		D2DMANAGER->drawText(str, 726 + CAMERA->getPosX(), 393 + CAMERA->getPosY(), 40);

		switch (_cselect)
		{
		case POKEMON_BOOK:
			IMAGEMANAGER->findImage("ȭ��ǥ")->render(702 + CAMERA->getPosX(), 33 + CAMERA->getPosY());
			swprintf_s(str, L"������ ��ϵ� ���ϸ��� �� ������ Ȯ���մϴ�. ");
			D2DMANAGER->drawText(str, 10 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
			break;
		case POKEMON:
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
	*/
}
