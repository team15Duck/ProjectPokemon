#include "stdafx.h"
#include "loadScene.h"
#include "newGameScene.h"

loadScene::loadScene()
{
}


loadScene::~loadScene()
{
}

HRESULT loadScene::init()
{
	IMAGEMANAGER->addImage("loadBackground", L"image/load.png", 960, 640);
	MENUMANAGER->addFrame("loadFrame", 1, 1, 30, 14);
	MENUMANAGER->addFrame("textFrame", 1, 481, 30, 5);
	MENUMANAGER->addFrame("newGameFrame", 640, 320, 10, 4);
	_select = 0;
	_startPointX = 64;
	_startPointY = 60;

	_pointPosX = _startPointX;
	_pointPosY = _startPointY;

	_storePosX = _storePosY = 0;

	_isSaveLocation = true;
	_isData = false;

	return S_OK;
}

void loadScene::release()
{
}

void loadScene::update()
{
	SCRIPTMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_select++;
		_pointPosY += _startPointY;
		if (_select >= 6)
		{
			_select = 0;
			_pointPosY = _startPointY;
		}
		//ȭ��ǥ�� �����ϱ� ��ư �ʿ� ������ ���� ������ �ؾߡ�
		if (_pointPosX >= 600)
		{
			_pointPosY = _startPointY * 6;
			return;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_select--;
		_pointPosY -= _startPointY;
		if (_select < 0)
		{
			_select = 5;
			_pointPosY = _startPointY  * 6;
		}
		//ȭ��ǥ�� �����ϱ� ��ư �ʿ� ������ ���� ������ �ؾߡ�
		if (_pointPosX >= 600)
		{
			_pointPosY = _startPointY * 6;
			return;

		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		//save �ʿ� ȭ��ǥ�� ������ �����ϱ������� �Űܰ��ô�
		if (_pointPosX >= 0 && _pointPosX < 600)
		{
			_pointPosX = 688;
			_pointPosY = _startPointY * 6;
		}
		//�����ϱ� �ʿ� ȭ��ǥ�� ������ save������ �Űܰ��ô�
		else if (_pointPosX >= 600)
		{
			_pointPosX = _startPointX;
			_pointPosY = _startPointY * 6;
		}
		//save���� ���ư��� ���� ���ؼ� _select ��ȣ�� �����ϱ� �� Y�� ��ǥ�� ��ġ�ϴ� ��ȣ�� �ٲ���� �ؿ�
		//(�׷��� �����ϱ⿡�� save�� ���ƿ��� �� ������ ������ ������ �ʾƿ�)
		_select = 5;

	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		//save �ʿ� ȭ��ǥ�� ������ �����ϱ������� �Űܰ��ô�
		if (_pointPosX >= 0 && _pointPosX < 600)
		{
			_pointPosX = 688;
			_pointPosY = _startPointY * 6;
		}
		//�����ϱ� �ʿ� ȭ��ǥ�� ������ save������ �Űܰ��ô�
		else if (_pointPosX >= 600)
		{
			_pointPosX = _startPointX;
			_pointPosY = _startPointY * 6;
		}
		_select = 5;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		int loadData = _pointPosY / 60;
		if (_pointPosX == 688)
		{
			//�����ϱ�
			SCENEMANAGER->changeScene("newGameScene");
		}
		else
		{
			PLAYERDATA->dataLoad(playerDataBase::DATA(loadData));
		}
	}
}

void loadScene::render()
{
	IMAGEMANAGER->render("loadBackground");
	MENUMANAGER->findMenuFrame("loadFrame")->render();


	wstring saveName;
	saveName = L"save1 : " + string2wstring(PLAYERDATA->playerDataLoad(playerDataBase::DATA::DATA_1)[0]);
	D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY, 30);
	saveName = L"save2 : " + string2wstring(PLAYERDATA->playerDataLoad(playerDataBase::DATA::DATA_2)[0]);
	D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (_startPointY * 1),30);
	saveName = L"save3 : " + string2wstring(PLAYERDATA->playerDataLoad(playerDataBase::DATA::DATA_3)[0]);
	D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (_startPointY * 2),30);
	saveName = L"save4 : " + string2wstring(PLAYERDATA->playerDataLoad(playerDataBase::DATA::DATA_4)[0]);
	D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (_startPointY * 3),30);
	saveName = L"save5 : " + string2wstring(PLAYERDATA->playerDataLoad(playerDataBase::DATA::DATA_5)[0]);
	D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (_startPointY * 4),30);
	saveName = L"save6 : " + string2wstring(PLAYERDATA->playerDataLoad(playerDataBase::DATA::DATA_6)[0]);
	D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (_startPointY * 5),30);


	if (!_isData)
	{
		MENUMANAGER->findMenuFrame("textFrame")->render();
		

		SCRIPTMANAGER->render();
		//D2DMANAGER->drawText(str.c_str(), 64, 525, 30);
	}
	MENUMANAGER->findMenuFrame("newGameFrame")->render();
	IMAGEMANAGER->findImage("ȭ��ǥ")->render(_pointPosX, _pointPosY);

	saveName = L"�����ϱ�";
	D2DMANAGER->drawText(saveName.c_str(), 736, _startPointY + (_startPointY * 5) + 10, 30);


}

void loadScene::loadPlayData(int dataNum)
{
	//data

	//���࿡ �ε��� data�� ������ �ε带 �ϰ�
	
	

	
	//���࿡ �ε��� data�� ������ "load�� data�� �����ϴ�" �޼��� ���(�̶� _isData �� false�� ����)
	
	
	



	
}
