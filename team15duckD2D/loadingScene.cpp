#include "stdafx.h"
#include "loadingScene.h"


loadingScene::loadingScene()
	:_backGround(nullptr), _currentCount(0)
{
}


loadingScene::~loadingScene()
{
}

HRESULT loadingScene::init()
{
	//����̶� �ε��� �̹��� ó�� �ϸ�� ���⼭ 
	//����̶� �ε��� �̹��� ó�� �ϸ�� ���⼭ 
	//����̶� �ε��� �̹��� ó�� �ϸ�� ���⼭ 


	CreateThread
	(
		NULL,			//�������� ���ȼӼ�(�ڽ������찡 ������) �ڵ�� �ڽ����� �θ����� �����ľ�
		NULL,			//�������� ����ũ��(NULL�� �θ� ���ξ������ ����ũ��� ����)
		ThreadFunction,	//������ �Լ� ��
		this,			//�������� �Ű����� (this�� �ϸ� �� Ŭ����)
		NULL,			//�������� Ư��(NULL�� �θ� �ٷ� ������)
		0				//�������� ���� �� �������� ID�� �Ѱ��ش� ������ NULL�� ��.
	);

	return S_OK;
}

void loadingScene::release()
{
}

void loadingScene::update()
{
	//��������������



	//�ٷε��ϸ� ���ٲ�
	if (_currentCount == LOADINGMAX) 
	{
		//SCENEMANAGER->changeScene("");
	}

}

void loadingScene::render()
{
	//��׶���
	//�ε���
}



DWORD CALLBACK ThreadFunction(LPVOID lpParameter)
{
	loadingScene* loadHelper = (loadingScene*)lpParameter;

	//���� ���ҽ� �߰��ع����� loadHelper->_currentCount++; �̰�����ߵ� �׷��� ������ ������

	return 0;
}
