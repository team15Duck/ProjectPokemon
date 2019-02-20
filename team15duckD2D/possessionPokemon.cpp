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
	IMAGEMANAGER->addImage("체력베이스", L"image/battle_UI/battle_UI_HP_base.png", 36, 12);
	IMAGEMANAGER->addFrameImage("체력게이지", L"image/pokemonMenu_gauge.png", 192, 12, 3, 1);
	_isMainpokemon = true;
	_isSubpokemon = false;
	_isSubMenu = false;
	_isPokemonChange = false;


	//================================ 애니 테스트
	keyani();

	return S_OK;
}

void possessionPokemon::release()
{
}

void possessionPokemon::update()
{

	if (_ppstate == P_POKEMON_LIST)
	{
		for (int i = 0; i < _pokemonCnt; ++i)
		{
			_pokemonAni[i]->frameUpdate(TIMEMANAGER->getElapsedTime());
		}

		//포켓몬 리스트 이동관련
		if (!_isSubMenu)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				if (_ppselect == SELECT_MAIN_POKEMON)
				{
					if (0 < _pokemonCnt)
					{
						_ppselect = SELECT_SUB_POKEMON1;
					}
					else
					{
						_ppselect = SELECT_CANCEL;
					}
				}
				else if (_ppselect == SELECT_CANCEL)
				{
					_ppselect = SELECT_MAIN_POKEMON;
				}
				else
				{
					if (_pokemonCnt <= _ppselect + 1)
					{
						_ppselect = SELECT_CANCEL;
					}
					else
					{
						switch (_ppselect)
						{
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
						}
					}
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
				if (!_isPokemonChange)
				{
					_isSubMenu = true;
				}
				else
				{
					//to do : 포켓몬바꾸기임다 
					_changeSelecPok = _ppselect;

					uiInfoSet();					//데이터신규갱신
					_isPokemonChange = false;		//불값 끄기
				}
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
					_isPokemonChange = true;
					_isSubMenu = false;
					
					_currentSelecPok = _ppselect;
				break;
				case SELECT_KEEP_ITEM:
					//아이템 전달하기 끝나면추가추가 
				break;
				case SELECT_NONE:
					_isSubMenu = false;
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
			swprintf_s(possessionPokemon, L"포켓몬을 선택해주세요");
			D2DMANAGER->drawText(possessionPokemon, 50 + CAMERA->getPosX(), 555 + CAMERA->getPosY(), 40);
		}
		if (_ppselect == SELECT_CANCEL)
		{
			IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
		}
		else
		{
			IMAGEMANAGER->findImage("포켓몬메뉴_취소")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
		}
		swprintf_s(possessionPokemon, L"취소");
		D2DMANAGER->drawText(possessionPokemon, 835 + CAMERA->getPosX(), 558 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
		for (int i = 0; i < 6; ++i)
		{
			// 메인 포켓몬
			if (i == 0)
			{
				if (_ppselect == SELECT_MAIN_POKEMON)
				{
					IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 2);
					if (_isPokemonChange)
					{
						IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 3);
					}
				}
				else
				{
					IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
					if (_isPokemonChange)
					{
						IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 1);
					}
				}

				//hp
				float currentHp = stof(_pPokemon[i].currentHp);
				float maxHp = stof(_pPokemon[i].maxHp);

				float hpPercent = currentHp / maxHp;

				if (hpPercent < 0)
				{
					hpPercent = 0;
				}
				if (hpPercent > 0.5f)
				{
					IMAGEMANAGER->findImage("체력게이지")->frameRender(200 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), hpPercent * 192, 12, 2, 0);
				}
				else if (hpPercent > 0.2f && hpPercent <= 0.5f)
				{
					IMAGEMANAGER->findImage("체력게이지")->frameRender(200 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), hpPercent * 192, 12, 1, 0);
				}
				else
				{
					IMAGEMANAGER->findImage("체력게이지")->frameRender(200 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), hpPercent * 192, 12, 0, 0);
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
					D2DMANAGER->drawText(_pPokemon[i].name.c_str(), 583, 60 + ((i - 1) * 90), 30, RGB(114, 114, 114));
					D2DMANAGER->drawText(_pPokemon[i].name.c_str(), 580, 60 + ((i - 1) * 90), 30, RGB(255, 255, 255));
					D2DMANAGER->drawText(_pPokemon[i].level.c_str(), 623, 98 + ((i - 1) * 90), 38, RGB(114, 114, 114));
					D2DMANAGER->drawText(_pPokemon[i].level.c_str(), 620, 95 + ((i - 1) * 90), 38, RGB(255, 255, 255));
					D2DMANAGER->drawText(_pPokemon[i].currentHp.c_str(), 813, 98 + ((i - 1) * 90), 40, RGB(114, 114, 114));
					D2DMANAGER->drawText(_pPokemon[i].currentHp.c_str(), 810, 95 + ((i - 1) * 90), 40, RGB(255, 255, 255));
					D2DMANAGER->drawText(_pPokemon[i].maxHp.c_str(), 883, 98 + ((i - 1) * 90), 40, RGB(114, 114, 114));
					D2DMANAGER->drawText(_pPokemon[i].maxHp.c_str(), 880, 95 + ((i - 1) * 90), 40, RGB(255, 255, 255));
				
					//hp
					float currentHp = stof(_pPokemon[i].currentHp);
					float maxHp = stof(_pPokemon[i].maxHp);

					float hpPercent = currentHp / maxHp;

					if (hpPercent < 0)
					{
						hpPercent = 0;
					}
					if (hpPercent > 0.5f)
					{
						IMAGEMANAGER->findImage("체력게이지")->frameRender(770 + CAMERA->getPosX(), 80 + ((i - 1) * 90) + CAMERA->getPosY(), hpPercent * 160, 10, 2, 0);
					}
					else if (hpPercent > 0.2f && hpPercent <= 0.5f)
					{
						IMAGEMANAGER->findImage("체력게이지")->frameRender(770 + CAMERA->getPosX(), 80 + ((i - 1) * 90) + CAMERA->getPosY(), hpPercent * 160, 10, 1, 0);
					}
					else
					{
						IMAGEMANAGER->findImage("체력게이지")->frameRender(770 + CAMERA->getPosX(), 80 + ((i - 1) * 90) + CAMERA->getPosY(), hpPercent * 160, 10, 0, 0);
					}
				}
				else
				{
					IMAGEMANAGER->findImage("서브포켓몬1")->render(450 + CAMERA->getPosX(), 50 + ((i-1) * 90) + CAMERA->getPosY());
				}
			}

			//===================================================================================== 애니메이션
			
			//메인 포켓몬 애니
			IMAGEMANAGER->findImage("포켓몬파닥")->aniRender(100,100, _pokemonAni[0]);

			//서브 포켓몬 애니
			for (int i = 1; i < _pokemonCnt; ++i)
			{
				IMAGEMANAGER->findImage("포켓몬파닥2")->aniRender(510, 60 + ((i - 1) * 85), _pokemonAni[i]);
			}
			//===============================================================================================

			if (_isSubMenu)
			{
				MENUMANAGER->findMenuFrame("서머리메뉴")->render();
				MENUMANAGER->findMenuFrame("서머리정보")->render();

				swprintf_s(possessionPokemon, L"어떻게할까?");
				D2DMANAGER->drawText(possessionPokemon, 50 + CAMERA->getPosX(), 555 + CAMERA->getPosY(), 40);

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
				switch (_ppselect)
				{
				case SELECT_MAIN_POKEMON:
					swprintf_s(possessionPokemon, L"Lv.");
					D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
					D2DMANAGER->drawText(_pPokemon[0].level.c_str(), 100, 70, 58);
					D2DMANAGER->drawText(_pPokemon[0].name.c_str(), 230, 70, 58);

					//오른쪽정보
					D2DMANAGER->drawText(_pPokemon[0].name.c_str(), 670, 145, 40);
					D2DMANAGER->drawText(_pPokemon[0].iD_number.c_str(), 670, 325, 40);
						break;
				case SELECT_SUB_POKEMON1:
					swprintf_s(possessionPokemon, L"Lv.");
					D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
					D2DMANAGER->drawText(_pPokemon[1].level.c_str(), 100, 70, 58);
					D2DMANAGER->drawText(_pPokemon[1].name.c_str(), 230, 70, 58);

					//오른쪽정보
					D2DMANAGER->drawText(_pPokemon[1].name.c_str(), 670, 145, 40);
					D2DMANAGER->drawText(_pPokemon[1].iD_number.c_str(), 670, 325, 40);
					break;
				case SELECT_SUB_POKEMON2:
					swprintf_s(possessionPokemon, L"Lv.");
					D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
					D2DMANAGER->drawText(_pPokemon[2].level.c_str(), 100, 70, 58);
					D2DMANAGER->drawText(_pPokemon[2].name.c_str(), 230, 70, 58);

					//오른쪽정보
					D2DMANAGER->drawText(_pPokemon[2].name.c_str(), 670, 145, 40);
					D2DMANAGER->drawText(_pPokemon[2].iD_number.c_str(), 670, 325, 40);
					break;
				case SELECT_SUB_POKEMON3:
					swprintf_s(possessionPokemon, L"Lv.");
					D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
					D2DMANAGER->drawText(_pPokemon[3].level.c_str(), 100, 70, 58);
					D2DMANAGER->drawText(_pPokemon[3].name.c_str(), 230, 70, 58);

					//오른쪽정보
					D2DMANAGER->drawText(_pPokemon[3].name.c_str(), 670, 145, 40);
					D2DMANAGER->drawText(_pPokemon[3].iD_number.c_str(), 670, 325, 40);
					break;
				case SELECT_SUB_POKEMON4:
					swprintf_s(possessionPokemon, L"Lv.");
					D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
					D2DMANAGER->drawText(_pPokemon[4].level.c_str(), 100, 70, 58);
					D2DMANAGER->drawText(_pPokemon[4].name.c_str(), 230, 70, 58);

					//오른쪽정보
					D2DMANAGER->drawText(_pPokemon[4].name.c_str(), 670, 145, 40);
					D2DMANAGER->drawText(_pPokemon[4].iD_number.c_str(), 670, 325, 40);
					break;
				case SELECT_SUB_POKEMON5:
					swprintf_s(possessionPokemon, L"Lv.");
					D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
					D2DMANAGER->drawText(_pPokemon[5].level.c_str(), 100, 70, 58);
					D2DMANAGER->drawText(_pPokemon[5].name.c_str(), 230, 70, 58);

					//오른쪽정보
					D2DMANAGER->drawText(_pPokemon[5].name.c_str(), 670, 145, 40);
					D2DMANAGER->drawText(_pPokemon[5].iD_number.c_str(), 670, 325, 40);
					break;
				}
			
		break;
		case LP_ABILITY:
			IMAGEMANAGER->findImage("서머리상단")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 1);
			IMAGEMANAGER->findImage("서머리프레임")->frameRender(0 + CAMERA->getPosX(), 64 + CAMERA->getPosY(), 1, 0);
		
			switch (_ppselect)
			{
			case SELECT_MAIN_POKEMON:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[0].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[0].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[0].currentHp.c_str(), 740, 85, 40);
				swprintf_s(possessionPokemon, L" / ");
				D2DMANAGER->drawText(possessionPokemon, 780 + CAMERA->getPosX(), 85 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[0].maxHp.c_str(), 860, 85, 40);
				
				D2DMANAGER->drawText(_pPokemon[0].attk.c_str(), 860, 155, 40);
				D2DMANAGER->drawText(_pPokemon[0].def.c_str(), 860, 210, 40);
				D2DMANAGER->drawText(_pPokemon[0].s_attk.c_str(), 860, 260, 40);
				D2DMANAGER->drawText(_pPokemon[0].s_def.c_str(), 860, 310, 40);
				D2DMANAGER->drawText(_pPokemon[0].speed.c_str(), 860, 365, 40);
				D2DMANAGER->drawText(_pPokemon[0].currentExp.c_str(), 860, 420, 40);
				D2DMANAGER->drawText(_pPokemon[0].nextLvExp.c_str(), 860, 470, 40);
				break;
			case SELECT_SUB_POKEMON1:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[1].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[1].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[1].currentHp.c_str(), 740, 85, 40);
				swprintf_s(possessionPokemon, L" / ");
				D2DMANAGER->drawText(possessionPokemon, 780 + CAMERA->getPosX(), 85 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[1].maxHp.c_str(), 860, 85, 40);

				D2DMANAGER->drawText(_pPokemon[1].attk.c_str(), 860, 155, 40);
				D2DMANAGER->drawText(_pPokemon[1].def.c_str(), 860, 210, 40);
				D2DMANAGER->drawText(_pPokemon[1].s_attk.c_str(), 860, 260, 40);
				D2DMANAGER->drawText(_pPokemon[1].s_def.c_str(), 860, 310, 40);
				D2DMANAGER->drawText(_pPokemon[1].speed.c_str(), 860, 355, 40);
				D2DMANAGER->drawText(_pPokemon[1].currentExp.c_str(), 860, 420, 40);
				D2DMANAGER->drawText(_pPokemon[1].nextLvExp.c_str(), 860, 470, 40);
				break;
			case SELECT_SUB_POKEMON2:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[2].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[2].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[2].currentHp.c_str(), 740, 85, 40);
				swprintf_s(possessionPokemon, L" / ");
				D2DMANAGER->drawText(possessionPokemon, 780 + CAMERA->getPosX(), 85 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[2].maxHp.c_str(), 860, 85, 40);

				D2DMANAGER->drawText(_pPokemon[2].attk.c_str(), 860, 155, 40);
				D2DMANAGER->drawText(_pPokemon[2].def.c_str(), 860, 210, 40);
				D2DMANAGER->drawText(_pPokemon[2].s_attk.c_str(), 860, 260, 40);
				D2DMANAGER->drawText(_pPokemon[2].s_def.c_str(), 860, 310, 40);
				D2DMANAGER->drawText(_pPokemon[2].speed.c_str(), 860, 355, 40);
				D2DMANAGER->drawText(_pPokemon[2].currentExp.c_str(), 860, 420, 40);
				D2DMANAGER->drawText(_pPokemon[2].nextLvExp.c_str(), 860, 470, 40);
				break;
			case SELECT_SUB_POKEMON3:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[3].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[3].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[3].currentHp.c_str(), 740, 85, 40);
				swprintf_s(possessionPokemon, L" / ");
				D2DMANAGER->drawText(possessionPokemon, 780 + CAMERA->getPosX(), 85 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[3].maxHp.c_str(), 860, 85, 40);

				D2DMANAGER->drawText(_pPokemon[3].attk.c_str(), 860, 155, 40);
				D2DMANAGER->drawText(_pPokemon[3].def.c_str(), 860, 210, 40);
				D2DMANAGER->drawText(_pPokemon[3].s_attk.c_str(), 860, 260, 40);
				D2DMANAGER->drawText(_pPokemon[3].s_def.c_str(), 860, 310, 40);
				D2DMANAGER->drawText(_pPokemon[3].speed.c_str(), 860, 355, 40);
				D2DMANAGER->drawText(_pPokemon[3].currentExp.c_str(), 860, 420, 40);
				D2DMANAGER->drawText(_pPokemon[3].nextLvExp.c_str(), 860, 470, 40);
				break;
			case SELECT_SUB_POKEMON4:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[4].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[4].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[4].currentHp.c_str(), 740, 85, 40);
				swprintf_s(possessionPokemon, L" / ");
				D2DMANAGER->drawText(possessionPokemon, 780 + CAMERA->getPosX(), 85 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[4].maxHp.c_str(), 860, 85, 40);

				D2DMANAGER->drawText(_pPokemon[4].attk.c_str(), 860, 155, 40);
				D2DMANAGER->drawText(_pPokemon[4].def.c_str(), 860, 210, 40);
				D2DMANAGER->drawText(_pPokemon[4].s_attk.c_str(), 860, 260, 40);
				D2DMANAGER->drawText(_pPokemon[4].s_def.c_str(), 860, 310, 40);
				D2DMANAGER->drawText(_pPokemon[4].speed.c_str(), 860, 355, 40);
				D2DMANAGER->drawText(_pPokemon[4].currentExp.c_str(), 860, 420, 40);
				D2DMANAGER->drawText(_pPokemon[4].nextLvExp.c_str(), 860, 470, 40);

				break;
			case SELECT_SUB_POKEMON5:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[5].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[5].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[5].currentHp.c_str(), 740, 85, 40);
				swprintf_s(possessionPokemon, L" / ");
				D2DMANAGER->drawText(possessionPokemon, 780 + CAMERA->getPosX(), 85 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[5].maxHp.c_str(), 860, 85, 40);

				D2DMANAGER->drawText(_pPokemon[5].attk.c_str(), 860, 155, 40);
				D2DMANAGER->drawText(_pPokemon[5].def.c_str(), 860, 210, 40);
				D2DMANAGER->drawText(_pPokemon[5].s_attk.c_str(), 860, 260, 40);
				D2DMANAGER->drawText(_pPokemon[5].s_def.c_str(), 860, 310, 40);
				D2DMANAGER->drawText(_pPokemon[5].speed.c_str(), 860, 355, 40);
				D2DMANAGER->drawText(_pPokemon[5].currentExp.c_str(), 860, 420, 40);
				D2DMANAGER->drawText(_pPokemon[5].nextLvExp.c_str(), 860, 470, 40);
				
				break;
			}
			break;
		case LP_ATTK_SKILL:
			IMAGEMANAGER->findImage("서머리상단")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 2);
			IMAGEMANAGER->findImage("서머리스킬")->render(476 + CAMERA->getPosX(), 64 + CAMERA->getPosY());
			switch (_ppselect)
			{
			case SELECT_MAIN_POKEMON:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[0].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[0].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[0].name.c_str(), 670, 145, 40);
				D2DMANAGER->drawText(_pPokemon[0].iD_number.c_str(), 670, 325, 40);
				break;
			case SELECT_SUB_POKEMON1:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[1].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[1].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[1].name.c_str(), 670, 145, 40);
				D2DMANAGER->drawText(_pPokemon[1].iD_number.c_str(), 670, 325, 40);
				break;
			case SELECT_SUB_POKEMON2:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[2].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[2].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[2].name.c_str(), 670, 145, 40);
				D2DMANAGER->drawText(_pPokemon[2].iD_number.c_str(), 670, 325, 40);
				break;
			case SELECT_SUB_POKEMON3:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[3].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[3].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[3].name.c_str(), 670, 145, 40);
				D2DMANAGER->drawText(_pPokemon[3].iD_number.c_str(), 670, 325, 40);
				break;
			case SELECT_SUB_POKEMON4:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[4].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[4].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[4].name.c_str(), 670, 145, 40);
				D2DMANAGER->drawText(_pPokemon[4].iD_number.c_str(), 670, 325, 40);
				break;
			case SELECT_SUB_POKEMON5:
				swprintf_s(possessionPokemon, L"Lv.");
				D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
				D2DMANAGER->drawText(_pPokemon[5].level.c_str(), 100, 70, 58);
				D2DMANAGER->drawText(_pPokemon[5].name.c_str(), 230, 70, 58);

				//오른쪽정보
				D2DMANAGER->drawText(_pPokemon[5].name.c_str(), 670, 145, 40);
				D2DMANAGER->drawText(_pPokemon[5].iD_number.c_str(), 670, 325, 40);
				break;
			}
		break;
		}
	
	}

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
	pokemon** pokemons = new pokemon*[5];
	_pokemonCnt = 5;
	
	for (int i = 0; i < 5; ++i)
	{
		pokemons[i] = new pokemon;
	}
	pokemons[0]->init(0, (POKEMON)0, 5, true);
	pokemons[1]->init(0, (POKEMON)1, 10, true);
	pokemons[2]->init(0, (POKEMON)2, 15, true);
	pokemons[3]->init(0, (POKEMON)3, 20, true);
	pokemons[4]->init(0, (POKEMON)4, 15, true);
	//pokemons[5]->init(0, (POKEMON)5, 30, true);

	//===============================================================================
	for (int i = 0; i < _pokemonCnt; ++i)
	{

		if (pokemons[i] == nullptr) continue;

		_pPokemon[i].isDataSet = false;
		_pPokemon[i].level = to_wstring(pokemons[i]->getLevel());

		_pPokemon[i].iD_number = to_wstring(pokemons[i]->getIdNo());
		_pPokemon[i].name = string2wstring(pokemons[i]->getName());
		//_pPokemon[i].type = string2wstring(pokemons[i]->getPokemonType()); 이뇨속 스위치로해서 가져와야하나욥?
		_pPokemon[i].currentHp = to_wstring(pokemons[i]->getHp()); // 현재?
		_pPokemon[i].maxHp = to_wstring(pokemons[i]->getMaxHp()); // 전체?
		
		_pPokemon[i].def = to_wstring(pokemons[i]->getDex());
		_pPokemon[i].s_def = to_wstring(pokemons[i]->getSpDex());
	
		_pPokemon[i].attk = to_wstring(pokemons[i]->getAttk());
		_pPokemon[i].s_attk = to_wstring(pokemons[i]->getSpAttk());

		_pPokemon[i].speed = to_wstring(pokemons[i]->getspeed());

		_pPokemon[i].currentExp = to_wstring(pokemons[i]->getCurrentExp());
		_pPokemon[i].nextLvExp = to_wstring(pokemons[i]->getNextExp());






		char name[128] = "";
		sprintf_s(name, "ui_pokemons_%d", pokemons[i]->getPokeminIndex());
		_pokemonAni[i] = KEYANIMANAGER->findAnimation("포켓몬선택", name);
		_pokemonAni[i]->start();
	}


}

