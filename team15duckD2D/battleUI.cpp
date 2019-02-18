#include "stdafx.h"
#include "battleUI.h"


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

	IMAGEMANAGER->addImage("battleScript", L"image/battle_UI/battle_UI_Main_chat_board.png", 960, 192);

	
	MENUMANAGER->addFrame("battleMenu", 480, 448, 15, 6);
	MENUMANAGER->addFrame("skillPPFrame", 480, 448, 15, 6);
	MENUMANAGER->addFrame("skillFrame", 0, 448, 15, 6);
	
	IMAGEMANAGER->addImage("playerUI", L"image/battle_UI/battle_UI_Player.png", 416, 148);
	IMAGEMANAGER->addImage("enemyUI", L"image/battle_UI/battle_UI_enemy.png", 400, 116);
	IMAGEMANAGER->addImage("battleCheckPoint", L"image/battle_UI/battle_UI_chk_point.png", 24, 40);
	_isSkip = false;
	_currentMenu = BATTLE_UI_NONE;

	_currentSelectMenu = 0;
	_currentSelectSkill = 0;
	_isEscape = false;
	return S_OK;
}

void battleUI::release()
{
}

void battleUI::update()
{
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
							//가방 열기

						break;
						case 2:
							//포켓몬 열기

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
		

		if (_currentMenu == BATTLE_UI_SKILL)
		{
			MENUMANAGER->findMenuFrame("skillPPFrame")->render();
			MENUMANAGER->findMenuFrame("skillFrame")->render();

			for (int i = 0; i < _skillUI.size(); i++)
			{
				D2DMANAGER->drawText(_skillUI[i].skillName.c_str(), 80 + i / 2 * 200, 498 + i % 2 * 50, 30 );
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
	IMAGEMANAGER->findImage("playerUI")->render(960 - 416, 448 - 148);// , L"image/battle_UI/battle_UI_Player.png", 416, 148);
	
	
	if (_myPokemon)
	{

	}
	
	
	
	
	
	
	
	
	
	
	
	
	IMAGEMANAGER->findImage("enemyUI")->render(0, 0);// , L"image/battle_UI/battle_UI_enemy.png", 400, 116);


	if (_enemyPokemon)
	{

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
