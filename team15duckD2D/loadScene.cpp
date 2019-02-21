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
		//화살표가 새로하기 버튼 쪽에 있으면 위로 못가게 해야죱
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
		//화살표가 새로하기 버튼 쪽에 있으면 위로 못가게 해야죱
		if (_pointPosX >= 600)
		{
			_pointPosY = _startPointY * 6;
			return;

		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		//save 쪽에 화살표가 있으면 새로하기쪽으로 옮겨갑시다
		if (_pointPosX >= 0 && _pointPosX < 600)
		{
			_pointPosX = 688;
			_pointPosY = _startPointY * 6;
		}
		//새로하기 쪽에 화살표가 있으면 save쪽으로 옮겨갑시다
		else if (_pointPosX >= 600)
		{
			_pointPosX = _startPointX;
			_pointPosY = _startPointY * 6;
		}
		//save쪽을 돌아갔을 때를 위해서 _select 번호는 새로하기 의 Y축 좌표와 일치하는 번호로 바꿔줘야 해영
		//(그래야 새로하기에서 save로 돌아왔을 때 프레임 밖으로 나가지 않아욥)
		_select = 5;

	}
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		//save 쪽에 화살표가 있으면 새로하기쪽으로 옮겨갑시다
		if (_pointPosX >= 0 && _pointPosX < 600)
		{
			_pointPosX = 688;
			_pointPosY = _startPointY * 6;
		}
		//새로하기 쪽에 화살표가 있으면 save쪽으로 옮겨갑시다
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
			//새로하기
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
	IMAGEMANAGER->findImage("화살표")->render(_pointPosX, _pointPosY);

	saveName = L"새로하기";
	D2DMANAGER->drawText(saveName.c_str(), 736, _startPointY + (_startPointY * 5) + 10, 30);


}

void loadScene::loadPlayData(int dataNum)
{
	//data

	//만약에 로드할 data가 있으면 로드를 하고
	
	

	
	//만약에 로드할 data가 없으면 "load할 data가 없습니다" 메세지 출력(이때 _isData 를 false로 만듬)
	
	
	



	
}
