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
	commonMenuinit();

	_isFemale = false;
	_isMale = true;

	_cmpm._pcs = MAIN_POKEMON;

	IMAGEMANAGER->addFrameImage("Ʈ���̳�ī��", L"image/common_menu/player/trainerCard.png", 1920, 640, 2, 1);

	IMAGEMANAGER->addFrameImage("����", L"image/common_menu/pokemonbook/cm_pokemon_book.png", 1920, 640, 2, 1);

	IMAGEMANAGER->addImage("���������ϸ�", L"image/common_menu/pokemon/pokemonMenu_background.png", 960, 640);
	IMAGEMANAGER->addFrameImage("�������ϸ�", L"image/common_menu/pokemon/pokemonMenu_slot_first.png", 384, 512, 1, 2);
	IMAGEMANAGER->addFrameImage("���ϸ�޴�_���", L"image/common_menu/pokemon/pokemonMenu_btn_cancle.png", 216, 192, 1, 2);
	IMAGEMANAGER->addFrameImage("�������ϸ�", L"image/common_menu/pokemon/pokemonMenu_slot.png", 620, 256, 1, 2);
	MENUMANAGER->addFrame("����������1", 80, 64, 25, 4);
	MENUMANAGER->addFrame("����������2", 0, 192, 30, 14);
	MENUMANAGER->addFrame("���ϸ�������1", 0, 512, 23, 4);
	
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
	//�����޴��� �����ִ� ���¿���
	if (_cm._ms == YES)
	{
		//���࿡ xŰ�� ������ 
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			switch (_cm._cstate)
			{
			case POKEMON_BOOK:
			case POKEMON:
			case BAG:
			case PLAYER:
			case SAVE_REPORT:
			case SETTING:
			case CLOSE:
				_cm._ms = NO;			//�������� �ƴϴٷ� �ٲ��ش�
				break;
			}
		}

		//���࿡ ���ϸ� �޴����� ����Ű�� ������
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			switch (_cmpm._pcs)
			{
			case MAIN_POKEMON:
				_cmpm._pcs = CANCEL;
				break;
			case SUB_POKEMON1:
				_cmpm._pcs = MAIN_POKEMON;
				break;
			case SUB_POKEMON2:
				
				break;
			case SUB_POKEMON3:
				
				break;
			case SUB_POKEMON4:
				
				break;
			case SUB_POKEMON5:
				
				break;
			case CANCEL:
			
				break;
			}
		}
	}
	if (_cm._ms == NO && _isCommonMenu)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_isCommonMenu = false;
		}
	}
	//���࿡ �⺻�޴��� �������¿����� Ű���� 
	if (_isCommonMenu && _cm._ms != YES)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
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
		//�ٸ�ȭ������ �����غ���
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			switch (_cm._cstate)
			{
			case POKEMON_BOOK:
			case POKEMON:
			case BAG:
			case PLAYER:
			case SAVE_REPORT:
			case SETTING:
				_cm._ms = YES;
				break;
			}
			if (_cm._cstate == CLOSE)
			{
				_isCommonMenu = false;
			}
		}
	}


}

void hayoungTestScene::render()
{
	commonMenurender();
	if (_cm._cstate == POKEMON_BOOK && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
		WCHAR pokemon_book[1024];
		swprintf_s(pokemon_book, L"���ϸ� ���� ���");
		D2DMANAGER->drawText(pokemon_book, 285 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(160, 160, 160));
		swprintf_s(pokemon_book, L"���ϸ� ���� ���");
		D2DMANAGER->drawText(pokemon_book, 280 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(255,255,255));

	}
	else if (_cm._cstate == POKEMON && _cm._ms == YES)
	{
		IMAGEMANAGER->findImage("���������ϸ�")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		IMAGEMANAGER->findImage("�������ϸ�")->frameRender(0 + CAMERA->getPosX(), 60 + CAMERA->getPosY(), 0, 0);
		MENUMANAGER->findMenuFrame("���ϸ�������1")->render("Ÿ��1");
		IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
		IMAGEMANAGER->findImage("�������ϸ�")->frameRender(345 + CAMERA->getPosX(), 20 + CAMERA->getPosY(), 0, 0);
		
		switch (_cmpm._pcs)
		{
			case MAIN_POKEMON:
				IMAGEMANAGER->findImage("�������ϸ�")->frameRender(0 + CAMERA->getPosX(), 60 + CAMERA->getPosY(), 0, 1);
			break;
			case SUB_POKEMON1:

			break;
			case SUB_POKEMON2:

			break;
			case SUB_POKEMON3:

			break;
			case SUB_POKEMON4:

			break;
			case SUB_POKEMON5:

			break;
			case CANCEL:
				IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
			break;
		}

		WCHAR pokemon[1024];
		swprintf_s(pokemon, L"���");
		D2DMANAGER->drawText(pokemon, 820 + CAMERA->getPosX(), 552 + CAMERA->getPosY(), 48, RGB(255, 255, 255));
	}
	else if (_cm._cstate == BAG && _cm._ms == YES)
	{
		//if (_isMale)b
		{

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
	

	//WCHAR aa[1024];
	//swprintf_s(aa, L"�����޴�����: %d", _cm._ms);
	//D2DMANAGER->drawText(aa, 140 + CAMERA->getPosX(), 150 + CAMERA->getPosY(), 40);
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_menu/common_menu_bg.png", 960, 160);
	IMAGEMANAGER->addImage("�⺻���", L"image/common_menu/common_menu_top.png", 960, 64);
	IMAGEMANAGER->addImage("ȭ��ǥ", L"image/common_menu/pokemonMenu_cursor.png", 24, 40);
	IMAGEMANAGER->addImage("�׽�Ʈ", L"image/test/aaa.png", 960, 640);
	IMAGEMANAGER->addImage("�׽�Ʈ2", L"image/test/bbb.png", 960, 640);

}

void hayoungTestScene::commonMenuinit()
{
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
	_cm._ms = NO;

	_isCommonMenu = false;
}

void hayoungTestScene::commonMenurender()
{

	if (_isCommonMenu)
	{
		IMAGEMANAGER->findImage("�׽�Ʈ")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("�⺻�޴�")->render("Ÿ��1");

		IMAGEMANAGER->findImage("�⺻�ϴ�")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());

		WCHAR str[1024];
		swprintf_s(str, L"�޴����û���: %d", _cm._cstate);
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
			D2DMANAGER->drawText(str, _cm._bottom.left + 10 + CAMERA->getPosX(), _cm._bottom.top + 15 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
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
