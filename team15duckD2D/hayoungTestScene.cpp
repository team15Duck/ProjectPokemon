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
	_book = new IllustratedBook;
	_book->init();
	_book->pokemonDataSet();

	_bag = new bag;
	_bag->init();
	_bag->itemDataSet();

	_setting = new setting;
	_setting->init();

	frameImageinit();

	_isFemale = true;
	_isMale = false;

	//���θ޴� �ʱ�ȭ 
	MENUMANAGER->addFrame("���θ޴�", 670, 1, 9, 15);


	//���θ޴� �����߳���? �ƴϿ�
	_mmselect = MMS_NO;
	//����޴� �����߳���? �ƴϿ�
	_smselect = SMS_NO;
	//Ŀ���� ó������ ������ ����ŵ�ϴ�
	_cselect = POKEMON_BOOK;

	_cmpm._pcs = MAIN_POKEMON;


	//�������ϸ� ���� 
	for (int i = 0; i < 5; ++i)
	{
		float top = 35 + (i * 95);
		float bottom = 115 + (i * 95);

		_cmpm._subPokemon[i] = { 450, top, 950 , bottom };
	}

	MENUMANAGER->addFrame("����������1", 80, 64, 25, 4);
	MENUMANAGER->addFrame("����������2", 0, 192, 30, 14);
	MENUMANAGER->addFrame("���ϸ�������1", 0, 512, 23, 4);

	IMAGEMANAGER->addFrameImage("��������", L"image/common_menu/bag/item_bag.png", 472, 257, 2, 1);

	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{
	

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
			_smselect = SMS_YES;
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
	//=================================

}

