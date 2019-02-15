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
	
	IMAGEMANAGER->addImage("playerUI", L"image/battle_UI/battle_UI_Player.png", 416, 148);
	IMAGEMANAGER->addImage("enemyUI", L"image/battle_UI/battle_UI_enemy.png", 400, 116);

	_isSkip = false;
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
				}
			}
		}

		//if (_isSkip)
		//{
		//	_script.pop();
		//	_scriptLength = 0;
		//	_viewScript.clear();
		//	_isSkip = false;
		//}
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
	}
	IMAGEMANAGER->findImage("playerUI")->render(960 - 416, 448 - 148);// , L"image/battle_UI/battle_UI_Player.png", 416, 148);
	IMAGEMANAGER->findImage("enemyUI")->render(0, 0);// , L"image/battle_UI/battle_UI_enemy.png", 400, 116);
}

void battleUI::pushScript(wstring script)
{
	_script.push(script);
}

bool battleUI::battleSceneUpdate()
{
	return _script.size() > 0 ? false : true;
}
