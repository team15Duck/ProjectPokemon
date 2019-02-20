#include "stdafx.h"
#include "loadScene.h"


loadScene::loadScene()
{
}


loadScene::~loadScene()
{
}

HRESULT loadScene::init()
{
	MENUMANAGER->addFrame("loadFrame", 10, 1, 29, 15);
	MENUMANAGER->addFrame("textFrame", 10, 481, 29, 5);
	_select = 0;
	_startPointX = 64;
	_startPointY = 64;

	_pointPosX = _startPointX;
	_pointPosY = _startPointY;

	_isData = false;

	return S_OK;
}

void loadScene::release()
{
}

void loadScene::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_select++;
		_pointPosY += 64;
		if (_select >= 6)
		{
			_select = 0;
			_pointPosY = _startPointY;
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_select--;
		_pointPosY -= 64;
		if (_select < 0)
		{
			_select = 5;
			_pointPosY = _startPointY  * 6;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		//loadPlayData();
	}
}

void loadScene::render()
{
	MENUMANAGER->findMenuFrame("loadFrame")->render();
	IMAGEMANAGER->findImage("화살표")->render(_pointPosX, _pointPosY);
	
		wstring saveName;
		saveName = L"save1 : ";
		D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY, 30);
		saveName = L"save2 : ";
		D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (64 * 1),30);
		saveName = L"save3 : ";											   
		D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (64 * 2),30);
		saveName = L"save4 : ";											   
		D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (64 * 3),30);
		saveName = L"save5 : ";											   
		D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (64 * 4),30);
		saveName = L"save6 : ";											   
		D2DMANAGER->drawText(saveName.c_str(), 110, _startPointY + (64 * 5),30);
		


	



	if (!_isData)
	{
		MENUMANAGER->findMenuFrame("textFrame")->render();
		//IMAGEMANAGER->findImage("battleScript")->render(0, 640 - 192);
		wstring str;
		str = L"저장된 데이터가 없습니다.";
		D2DMANAGER->drawText(str.c_str(), 64, 525, 30);



		
	}

}

void loadScene::loadPlayData(int dataNum)
{
	//data

	//만약에 로드할 data가 있으면 로드를 하고
	
	

	
	//만약에 로드할 data가 없으면 "load할 data가 없습니다" 메세지 출력(이때 _isData 를 false로 만듬)
	
	
	



	
}
