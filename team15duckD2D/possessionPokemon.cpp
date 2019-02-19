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
	MENUMANAGER->addFrame("포켓몬프레임1", 0, 512, 23, 4);
	MENUMANAGER->addFrame("서머리메뉴", 635, 380, 10, 8);
	MENUMANAGER->addFrame("서머리정보", 0, 512, 20, 4);

	_ppstate = P_POKEMON_LIST;
	_ppselect = SELECT_MAIN_POKEMON;
	_psmselect = SELECT_LOOK_POKEMON;
	_plpokemon = LP_INFO;
	_currentSelecPok = 0;

	//초기화해벌이기 
	for (int i = 0; i < 6; ++i)
	{
		_pPokemon[i].name.clear();
	}

	IMAGEMANAGER->addFrameImage("서머리상단", L"image/Summary Menu/summary_top_bar.png", 960, 192, 1, 3);
	IMAGEMANAGER->addImage("서머리배경", L"image/Summary Menu/summary_base.png", 960, 640);
	IMAGEMANAGER->addFrameImage("서머리프레임", L"image/Summary Menu/summary_pokemon_info.png", 1920, 576, 2, 1);
	IMAGEMANAGER->addImage("서머리포켓몬", L"image/Summary Menu/summary_pokemon_base.png", 484, 336);
	IMAGEMANAGER->addImage("서머리스킬", L"image/Summary Menu/summary_pokemon_skill.png", 484, 576);
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

	if (_ppstate == P_POKEMON_LIST)
	{
		//포켓몬 리스트 이동관련
		if (!_isSubMenu)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				switch (_ppselect)
				{
				case SELECT_MAIN_POKEMON:
					if (0 < _pokemonCnt)
					{
						_ppselect = SELECT_SUB_POKEMON1;
					}
					else
					{
						_ppselect = SELECT_CANCEL;
					}
					break;
				case SELECT_SUB_POKEMON1:
					_ppselect = SELECT_SUB_POKEMON2;
					break;
				case SELECT_SUB_POKEMON2:
					_ppselect = SELECT_SUB_POKEMON3;
					break;
				case SELECT_SUB_POKEMON3:
					_ppselect = SELECT_SUB_POKEMON4;
					break;
				case SELECT_SUB_POKEMON4:
					_ppselect = SELECT_SUB_POKEMON5;
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

			//하위메뉴창 출력
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_isSubMenu = true;
				//_ppselect = P_POKEMON_INFO;
			}

			//exit
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				UIMANAGER->moveBeforeUI();
			}
		}

		//하위메뉴창이 열렸을때 키세팅
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
	if (_ppstate == P_POKEMON_INFO)
	{
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_ppstate = P_POKEMON_LIST;
			_isSubMenu = true;
		}
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			switch (_plpokemon)
			{
				case LP_INFO:
					_plpokemon = LP_ABILITY;
				break;
				case LP_ABILITY:
					_plpokemon = LP_ATTK_SKILL;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			switch (_plpokemon)
			{
				case LP_ABILITY:
					_plpokemon = LP_INFO;
				break;
				case LP_ATTK_SKILL:
					_plpokemon = LP_ABILITY;
				break;
			}
		}
	}


}

