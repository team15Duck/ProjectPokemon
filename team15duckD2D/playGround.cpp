#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);
	
	IMAGEMANAGER->addFrameImage("테스트", L"image/playerM.png", 1500, 1500, 10, 10);

	return S_OK;
}

void playGround::release()
{
	gameNode::release();
	
}

void playGround::update()
{
	gameNode::update();



}

void playGround::render()
{
	// Draw 시작 - 이 코드가 빠지면 D2D 출력 X
	D2DMANAGER->beginDraw();
	//===========================================================================
	//				##		여기에 코드 작성(Start)			##



	IMAGEMANAGER->findImage("테스트")->frameRenderReverseX(0, 0, 0, 2, 1);

	




	//				##			여기에 코드 작성(End)			##
	//===========================================================================
	//				##카메라 정보 마우스 정보 시간정보 출력	##===================
	WCHAR str[128];
	swprintf_s(str, L"cameraX : %.1f / %.1f", CAMERA->getPosX(), (float)CAMERA->getMaxX());
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 80);
	swprintf_s(str, L"cameraY : %.1f / %.1f", CAMERA->getPosY(), (float)CAMERA->getMaxY());
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 100);
	swprintf_s(str, L"mouseX : %.2f", _ptMouse.x);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 140);
	swprintf_s(str, L"mouseY : %.2f", _ptMouse.y);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 160);
	TIMEMANAGER->render();
	// Draw 끝 - 이 코드가 빠지면 D2D 출력 X
	D2DMANAGER->endDraw();
}