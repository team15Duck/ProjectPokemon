#include "stdafx.h"
#include "hayoungTestScene.h"


hayoungTestScene::hayoungTestScene()
{
}


hayoungTestScene::~hayoungTestScene()
{
}

HRESULT hayoungTestScene::init()
{
	frameImageinit();
	//_rc = { 0, 490, 960, 640 };
	//
	//uiframeMake(10, 15, 32, 630, 5);

	//for (int i = 0; i < 15; ++i)
	//{
	//	for (int j = 0; j < 10; j++)
	//	{
	//		float left = 630 + (j * 32);
	//		float top = 5 + (i * 32);
	//		float right = left + 32;
	//		float bottom = top + 32;
	//		_test[i * 10 + j] = { left, top, right, bottom };
	//	}
	//}

	MENUMANAGER->addFrame("��ü�޴�������", 630, 5, 10, 15);

	
	return S_OK;
}

void hayoungTestScene::release()
{
}

void hayoungTestScene::update()
{
}

void hayoungTestScene::render()
{
	string type = "Ÿ��3";
	MENUMANAGER->findMenuFrame("��ü�޴�������")->render(type);
	/*
	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 && j == 0)
			{
				//��������������
				IMAGEMANAGER->findImage("Ÿ��1_01")->render(_test[0].left + CAMERA->getPosX(), _test[0].top + CAMERA->getPosY());
			}
			else if (i == 14 && j == 0)
			{
				//���ʾƷ�
				IMAGEMANAGER->findImage("Ÿ��1_06")->render(_test[140].left + CAMERA->getPosX(), _test[140].top + CAMERA->getPosY());
			}
			else if (i == 0 && j == 9)
			{
				//��������
				IMAGEMANAGER->findImage("Ÿ��1_03")->render(_test[9].left + CAMERA->getPosX(), _test[9].top + CAMERA->getPosY());
			}
			else if (i == 14 && j == 9)
			{
				//�����ʾƷ�
				IMAGEMANAGER->findImage("Ÿ��1_08")->render(_test[149].left + CAMERA->getPosX(), _test[149].top + CAMERA->getPosY());
			}
			else if (i == 0)
			{
				//��
				IMAGEMANAGER->findImage("Ÿ��1_02")->render(_test[i * 10 + j].left + CAMERA->getPosX(), _test[i * 10 + j].top + CAMERA->getPosY());
			}
			else if (i == 14)
			{
				//�Ʒ�
				IMAGEMANAGER->findImage("Ÿ��1_07")->render(_test[i * 10 + j].left + CAMERA->getPosX(), _test[i * 10 + j].top + CAMERA->getPosY());
			}
			else if (j == 0)
			{
				//��
				IMAGEMANAGER->findImage("Ÿ��1_04")->render(_test[i * 10 + j].left + CAMERA->getPosX(), _test[i * 10 + j].top + CAMERA->getPosY());
			}
			else if (j == 9)
			{
				//������
				IMAGEMANAGER->findImage("Ÿ��1_05")->render(_test[i * 10 + j].left + CAMERA->getPosX(), _test[i * 10 + j].top + CAMERA->getPosY());
			}
			else
			{
				//���
				IMAGEMANAGER->findImage("�����ӱ⺻")->render(_test[i * 10 + j].left + CAMERA->getPosX(), _test[i * 10 + j].top + CAMERA->getPosY());
			}
		}
	}
	*/

	IMAGEMANAGER->findImage("�⺻�ϴ�")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_bg.png", 960, 150);

	
}
