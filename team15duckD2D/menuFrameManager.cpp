#include "stdafx.h"
#include "menuFrameManager.h"


menuFrameManager::menuFrameManager()
{
}


menuFrameManager::~menuFrameManager()
{
}

HRESULT menuFrameManager::init()
{
	return S_OK;
}

void menuFrameManager::release()
{
	mapMenuFrameIter miMenuFrameList = _mMenuFrameList.begin();

	for (; miMenuFrameList != _mMenuFrameList.end();)
	{
		//만약에 리스트의 2번째에 무언가있다면 
		if (miMenuFrameList->second != nullptr)
		{
			miMenuFrameList->second->release();
			SAFE_DELETE(miMenuFrameList->second);
			miMenuFrameList++;
		}
	}
	_mMenuFrameList.clear();
}

menuFrame * menuFrameManager::addFrame(string key, UINT destX, UINT destY, UINT frameWidth, UINT frameHeight)
{
	menuFrame* newFrame = findMenuFrame(key);
	
	if (newFrame) return newFrame;

	newFrame = new menuFrame;
	if (FAILED(newFrame->init(destX, destY, frameWidth, frameHeight)))
	{
		SAFE_DELETE(newFrame);
		return nullptr;
	}
	
	_mMenuFrameList.insert(make_pair(key, newFrame));

	return newFrame;
}

menuFrame * menuFrameManager::findMenuFrame(string key)
{
	mapMenuFrameIter find = _mMenuFrameList.find(key);

	//변경할 씬을 못찾았다
	if (find == _mMenuFrameList.end()) return nullptr;

	return find->second;
}

void menuFrameManager::render(string key, string imgName)
{
	mapMenuFrameIter find = _mMenuFrameList.find(key);

	//변경할 씬을 못찾았다
	if (find == _mMenuFrameList.end()) return;

	find->second->render(imgName);
}
