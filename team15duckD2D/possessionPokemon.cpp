#include "stdafx.h"
#include "possessionPokemon.h"


possessionPokemon::possessionPokemon()
{
}


possessionPokemon::~possessionPokemon()
{
}

HRESULT possessionPokemon::init()
{
	MENUMANAGER->addFrame("���ϸ�������1", 0, 512, 23, 4);
	MENUMANAGER->addFrame("���Ӹ��޴�", 635, 380, 10, 8);
	MENUMANAGER->addFrame("���Ӹ�����", 0, 512, 20, 4);

	_ppstate = P_POKEMON_LIST;
	_ppselect = SELECT_MAIN_POKEMON;
	_psmselect = SELECT_LOOK_POKEMON;
	_currentSelecPok = 0;

	//�ʱ�ȭ�ع��̱� 
	for (int i = 0; i < 6; ++i)
	{
		_pPokemon[i].name.clear();
	}

	IMAGEMANAGER->addFrameImage("���Ӹ����", L"image/Summary Menu/summary_top_bar.png", 960, 192, 1, 3);

	_isMainpokemon = true;
	_isSubpokemon = false;
	_isSubMenu = false;

	return S_OK;
}

void possessionPokemon::release()
{
}

void possessionPokemon::update()
{
	//pPokemonDataSet();

	if (_ppstate == P_POKEMON_LIST)
	{
		//���ϸ� ����Ʈ �̵�����
		if (!_isSubMenu)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				switch (_ppselect)
				{
				case SELECT_MAIN_POKEMON:
					if (0 < _pokemonCnt)
					{
						_ppselect = (P_POKEMON_SELECT)(_pokemonCnt - 1);
					}
					else
					{
						_ppselect = SELECT_CANCEL;
					}
					break;
				case SELECT_SUB_POKEMON1:

					break;
				case SELECT_SUB_POKEMON2:

					break;
				case SELECT_SUB_POKEMON3:

					break;
				case SELECT_SUB_POKEMON4:

					break;
				case SELECT_SUB_POKEMON5:

					break;
				case SELECT_CANCEL:
					_ppselect = SELECT_MAIN_POKEMON;
					break;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				switch (_ppselect)
				{
				case SELECT_MAIN_POKEMON:
					_ppselect = SELECT_CANCEL;
					break;
				case SELECT_SUB_POKEMON1:
					_ppselect = SELECT_MAIN_POKEMON;
					break;
				case SELECT_SUB_POKEMON2:
					_ppselect = SELECT_SUB_POKEMON1;
					break;
				case SELECT_SUB_POKEMON3:
					_ppselect = SELECT_SUB_POKEMON2;
					break;
				case SELECT_SUB_POKEMON4:
					_ppselect = SELECT_SUB_POKEMON3;
					break;
				case SELECT_SUB_POKEMON5:
					_ppselect = SELECT_SUB_POKEMON4;
					break;
				case SELECT_CANCEL:
					if (0 < _pokemonCnt)
					{
						_ppselect = (P_POKEMON_SELECT)(_pokemonCnt - 1);
					}
					else
					{
						_ppselect = SELECT_MAIN_POKEMON;
					}

					break;
				}
			}

			//�����޴�â ���
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_isSubMenu = true;
				//_ppselect = P_POKEMON_INFO;
			}

			//exit
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				//UI_TYPE type = UIMANAGER->getbeforeUI();
				//UIMANAGER->selectUI(type);
				UIMANAGER->moveBeforeUI();
			}
		}

		//�����޴�â�� �������� Ű����
		if (_isSubMenu)
		{
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				_isSubMenu = false;
			}

			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				switch (_psmselect)
				{
					case SELECT_LOOK_POKEMON:
						_psmselect = SELECT_CHANGE_ORDER;
					break;
					case SELECT_CHANGE_ORDER:
						_psmselect = SELECT_KEEP_ITEM;
					break;
					case SELECT_KEEP_ITEM:
						_psmselect = SELECT_NONE;
					break;
					case SELECT_NONE:
						_psmselect = SELECT_LOOK_POKEMON;
					break;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				switch (_psmselect)
				{
				case SELECT_LOOK_POKEMON:
					_psmselect = SELECT_NONE;
				break;
				case SELECT_CHANGE_ORDER:
					_psmselect = SELECT_LOOK_POKEMON;
				break;
				case SELECT_KEEP_ITEM:
					_psmselect = SELECT_CHANGE_ORDER;
				break;
				case SELECT_NONE:
					_psmselect = SELECT_KEEP_ITEM;
				break;
				}
			}

			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				switch (_psmselect)
				{
				case SELECT_LOOK_POKEMON:
					_ppstate = P_POKEMON_INFO;
				break;
				case SELECT_CHANGE_ORDER:
					
				break;
				case SELECT_KEEP_ITEM:
					
				break;
				case SELECT_NONE:
					
				break;
				}
			}
		}
	}


}

