#include "stdafx.h"
#include "loadingScene.h"
#include "tileNode.h"
#include "objectTool.h"
#include "soundFile.h"


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
	IMAGEMANAGER->addFrameImage("loadingBackGround", L"image/loadingBackGround.png", WINSIZEX * 4, WINSIZEY, 4, 1);
	IMAGEMANAGER->addImage("loadingBar", L"image/loadingBar.png", 3, 100);
	KEYANIMANAGER->addAnimationType("loading");
	//���������ֱ�
	int loading[4] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("loading", "loadingBackGround", "loadingBackGround", loading, 4, 14, true);
	_ani = KEYANIMANAGER->findAnimation("loading", "loadingBackGround");
	_ani->start();

	CreateThread
	(
		NULL,			//�������� ���ȼӼ�(�ڽ������찡 ������) �ڵ�� �ڽ����� �θ����� �����ľ�
		NULL,			//�������� ����ũ��(NULL�� �θ� ���ξ������ ����ũ��� ����)
		ThreadFunction,	//������ �Լ� ��
		this,			//�������� �Ű����� (this�� �ϸ� �� Ŭ����)
		NULL,			//�������� Ư��(NULL�� �θ� �ٷ� ������)
		0				//�������� ���� �� �������� ID�� �Ѱ��ش� ������ NULL�� ��.
	);
	//ThreadFunction(this);
	return S_OK;
}

void loadingScene::release()
{
}

void loadingScene::update()
{
	//��������������
	_loadingBar = (float)_currentCount / (float)LOADINGMAX;
	KEYANIMANAGER->update("loading");

	//�ٷε��ϸ� ���ٲ�
	if (_currentCount == LOADINGMAX) 
	{
		if (MAPTOOLSCENE)
		{
			SCENEMANAGER->changeScene("mapToolScene");
		}
		else
		{
			SCENEMANAGER->changeScene("startScene");
		}
	}

}

void loadingScene::render()
{
	//��׶���
	IMAGEMANAGER->findImage("loadingBackGround")->aniRender(0, 0, _ani);
	//�ε���
	IMAGEMANAGER->findImage("loadingBar")->render(0, 580, 960 * _loadingBar, 100);
}



