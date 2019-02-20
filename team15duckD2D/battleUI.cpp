#include "stdafx.h"
#include "battleUI.h"
#include "pokemon.h"

battleUI::battleUI()
{
}


battleUI::~battleUI()
{
}

HRESULT battleUI::init()
{
	_scriptLength = 0;
	_scriptCount = 0;
	_scriptDelay = 0.05f;
	_currentPokemonNum = 0;
	IMAGEMANAGER->addImage("battleScript", L"image/battle_UI/battle_UI_Main_chat_board.png", 960, 192);

	_ppState = P_POKEMON_LIST;
	_ppselect = SELECT_MAIN_POKEMON;
	_psmselect = SELECT_LOOK_POKEMON;
	_plpokemon = LP_INFO;

	_isSubMenu = false;

	MENUMANAGER->addFrame("battleMenu", 480, 448, 15, 6);
	MENUMANAGER->addFrame("skillPPFrame", 480, 448, 15, 6);
	MENUMANAGER->addFrame("skillFrame", 0, 448, 15, 6);
	
	IMAGEMANAGER->addImage("playerUI", L"image/battle_UI/battle_UI_Player.png", 416, 148);
	IMAGEMANAGER->addImage("enemyUI", L"image/battle_UI/battle_UI_enemy.png", 400, 116);
	IMAGEMANAGER->addImage("battleCheckPoint", L"image/battle_UI/battle_UI_chk_point.png", 24, 40);

	IMAGEMANAGER->addImage("hpBar01", L"image/battle_UI/battle_UI_HP_01.png", 36, 12);
	IMAGEMANAGER->addImage("hpBar02", L"image/battle_UI/battle_UI_HP_02.png", 36, 12);
	IMAGEMANAGER->addImage("hpBar03", L"image/battle_UI/battle_UI_HP_03.png", 36, 12);
	IMAGEMANAGER->addImage("hpBarBase", L"image/battle_UI/battle_UI_HP_base.png", 36, 12);

	IMAGEMANAGER->addImage("expBar", L"image/battle_UI/battle_UI_experience_02.png", 28, 8);

	_isSkip = false;
	_currentMenu = BATTLE_UI_NONE;

	_currentSelectMenu = 0;
	_currentSelectSkill = 0;
	_isEscape = false;

	_isPlayerTurn = false;
	_isBattle = false;

	MENUMANAGER->addFrame("포켓몬프레임1", 0, 512, 23, 4);
	MENUMANAGER->addFrame("서머리메뉴2", 635, 444, 10, 6);
	MENUMANAGER->addFrame("서머리정보", 0, 512, 20, 4);



	IMAGEMANAGER->addFrameImage("서머리상단", L"image/Summary Menu/summary_top_bar.png", 960, 192, 1, 3);
	IMAGEMANAGER->addImage("서머리배경", L"image/Summary Menu/summary_base.png", 960, 640);
	IMAGEMANAGER->addFrameImage("서머리프레임", L"image/Summary Menu/summary_pokemon_info.png", 1920, 576, 2, 1);
	IMAGEMANAGER->addImage("서머리포켓몬", L"image/Summary Menu/summary_pokemon_base.png", 484, 336);
	IMAGEMANAGER->addImage("서머리스킬", L"image/Summary Menu/summary_pokemon_skill.png", 484, 576);
	IMAGEMANAGER->addImage("체력베이스", L"image/battle_UI/battle_UI_HP_base.png", 36, 12);
	IMAGEMANAGER->addFrameImage("체력게이지", L"image/pokemonMenu_gauge.png", 192, 12, 3, 1);


	_pokemonSelectNum = 0;

	return S_OK;
}

void battleUI::release()
{
}

void battleUI::update()
{
	_isKeyDownZ = false;
	if (_script.size() > 0)
	{
		_scriptCount += TIMEMANAGER->getElapsedTime();

		if (_scriptCount >= _scriptDelay)
		{
			_scriptCount = 0;
			if (_script.front().size() > _scriptLength)
			{
				_scriptLength++;
				_viewScript.clear();
				for (int i = 0; i < _scriptLength; i++)
				{
					_viewScript += _script.front()[i];
				}
				if (_scriptLength == _script.front().size())
				{
					_isSkip = true;
					if (_isEscape)
					{
						//원래있던씬으로
						SCENEMANAGER->changeScene(PLAYERDATA->getPlayer()->getSceneName());
					}
				}
			}
		}
		if (_isSkip)
		{
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_script.pop();
				_scriptLength = 0;
				_viewScript.clear();
				_isSkip = false;
				_isKeyDownZ = true;
			}
		}
	}
	else
	{
		switch (_currentMenu)
		{
			case BATTLE_UI_SKILL:
			break;
			case BATTLE_UI_BAG:
			break;
			case BATTLE_UI_POKEMON:

			break;
			case BATTLE_UI_RUN:
			break;
			case BATTLE_UI_NONE:
				if (KEYMANAGER->isOnceKeyDown('Z'))
				{
					switch (_currentSelectMenu)
					{
						case 0:
							//스킬창 열기
							_currentMenu = BATTLE_UI_SKILL;
						break;
						case 1:
							//포켓몬 열기
							_currentMenu = BATTLE_UI_POKEMON;

						break;
						case 2:
							//가방 열기
						break;
						case 3:
							_isEscape = true;
							pushScript(L"무사히 탈출했다.");
							_isSkip = false;
						break;
					}				
				}
			break;
		}
	}
}

