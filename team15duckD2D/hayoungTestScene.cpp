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
	
	MENUMANAGER->addFrame("��ü�޴�������", 630, 5, 10, 15);
	MENUMANAGER->addFrame("���¯", 0, 0, 30, 20);

	
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
	string type = "Ÿ��3";
	MENUMANAGER->findMenuFrame("��ü�޴�������")->render(type);
	MENUMANAGER->findMenuFrame("���¯")->render("Ÿ��6");

	IMAGEMANAGER->findImage("�⺻�ϴ�")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_bg.png", 960, 150);

}
