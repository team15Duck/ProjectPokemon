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
	_scriptDelay = 0.3f;
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
			_scriptLength++;
			_viewScript.clear();
			for (int i = 0; i < _scriptLength; i++)
			{
				_viewScript += _script.front()[i];
			}

			if (_script.front().size() <= _scriptLength)
			{
				_script.pop();
				_scriptLength = 0;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_script.pop();
			_scriptLength = 0;
		}
	}
}

void battleUI::render()
{
	if (_script.size() > 0)
	{
		D2DMANAGER->drawText(_viewScript.c_str(), 30, 500, 20);
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
