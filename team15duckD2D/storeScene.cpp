#include "stdafx.h"
#include "storeScene.h"


storeScene::storeScene()
{
}

storeScene::~storeScene()
{
}



HRESULT storeScene::init()
{
	_storeMap = new storeMap;
	_storeMap->init("data/storeMapSize.map", "data/storeMapData.map");

	_storeMap->setPlayerMemoryAdressLink(PLAYERDATA->getPlayer());
	PLAYERDATA->getPlayer()->setMapDataMemoryAdressLink(_storeMap);
	
	SOUNDMANAGER->addSound("storeBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);
	//SOUNDMANAGER->play("storeBGM");

	_npc = new npc;
	_npc->init(NPC_TYPE_SHOPOWNER);
	_storeMap->pushNpc(_npc);

	_test = false;
	
	return S_OK;
}

void storeScene::release()
{
	_storeMap->release();
}

void storeScene::update()
{
	_storeMap->update();
	PLAYERDATA->getPlayer()->update();
	_npc->update();

	_test = _npc->getIsTalk();
	if (_test)
	{
		//activeShopOwner();
	}

	SCRIPTMANAGER->update();
	CAMERA->move(PLAYERDATA->getPlayer()->getPosX(), PLAYERDATA->getPlayer()->getPosY());
}

void storeScene::render()
{
	_storeMap->render();
	SCRIPTMANAGER->render();
}

void storeScene::activeShopOwner()
{
	//����â ( 1. �緯�Դ� / 2. �ȷ��Դ� / 3. �ƴմϴ�)

	//1. �緯�Դ� ����������
	{
		wstring text = L"(������)(��)�� \n�� �� �����Ͻðڽ��ϱ�?";
		SCRIPTMANAGER->pushScript(text);
	}
	//��������
	{
		wstring text = L"(������) (����)�α���. \n�� (�ݾ�)���ϴ�.";
		SCRIPTMANAGER->pushScript(text);
	}
	{
		wstring text = L"�� ���� �ֽ��ϴ�. \n����� �����մϴ�.";
		SCRIPTMANAGER->pushScript(text);
	}

	//2. �ȷ��Դ� ���������� 
	{
		wstring text = L"(������)(��)�� \n �� �� �Ľðڽ��ϱ�?";
		SCRIPTMANAGER->pushScript(text);
	}
	//��������
	{
		wstring text = L"(������) (����)�α���. �� (�ݾ�)���Դϴ�.";
		SCRIPTMANAGER->pushScript(text);
	}
	{
		wstring text = L"(������)(��)�� �޾� (�ݾ�)���� ��Ƚ��ϴ�.";
		SCRIPTMANAGER->pushScript(text);
	}

	//1,2������ ��ҹ�ư ��������
	{
		wstring text = L"�� �ۿ� ���� \n�� ���͵帱 �� �����ϱ�?";
		SCRIPTMANAGER->pushScript(text);
	}

	//3. �ƴմϴ�.
	{
		wstring text = L"�� ������!";
		SCRIPTMANAGER->pushScript(text);
	}
}