void battleUI::render()
{
	if (_script.size() > 0)
	{
		IMAGEMANAGER->findImage("battleScript")->render(0,640 - 192);
		D2DMANAGER->drawText(_viewScript.c_str(), 50, 500, 30);
	}
	else
	{
		if (_isPlayerTurn)
		{
			if (_currentMenu == BATTLE_UI_SKILL)
			{
				MENUMANAGER->findMenuFrame("skillPPFrame")->render();
				MENUMANAGER->findMenuFrame("skillFrame")->render();

				for (int i = 0; i < _skillUI.size(); i++)
				{
					D2DMANAGER->drawText(_skillUI[i].skillName.c_str(), 80 + i / 2 * 200, 498 + i % 2 * 50, 30);
					if (i == _currentSelectSkill)
					{
						WCHAR str[128];
						swprintf_s(str, L"PP        %d/", _skillUI[i].currentPP);
						D2DMANAGER->drawText(str, 550, 500, 40);
						swprintf_s(str, L"%d", _skillUI[i].maxPP);
						D2DMANAGER->drawText(str, 810, 500, 40);
						swprintf_s(str, L"기술타입  /");
						D2DMANAGER->drawText(str, 550, 560, 40);
						D2DMANAGER->drawText(_skillUI[i].type.c_str(), 800, 560, 40);
					}
				}

				IMAGEMANAGER->findImage("battleCheckPoint")->render(50 + _currentSelectSkill / 2 * 200, 498 + _currentSelectSkill % 2 * 50);
			}
			else
			{
				IMAGEMANAGER->findImage("battleScript")->render(0, 640 - 192);
				wstring str = _pokemonName + L"은(는)";
				D2DMANAGER->drawText(str.c_str(), 50, 500, 30);
				str = L"무엇을할까?";
				D2DMANAGER->drawText(str.c_str(), 50, 550, 30);
				MENUMANAGER->findMenuFrame("battleMenu")->render();

				str = L"싸운다";
				D2DMANAGER->drawText(str.c_str(), 600, 500, 30);
				str = L"포켓몬";
				D2DMANAGER->drawText(str.c_str(), 600, 550, 30);
				str = L"가방";
				D2DMANAGER->drawText(str.c_str(), 800, 500, 30);
				str = L"도망간다";
				D2DMANAGER->drawText(str.c_str(), 800, 550, 30);

				IMAGEMANAGER->findImage("battleCheckPoint")->render(560 + _currentSelectMenu / 2 * 200, 498 + _currentSelectMenu % 2 * 50);
			}
		}
		else
			IMAGEMANAGER->findImage("battleScript")->render(0, 640 - 192);
	}

	if (_isBattle)
	{
		IMAGEMANAGER->findImage("playerUI")->render(544, 300);// , L"image/battle_UI/battle_UI_Player.png", 416, 148);
		if (_myPokemon)
		{
			D2DMANAGER->drawText(string2wstring(_myPokemon->getName()).c_str(), 600, 320, 35);
			WCHAR str[128];
			swprintf_s(str, L"Lv %d", _myPokemon->getLevel());
			D2DMANAGER->drawText(str, 800, 320, 35);

			swprintf_s(str, L"%d/", _myPokemon->getDisplayHp());
			D2DMANAGER->drawText(str, 700, 385, 30);
			swprintf_s(str, L"%d", _myPokemon->getMaxHp());
			D2DMANAGER->drawText(str, 800, 385, 30);
			IMAGEMANAGER->findImage("hpBarBase")->render(737, 367, 190, 12);
			float hpPercent = (float)_myPokemon->getDisplayHp() / (float)_myPokemon->getMaxHp();
			if (hpPercent < 0) hpPercent = 0;
			if (hpPercent > 0.5f)
			{
				IMAGEMANAGER->findImage("hpBar01")->render(737, 367, hpPercent * 190, 12);
			}
			else if (hpPercent > 0.2f && hpPercent <= 0.5f)
			{
				IMAGEMANAGER->findImage("hpBar02")->render(737, 367, hpPercent * 190, 12);
			}
			else
			{
				IMAGEMANAGER->findImage("hpBar03")->render(737, 367, hpPercent * 190, 12);
			}
			float expPercent = (float)_myPokemon->getCurrentDisplayExp() / (float)_myPokemon->getNextExp();
			if (expPercent < 0) expPercent = 0;
			IMAGEMANAGER->findImage("expBar")->render(672, 432, expPercent * 256, 8);

			if (_myPokemon->getCurrentDisplayExp() > 0)
			{

			}

		}


		IMAGEMANAGER->findImage("enemyUI")->render(0, 0);// , L"image/battle_UI/battle_UI_enemy.png", 400, 116);


		if (_enemyPokemon)
		{
			D2DMANAGER->drawText(string2wstring(_enemyPokemon->getName()).c_str(), 13, 15, 30);
			WCHAR str[128];
			swprintf_s(str, L"Lv %d", _enemyPokemon->getLevel());
			D2DMANAGER->drawText(str, 220, 15, 30);



			IMAGEMANAGER->findImage("hpBarBase")->render(157, 68, 190, 12);
			float hpPercent = (float)_enemyPokemon->getDisplayHp() / (float)_enemyPokemon->getMaxHp();
			if (hpPercent < 0) hpPercent = 0;
			if (hpPercent > 0.5f)
			{
				IMAGEMANAGER->findImage("hpBar01")->render(157, 68, hpPercent * 190, 12);
			}
			else if (hpPercent > 0.2f && hpPercent <= 0.5f)
			{
				IMAGEMANAGER->findImage("hpBar02")->render(157, 68, hpPercent * 190, 12);
			}
			else
			{
				IMAGEMANAGER->findImage("hpBar03")->render(157, 68, hpPercent * 190, 12);
			}
		}
	}
	
	switch (_currentMenu)
	{
		case BATTLE_UI_SKILL:
		break;
		case BATTLE_UI_BAG:
		break;
		case BATTLE_UI_POKEMON:

			WCHAR possessionPokemon[1024];
			if (_ppState == P_POKEMON_LIST)
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
				int j = 1;
				for (int i = 0; i < 6; ++i)
				{
					// 메인 포켓몬
					if (i == _currentPokemonNum && i < PLAYERDATA->getPlayer()->getCurrentPokemonCnt())
					{
						if (_ppselect == SELECT_MAIN_POKEMON)
						{
							IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 2);
						}
						else
						{
							IMAGEMANAGER->findImage("메인포켓몬")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
						}

						//hp
						float currentHp = PLAYERDATA->getPlayer()->getPokemonArray(i)->getHp();
						float maxHp = PLAYERDATA->getPlayer()->getPokemonArray(i)->getMaxHp();

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

						D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getName()).c_str(), 228, 115, 34, RGB(114, 114, 114));
						D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getName()).c_str(), 225, 115, 34, RGB(255, 255, 255));
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getLevel()).c_str(), 353, 170, 34, RGB(114, 114, 114));
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getLevel()).c_str(), 350, 170, 34, RGB(255, 255, 255));
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getHp()).c_str(), 263, 228, 48, RGB(114, 114, 114));
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getHp()).c_str(), 260, 225, 48, RGB(255, 255, 255));
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getMaxHp()).c_str(), 343, 228, 48, RGB(114, 114, 114));
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getMaxHp()).c_str(), 340, 225, 48, RGB(255, 255, 255));
					}
					else
					{
						if (i < PLAYERDATA->getPlayer()->getCurrentPokemonCnt())
						{
							if (_ppselect == i)
							{
								// 하늘색
								IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 50 + ((i - 1) * 90) + CAMERA->getPosY(), 1, 0);
							}
							else
							{
								// 파란색
								IMAGEMANAGER->findImage("서브포켓몬2")->frameRender(450 + CAMERA->getPosX(), 50 + ((i - 1) * 90) + CAMERA->getPosY(), 0, 0);
							}
							D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getName()).c_str(), 553, 60 + ((i - 1) * 90), 30, RGB(114, 114, 114));
							D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getName()).c_str(), 550, 60 + ((i - 1) * 90), 30, RGB(255, 255, 255));
							D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getLevel()).c_str(), 623, 98 + ((i - 1) * 90), 38, RGB(114, 114, 114));
							D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getLevel()).c_str(), 620, 95 + ((i - 1) * 90), 38, RGB(255, 255, 255));
							D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getHp()).c_str(), 813, 98 + ((i - 1) * 90), 40, RGB(114, 114, 114));
							D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getHp()).c_str(), 810, 95 + ((i - 1) * 90), 40, RGB(255, 255, 255));
							D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getMaxHp()).c_str(), 883, 98 + ((i - 1) * 90), 40, RGB(114, 114, 114));
							D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(i)->getMaxHp()).c_str(), 880, 95 + ((i - 1) * 90), 40, RGB(255, 255, 255));

							//hp
							float currentHp = PLAYERDATA->getPlayer()->getPokemonArray(i)->getHp();
							float maxHp = PLAYERDATA->getPlayer()->getPokemonArray(i)->getMaxHp();

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
							IMAGEMANAGER->findImage("서브포켓몬1")->render(450 + CAMERA->getPosX(), 50 + ((i - 1) * 90) + CAMERA->getPosY());
						}
						j++;
					}

					if (_isSubMenu)
					{
						MENUMANAGER->findMenuFrame("서머리메뉴2")->render();
						MENUMANAGER->findMenuFrame("서머리정보")->render();

						swprintf_s(possessionPokemon, L"내보내기");
						D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 465 + CAMERA->getPosY(), 40);
						swprintf_s(possessionPokemon, L"상태보기");
						D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 515 + CAMERA->getPosY(), 40);
						swprintf_s(possessionPokemon, L"그만두기");
						D2DMANAGER->drawText(possessionPokemon, 700 + CAMERA->getPosX(), 565 + CAMERA->getPosY(), 40);

						switch (_psmselect)
						{
							case SELECT_LOOK_POKEMON:
								IMAGEMANAGER->findImage("화살표")->render(670 + CAMERA->getPosX(), 465 + CAMERA->getPosY());
							break;
							case SELECT_CHANGE_ORDER:
								IMAGEMANAGER->findImage("화살표")->render(670 + CAMERA->getPosX(), 515 + CAMERA->getPosY());
							break;
							case SELECT_KEEP_ITEM:
								IMAGEMANAGER->findImage("화살표")->render(670 + CAMERA->getPosX(), 565 + CAMERA->getPosY());
							break;
						}
					}
				}
			}
			if (_ppState == P_POKEMON_INFO)
			{
				IMAGEMANAGER->findImage("서머리배경")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
				IMAGEMANAGER->findImage("서머리포켓몬")->render(0 + CAMERA->getPosX(), 64 + CAMERA->getPosY());
				switch (_plpokemon)
				{
					case LP_INFO:
						IMAGEMANAGER->findImage("서머리상단")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
						IMAGEMANAGER->findImage("서머리프레임")->frameRender(0 + CAMERA->getPosX(), 64 + CAMERA->getPosY(), 0, 0);

						swprintf_s(possessionPokemon, L"Lv.");
						D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getLevel()).c_str(), 100, 70, 58);
						D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getName()).c_str(), 230, 70, 58);

						//오른쪽정보
						D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getName()).c_str(), 670, 145, 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getIdNo()).c_str(), 670, 325, 40);
						
					break;
					case LP_ABILITY:
						IMAGEMANAGER->findImage("서머리상단")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 1);
						IMAGEMANAGER->findImage("서머리프레임")->frameRender(0 + CAMERA->getPosX(), 64 + CAMERA->getPosY(), 1, 0);

						swprintf_s(possessionPokemon, L"Lv.");
						D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getLevel()).c_str(), 100, 70, 58);
						D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getName()).c_str(), 230, 70, 58);

						//오른쪽정보
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getHp()).c_str(), 740, 85, 40);
						swprintf_s(possessionPokemon, L" / ");
						D2DMANAGER->drawText(possessionPokemon, 780 + CAMERA->getPosX(), 85 + CAMERA->getPosY(), 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getMaxHp()).c_str(), 860, 85, 40);

						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getAttk()).c_str(), 860, 155, 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getDex()).c_str(), 860, 210, 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getSpAttk()).c_str(), 860, 260, 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getSpDex()).c_str(), 860, 310, 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getspeed()).c_str(), 860, 355, 40);

					break;
					case LP_ATTK_SKILL:
						IMAGEMANAGER->findImage("서머리상단")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 2);
						IMAGEMANAGER->findImage("서머리스킬")->render(476 + CAMERA->getPosX(), 64 + CAMERA->getPosY());
						swprintf_s(possessionPokemon, L"Lv.");
						D2DMANAGER->drawText(possessionPokemon, 20 + CAMERA->getPosX(), 80 + CAMERA->getPosY(), 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getLevel()).c_str(), 100, 70, 58);
						D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getName()).c_str(), 230, 70, 58);

						//오른쪽정보
						D2DMANAGER->drawText(string2wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getName()).c_str(), 670, 145, 40);
						D2DMANAGER->drawText(to_wstring(PLAYERDATA->getPlayer()->getPokemonArray(_ppselect)->getIdNo()).c_str(), 670, 325, 40);
					break;
				}

			}

		break;
		case BATTLE_UI_RUN:
		break;
		case BATTLE_UI_NONE:
		break;
		default:
		break;
	}
	
}

void battleUI::pushScript(wstring script)
{
	_script.push(script);
}

bool battleUI::battleSceneUpdate()
{
	return _script.size() > 0 ? false : true;
}
