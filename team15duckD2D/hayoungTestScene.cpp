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

	frameImageinit();
	commonMenuinit();

	_issubpkm1exist = true;
	_issubpkm2exist	= false;
	_issubpkm3exist	= false;
	_issubpkm4exist	= false;
	_issubpkm5exist	= false;

	_isFemale = false;
	_isMale = true;

	_cmpm._pcs = MAIN_POKEMON;

	IMAGEMANAGER->addFrameImage("Ʈ���̳�ī��", L"image/common_menu/player/trainerCard.png", 1920, 640, 2, 1);

	IMAGEMANAGER->addFrameImage("����", L"image/common_menu/pokemonbook/cm_pokemon_book.png", 1920, 640, 2, 1);
	IMAGEMANAGER->addFrameImage("���ϸ�Ӽ�", L"image/Summary Menu/summary_pokemon_tage.png", 1152, 96, 9, 2);


	IMAGEMANAGER->addImage("���������ϸ�", L"image/common_menu/pokemon/pokemonMenu_background.png", 960, 640);
	IMAGEMANAGER->addFrameImage("�������ϸ�", L"image/common_menu/pokemon/pokemonMenu_slot_first.png", 336, 456, 1, 2);
	IMAGEMANAGER->addFrameImage("���ϸ�޴�_���", L"image/common_menu/pokemon/pokemonMenu_btn_cancle.png", 216, 192, 1, 2);
	IMAGEMANAGER->addFrameImage("�������ϸ�2", L"image/common_menu/pokemon/pokemonMenu_slot.png", 1000, 80, 2, 1);
	IMAGEMANAGER->addImage("�������ϸ�1", L"image/common_menu/pokemon/pokemon_subpokemon_list.png", 500, 80);

	//�������ϸ� ���� 
	for (int i = 0; i < 5; ++i)
	{
		float top = 35 + (i * 95);
		float bottom = 115 + (i * 95);

		_cmpm._subPokemon[i] = { 450, top, 950 , bottom };
	}

	IMAGEMANAGER->addFrameImage("����޴����", L"image/common_menu/bag/bag_background.png", 1920, 640, 2, 1);


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
				_cmpm._pcs = SUB_POKEMON1;
				break;
			case SUB_POKEMON3:
				_cmpm._pcs = SUB_POKEMON2;
				break;
			case SUB_POKEMON4:
				_cmpm._pcs = SUB_POKEMON3;
				break;
			case SUB_POKEMON5:
				_cmpm._pcs = SUB_POKEMON4;
				break;
			case CANCEL:
				if (_issubpkm1exist && !_issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON1;
				}
				else if (_issubpkm1exist && _issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON2;
				}
				else if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON3;
				}
				else if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && _issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON4;
				}
				else if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && _issubpkm4exist && _issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON5;
				}
				break;
			}
		}
		//���࿡ ���ϸ� �޴����� �Ʒ�Ű�� ������
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			switch (_cmpm._pcs)
			{
			case MAIN_POKEMON:
				if (!_issubpkm1exist && !_issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_cmpm._pcs = CANCEL;
				}
				else if (_issubpkm1exist)
				{
					_cmpm._pcs = SUB_POKEMON1;
				}
				break;
			case SUB_POKEMON1:
				if (_issubpkm2exist)
				{
					_cmpm._pcs = SUB_POKEMON2;
				}
				else 
				{
					_cmpm._pcs = CANCEL;
				}
				break;
			case SUB_POKEMON2:
				if (_issubpkm3exist)
				{
					_cmpm._pcs = SUB_POKEMON3;
				}
				else
				{
					_cmpm._pcs = CANCEL;
				}
				break;
			case SUB_POKEMON3:
				if (_issubpkm4exist)
				{
					_cmpm._pcs = SUB_POKEMON4;
				}
				else
				{
					_cmpm._pcs = CANCEL;
				}
				break;
			case SUB_POKEMON4:
				if (_issubpkm5exist)
				{
					_cmpm._pcs = SUB_POKEMON5;
				}
				else
				{
					_cmpm._pcs = CANCEL;
				}
				break;
			case SUB_POKEMON5:
				_cmpm._pcs = CANCEL;
				break;
			case CANCEL:
				_cmpm._pcs = MAIN_POKEMON;
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
	
	_book->update();
}

void hayoungTestScene::render()
{
	commonMenurender();
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

	for (int i = 0; i < 7; ++i)
	{
		float menutop = 33 + (i * 60);
		float menubottom = 93 + (i * 60);

		float cursortop = 43 + (i * 60);
		float cursorbottom = 83 + (i * 60);

		_cm._menu[i] = { 726, menutop, 926, menubottom };
		_cm._cursor[i] = { 702 ,cursortop, 726,cursorbottom };
	}

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
