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
	//frameImageinit();
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

	MENUMANAGER->addFrame("��ü�޴�������", 0, 0, 30, 20);

	
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

	//D2DMANAGER->fillRectangle(RGB(255, 0, 255), rc[10*15]);
	//
	//IMAGEMANAGER->findImage("�⺻�ϴ�")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());
}


D2D1_RECT_F hayoungTestScene::uiframeMake(int width, int height, float size, float positionX, float positionY)
{
	D2D1_RECT_F* rc = new D2D1_RECT_F[width * height];

	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; j++)
		{
			float left = positionX + (j * size);
			float top = positionY + (i * size);
			float right = left + size;
			float bottom = top + size;

			rc[i * width + j] = { left, top, right, bottom };
		}
	}
	return rc[width * height];
}

void hayoungTestScene::uiframeRender(int width, int height, float left, float top)
{
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			if (i == 0 && j == 0)
			{
				//���� ��
			}
			else if (i == 0 && j == width)
			{
				//������ ��
			}
			else if (i == height && j == 0)
			{
				//���� �Ʒ�
			}
			else if (i == height && j == width)
			{
				//�����ʾƷ�
			}
			else if (i == 0)
			{
				//��
			}
			else if (i == height)
			{
				//�Ʒ�
			}
			else if (j == 0)
			{
				//����
			}
			else if (j == width)
			{
				//������
			}
			else
			{
				//������
			}
		}
	}
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_bg.png", 960, 150);

	
}
