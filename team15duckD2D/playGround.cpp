#include "stdafx.h"
#include "playGround.h"

playGround::playGround()
{
}


playGround::~playGround()
{
}

HRESULT playGround::init()
{
	gameNode::init(true);
	
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

	IMAGEMANAGER->addFrameImage("playerM", L"image/player/playerM.png", 1500, 1500, 10, 10);
	IMAGEMANAGER->addFrameImage("playerF", L"image/player/playerF.png", 1500, 1500, 10, 10);

	IMAGEMANAGER->addFrameImage(TERRAIN_NAME1, L"image/tile/tile_01.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME2, L"image/tile/tile_02.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME3, L"image/tile/tile_03.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME4, L"image/tile/tile_04.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME5, L"image/tile/tile_05.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME6, L"image/tile/tile_06.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME7, L"image/tile/tile_07.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME8, L"image/tile/tile_08.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME9, L"image/tile/tile_09.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME10, L"image/tile/tile_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME1, L"image/object/object_1.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);

	SCENEMANAGER->addScene("ġ����", new chiyeongTestScene);
	SCENEMANAGER->addScene("�Ͽ���", new hayoungTestScene);
	SCENEMANAGER->addScene("mapToolScene", new mapToolScene);
	SCENEMANAGER->addScene("mapTestScene", new mapTestScene);

	if (MAPTOOLSCENE)
	{
		SCENEMANAGER->changeScene("mapToolScene");
	}
	else
	{
		SCENEMANAGER->changeScene("ġ����");
	}
	
	return S_OK;
}

void playGround::release()
{
	gameNode::release();
	
}

void playGround::update()
{
	gameNode::update();

	SCENEMANAGER->update();

}

void playGround::render()
{
	// Draw ���� - �� �ڵ尡 ������ D2D ��� X
	D2DMANAGER->beginDraw();
	//===========================================================================
	//				##		���⿡ �ڵ� �ۼ�(Start)			##



	SCENEMANAGER->render();




	//				##			���⿡ �ڵ� �ۼ�(End)			##
	//===========================================================================
	//				##ī�޶� ���� ���콺 ���� �ð����� ���	##===================
	WCHAR str[128];
	swprintf_s(str, L"cameraX : %.1f / %.1f", CAMERA->getPosX(), (float)CAMERA->getMaxX());
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 80);
	swprintf_s(str, L"cameraY : %.1f / %.1f", CAMERA->getPosY(), (float)CAMERA->getMaxY());
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 100);
	swprintf_s(str, L"mouseX : %.2f", _ptMouse.x);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 140);
	swprintf_s(str, L"mouseY : %.2f", _ptMouse.y);
	D2DMANAGER->drawText(str, CAMERA->getPosX(), CAMERA->getPosY() + 160);
	TIMEMANAGER->render();
	// Draw �� - �� �ڵ尡 ������ D2D ��� X
	D2DMANAGER->endDraw();
}