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

	uiframeMake(10, 15, 32, 630, 5);
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

	D2DMANAGER->fillRectangle(RGB(255, 0, 255), rc[10*15]);

	IMAGEMANAGER->findImage("�⺻�ϴ�")->render(_rc.left + CAMERA->getPosX(), _rc.top + CAMERA->getPosY());
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

	IMAGEMANAGER->addImage("�����ӱ⺻", L"image/Menu_Frames/Menu_Frames_common.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_01", L"image/Menu_Frames/Menu_Frames_Type1_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_02", L"image/Menu_Frames/Menu_Frames_Type1_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_03", L"image/Menu_Frames/Menu_Frames_Type1_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_04", L"image/Menu_Frames/Menu_Frames_Type1_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_05", L"image/Menu_Frames/Menu_Frames_Type1_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_06", L"image/Menu_Frames/Menu_Frames_Type1_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_07", L"image/Menu_Frames/Menu_Frames_Type1_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��1_08", L"image/Menu_Frames/Menu_Frames_Type1_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��2_01", L"image/Menu_Frames/Menu_Frames_Type2_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��2_02", L"image/Menu_Frames/Menu_Frames_Type2_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��2_03", L"image/Menu_Frames/Menu_Frames_Type2_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��2_04", L"image/Menu_Frames/Menu_Frames_Type2_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��2_05", L"image/Menu_Frames/Menu_Frames_Type2_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��2_06", L"image/Menu_Frames/Menu_Frames_Type2_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��2_07", L"image/Menu_Frames/Menu_Frames_Type2_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��2_08", L"image/Menu_Frames/Menu_Frames_Type2_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��3_01", L"image/Menu_Frames/Menu_Frames_Type3_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��3_02", L"image/Menu_Frames/Menu_Frames_Type3_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��3_03", L"image/Menu_Frames/Menu_Frames_Type3_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��3_04", L"image/Menu_Frames/Menu_Frames_Type3_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��3_05", L"image/Menu_Frames/Menu_Frames_Type3_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��3_06", L"image/Menu_Frames/Menu_Frames_Type3_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��3_07", L"image/Menu_Frames/Menu_Frames_Type3_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��3_08", L"image/Menu_Frames/Menu_Frames_Type3_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��4_01", L"image/Menu_Frames/Menu_Frames_Type4_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��4_02", L"image/Menu_Frames/Menu_Frames_Type4_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��4_03", L"image/Menu_Frames/Menu_Frames_Type4_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��4_04", L"image/Menu_Frames/Menu_Frames_Type4_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��4_05", L"image/Menu_Frames/Menu_Frames_Type4_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��4_06", L"image/Menu_Frames/Menu_Frames_Type4_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��4_07", L"image/Menu_Frames/Menu_Frames_Type4_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��4_08", L"image/Menu_Frames/Menu_Frames_Type4_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��5_01", L"image/Menu_Frames/Menu_Frames_Type5_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��5_02", L"image/Menu_Frames/Menu_Frames_Type5_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��5_03", L"image/Menu_Frames/Menu_Frames_Type5_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��5_04", L"image/Menu_Frames/Menu_Frames_Type5_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��5_05", L"image/Menu_Frames/Menu_Frames_Type5_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��5_06", L"image/Menu_Frames/Menu_Frames_Type5_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��5_07", L"image/Menu_Frames/Menu_Frames_Type5_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��5_08", L"image/Menu_Frames/Menu_Frames_Type5_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��6_01", L"image/Menu_Frames/Menu_Frames_Type6_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��6_02", L"image/Menu_Frames/Menu_Frames_Type6_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��6_03", L"image/Menu_Frames/Menu_Frames_Type6_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��6_04", L"image/Menu_Frames/Menu_Frames_Type6_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��6_05", L"image/Menu_Frames/Menu_Frames_Type6_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��6_06", L"image/Menu_Frames/Menu_Frames_Type6_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��6_07", L"image/Menu_Frames/Menu_Frames_Type6_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��6_08", L"image/Menu_Frames/Menu_Frames_Type6_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��7_01", L"image/Menu_Frames/Menu_Frames_Type7_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��7_02", L"image/Menu_Frames/Menu_Frames_Type7_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��7_03", L"image/Menu_Frames/Menu_Frames_Type7_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��7_04", L"image/Menu_Frames/Menu_Frames_Type7_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��7_05", L"image/Menu_Frames/Menu_Frames_Type7_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��7_06", L"image/Menu_Frames/Menu_Frames_Type7_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��7_07", L"image/Menu_Frames/Menu_Frames_Type7_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��7_08", L"image/Menu_Frames/Menu_Frames_Type7_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��8_01", L"image/Menu_Frames/Menu_Frames_Type8_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��8_02", L"image/Menu_Frames/Menu_Frames_Type8_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��8_03", L"image/Menu_Frames/Menu_Frames_Type8_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��8_04", L"image/Menu_Frames/Menu_Frames_Type8_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��8_05", L"image/Menu_Frames/Menu_Frames_Type8_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��8_06", L"image/Menu_Frames/Menu_Frames_Type8_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��8_07", L"image/Menu_Frames/Menu_Frames_Type8_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��8_08", L"image/Menu_Frames/Menu_Frames_Type8_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��9_01", L"image/Menu_Frames/Menu_Frames_Type9_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��9_02", L"image/Menu_Frames/Menu_Frames_Type9_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��9_03", L"image/Menu_Frames/Menu_Frames_Type9_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��9_04", L"image/Menu_Frames/Menu_Frames_Type9_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��9_05", L"image/Menu_Frames/Menu_Frames_Type9_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��9_06", L"image/Menu_Frames/Menu_Frames_Type9_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��9_07", L"image/Menu_Frames/Menu_Frames_Type9_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��9_08", L"image/Menu_Frames/Menu_Frames_Type9_08.png", 32, 32);

	IMAGEMANAGER->addImage("Ÿ��10_01", L"image/Menu_Frames/Menu_Frames_Type10_01.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��10_02", L"image/Menu_Frames/Menu_Frames_Type10_02.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��10_03", L"image/Menu_Frames/Menu_Frames_Type10_03.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��10_04", L"image/Menu_Frames/Menu_Frames_Type10_04.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��10_05", L"image/Menu_Frames/Menu_Frames_Type10_05.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��10_06", L"image/Menu_Frames/Menu_Frames_Type10_06.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��10_07", L"image/Menu_Frames/Menu_Frames_Type10_07.png", 32, 32);
	IMAGEMANAGER->addImage("Ÿ��10_08", L"image/Menu_Frames/Menu_Frames_Type10_08.png", 32, 32);
}
