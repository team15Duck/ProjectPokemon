#include "stdafx.h"
#include "scriptManager.h"


scriptManager::scriptManager()
{
}


scriptManager::~scriptManager()
{
}

HRESULT scriptManager::init()
{
	_scriptLength = 0;
	_scriptCount = 0;
	_scriptDelay = 0.05f;

	MENUMANAGER->addFrame("scriptFrame", 0, 640 - 192, 15, 6);

	
	return S_OK;
}

void scriptManager::release()
{
}

void scriptManager::update()
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

void scriptManager::render()
{
	if (_script.size() > 0)
	{
		MENUMANAGER->findMenuFrame("scriptFrame")->render();
		D2DMANAGER->drawText(_viewScript.c_str(), 50 + CAMERA->getPosX(), 500 + CAMERA->getPosY(), 30);
	}
}

void scriptManager::pushScript(wstring script)
{
	_script.push(script);
}

bool scriptManager::isUpdate()
{
	return _script.size() > 0 ? false : true;
}
