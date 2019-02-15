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
	_frameNameMap.insert(make_pair(0, "Ÿ��1"));
	_frameNameMap.insert(make_pair(1, "Ÿ��2"));
	_frameNameMap.insert(make_pair(2, "Ÿ��3"));
	_frameNameMap.insert(make_pair(3, "Ÿ��4"));
	_frameNameMap.insert(make_pair(4, "Ÿ��5"));
	_frameNameMap.insert(make_pair(5, "Ÿ��6"));
	_frameNameMap.insert(make_pair(6, "Ÿ��7"));
	_frameNameMap.insert(make_pair(7, "Ÿ��8"));
	_frameNameMap.insert(make_pair(8, "Ÿ��9"));
	_frameNameMap.insert(make_pair(9, "Ÿ��10"));

	return S_OK;
}

void menuFrameManager::release()
{
	mapMenuFrameIter miMenuFrameList = _mMenuFrameList.begin();

	for (; miMenuFrameList != _mMenuFrameList.end();)
	{
		//���࿡ ����Ʈ�� 2��°�� �����ִٸ� 
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

	//������ ���� ��ã�Ҵ�
	if (find == _mMenuFrameList.end()) return nullptr;

	return find->second;
}

void menuFrameManager::render(string key, string imgName)
{
	mapMenuFrameIter find = _mMenuFrameList.find(key);

	//������ ���� ��ã�Ҵ�
	if (find == _mMenuFrameList.end()) return;

	//find->second->render(imgName);
}

