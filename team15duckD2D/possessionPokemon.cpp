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

	_isMainpokemon = true;
	_isSubpokemon = false;

	_issubpkm1exist	= true;
	_issubpkm2exist	= true;
	_issubpkm3exist	= true;
	_issubpkm4exist	= true;
	_issubpkm5exist	= true;
	
	return S_OK;
}

void possessionPokemon::release()
{
}

void possessionPokemon::update()
{
	//���ϸ� ����Ʈ �̵�����
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		switch (_ppselect)
		{
		case SELECT_MAIN_POKEMON:
			if (_issubpkm1exist)
			{
				_ppselect = SELECT_SUB_POKEMON1;
			}
			else
			{
				_ppselect = SELECT_CANCEL;
			}
		break;
		case SELECT_SUB_POKEMON1:
			if (_issubpkm2exist)
			{
				_ppselect = SELECT_SUB_POKEMON2;
			}
			else
			{
				_ppselect = SELECT_CANCEL;
			}
		break;
		case SELECT_SUB_POKEMON2:
			if (_issubpkm3exist)
			{
				_ppselect = SELECT_SUB_POKEMON3;
			}
			else
			{
				_ppselect = SELECT_CANCEL;
			}
		break;
		case SELECT_SUB_POKEMON3:
			if (_issubpkm4exist)
			{
				_ppselect = SELECT_SUB_POKEMON4;
			}
			else
			{
				_ppselect = SELECT_CANCEL;
			}
		break;
		case SELECT_SUB_POKEMON4:
			if (_issubpkm5exist)
			{
				_ppselect = SELECT_SUB_POKEMON5;
			}
			else
			{
				_ppselect = SELECT_CANCEL;
			}
		break;
		case SELECT_SUB_POKEMON5:
			_ppselect = SELECT_CANCEL;
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
		break;
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
	}
}

void possessionPokemon::pPokemonDataSet()
{
	locale("kor");
	//pokemonInfo* info = POKEMONDATA->getPokemonInfomation((POKEMON)i);
}
