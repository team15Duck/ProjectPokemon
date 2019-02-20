#include "stdafx.h"
#include "newGameScene.h"


newGameScene::newGameScene()
{
}


newGameScene::~newGameScene()
{
}
 
HRESULT newGameScene::init()
{
	_step = NEWPLAYER_GENDER;

	MENUMANAGER->addFrame("��������", 0, 0, 30, 20);
	MENUMANAGER->addFrame("����", 300, 150, 10, 5);
	MENUMANAGER->addFrame("����", 300, 350, 10, 5);
	IMAGEMANAGER->addImage("newGameArrow", L"image/player/arrow.png", 24, 40);
	IMAGEMANAGER->addImage("newGameNaming", L"image/player/naming.png", 960, 640);
	_isMan = true;
	_name = "";


	_nameSample[ 0] = "��";
	_nameSample[ 1] = "��";
	_nameSample[ 2] = "��";
	_nameSample[ 3] = "��";
	_nameSample[ 4] = "��";
	_nameSample[ 5] = "��";
	_nameSample[ 6] = "��";
	_nameSample[ 7] = "��";
	_nameSample[ 8] = "��";
	_nameSample[ 9] = "��";
	_nameSample[10] = "��";
	_nameSample[11] = "ġ";
	_nameSample[12] = "��";
	_nameSample[13] = "��";
	_nameSample[14] = "��";

	_nameSelectNum = 0;


	return S_OK;
}

void newGameScene::release()
{
}

void newGameScene::update()
{
	switch (_step)
	{
		case newGameScene::NEWPLAYER_GENDER:
			if (KEYMANAGER->isOnceKeyDown(VK_UP) || KEYMANAGER->isOnceKeyDown(VK_DOWN))
				_isMan = !_isMan;
			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				PLAYERDATA->getPlayer()->setIsMan(_isMan);
				_step = NEWPLAYER_NAME;
			}
		break;
		case newGameScene::NEWPLAYER_NAME:

			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				if (_nameSelectNum < 5)
				{
					_nameSelectNum = 10 + _nameSelectNum;
				}
				else
				{
					_nameSelectNum -= 5;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				if (_nameSelectNum > 9)
				{
					_nameSelectNum = _nameSelectNum - 10;
				}
				else
				{
					_nameSelectNum += 5;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
			{
				if (_nameSelectNum == 0)
				{
					_nameSelectNum = 14;
				}
				else
				{
					_nameSelectNum--;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
			{
				if (_nameSelectNum == 14)
				{
					_nameSelectNum = 0;
				}
				else
				{
					_nameSelectNum++;
				}
			}

			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				if (_name.size() < 14)
				{
					_name += _nameSample[_nameSelectNum];
				}
			}

			if (KEYMANAGER->isOnceKeyDown(VK_BACK))
			{
				if (_name.size() > 0)
				{
					_name.pop_back();
					_name.pop_back();
				}
			}

			if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
			{
				if (_name.size() > 0)
				{
					PLAYERDATA->getPlayer()->setName(_name);
					PLAYERDATA->getPlayer()->setSceneName("homeScene");
					SCENEMANAGER->changeScene("homeScene");
				}
			}

		break;
	}
}

void newGameScene::render()
{
	switch (_step)
	{
		case newGameScene::NEWPLAYER_GENDER:
			MENUMANAGER->findMenuFrame("��������")->render();
			MENUMANAGER->findMenuFrame("����")->render();
			MENUMANAGER->findMenuFrame("����")->render();

			D2DMANAGER->drawText(L"��   ��", 370, 200, 50);
			D2DMANAGER->drawText(L"��   ��", 370, 400, 50);

			if (_isMan)
				IMAGEMANAGER->findImage("newGameArrow")->render(340, 205);
			else
				IMAGEMANAGER->findImage("newGameArrow")->render(340, 405);
		break;
		case newGameScene::NEWPLAYER_NAME:
			IMAGEMANAGER->findImage("newGameNaming")->render(0, 0);
			for (int i = 0; i < 15; i++)
			{
				D2DMANAGER->drawText(string2wstring(_nameSample[i]).c_str(), 200 + i % 5 * 130, 340 + i / 5 * 90, 50);
			}
			D2DMANAGER->drawText(string2wstring(_name).c_str(), 390, 215, 32);
			IMAGEMANAGER->findImage("newGameArrow")->render(170 + _nameSelectNum % 5 * 130, 340 + _nameSelectNum / 5 * 90);
		break;
	}
}
