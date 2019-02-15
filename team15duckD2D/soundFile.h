#pragma once
#include "stdafx.h"
enum SOUND_FILE_NAME
{
	BGM_NONE,
	BGM_01_GAME_FREAK_LOGO,						//게임 시작할 때 나오는 음악(별 뾰로롱)
	BGM_02_OPENING_MOVIE,						//별 끝난 후 두마리 배틀 영상에서 나오는 음악
	BGM_03_TITLE_SCREEN,						//리자몽이 등장한 타이틀 씬에서 나오는 음악
	//BGM_04_GAME_TUTORIAL,
	BGM_05_WELCOME_TO_THE_WORLD_OF_POKEMON,		//오박사 나오는 씬 음악(이름정할때도 이음악이에영
												//이제 포켓몬 월드로 떠나보자아 하면서 나오는 효과음(루프 ㄴㄴ)(읎네...)

	bgm_07_Professor_Oaks_Laboratory,			//오박사 연구실에서 나오는 음악
	bgm_11_City_Theme_Pallet_Town,				//집, 태초마을에서 나오는음악
	effect_51_Enter_building,					//실외에서 실내로 들어갈때 나오는 효과음
	effect_53_Exit_building,					//실내에서 밖으로 나올때 효과음

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





