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
	// 1. �������� ���ǰ�� �ִ�. �׸��� ���԰��� 0 / �ǸŰ� ����				 v
	// 2. value���� �ӵ�, ���� ���� Ȯ�� �� �ʿ��ϴ�.						 v
	// 3. ������ �̹����� ��� UI�� ��ġ�� �����ϴ�. (����, ����, �����ý���)	 v
	// 4. ���ϸ��� ��ȹ���� ��� �Ұ��� �����غ���
	// 5. ���̺�ε� ������
	// ==============================================================

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

	_vItems[_choiceItem]->render();
}

