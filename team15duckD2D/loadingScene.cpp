#include "stdafx.h"
#include "loadingScene.h"


loadingScene::loadingScene()
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
}

void loadingScene::render()
{
	//��׶���
	//�ε���
}



DWORD CALLBACK ThreadFunction(LPVOID lpParameter)
{
	loadingScene* loadHelper = (loadingScene*)lpParameter;

	//�ε��ƽ��� 1000�̱� ������ �̹����� ���Ƿ� 1000���� �������ô�
	while (loadHelper->_currentCount != LOADINGMAX)
	{
		IMAGEMANAGER->addImage("�ΰ���", "ĳ����.bmp", 580, 565, false, RGB(0, 0, 0));
		Sleep(1); //�̰� ������ õ���̰� ���� �Ĵٴٴ� �ع���

		loadHelper->_currentCount++;
	}

	return 0;
}