DWORD CALLBACK ThreadFunction(LPVOID lpParameter)
{
	loadingScene* loadHelper = (loadingScene*)lpParameter;

	//���� ���ҽ� �߰��ع����� loadHelper->_currentCount++; �̰�����ߵ� �׷��� ������ ������
	SOUNDMANAGER->addSound("�׽�Ʈ��", "sound/bgm_01_Game_Freak_Logo.mp3", true, true);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("startSceneBgm", _vBgmString[1], true, false);																											loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("startBattleBgm", _vBgmString[2], true, false);																											loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("titleBgm", _vBgmString[3], true, false);																											loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("townBGM", "sound/bgm_11_City_Theme_Pallet_Town.mp3", true, true);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("storeBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("oLabBGM", "sound/bgm_07_Professor_Oaks_Laboratory.mp3", true, true);																					loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("homeBGM", "sound/bgm_11_City_Theme_Pallet_Town.mp3", true, true);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("gymBGM", "sound/bgm_14_Pokemon_Gym.mp3", true, true);																									loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("fieldBGM", "sound/bgm_10_Road_to_Viridian_City.mp3", true, true);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("caveBGM", "sound/bgm_15_Caves_of_Mt_Moon.mp3", true, true);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SOUNDMANAGER->addSound("centerBGM", "sound/bgm_13_Pokemon_Center.mp3", true, true);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("�����ӱ⺻", L"image/Menu_Frames/Menu_Frames_common.png", 32, 32);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��1_01", L"image/Menu_Frames/Menu_Frames_Type1_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��1_02", L"image/Menu_Frames/Menu_Frames_Type1_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��1_03", L"image/Menu_Frames/Menu_Frames_Type1_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��1_04", L"image/Menu_Frames/Menu_Frames_Type1_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��1_05", L"image/Menu_Frames/Menu_Frames_Type1_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��1_06", L"image/Menu_Frames/Menu_Frames_Type1_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��1_07", L"image/Menu_Frames/Menu_Frames_Type1_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��1_08", L"image/Menu_Frames/Menu_Frames_Type1_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��2_01", L"image/Menu_Frames/Menu_Frames_Type2_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��2_02", L"image/Menu_Frames/Menu_Frames_Type2_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��2_03", L"image/Menu_Frames/Menu_Frames_Type2_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��2_04", L"image/Menu_Frames/Menu_Frames_Type2_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��2_05", L"image/Menu_Frames/Menu_Frames_Type2_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��2_06", L"image/Menu_Frames/Menu_Frames_Type2_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��2_07", L"image/Menu_Frames/Menu_Frames_Type2_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��2_08", L"image/Menu_Frames/Menu_Frames_Type2_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��3_01", L"image/Menu_Frames/Menu_Frames_Type3_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��3_02", L"image/Menu_Frames/Menu_Frames_Type3_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��3_03", L"image/Menu_Frames/Menu_Frames_Type3_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��3_04", L"image/Menu_Frames/Menu_Frames_Type3_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��3_05", L"image/Menu_Frames/Menu_Frames_Type3_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��3_06", L"image/Menu_Frames/Menu_Frames_Type3_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��3_07", L"image/Menu_Frames/Menu_Frames_Type3_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��3_08", L"image/Menu_Frames/Menu_Frames_Type3_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��4_01", L"image/Menu_Frames/Menu_Frames_Type4_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��4_02", L"image/Menu_Frames/Menu_Frames_Type4_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��4_03", L"image/Menu_Frames/Menu_Frames_Type4_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��4_04", L"image/Menu_Frames/Menu_Frames_Type4_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��4_05", L"image/Menu_Frames/Menu_Frames_Type4_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��4_06", L"image/Menu_Frames/Menu_Frames_Type4_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��4_07", L"image/Menu_Frames/Menu_Frames_Type4_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��4_08", L"image/Menu_Frames/Menu_Frames_Type4_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��5_01", L"image/Menu_Frames/Menu_Frames_Type5_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��5_02", L"image/Menu_Frames/Menu_Frames_Type5_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��5_03", L"image/Menu_Frames/Menu_Frames_Type5_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��5_04", L"image/Menu_Frames/Menu_Frames_Type5_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��5_05", L"image/Menu_Frames/Menu_Frames_Type5_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��5_06", L"image/Menu_Frames/Menu_Frames_Type5_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��5_07", L"image/Menu_Frames/Menu_Frames_Type5_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��5_08", L"image/Menu_Frames/Menu_Frames_Type5_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��6_01", L"image/Menu_Frames/Menu_Frames_Type6_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��6_02", L"image/Menu_Frames/Menu_Frames_Type6_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��6_03", L"image/Menu_Frames/Menu_Frames_Type6_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��6_04", L"image/Menu_Frames/Menu_Frames_Type6_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��6_05", L"image/Menu_Frames/Menu_Frames_Type6_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��6_06", L"image/Menu_Frames/Menu_Frames_Type6_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��6_07", L"image/Menu_Frames/Menu_Frames_Type6_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��6_08", L"image/Menu_Frames/Menu_Frames_Type6_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��7_01", L"image/Menu_Frames/Menu_Frames_Type7_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��7_02", L"image/Menu_Frames/Menu_Frames_Type7_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��7_03", L"image/Menu_Frames/Menu_Frames_Type7_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��7_04", L"image/Menu_Frames/Menu_Frames_Type7_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��7_05", L"image/Menu_Frames/Menu_Frames_Type7_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��7_06", L"image/Menu_Frames/Menu_Frames_Type7_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��7_07", L"image/Menu_Frames/Menu_Frames_Type7_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��7_08", L"image/Menu_Frames/Menu_Frames_Type7_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��8_01", L"image/Menu_Frames/Menu_Frames_Type8_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��8_02", L"image/Menu_Frames/Menu_Frames_Type8_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��8_03", L"image/Menu_Frames/Menu_Frames_Type8_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��8_04", L"image/Menu_Frames/Menu_Frames_Type8_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��8_05", L"image/Menu_Frames/Menu_Frames_Type8_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��8_06", L"image/Menu_Frames/Menu_Frames_Type8_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��8_07", L"image/Menu_Frames/Menu_Frames_Type8_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��8_08", L"image/Menu_Frames/Menu_Frames_Type8_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��9_01", L"image/Menu_Frames/Menu_Frames_Type9_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��9_02", L"image/Menu_Frames/Menu_Frames_Type9_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��9_03", L"image/Menu_Frames/Menu_Frames_Type9_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��9_04", L"image/Menu_Frames/Menu_Frames_Type9_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��9_05", L"image/Menu_Frames/Menu_Frames_Type9_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��9_06", L"image/Menu_Frames/Menu_Frames_Type9_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��9_07", L"image/Menu_Frames/Menu_Frames_Type9_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��9_08", L"image/Menu_Frames/Menu_Frames_Type9_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��10_01", L"image/Menu_Frames/Menu_Frames_Type10_01.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��10_02", L"image/Menu_Frames/Menu_Frames_Type10_02.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��10_03", L"image/Menu_Frames/Menu_Frames_Type10_03.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��10_04", L"image/Menu_Frames/Menu_Frames_Type10_04.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��10_05", L"image/Menu_Frames/Menu_Frames_Type10_05.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��10_06", L"image/Menu_Frames/Menu_Frames_Type10_06.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��10_07", L"image/Menu_Frames/Menu_Frames_Type10_07.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("Ÿ��10_08", L"image/Menu_Frames/Menu_Frames_Type10_08.png", 32, 32);																					  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("playerM", L"image/player/playerM.png", 1500, 1500, 10, 10);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("playerF", L"image/player/playerF.png", 1500, 1500, 10, 10);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("shadow", L"image/player/shadow.png", 64, 32);																											loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME1], L"image/tile/tile_01.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME2], L"image/tile/tile_02.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME3], L"image/tile/tile_03.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME4], L"image/tile/tile_04.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME5], L"image/tile/tile_05.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME6], L"image/tile/tile_06.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME7], L"image/tile/tile_07.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME8], L"image/tile/tile_08.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME9], L"image/tile/tile_09.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME10], L"image/tile/tile_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME11], L"image/tile/tile_11.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME1], L"image/object/object_1.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME2], L"image/object/object_2.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME3], L"image/object/object_3.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME4], L"image/object/object_4.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME5], L"image/object/object_5.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME6], L"image/object/object_6.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME7], L"image/object/object_7.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME8], L"image/object/object_8.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME9], L"image/object/object_9.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME10], L"image/object/object_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME11], L"image/object/myHouse.png", 320, 320, 5, 5);																			loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME12], L"image/object/oakHouse.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME13], L"image/object/pokemonCenter.png", 320, 320, 5, 5);																		loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME14], L"image/object/pokemonShop.png", 256, 256, 4, 4);																		loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME15], L"image/object/gym.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);													loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME16], L"image/object/openTheDoor.png", 320, 256, 5, 4);																		loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME17], L"image/object/etc.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);													loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("items", L"image/items.png", 3900, 100, 39, 1); 																									loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("pokemon_ingame", L"image/pokemon/pokemon.png", 5120, 4096, 20, 16);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("shopOwner", L"image/shopOwner.png", 240, 80, 4, 1);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("nurse", L"image/nurse.png", 272, 80, 4, 1);																										loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("battleBackground", L"image/BattleBackgrounds.png", 2880, 1792, 3, 4);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("�⺻�ϴ�", L"image/common_menu/common_menu_bg.png", 960, 160);																							 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("ȭ��ǥ", L"image/common_menu/pokemonMenu_cursor.png", 24, 40);																							  loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("�⺻���", L"image/common_menu/common_menu_top.png", 960, 64);																							 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("����", L"image/common_menu/pokemonbook/cm_pokemon_book.png", 1920, 640, 2, 1);																	  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("���ϸ�Ӽ�", L"image/Summary Menu/summary_pokemon_tage.png", 1152, 96, 9, 2);																		loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("�������ϸ�", L"image/common_menu/pokemon/pokemonMenu_slot_first.png", 336, 912, 1, 4);																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("���������ϸ�", L"image/common_menu/pokemon/pokemonMenu_background.png", 960, 640);																	   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("�������ϸ�1", L"image/common_menu/pokemon/pokemon_subpokemon_list.png", 500, 80);																		loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("�������ϸ�2", L"image/common_menu/pokemon/pokemonMenu_slot.png", 2000, 80, 4, 1);																	loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("���ϸ�޴�_���", L"image/common_menu/pokemon/pokemonMenu_btn_cancle.png", 216, 192, 1, 2);														  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("���Ӹ����", L"image/Summary Menu/summary_top_bar.png", 960, 192, 1, 3);																			loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("���Ӹ����", L"image/Summary Menu/summary_base.png", 960, 640);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("���Ӹ�������", L"image/Summary Menu/summary_pokemon_info.png", 1920, 576, 2, 1);																	   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("���Ӹ����ϸ�", L"image/Summary Menu/summary_pokemon_base.png", 484, 336);																				   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("���Ӹ���ų", L"image/Summary Menu/summary_pokemon_skill.png", 484, 576);																					loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("ü�º��̽�", L"image/battle_UI/battle_UI_HP_base.png", 36, 12);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("ü�°�����", L"image/pokemonMenu_gauge.png", 192, 12, 3, 1);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("����޴����", L"image/common_menu/bag/bag_background.png", 1920, 640, 2, 1);																	   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("Ʈ���̳�ī��", L"image/common_menu/player/trainerCard.png", 1920, 640, 2, 1);																	   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("���ϸ��Ĵ�", L"image/pokemon/pokemon_mini.png", 2304, 2176, 18, 17);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("���ϸ��Ĵ�2", L"image/pokemon/pokemon_mini_start.png", 2304 / 2, 2176 / 2, 18, 17);																	loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("���θ޴�", 670, 1, 9, 15);																																 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("money_Frame", 5, 5, 10, 5);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("shop_Frame", 320, 5, 20, 14);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("number_Frame", 480, 260, 15, 6);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("choice_Frame", 650, 260, 8, 6);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("����������1", 80, 64, 25, 4);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("����������2", 0, 192, 30, 14);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("��������", 0, 0, 14, 6);																																	 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("����޴�", 0, 190, 12, 14);																																 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("üũ�ڽ�", 750, 280, 6, 5);																																 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("Ȯ��â", 200, 200, 6, 5);																																  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("���ϸ�������1", 0, 512, 23, 4);																														   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("���Ӹ��޴�", 635, 380, 10, 8);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("���Ӹ�����", 0, 512, 20, 4);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("�����ۻ��", 700, 300, 8, 10);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("��������", L"image/common_menu/bag/item_bag.png", 472, 257, 2, 1);																					 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("pokemonInfoImg", L"image/startSceneImg/startImage01.png", 960, 640);																					loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("starBackground", L"image/startSceneImg/startImage02.png", 960, 640);																					loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("star", L"image/startSceneImg/Star.png", 608, 76, 8, 1);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("gameFreak", L"image/startSceneImg/gameFreak.png", 576, 76);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("gameFreakLogo", L"image/startSceneImg/gameFreakLogo.png", 96, 224);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("presents", L"image/startSceneImg/presents.png", 266, 32);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("pokemon", L"image/pokemon/pokemon_mini_start.png", 1152, 1088, 18, 17);																			loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("gameFreak", L"image/pokemon/gameFreak.png", 576, 76);																									loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("gameFreakLogo", L"image/pokemon/gameFreakLogo.png", 96, 224);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("presents", L"image/pokemon/presents.png", 266, 32);																										loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("background", L"image/startSceneImg/startImage03.png", 960, 640);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("introForest", L"image/startSceneImg/grassFrame.png", 2880, 640, 3, 1);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("meeting", L"image/startSceneImg/startImage04.png", 960, 640);																							 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("battleBackground2nd", L"image/startSceneImg/startImage05.png", 960, 640);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("startBattleGrass", L"image/startSceneImg/startBattleGrass.png", 960, 640);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("phantom1", L"image/startSceneImg/Phantom1.png", 380, 380);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("nidrun1", L"image/startSceneImg/nidrun1.png", 380, 380);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("phantom2", L"image/startSceneImg/Phantom2.png", 380, 380);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("nidrun2", L"image/startSceneImg/nidrun2.png", 440, 404);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("phantomIdle", L"image/startSceneImg/PhantomFrame.png", 1520, 380, 4, 1);																			loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("nidrunFrame", L"image/startSceneImg/nidrunFrame.png", 1350, 270, 5, 1);																			loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("attack", L"image/startSceneImg/attackEffect.png", 88, 304);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("grass", L"image/startSceneImg/zOderGrass.png", 240, 104);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("startLogoBackground", L"image/startLogoBackground.png", 960, 640);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("Charizard", L"image/Charizard.png", 1332, 396, 3, 1);																							   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("pokemonLogo", L"image/logo.png", 3984, 224, 6, 1);																									loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("fireRed", L"image/firered.png", 284, 152);																												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("c2004_game_freak", L"image/startSceneImg/c2004_game_freak.png", 592, 28);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("press_start", L"image/startSceneImg/press_start.png", 356, 28);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	EFFECTMANAGER->addEffect("grassEffect", "image/player/grassSprite.png", 256, 56, 64, 56, 7, 0.01, 20);																			loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	EFFECTMANAGER->addEffect("footLeft", "image/player/footLeft.png", 256, 64, 64, 64, 7, 0.01, 20);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	EFFECTMANAGER->addEffect("footUp", "image/player/footUp.png", 256, 64, 64, 64, 7, 0.01, 20);																					loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	EFFECTMANAGER->addEffect("footRight", "image/player/footRight.png", 256, 64, 64, 64, 7, 0.01, 20);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	EFFECTMANAGER->addEffect("footDown", "image/player/footDown.png", 256, 64, 64, 64, 7, 0.01, 20);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("healingBall", L"image/object/healing_Pokemon.png", 120, 24, 5, 1); //ȸ���Ҷ� ���̴� ���ϸ��̹���													 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("oak", L"image/oak.png", 720, 85, 12, 1);																											loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("boss", L"image/boss.png", 576, 80, 9, 1);																											loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("��������", 0, 0, 30, 20);																																 loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("����", 300, 150, 10, 5);																																  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("����", 300, 350, 10, 5);																																  loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("newGameArrow", L"image/player/arrow.png", 24, 40);																										loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("newGameNaming", L"image/player/naming.png", 960, 640);																									loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("choiceFrame_shop", 35, 5, 10, 8);																														loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("choiceFrame", 960 - 290, 640 - 370, 8, 5);																												loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("battleScript", L"image/battle_UI/battle_UI_Main_chat_board.png", 960, 192);																				loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("battleMenu", 480, 448, 15, 6);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("skillPPFrame", 480, 448, 15, 6);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("skillFrame", 0, 448, 15, 6);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("playerUI", L"image/battle_UI/battle_UI_Player.png", 416, 148);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("enemyUI", L"image/battle_UI/battle_UI_enemy.png", 400, 116);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("battleCheckPoint", L"image/battle_UI/battle_UI_chk_point.png", 24, 40);																					loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("hpBar01", L"image/battle_UI/battle_UI_HP_01.png", 36, 12);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("hpBar02", L"image/battle_UI/battle_UI_HP_02.png", 36, 12);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("hpBar03", L"image/battle_UI/battle_UI_HP_03.png", 36, 12);																								loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("hpBarBase", L"image/battle_UI/battle_UI_HP_base.png", 36, 12);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("expBar", L"image/battle_UI/battle_UI_experience_02.png", 28, 8);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("���ϸ�������1", 0, 512, 23, 4);																														   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("���Ӹ��޴�2", 635, 444, 10, 6);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("���Ӹ�����", 0, 512, 20, 4);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("���Ӹ����", L"image/Summary Menu/summary_top_bar.png", 960, 192, 1, 3);																			loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("���Ӹ����", L"image/Summary Menu/summary_base.png", 960, 640);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("���Ӹ�������", L"image/Summary Menu/summary_pokemon_info.png", 1920, 576, 2, 1);																	   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("���Ӹ����ϸ�", L"image/Summary Menu/summary_pokemon_base.png", 484, 336);																				   loadHelper->_currentCount++;		Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("���Ӹ���ų", L"image/Summary Menu/summary_pokemon_skill.png", 484, 576);																					loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("ü�º��̽�", L"image/battle_UI/battle_UI_HP_base.png", 36, 12);																							loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("ü�°�����", L"image/pokemonMenu_gauge.png", 192, 12, 3, 1);																						loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("�����ۻ��2", 700, 460, 8, 5);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addFrameImage("��������", L"image/common_menu/bag/item_bag.png", 472, 257, 2, 1);																					 loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	MENUMANAGER->addFrame("���Ӹ��޴�3", 635, 444, 10, 6);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	IMAGEMANAGER->addImage("boss_battle", L"image/boss_battle.png", 230, 260);																										loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("ġ����", new chiyeongTestScene);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);						
	SCENEMANAGER->addScene("�Ͽ���", new hayoungTestScene);																														  loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("mapToolScene", new mapToolScene);																														loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("mapTestScene", new mapTestScene);																														loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("objectToolScene", new objectToolScene);																													loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("startScene", new startScene);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("battleScene", new battleScene);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("battleScene2", new battleScene2);																														loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("caveScene", new caveScene);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("centerScene", new centerScene);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("fieldScene", new fieldScene);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("gymScene", new gymScene);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("homeScene", new homeScene);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("oLabScene", new oLabScene);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("storeScene", new storeScene);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("townScene", new townScene);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("loadScene", new loadScene);																																loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("newGameScene", new newGameScene);																														loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	SCENEMANAGER->addScene("endingScene", new endingScene);																															loadHelper->_currentCount++;	Sleep(SLEEPCOUNT);
	PLAYERDATA->init(); loadHelper->_currentCount++;																																								Sleep(SLEEPCOUNT);


	return 0;
}
