#include "stdafx.h"
#include "menuFrame.h"


menuFrame::menuFrame()
	:_menuFrameInfo(nullptr)
{
}


menuFrame::~menuFrame()
{
}

HRESULT menuFrame::init(UINT destX, UINT destY, UINT frameWidth, UINT frameHeight)
{
	if (_menuFrameInfo != NULL) release();

	_menuFrameInfo = new MENU_FRAME_INFO;
	_menuFrameInfo->destX = destX;
	_menuFrameInfo->destY = destY;
	_menuFrameInfo->frameWidth = frameWidth;
	_menuFrameInfo->frameHeight = frameHeight;

	_settingframe = new setting;
	

	return S_OK;
}


void menuFrame::release()
{
	if (_menuFrameInfo)
	{
		SAFE_DELETE(_menuFrameInfo);
	}
}

void menuFrame::render()
{
	string name = MENUMANAGER->getFrameName(MENUMANAGER->getFrameType());


	//상단 오른쪽 왼쪽
	IMAGEMANAGER->findImage(name + "_01")->render(_menuFrameInfo->destX + CAMERA->getPosX(), _menuFrameInfo->destY + CAMERA->getPosY(), 1);
	IMAGEMANAGER->findImage(name + "_03")->render(_menuFrameInfo->destX + ((_menuFrameInfo->frameWidth - 1) * 32) + CAMERA->getPosX(), _menuFrameInfo->destY + CAMERA->getPosY(), 1);

	//하단 오른쪽 왼쪽
	IMAGEMANAGER->findImage(name + "_06")->render(_menuFrameInfo->destX + CAMERA->getPosX(), _menuFrameInfo->destY + (_menuFrameInfo->frameHeight - 1) * 32 + CAMERA->getPosY(), 1);
	IMAGEMANAGER->findImage(name + "_08")->render(_menuFrameInfo->destX + ((_menuFrameInfo->frameWidth - 1) * 32) + CAMERA->getPosX(), _menuFrameInfo->destY + (_menuFrameInfo->frameHeight - 1) * 32 + CAMERA->getPosY(), 1);


	//상단 길게 
	IMAGEMANAGER->findImage(name + "_02")->render(_menuFrameInfo->destX + 32 + CAMERA->getPosX(),
												  _menuFrameInfo->destY + CAMERA->getPosY(),
												  (_menuFrameInfo->frameWidth - 2) * 32,
												  32,
												  0, 0, 32, 32, 1);
	//하단 길게 
	IMAGEMANAGER->findImage(name + "_07")->render(_menuFrameInfo->destX + 32 + CAMERA->getPosX(),
												  _menuFrameInfo->destY + ((_menuFrameInfo->frameHeight - 1) * 32) + CAMERA->getPosY(),
												  (_menuFrameInfo->frameWidth - 2) * 32,
												  32,
												  0, 0, 32, 32, 1);
	//왼쪽 길게
	IMAGEMANAGER->findImage(name + "_04")->render(_menuFrameInfo->destX + CAMERA->getPosX(),
												  _menuFrameInfo->destY + 32 + CAMERA->getPosY(),
												  32,
												  (_menuFrameInfo->frameHeight - 2) * 32,
												  0, 0, 32, 32, 1);
	//오른쪽 길게
	IMAGEMANAGER->findImage(name + "_05")->render(_menuFrameInfo->destX + ((_menuFrameInfo->frameWidth - 1) * 32) + CAMERA->getPosX(),
												  _menuFrameInfo->destY + 32 + CAMERA->getPosY(),
												  32,
												  (_menuFrameInfo->frameHeight - 2) * 32,
												  0, 0, 32, 32, 1);

	IMAGEMANAGER->findImage("프레임기본")->render(_menuFrameInfo->destX + 32 + CAMERA->getPosX(),				//그려주기 시작할 지점 
												 _menuFrameInfo->destY + 32 + CAMERA->getPosY(),				//그려주기 시작할 지점
												 (_menuFrameInfo->frameWidth - 2) * 32,							//늘릴 크기
												 (_menuFrameInfo->frameHeight - 2) * 32,							//늘릴 크기
												 0,
												 0, 32, 32, 1);
}