void hayoungTestScene::render()
{
	commonMenurender();

	// ============================================================= �׽�Ʈ �� üũ�� �ؽ�Ʈ ��� ���� ����
	WCHAR test[1024];
	swprintf_s(test, L"���θ޴�����: %d", _mmselect);
	D2DMANAGER->drawText(test, 0 + CAMERA->getPosX(), 400 + CAMERA->getPosY(), 40);
	// =================================================================================================

	//1. ���ϸ� ���� ����
	//�����޴��� ������ ������ ������ <���θ޴��� �����ְ�, Ŀ���� ���ϸ󵵰��� ����Ű�� , �����޴��� ����> �������̴�.
	if (_mmselect == MMS_YES && _cselect == POKEMON_BOOK && _smselect == SMS_YES)
	{
		_book->render();
	}
	//2. �������� ���ϸ� ����
	//�����޴��� ���ϸ��� ������ ������ <���θ޴��� �����ְ�, Ŀ���� ���ϸ��� ����Ű��, �����޴��� ����> �������̴�.
	if (_mmselect == MMS_YES && _cselect == POKEMON && _smselect == SMS_YES)
	{
		IMAGEMANAGER->findImage("���������ϸ�")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("���ϸ�������1")->render();
		IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
	
	
	}
	//3. ���� ����
	//�����޴��� ���ϸ��� ������ ������ <���θ޴��� �����ְ�, Ŀ���� ������ ����Ű��, �����޴��� ����> �������̴�.
	if (_mmselect == MMS_YES && _cselect == BAG_ITEM && _smselect == SMS_YES)
	{
		if (_isMale)
		{
			IMAGEMANAGER->findImage("����޴����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
			IMAGEMANAGER->findImage("��������")->frameRender(45 + CAMERA->getPosX(), 160 + CAMERA->getPosY(), 0, 0);
			_bag->render();
		}
		else if (_isFemale)
		{
			IMAGEMANAGER->findImage("����޴����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
			IMAGEMANAGER->findImage("��������")->frameRender(45 + CAMERA->getPosX(), 172 + CAMERA->getPosY(), 1, 0);
			_bag->render();
		}

		WCHAR bag[1024];
		swprintf_s(bag, L"������");
		D2DMANAGER->drawText(bag, 110 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 40);
	}
	//4. �÷��̾� ���� ���
	if (_mmselect == MMS_YES && _cselect == PLAYER && _smselect == SMS_YES)
	{
		IMAGEMANAGER->findImage("Ʈ���̳�ī��")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
	}
	//5. ����Ʈ < ���̺� > ���
	if (_mmselect == MMS_YES && _cselect == SAVE_REPORT && _smselect == SMS_YES)
	{

	}
	//6. ���� ���
	if (_mmselect == MMS_YES && _cselect == SETTING && _smselect == SMS_YES)
	{
		_setting->render();
	}
	/*
	if (_cm._cstate == POKEMON_BOOK && _cm._ms == YES)
	{
		_book->render();
	}
	else if (_cm._cstate == POKEMON && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("���������ϸ�")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("���ϸ�������1")->render("Ÿ��1");
		IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);

		if (_issubpkm1exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[0].left + CAMERA->getPosX(), _cmpm._subPokemon[0].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm1exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(_cmpm._subPokemon[0].left + CAMERA->getPosX(), _cmpm._subPokemon[0].top + CAMERA->getPosY());
		}
		if (_issubpkm2exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[1].left + CAMERA->getPosX(), _cmpm._subPokemon[1].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm2exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(_cmpm._subPokemon[1].left + CAMERA->getPosX(), _cmpm._subPokemon[1].top + CAMERA->getPosY());
		}
		if (_issubpkm3exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[2].left + CAMERA->getPosX(), _cmpm._subPokemon[2].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm3exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(_cmpm._subPokemon[2].left + CAMERA->getPosX(), _cmpm._subPokemon[2].top + CAMERA->getPosY());
		}
		if (_issubpkm4exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[3].left + CAMERA->getPosX(), _cmpm._subPokemon[3].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm4exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(_cmpm._subPokemon[3].left + CAMERA->getPosX(), _cmpm._subPokemon[3].top + CAMERA->getPosY());
		}
		if (_issubpkm5exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[4].left + CAMERA->getPosX(), _cmpm._subPokemon[4].top + CAMERA->getPosY(), 0, 0);
		}
		else if (!_issubpkm5exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(_cmpm._subPokemon[4].left + CAMERA->getPosX(), _cmpm._subPokemon[4].top + CAMERA->getPosY());
		}

		IMAGEMANAGER->findImage("�������ϸ�")->frameRender(65 + CAMERA->getPosX(), 65 + CAMERA->getPosY(), 0, 0);

		switch (_cmpm._pcs)
		{
		case MAIN_POKEMON:
				IMAGEMANAGER->findImage("�������ϸ�")->frameRender(65 + CAMERA->getPosX(), 64 + CAMERA->getPosY(), 0, 1);
			break;
			case SUB_POKEMON1:
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[0].left + CAMERA->getPosX(), _cmpm._subPokemon[0].top + CAMERA->getPosY(), 1, 0);
			break;
			case SUB_POKEMON2:
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[1].left + CAMERA->getPosX(), _cmpm._subPokemon[1].top + CAMERA->getPosY(), 1, 0);
			break;
			case SUB_POKEMON3:
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[2].left + CAMERA->getPosX(), _cmpm._subPokemon[2].top + CAMERA->getPosY(), 1, 0);
			break;
			case SUB_POKEMON4:
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[3].left + CAMERA->getPosX(), _cmpm._subPokemon[3].top + CAMERA->getPosY(), 1, 0);
			break;
			case SUB_POKEMON5:
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(_cmpm._subPokemon[4].left + CAMERA->getPosX(), _cmpm._subPokemon[4].top + CAMERA->getPosY(), 1, 0);
			break;
			case CANCEL:
				IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
			break;
		}

		WCHAR pokemon[1024];
		swprintf_s(pokemon, L"���");
		D2DMANAGER->drawText(pokemon, 820 + CAMERA->getPosX(), 552 + CAMERA->getPosY(), 48, RGB(255, 255, 255));
		swprintf_s(pokemon, L"���ϸ��� ������ �ֽʽÿ�.");
		D2DMANAGER->drawText(pokemon, 50 + CAMERA->getPosX(), 550 + CAMERA->getPosY(), 48, RGB(0, 0, 0));
	}
	else if (_cm._cstate == BAG && _cm._ms == YES)
	{
		if (_isMale)
		{
			IMAGEMANAGER->findImage("����޴����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
		}
		else if (_isFemale)
		{
			IMAGEMANAGER->findImage("����޴����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
		}
	}
	else if (_cm._cstate == PLAYER && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("Ʈ���̳�ī��")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 1, 0);
	}
	else if (_cm._cstate == SAVE_REPORT && _cm._ms == YES)
	{

	}
	else if (_cm._cstate == SETTING && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("�׽�Ʈ2")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		IMAGEMANAGER->findImage("�⺻���")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("����������1")->render("Ÿ��1");
		MENUMANAGER->findMenuFrame("����������2")->render("Ÿ��1");

		WCHAR settingtext[1024];
		swprintf_s(settingtext, L"���ϸ��� ���̾�� ȯ�漳��");
		D2DMANAGER->drawText(settingtext, 120 + CAMERA->getPosX(), 100 + CAMERA->getPosY(), 48);
	}
	*/
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_menu/common_menu_bg.png", 960, 160);
	IMAGEMANAGER->addImage("�⺻���", L"image/common_menu/common_menu_top.png", 960, 64);
	IMAGEMANAGER->addImage("ȭ��ǥ", L"image/common_menu/pokemonMenu_cursor.png", 24, 40);
	IMAGEMANAGER->addImage("�׽�Ʈ", L"image/test/aaa.png", 960, 640);
	IMAGEMANAGER->addImage("�׽�Ʈ2", L"image/test/bbb.png", 960, 640);
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
}
