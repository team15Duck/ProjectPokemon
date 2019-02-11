#include "stdafx.h"
#include "itemManager.h"
#include "pokemonInfo.h"

itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	_vItems.clear();
	// ==============================================================
	// 1. �������� ���ǰ�� �ִ�. �׸��� ���԰��� 0 / �ǸŰ� ����
	// 2. value���� �ӵ�, ���� ���� Ȯ�� �� �ʿ��ϴ�.
	// 3. ������ �̹����� ��� UI�� ��ġ�� �����ϴ�. (����, ����, �����ý���)
	// 4. ���ϸ��� ��ȹ���� ��� �Ұ��� �����غ���
	// ==============================================================
	IMAGEMANAGER->addFrameImage("items", L"image/items.png", 2600, 100, 26, 1);
	IMAGEMANAGER->addImage("�׽�Ʈ11", L"image/test/ccc.png", 960, 640);

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
}

void itemManager::render()
{
	IMAGEMANAGER->render("�׽�Ʈ11", 0 + CAMERA->getPosX(), 0 + +CAMERA->getPosY(), 1.0f);
	_vItems[_choiceItem]->render();
}

