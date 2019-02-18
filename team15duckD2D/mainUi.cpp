#include "stdafx.h"
#include "mainUi.h"


mainUi::mainUi()
{
}


mainUi::~mainUi()
{
}

HRESULT mainUi::init()
{
	//메인메뉴 초기화 
	MENUMANAGER->addFrame("메인메뉴", 670, 1, 9, 15);

	return S_OK;
}

void mainUi::release()
{
}

void mainUi::update()
{
	
}

void mainUi::render()
{
}
