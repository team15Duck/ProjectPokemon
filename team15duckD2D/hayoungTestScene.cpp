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
	_rc = { 0, 490, 960, 640 };

	for (int i = 0; i < 15; ++i)
	{
		for (int j = 0; j < 10; j++)
		{
			float left = 630 + (j * 32);
			float top = 5 + (i * 32);
			float right = left + 32;
			float bottom = top + 32;
			_test[i * 10 + j] = { left, top, right, bottom };
		}
	}

	
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
	//D2DMANAGER->fillRectangle(RGB(255, 0, 255), _rc);
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
				IMAGEMANAGER->findImage("Ÿ��1_06")->render(_test[140].left, _test[140].top);
			}
			else if (i == 0 && j == 9)
			{
				//��������
				IMAGEMANAGER->findImage("Ÿ��1_03")->render(_test[9].left, _test[9].top);
			}
			else if (i == 14 && j == 9)
			{
				//�����ʾƷ�
				IMAGEMANAGER->findImage("Ÿ��1_08")->render(_test[149].left, _test[149].top);
			}
			else if (i == 0)
			{
				//��
				IMAGEMANAGER->findImage("Ÿ��1_02")->render(_test[i * 10 + j].left, _test[i * 10 + j].top);
			}
			else if (i == 14)
			{
				//�Ʒ�
				//IMAGEMANAGER->findImage("Ÿ��1_04")->render(_test[i * 10 + j].left, _test[i * 10 + j].top);
			}
			else if (j == 0)
			{
				//��
				IMAGEMANAGER->findImage("Ÿ��1_04")->render(_test[i * 10 + j].left, _test[i * 10 + j].top);
			}
			else if (j == 9)
			{
				//������
			}
			else
			{
				//���
			}
		}
	}

	IMAGEMANAGER->findImage("�⺻�ϴ�")->render(_rc.left, _rc.top);
}

void hayoungTestScene::frameImageinit()
{
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_bg.png", 960, 150);

	IMAGEMANAGER->addImage("Ÿ��1_01", L"image/Menu_Frames/Menu_Frames_Type1_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_02", L"image/Menu_Frames/Menu_Frames_Type1_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_03", L"image/Menu_Frames/Menu_Frames_Type1_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_04", L"image/Menu_Frames/Menu_Frames_Type1_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_05", L"image/Menu_Frames/Menu_Frames_Type1_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_06", L"image/Menu_Frames/Menu_Frames_Type1_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_07", L"image/Menu_Frames/Menu_Frames_Type1_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_08", L"image/Menu_Frames/Menu_Frames_Type1_08.png", 32, 32);
}
