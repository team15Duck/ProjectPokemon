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

	MENUMANAGER->addFrame("성별선택", 0, 0, 30, 20);
	MENUMANAGER->addFrame("남자", 300, 150, 10, 5);
	MENUMANAGER->addFrame("여자", 300, 350, 10, 5);
	IMAGEMANAGER->addImage("newGameArrow", L"image/player/arrow.png", 24, 40);
	IMAGEMANAGER->addImage("newGameNaming", L"image/player/naming.png", 960, 640);
	_isMan = true;
	_name = "";


	_nameSample[ 0] = "김";
	_nameSample[ 1] = "덕";
	_nameSample[ 2] = "영";
	_nameSample[ 3] = "십";
	_nameSample[ 4] = "오";
	_nameSample[ 5] = "원";
	_nameSample[ 6] = "윤";
	_nameSample[ 7] = "정";
	_nameSample[ 8] = "재";
	_nameSample[ 9] = "진";
	_nameSample[10] = "최";
	_nameSample[11] = "치";
	_nameSample[12] = "하";
	_nameSample[13] = "한";
	_nameSample[14] = "형";

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
			MENUMANAGER->findMenuFrame("성별선택")->render();
			MENUMANAGER->findMenuFrame("남자")->render();
			MENUMANAGER->findMenuFrame("여자")->render();

			D2DMANAGER->drawText(L"남   자", 370, 200, 50);
			D2DMANAGER->drawText(L"여   자", 370, 400, 50);

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
