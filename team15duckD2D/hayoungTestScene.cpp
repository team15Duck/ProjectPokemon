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

	_cm._bottom = { 0, 490, 960, 640 };
	_cm._menu[0] = { 726, 37, 918, 107 };
	_cm._menu[1] = { 726, 107, 918, 177 };
	_cm._menu[2] = { 726, 177, 918, 247 };
	_cm._menu[3] = { 726, 247, 918, 317 };
	_cm._menu[4] = { 726, 317, 918, 387 };
	_cm._menu[5] = { 726, 387, 918, 457 };
 	_cm._cursor[0] = { 702, 52, 726, 92 };
	_rc = { 0 , 480, 960, 640 };
	MENUMANAGER->addFrame("�⺻�޴�", 670, 1, 9, 15);
	_isCommonMenu = false;
	
	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{
	//���࿡ ����Ű�� ������ 
	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		_isCommonMenu = true;
	}
	if (KEYMANAGER->isOnceKeyDown('X'))
	{
		_isCommonMenu = false;
	}
}

void hayoungTestScene::render()
{

	if (_isCommonMenu)
	{
		IMAGEMANAGER->findImage("�׽�Ʈ")->render(0,0);
		MENUMANAGER->findMenuFrame("�⺻�޴�")->render("Ÿ��1");

		D2DMANAGER->fillRectangle(RGB(255, 0, 255), _cm._menu[0]);
		D2DMANAGER->fillRectangle(RGB(0, 10, 255), _cm._menu[1]);
		D2DMANAGER->fillRectangle(RGB(100, 20, 50), _cm._menu[2]);
		D2DMANAGER->fillRectangle(RGB(12, 30, 25), _cm._menu[3]);
		D2DMANAGER->fillRectangle(RGB(0, 30, 0), _cm._menu[4]);
		D2DMANAGER->fillRectangle(RGB(110, 30, 110), _cm._menu[5]);


		D2DMANAGER->fillRectangle(RGB(0, 0, 50), _cm._cursor[0]);
		IMAGEMANAGER->findImage("ȭ��ǥ")->render(_cm._cursor[0].left + CAMERA->getPosX(), _cm._cursor[0].top + CAMERA->getPosY());
		IMAGEMANAGER->findImage("�⺻�ϴ�")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());

		WCHAR str[128];
		swprintf_s(str, L"����");
		D2DMANAGER->drawText(str, _cm._menu[0].left + CAMERA->getPosX(), _cm._menu[0].top+ 15 + CAMERA->getPosY(), 40);
	}
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_bg.png", 960, 160);
	IMAGEMANAGER->addImage("ȭ��ǥ", L"image/pokemonMenu_cursor.png", 24, 40);
	IMAGEMANAGER->addImage("�׽�Ʈ", L"image/test/aaa.png", 960, 640);

}
