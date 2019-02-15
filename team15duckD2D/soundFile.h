#pragma once
#include "stdafx.h"
enum SOUND_FILE_NAME
{
	BGM_NONE,
	BGM_01_GAME_FREAK_LOGO,						//���� ������ �� ������ ����(�� �Ϸη�)
	BGM_02_OPENING_MOVIE,						//�� ���� �� �θ��� ��Ʋ ���󿡼� ������ ����
	BGM_03_TITLE_SCREEN,						//���ڸ��� ������ Ÿ��Ʋ ������ ������ ����
	//BGM_04_GAME_TUTORIAL,
	BGM_05_WELCOME_TO_THE_WORLD_OF_POKEMON,		//���ڻ� ������ �� ����(�̸����Ҷ��� �������̿���
												//���� ���ϸ� ����� �������ھ� �ϸ鼭 ������ ȿ����(���� ����)(����...)

	bgm_07_Professor_Oaks_Laboratory,			//���ڻ� �����ǿ��� ������ ����
	bgm_11_City_Theme_Pallet_Town,				//��, ���ʸ������� ����������
	effect_51_Enter_building,					//�ǿܿ��� �ǳ��� ���� ������ ȿ����
	effect_53_Exit_building,					//�ǳ����� ������ ���ö� ȿ����

	//BGM_06_PROFESSOR_OAK,
	

	BGM_END


};

static string _vBgmString[BGM_END] = 
{
	"sound/none",
	"sound/bgm_01_Game_Freak_Logo",
	"sound/bgm_02_Opening_Movie",
	"sound/bgm_03_Title_Screen",
	"sound/bgm_05_Welcome_to_the_World_of_Pokemon",
	"sound/bgm_07_Professor_Oaks_Laboratory",
	"sound/bgm_11_City_Theme_Pallet_Town",
	"sound/effect_51_Enter_building",
	"sound/effect_53_Exit_building"






};





