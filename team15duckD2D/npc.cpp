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
	// 플레이어가 말걸었을때 보는 방향의 반대로 플레이어를 봐야한다.
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
	//else if (_sceneName == "센터씬")
	//{

	//	_npcName = "nurse";
	//	_tileX = 16 * 64;
	//	_tileY = 10 * 64 - 20; //??????????????
	//}
	//else if (_sceneName == "상점씬")
	//{

	//	_npcName = "shopOnwer";
	//	_tileX = 16 * 64;
	//	_tileY = 10 * 64 - 20; //??????????????
	//}
	//else if (_sceneName == "체육관씬")
	//{

	//	_npcName = "shopOnwer";
	//	_tileX = 16 * 64;
	//	_tileY = 10 * 64 - 20; //??????????????
	//}
}
