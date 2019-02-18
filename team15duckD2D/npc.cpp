#include "stdafx.h"
#include "npc.h"


npc::npc()
{
}


npc::~npc()
{
}

HRESULT npc::init(string sceneName)
{
	_sceneName = sceneName;
	IMAGEMANAGER->addFrameImage("oak", L"image/oak.png", 720, 85, 12, 1);

	settingNPC();

	return S_OK;
}

void npc::release()
{
}

void npc::update()
{
	//=================================
	//
	// �÷��̾ ���ɾ����� ���� ������ �ݴ�� �÷��̾ �����Ѵ�.
	//
	//=================================
}

void npc::render()
{
	IMAGEMANAGER->findImage(_npcName)->frameRender(_tileX, _tileY, 0, 0);
}

void npc::settingNPC()
{
	if (_sceneName == "mapTestScene")
	{
		_npcName = "oak";
		_tileX = 16 * 64;
		_tileY = 10 * 64 - 20; //??????????????
	}
	//else if (_sceneName == "���;�")
	//{

	//	_npcName = "nurse";
	//	_tileX = 16 * 64;
	//	_tileY = 10 * 64 - 20; //??????????????
	//}
	//else if (_sceneName == "������")
	//{

	//	_npcName = "shopOnwer";
	//	_tileX = 16 * 64;
	//	_tileY = 10 * 64 - 20; //??????????????
	//}
	//else if (_sceneName == "ü������")
	//{

	//	_npcName = "shopOnwer";
	//	_tileX = 16 * 64;
	//	_tileY = 10 * 64 - 20; //??????????????
	//}
}
