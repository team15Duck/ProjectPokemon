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
	//���θ޴� �ʱ�ȭ 
	MENUMANAGER->addFrame("���θ޴�", 670, 1, 9, 15);

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
