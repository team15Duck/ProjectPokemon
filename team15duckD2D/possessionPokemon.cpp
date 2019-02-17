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
	//포켓몬 리스트 이동관련
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
			//만약에 서브 포켓몬이 한마리도 없다면
			if (!_issubpkm1exist && !_issubpkm2exist && !_issubpkm3exist && !_issubpkm4exist && !_issubpkm5exist)
			{
				_ppselect = SELECT_MAIN_POKEMON;
			}
			//만약에 1마리만있다면
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
		IMAGEMANAGER->findImage("보유중포켓몬")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("포켓몬프레임1")->render();

		if (_ppselect == SELECT_CANCEL)
		{
			IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
		}
		else
		{
			IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
		}
		//만약에 메인포켓몬이라면 이렇게 출력해라
		if (_isMainpokemon)
		{
			if (_ppselect == SELECT_MAIN_POKEMON)
			{
				IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 1);
			}
			else
			{
				IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
			}
		}
		//만약에 서브포켓몬리스트에서 서브포켓몬 데이터가 없다면
		if (!_issubpkm1exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(450 + CAMERA->getPosX(), 50 + CAMERA->getPosY());
		}
		if (!_issubpkm2exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(450 + CAMERA->getPosX(), 140 + CAMERA->getPosY());
		}
		if (!_issubpkm3exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(450 + CAMERA->getPosX(), 230 + CAMERA->getPosY());
		}
		if (!_issubpkm4exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(450 + CAMERA->getPosX(), 320 + CAMERA->getPosY());
		}
		if (!_issubpkm5exist)
		{
			IMAGEMANAGER->findImage("서브포켓몬1")->render(450 + CAMERA->getPosX(), 410 + CAMERA->getPosY());
		}

		//만약에 서브포켓몬리스트에서 서브포켓몬 데이터가 있다면
		if (_issubpkm1exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON1)
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
			}
		}
		if (_issubpkm2exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON2)
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 140 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 140 + CAMERA->getPosY(), 0, 0);
			}
		}
		if (_issubpkm3exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON3)
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 230 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 230 + CAMERA->getPosY(), 0, 0);
			}
		}
		if (_issubpkm4exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON4)
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 320 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 320 + CAMERA->getPosY(), 0, 0);
			}
		}
		if (_issubpkm5exist)
		{
			if (_ppselect == SELECT_SUB_POKEMON5)
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 410 + CAMERA->getPosY(), 1, 0);
			}
			else
			{
				IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 410 + CAMERA->getPosY(), 0, 0);
			}
		}
	}
}

void possessionPokemon::pPokemonDataSet()
{
	locale("kor");
	//pokemonInfo* info = POKEMONDATA->getPokemonInfomation((POKEMON)i);
}
