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
	
	//테스트용 음악추가
	
	SCENEMANAGER->addScene("loadingScene", new loadingScene);


	SCENEMANAGER->changeScene("loadingScene");
	

	//SOUNDMANAGER->addSound("테스트용", "sound/bgm_01_Game_Freak_Logo.mp3", true, true);
	//
	//IMAGEMANAGER->addImage("프레임기본", L"image/Menu_Frames/Menu_Frames_common.png", 32, 32);
	//IMAGEMANAGER->addImage("타입1_01", L"image/Menu_Frames/Menu_Frames_Type1_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입1_02", L"image/Menu_Frames/Menu_Frames_Type1_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입1_03", L"image/Menu_Frames/Menu_Frames_Type1_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입1_04", L"image/Menu_Frames/Menu_Frames_Type1_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입1_05", L"image/Menu_Frames/Menu_Frames_Type1_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입1_06", L"image/Menu_Frames/Menu_Frames_Type1_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입1_07", L"image/Menu_Frames/Menu_Frames_Type1_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입1_08", L"image/Menu_Frames/Menu_Frames_Type1_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입2_01", L"image/Menu_Frames/Menu_Frames_Type2_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입2_02", L"image/Menu_Frames/Menu_Frames_Type2_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입2_03", L"image/Menu_Frames/Menu_Frames_Type2_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입2_04", L"image/Menu_Frames/Menu_Frames_Type2_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입2_05", L"image/Menu_Frames/Menu_Frames_Type2_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입2_06", L"image/Menu_Frames/Menu_Frames_Type2_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입2_07", L"image/Menu_Frames/Menu_Frames_Type2_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입2_08", L"image/Menu_Frames/Menu_Frames_Type2_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입3_01", L"image/Menu_Frames/Menu_Frames_Type3_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입3_02", L"image/Menu_Frames/Menu_Frames_Type3_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입3_03", L"image/Menu_Frames/Menu_Frames_Type3_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입3_04", L"image/Menu_Frames/Menu_Frames_Type3_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입3_05", L"image/Menu_Frames/Menu_Frames_Type3_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입3_06", L"image/Menu_Frames/Menu_Frames_Type3_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입3_07", L"image/Menu_Frames/Menu_Frames_Type3_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입3_08", L"image/Menu_Frames/Menu_Frames_Type3_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입4_01", L"image/Menu_Frames/Menu_Frames_Type4_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입4_02", L"image/Menu_Frames/Menu_Frames_Type4_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입4_03", L"image/Menu_Frames/Menu_Frames_Type4_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입4_04", L"image/Menu_Frames/Menu_Frames_Type4_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입4_05", L"image/Menu_Frames/Menu_Frames_Type4_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입4_06", L"image/Menu_Frames/Menu_Frames_Type4_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입4_07", L"image/Menu_Frames/Menu_Frames_Type4_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입4_08", L"image/Menu_Frames/Menu_Frames_Type4_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입5_01", L"image/Menu_Frames/Menu_Frames_Type5_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입5_02", L"image/Menu_Frames/Menu_Frames_Type5_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입5_03", L"image/Menu_Frames/Menu_Frames_Type5_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입5_04", L"image/Menu_Frames/Menu_Frames_Type5_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입5_05", L"image/Menu_Frames/Menu_Frames_Type5_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입5_06", L"image/Menu_Frames/Menu_Frames_Type5_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입5_07", L"image/Menu_Frames/Menu_Frames_Type5_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입5_08", L"image/Menu_Frames/Menu_Frames_Type5_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입6_01", L"image/Menu_Frames/Menu_Frames_Type6_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입6_02", L"image/Menu_Frames/Menu_Frames_Type6_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입6_03", L"image/Menu_Frames/Menu_Frames_Type6_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입6_04", L"image/Menu_Frames/Menu_Frames_Type6_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입6_05", L"image/Menu_Frames/Menu_Frames_Type6_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입6_06", L"image/Menu_Frames/Menu_Frames_Type6_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입6_07", L"image/Menu_Frames/Menu_Frames_Type6_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입6_08", L"image/Menu_Frames/Menu_Frames_Type6_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입7_01", L"image/Menu_Frames/Menu_Frames_Type7_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입7_02", L"image/Menu_Frames/Menu_Frames_Type7_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입7_03", L"image/Menu_Frames/Menu_Frames_Type7_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입7_04", L"image/Menu_Frames/Menu_Frames_Type7_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입7_05", L"image/Menu_Frames/Menu_Frames_Type7_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입7_06", L"image/Menu_Frames/Menu_Frames_Type7_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입7_07", L"image/Menu_Frames/Menu_Frames_Type7_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입7_08", L"image/Menu_Frames/Menu_Frames_Type7_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입8_01", L"image/Menu_Frames/Menu_Frames_Type8_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입8_02", L"image/Menu_Frames/Menu_Frames_Type8_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입8_03", L"image/Menu_Frames/Menu_Frames_Type8_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입8_04", L"image/Menu_Frames/Menu_Frames_Type8_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입8_05", L"image/Menu_Frames/Menu_Frames_Type8_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입8_06", L"image/Menu_Frames/Menu_Frames_Type8_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입8_07", L"image/Menu_Frames/Menu_Frames_Type8_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입8_08", L"image/Menu_Frames/Menu_Frames_Type8_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입9_01", L"image/Menu_Frames/Menu_Frames_Type9_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입9_02", L"image/Menu_Frames/Menu_Frames_Type9_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입9_03", L"image/Menu_Frames/Menu_Frames_Type9_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입9_04", L"image/Menu_Frames/Menu_Frames_Type9_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입9_05", L"image/Menu_Frames/Menu_Frames_Type9_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입9_06", L"image/Menu_Frames/Menu_Frames_Type9_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입9_07", L"image/Menu_Frames/Menu_Frames_Type9_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입9_08", L"image/Menu_Frames/Menu_Frames_Type9_08.png", 32, 32);
	//
	//IMAGEMANAGER->addImage("타입10_01", L"image/Menu_Frames/Menu_Frames_Type10_01.png", 32, 32);
	//IMAGEMANAGER->addImage("타입10_02", L"image/Menu_Frames/Menu_Frames_Type10_02.png", 32, 32);
	//IMAGEMANAGER->addImage("타입10_03", L"image/Menu_Frames/Menu_Frames_Type10_03.png", 32, 32);
	//IMAGEMANAGER->addImage("타입10_04", L"image/Menu_Frames/Menu_Frames_Type10_04.png", 32, 32);
	//IMAGEMANAGER->addImage("타입10_05", L"image/Menu_Frames/Menu_Frames_Type10_05.png", 32, 32);
	//IMAGEMANAGER->addImage("타입10_06", L"image/Menu_Frames/Menu_Frames_Type10_06.png", 32, 32);
	//IMAGEMANAGER->addImage("타입10_07", L"image/Menu_Frames/Menu_Frames_Type10_07.png", 32, 32);
	//IMAGEMANAGER->addImage("타입10_08", L"image/Menu_Frames/Menu_Frames_Type10_08.png", 32, 32);
	//
	//IMAGEMANAGER->addFrameImage("playerM", L"image/player/playerM.png", 1500, 1500, 10, 10);
	//IMAGEMANAGER->addFrameImage("playerF", L"image/player/playerF.png", 1500, 1500, 10, 10);
	//IMAGEMANAGER->addImage("shadow", L"image/player/shadow.png", 64, 32);
	//
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME1 ], L"image/tile/tile_01.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME2 ], L"image/tile/tile_02.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME3 ], L"image/tile/tile_03.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME4 ], L"image/tile/tile_04.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME5 ], L"image/tile/tile_05.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME6 ], L"image/tile/tile_06.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME7 ], L"image/tile/tile_07.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME8 ], L"image/tile/tile_08.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME9 ], L"image/tile/tile_09.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME10], L"image/tile/tile_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(TERRAIN_NAME[TERRAIN_NAME11], L"image/tile/tile_11.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	////IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME1], L"image/object/object_1.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME1 ], L"image/object/object_1.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME2 ], L"image/object/object_2.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME3 ], L"image/object/object_3.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME4 ], L"image/object/object_4.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME5 ], L"image/object/object_5.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME6 ], L"image/object/object_6.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME7 ], L"image/object/object_7.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME8 ], L"image/object/object_8.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME9 ], L"image/object/object_9.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME10], L"image/object/object_10.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME11], L"image/object/myHouse.png", 320, 320, 5, 5);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME12], L"image/object/oakHouse.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME13], L"image/object/pokemonCenter.png", 320, 320, 5, 5);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME14], L"image/object/pokemonShop.png", 256, 256, 4, 4);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME15], L"image/object/gym.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME16], L"image/object/openTheDoor.png", 320, 256, 5, 4);
	//IMAGEMANAGER->addFrameImage(OBJECT_NAME[OBJECT_NAME17], L"image/object/etc.png", SAMPLE_TOTAL_SIZE, SAMPLE_TOTAL_SIZE, 6, 6);
	//
	//// 아이템이미지
	//IMAGEMANAGER->addFrameImage("items", L"image/items.png", 3900, 100, 39, 1);
	//
	//// 포켓몬 이미지 
	//IMAGEMANAGER->addFrameImage("pokemon_ingame", L"image/pokemon/pokemon.png", 5120, 4096, 20, 16);
	//
	//// 상점주인 이미지
	//IMAGEMANAGER->addFrameImage("shopOwner", L"image/shopOwner.png", 240, 80, 4, 1);
	//
	//// 간호사 이미지
	//IMAGEMANAGER->addFrameImage("nurse", L"image/nurse.png", 272, 80, 4, 1);
	//
	//// 배틀 배경
	//IMAGEMANAGER->addFrameImage("battleBackground", L"image/BattleBackgrounds.png", 2880, 1792, 3, 4);
	//
	//
	////=============================================================================================== UI 이미지 
	//// 0. 메인
	//IMAGEMANAGER->addImage("기본하단", L"image/common_menu/common_menu_bg.png", 960, 160);
	//IMAGEMANAGER->addImage("화살표", L"image/common_menu/pokemonMenu_cursor.png", 24, 40);
	//IMAGEMANAGER->addImage("기본상단", L"image/common_menu/common_menu_top.png", 960, 64);
	//// 1. 도감
	//IMAGEMANAGER->addFrameImage("도감", L"image/common_menu/pokemonbook/cm_pokemon_book.png", 1920, 640, 2, 1);
	//IMAGEMANAGER->addFrameImage("포켓몬속성", L"image/Summary Menu/summary_pokemon_tage.png", 1152, 96, 9, 2);
	//// 2. 포켓몬
	//IMAGEMANAGER->addFrameImage("메인포켓몬", L"image/common_menu/pokemon/pokemonMenu_slot_first.png", 336, 912, 1, 4);
	//IMAGEMANAGER->addImage("보유중포켓몬", L"image/common_menu/pokemon/pokemonMenu_background.png", 960, 640);
	//
	//IMAGEMANAGER->addImage("서브포켓몬1", L"image/common_menu/pokemon/pokemon_subpokemon_list.png", 500, 80);
	//IMAGEMANAGER->addFrameImage("서브포켓몬2", L"image/common_menu/pokemon/pokemonMenu_slot.png", 2000, 80, 4, 1);
	//
	//IMAGEMANAGER->addFrameImage("포켓몬메뉴_취소", L"image/common_menu/pokemon/pokemonMenu_btn_cancle.png", 216, 192, 1, 2);
	//
	//
	//IMAGEMANAGER->addFrameImage("서머리상단", L"image/Summary Menu/summary_top_bar.png", 960, 192, 1, 3);
	//IMAGEMANAGER->addImage("서머리배경", L"image/Summary Menu/summary_base.png", 960, 640);
	//IMAGEMANAGER->addFrameImage("서머리프레임", L"image/Summary Menu/summary_pokemon_info.png", 1920, 576, 2, 1);
	//IMAGEMANAGER->addImage("서머리포켓몬", L"image/Summary Menu/summary_pokemon_base.png", 484, 336);
	//IMAGEMANAGER->addImage("서머리스킬", L"image/Summary Menu/summary_pokemon_skill.png", 484, 576);
	//IMAGEMANAGER->addImage("체력베이스", L"image/battle_UI/battle_UI_HP_base.png", 36, 12);
	//IMAGEMANAGER->addFrameImage("체력게이지", L"image/pokemonMenu_gauge.png", 192, 12, 3, 1);
	//// 3. 가방
	//IMAGEMANAGER->addFrameImage("가방메뉴배경", L"image/common_menu/bag/bag_background.png", 1920, 640, 2, 1);
	//// 4. 플레이어
	//IMAGEMANAGER->addFrameImage("트레이너카드", L"image/common_menu/player/trainerCard.png", 1920, 640, 2, 1);
	//// 5. 저장
	//
	//// 6. 설정 
	//
	//// 7. 애니메이션 
	//IMAGEMANAGER->addFrameImage("포켓몬파닥", L"image/pokemon/pokemon_mini.png", 2304, 2176, 18, 17);	//큰사이즈 메인 포켓몬용
	//IMAGEMANAGER->addFrameImage("포켓몬파닥2", L"image/pokemon/pokemon_mini_start.png", 2304 / 2, 2176 / 2, 18, 17);	//작은사이즈 서브 포켓몬용
	//
	//// ========================================================================================================


	

	
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
	// Draw 시작 - 이 코드가 빠지면 D2D 출력 X
	D2DMANAGER->beginDraw();
	//===========================================================================
	//				##		여기에 코드 작성(Start)			##



	SCENEMANAGER->render();




	//				##			여기에 코드 작성(End)			##
	//===========================================================================
	//				##카메라 정보 마우스 정보 시간정보 출력	##===================
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
	// Draw 끝 - 이 코드가 빠지면 D2D 출력 X
	D2DMANAGER->endDraw();
}