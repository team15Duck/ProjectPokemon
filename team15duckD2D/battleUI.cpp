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

	MENUMANAGER->addFrame("battleScript", 0, 448, 30, 6);
	MENUMANAGER->addFrame("battleMenu", 512, 448, 14, 6);
	_script.push(L"이건 테스트용 텍스트이다 1");
	_script.push(L"이건 테스트용 텍스트이다 2");
	_script.push(L"이건 테스트용 텍스트이다 3");
	_script.push(L"이건 테스트용 텍스트이다 4");
	_script.push(L"이건 테스트용 텍스트이다 5");
	_script.push(L"이건 테스트용 텍스트이다 6");
	_script.push(L"이건 테스트용 텍스트이다 7");
	_script.push(L"이건 테스트용 텍스트이다 8");
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
			}
			
		}
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_script.pop();
			_scriptLength = 0;
			_viewScript.clear();
		}
	}
}

void battleUI::render()
{
	if (_script.size() > 0)
	{
		MENUMANAGER->findMenuFrame("battleScript")->render("타입1");
		D2DMANAGER->drawText(_viewScript.c_str(), 30, 520, 25);
	}
	else
	{
		MENUMANAGER->findMenuFrame("battleScript")->render("타입1");
		wstring str = L"무엇을할까?";
		D2DMANAGER->drawText(str.c_str(), 30, 520, 25);
		MENUMANAGER->findMenuFrame("battleMenu")->render("타입1");
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