void possessionPokemon::uiOpen()
{
	_ppstate = P_POKEMON_LIST;
	_ppselect = SELECT_MAIN_POKEMON;
	_psmselect = SELECT_LOOK_POKEMON;
	_plpokemon = LP_INFO;
}

void possessionPokemon::uiClose()
{
}

void possessionPokemon::keyani()
{
	IMAGEMANAGER->addFrameImage("포켓몬파닥", L"image/pokemon/pokemon_mini.png", 2304, 2176, 18, 17);	//큰사이즈 메인 포켓몬용
	IMAGEMANAGER->addFrameImage("포켓몬파닥2", L"image/pokemon/pokemon_mini_start.png", 2304 / 2, 2176 / 2, 18, 17);	//작은사이즈 서브 포켓몬용

	KEYANIMANAGER->addAnimationType("포켓몬선택");
	
	//큰 포켓몬용
	for (int i = 0; i < 151; ++i)
	{
		int pokemons_mini[] = { i * 2, i * 2 + 1 };
		char keyName[128] = "";
		sprintf_s(keyName, "ui_pokemons_%d", i);

		KEYANIMANAGER->addArrayFrameAnimation("포켓몬선택", keyName, "포켓몬파닥", pokemons_mini, 2, 10, true);
	}
	//작은포켓몬용
	for (int i = 0; i < 151; ++i)
	{
		int pokemons_mini2[] = { i * 2, i * 2 + 1 };
		char keyName2[128] = "";
		sprintf_s(keyName2, "ui_pokemons_%d", i);
		
		KEYANIMANAGER->addArrayFrameAnimation("포켓몬선택", keyName2, "포켓몬파닥2", pokemons_mini2, 2, 10, true);
	}
}