void possessionPokemon::render()
{
	WCHAR possessionPokemon[1024];
	if (_ppstate == P_POKEMON_LIST)
	{
		IMAGEMANAGER->findImage("���������ϸ�")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		if (!_isSubMenu)
		{
			MENUMANAGER->findMenuFrame("���ϸ�������1")->render();
		}
		if (_ppselect == SELECT_CANCEL)
		{
			IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
		}
		else
		{
			IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
		}

		for (int i = 0; i < 6; ++i)
		{
			// ���� ���ϸ�
			if (i == 0)
			{
				if (_ppselect == SELECT_MAIN_POKEMON)
				{
					IMAGEMANAGER->findImage("�������ϸ�")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 1);
				}
				else
				{
					IMAGEMANAGER->findImage("�������ϸ�")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
				}

				//D2DMANAGER->drawText(_pPokemon[i].level.c_str, 150, 150);
			}
			else
			{
				if(i < _pokemonCnt)
				//if (_pPokemon[ii].isDataSet)
				{
					if (_ppselect == i)
					{
						// �ϴû�
						IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 50 + (i * 90) + CAMERA->getPosY(), 1, 0);
					}
					else
					{
						// �Ķ���
						IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 50 + (i * 90) + CAMERA->getPosY(), 0, 0);
					}
				}
				else
				{
					IMAGEMANAGER->findImage("�������ϸ�1")->render(450 + CAMERA->getPosX(), 50 + ((i-1) * 90) + CAMERA->getPosY());
				}
			}

			if (_isSubMenu)
			{
				MENUMANAGER->findMenuFrame("���Ӹ��޴�")->render();
				MENUMANAGER->findMenuFrame("���Ӹ�����")->render();

				swprintf_s(possessionPokemon, L"���º���");
				D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 415 + CAMERA->getPosY(), 40);
				swprintf_s(possessionPokemon, L"��������");
				D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 465 + CAMERA->getPosY(), 40);
				swprintf_s(possessionPokemon, L"���ѹ���");
				D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 515 + CAMERA->getPosY(), 40);
				swprintf_s(possessionPokemon, L"�׸��α�");
				D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 565 + CAMERA->getPosY(), 40);

				switch (_psmselect)
				{
				case SELECT_LOOK_POKEMON:
					IMAGEMANAGER->findImage("ȭ��ǥ")->render(670 + CAMERA->getPosX(), 415 + CAMERA->getPosY());
					break;
				case SELECT_CHANGE_ORDER:
					IMAGEMANAGER->findImage("ȭ��ǥ")->render(670 + CAMERA->getPosX(), 465 + CAMERA->getPosY());
					break;
				case SELECT_KEEP_ITEM:
					IMAGEMANAGER->findImage("ȭ��ǥ")->render(670 + CAMERA->getPosX(), 515 + CAMERA->getPosY());
					break;
				case SELECT_NONE:
					IMAGEMANAGER->findImage("ȭ��ǥ")->render(670 + CAMERA->getPosX(), 565 + CAMERA->getPosY());
					break;
				}
			}
		}
	}
	if (_ppstate == P_POKEMON_INFO)
	{
		IMAGEMANAGER->findImage("���Ӹ����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
	}

	//swprintf_s(possessionPokemon, L"���Ӹ����°�: %d", _ppstate);
	//D2DMANAGER->drawText(possessionPokemon, 285 + CAMERA->getPosX(), 415 + CAMERA->getPosY(), 40);
}

void possessionPokemon::pPokemonDataSet()
{
	locale("kor");
	pokemon** pokemons = PLAYERDATA->getPlayer()->getPokemon();
	_pokemonCnt = PLAYERDATA->getPlayer()->getCurrentPokemonCnt() + 1;

	for (int i = 0; i < _pokemonCnt; ++i)
	{
		if (pokemons[i] == nullptr) continue;

		_pPokemon[i].isDataSet = false;
		_pPokemon[i].level = to_wstring(pokemons[i]->getLevel());
	}


}

void possessionPokemon::uiOpen()
{

}

void possessionPokemon::uiClose()
{
}
