#include "stdafx.h"
#include "hayoungTestScene.h"


hayoungTestScene::hayoungTestScene()
{
}


hayoungTestScene::~hayoungTestScene()
{
}

HRESULT hayoungTestScene::init()
{
	frameImageinit();
	
	MENUMANAGER->addFrame("전체메뉴프레임", 630, 5, 10, 15);
	MENUMANAGER->addFrame("재원짱", 0, 0, 30, 20);

	
	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{
}

void hayoungTestScene::render()
{
	string type = "타입3";
	MENUMANAGER->findMenuFrame("전체메뉴프레임")->render(type);
	MENUMANAGER->findMenuFrame("재원짱")->render("타입6");

	IMAGEMANAGER->findImage("기본하단")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("기본하단", L"image/common_bg.png", 960, 150);

}
