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
	_ppstate = P_POKEMON_LIST;
	_ppselect = SELECT_MAIN_POKEMON;
	_currentSelecPok = 0;

	//�ʱ�ȭ�ع��̱� 
	for (int i = 0; i < 6; ++i)
	{
		_pPokemon[i].name.clear();
	}

	_isMainpokemon = true;
	_isSubpokemon = false;

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
				/*
				//���࿡ ���� ���ϸ��� �Ѹ����� ���ٸ�
				if (!_issubpkm1exist && !_issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_ppselect = SELECT_MAIN_POKEMON;
				}
				//���࿡ 1�������ִٸ�
				if (_issubpkm1exist && !_issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_ppselect = SELECT_SUB_POKEMON1;
				}
				if (_issubpkm1exist && _issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_ppselect = SELECT_SUB_POKEMON2;
				}
				if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
				{
					_ppselect = SELECT_SUB_POKEMON3;
				}
				if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && _issubpkm4exist && !_issubpkm5exist)
				{
					_ppselect = SELECT_SUB_POKEMON4;
				}
				if (_issubpkm1exist && _issubpkm2exist && _issubpkm3exist && _issubpkm4exist && _issubpkm5exist)
				{
					_ppselect = SELECT_SUB_POKEMON5;
				}
				*/
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
			_ppstate = P_POKEMON_SUB_MENU;
		}
	}

}

void possessionPokemon::render()
{
	if (_ppstate == P_POKEMON_LIST)
	{
		IMAGEMANAGER->findImage("���������ϸ�")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("���ϸ�������1")->render();

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
		}

		/*
		//���࿡ �������ϸ��̶�� �̷��� ����ض�
		if (_isMainpokemon)
		{
			if (_ppselect == SELECT_MAIN_POKEMON)
			{
				IMAGEMANAGER->findImage("�������ϸ�")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 1);
		
			}
			else
			{
				IMAGEMANAGER->findImage("�������ϸ�")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
			}
		}
		//���࿡ �������ϸ󸮽�Ʈ���� �������ϸ� �����Ͱ� ���ٸ�
		if (!_issubpkm1exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(450 + CAMERA->getPosX(), 50 + CAMERA->getPosY());
		}
		if (!_issubpkm2exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(450 + CAMERA->getPosX(), 140 + CAMERA->getPosY());
		}
		if (!_issubpkm3exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(450 + CAMERA->getPosX(), 230 + CAMERA->getPosY());
		}
		if (!_issubpkm4exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(450 + CAMERA->getPosX(), 320 + CAMERA->getPosY());
		}
		if (!_issubpkm5exist)
		{
			IMAGEMANAGER->findImage("�������ϸ�1")->render(450 + CAMERA->getPosX(), 410 + CAMERA->getPosY());
		}

		//���࿡ �������ϸ󸮽�Ʈ���� �������ϸ� �����Ͱ� �ִٸ�
		if (_issubpkm1exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON1)
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
			}
		}
		if (_issubpkm2exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON2)
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 140 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 140 + CAMERA->getPosY(), 0, 0);
			}
		}
		if (_issubpkm3exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON3)
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 230 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 230 + CAMERA->getPosY(), 0, 0);
			}
		}
		if (_issubpkm4exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON4)
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 320 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 320 + CAMERA->getPosY(), 0, 0);
			}
		}
		if (_issubpkm5exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON5)
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 410 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 410 + CAMERA->getPosY(), 0, 0);
			}
		}
		*/
	}
	if (_ppstate == P_POKEMON_SUB_MENU)
	{
		MENUMANAGER->addFrame("���Ӹ��޴�", 0, 0, 4, 8);
		MENUMANAGER->findMenuFrame("���Ӹ��޴�")->render();

	}
	if (_ppstate == P_POKEMON_INFO)
	{

	}

	WCHAR test[1024];
	swprintf_s(test, L"���Ӹ����°�: %d", _ppstate);
	D2DMANAGER->drawText(test, 285 + CAMERA->getPosX(), 10 + CAMERA->getPosY(), 48, RGB(160, 160, 160));
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