void possessionPokemon::render()
{
	WCHAR possessionPokemon[1024];
	if (_ppstate == P_POKEMON_LIST)
	{
		IMAGEMANAGER->findImage("보유중포켓몬")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		if (!_isSubMenu)
		{
			MENUMANAGER->findMenuFrame("포켓몬프레임1")->render();
		}
		if (_ppselect == SELECT_CANCEL)
		{
			IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
		}
		else
		{
			IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
		}

		for (int i = 0; i < _pokemonCnt; ++i)
		{
			// 메인 포켓몬
			if (i == 0)
			{
				if (_ppselect == SELECT_MAIN_POKEMON)
				{
					IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 2);
				}
				else
				{
					IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
				}

				D2DMANAGER->drawText(_pPokemon[i].name.c_str(), 228, 115, 34, RGB(114,114,114));
				D2DMANAGER->drawText(_pPokemon[i].name.c_str(), 225, 115, 34, RGB(255, 255, 255));
				D2DMANAGER->drawText(_pPokemon[i].level.c_str(), 353, 170, 34, RGB(114, 114, 114));
				D2DMANAGER->drawText(_pPokemon[i].level.c_str(), 350, 170, 34, RGB(255, 255, 255));
				D2DMANAGER->drawText(_pPokemon[i].currentHp.c_str(), 263, 228, 48, RGB(114, 114, 114));
				D2DMANAGER->drawText(_pPokemon[i].currentHp.c_str(), 260, 225, 48, RGB(255, 255, 255));
				D2DMANAGER->drawText(_pPokemon[i].maxHp.c_str(), 343, 228, 48, RGB(114, 114, 114));
				D2DMANAGER->drawText(_pPokemon[i].maxHp.c_str(), 340, 225, 48, RGB(255, 255, 255));
			}
			else
			{
				if(i < _pokemonCnt)
				{
					if (_ppselect == i)
					{
						// 하늘색
						IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 50 + ((i-1) * 90) + CAMERA->getPosY(), 1, 0);
					}
					else
					{
						// 파란색
						IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 50 + ((i-1) * 90) + CAMERA->getPosY(), 0, 0);
					}

					D2DMANAGER->drawText(_pPokemon[i].name.c_str(), 553, 60 + ((i - 1) * 90), 30, RGB(114, 114, 114));
					D2DMANAGER->drawText(_pPokemon[i].name.c_str(), 550, 60 + ((i - 1) * 90), 30, RGB(255, 255, 255));
					D2DMANAGER->drawText(_pPokemon[i].level.c_str(), 623, 98 + ((i - 1) * 90), 38, RGB(114, 114, 114));
					D2DMANAGER->drawText(_pPokemon[i].level.c_str(), 620, 95 + ((i - 1) * 90), 38, RGB(255, 255, 255));
					D2DMANAGER->drawText(_pPokemon[i].currentHp.c_str(), 813, 98 + ((i - 1) * 90), 40, RGB(114, 114, 114));
					D2DMANAGER->drawText(_pPokemon[i].currentHp.c_str(), 810, 95 + ((i - 1) * 90), 40, RGB(255, 255, 255));
					D2DMANAGER->drawText(_pPokemon[i].maxHp.c_str(), 883, 98 + ((i - 1) * 90), 40, RGB(114, 114, 114));
					D2DMANAGER->drawText(_pPokemon[i].maxHp.c_str(), 880, 95 + ((i - 1) * 90), 40, RGB(255, 255, 255));
				}
				else
				{
					IMAGEMANAGER->findImage("서브포켓몬1")->render(450 + CAMERA->getPosX(), 50 + ((i-1) * 90) + CAMERA->getPosY());
				}
			}

			if (_isSubMenu)
			{
				MENUMANAGER->findMenuFrame("서머리메뉴")->render();
				MENUMANAGER->findMenuFrame("서머리정보")->render();

				swprintf_s(possessionPokemon, L"상태보기");
				D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 415 + CAMERA->getPosY(), 40);
				swprintf_s(possessionPokemon, L"순서변경");
				D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 465 + CAMERA->getPosY(), 40);
				swprintf_s(possessionPokemon, L"지닌물건");
				D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 515 + CAMERA->getPosY(), 40);
				swprintf_s(possessionPokemon, L"그만두기");
				D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 565 + CAMERA->getPosY(), 40);

				switch (_psmselect)
				{
				case SELECT_LOOK_POKEMON:
					IMAGEMANAGER->findImage("화살표")->render(670 + CAMERA->getPosX(), 415 + CAMERA->getPosY());
					break;
				case SELECT_CHANGE_ORDER:
					IMAGEMANAGER->findImage("화살표")->render(670 + CAMERA->getPosX(), 465 + CAMERA->getPosY());
					break;
				case SELECT_KEEP_ITEM:
					IMAGEMANAGER->findImage("화살표")->render(670 + CAMERA->getPosX(), 515 + CAMERA->getPosY());
					break;
				case SELECT_NONE:
					IMAGEMANAGER->findImage("화살표")->render(670 + CAMERA->getPosX(), 565 + CAMERA->getPosY());
					break;
				}
			}
		}
	}
	if (_ppstate == P_POKEMON_INFO)
	{
		IMAGEMANAGER->findImage("서머리배경")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		IMAGEMANAGER->findImage("서머리포켓몬")->render(0 + CAMERA->getPosX(), 64 + CAMERA->getPosY());
		switch (_plpokemon)
		{
		case LP_INFO:
			IMAGEMANAGER->findImage("서머리상단")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
			IMAGEMANAGER->findImage("서머리프레임")->frameRender(0 + CAMERA->getPosX(), 64 + CAMERA->getPosY(), 0, 0);
		break;
		case LP_ABILITY:
			IMAGEMANAGER->findImage("서머리상단")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 1);
			IMAGEMANAGER->findImage("서머리프레임")->frameRender(0 + CAMERA->getPosX(), 64 + CAMERA->getPosY(), 1, 0);
		break;
		case LP_ATTK_SKILL:
			IMAGEMANAGER->findImage("서머리상단")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 2);
			IMAGEMANAGER->findImage("서머리스킬")->render(476 + CAMERA->getPosX(), 64 + CAMERA->getPosY());
		break;
		}
	
	}

	swprintf_s(possessionPokemon, L"뭐선택중이냐너: %d", _pokemonCnt);
	D2DMANAGER->drawText(possessionPokemon, 285 + CAMERA->getPosX(), 415 + CAMERA->getPosY(), 40);
}

void possessionPokemon::uiInfoSet()
{
	pPokemonDataSet();
}

void possessionPokemon::pPokemonDataSet()
{
	locale("kor");
	//pokemon** pokemons = PLAYERDATA->getPlayer()->getPokemon();
	//_pokemonCnt = PLAYERDATA->getPlayer()->getCurrentPokemonCnt() + 1;
	
	//=============================================================임시데이터 지울꺼임
	pokemon** pokemons = new pokemon*[6];
	_pokemonCnt = 6;
	
	for (int i = 0; i < 6; ++i)
	{
		pokemons[i] = new pokemon;
	}
	pokemons[0]->init(0, (POKEMON)0, 5, true);
	pokemons[1]->init(0, (POKEMON)1, 10, true);
	pokemons[2]->init(0, (POKEMON)2, 15, true);
	pokemons[3]->init(0, (POKEMON)3, 20, true);
	pokemons[4]->init(0, (POKEMON)4, 15, true);
	pokemons[5]->init(0, (POKEMON)5, 30, true);

	//===============================================================================
	for (int i = 0; i < _pokemonCnt; ++i)
	{

		if (pokemons[i] == nullptr) continue;

		_pPokemon[i].isDataSet = false;
		_pPokemon[i].level = to_wstring(pokemons[i]->getLevel());

		_pPokemon[i].iD_number = to_wstring(pokemons[i]->getIdNo());
		_pPokemon[i].name = string2wstring(pokemons[i]->getName());
		_pPokemon[i].currentHp = to_wstring(pokemons[i]->getHp()); // 현재?
		_pPokemon[i].maxHp = to_wstring(pokemons[i]->getDisplayHp()); // 전체?

	}


}

void possessionPokemon::uiOpen()
{

}

void possessionPokemon::uiClose()
{
}
