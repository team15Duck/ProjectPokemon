#pragma once
#include "stdafx.h"

//요거 속성별로 다 추가해주세요 이거 있으면 판단이 너무쉬워집니다
//2배로 더해주세요
#define TILE_SIZE	64
#define SAMPLETILE  6

#define ATTR_NONE			0x00000000UL					//NONE
#define ATTR_UNMOVE			0x00000001UL					//못움직임
#define ATTR_WALL			0X00000002UL					//벽
#define ATTR_WATER			0x00000004UL					//물
#define ATTR_FOREST			0x00000008UL					//숲
#define ATTR_TREE			0x00000010UL					//나무

#define ATTR_ROCK			0X00000020UL					//돌
#define ATTR_JUMP			0X00000040UL					//언덕에서 점프
#define ATTR_COMPUTER		0X00000080UL					//컴퓨터(센터/집)
#define ATTR_DOOR			0X00000100UL					//문
#define ATTR_CUT			0X00000200UL					//풀베기
#define ATTR_GRASS			0X00000400UL					//풀(몬스터등장)
#define ATTR_OAK_MACHINE	0X00000800UL					//오박사기계
#define ATTR_BOOKCASE		0X00001000UL					//책장
#define ATTR_TIP			0X00002000UL					//팁게시판
#define ATTR_MAT			0X00004000UL					//발매트
#define ATTR_SINK			0X00008000UL					//싱크대
#define ATTR_PANTRY			0X00010000UL					//식기장
#define ATTR_GAME			0X00020000UL					//게임기
#define ATTR_STONE_STATUE	0X00040000UL					//석상
#define ATTR_STORE_STAND    0X00800000UL					//진열대(상점)
#define ATTR_STORE_DISPLAY  0X01000000UL					//진열대2(상점)
#define ATTR_MAP			0X02000000UL					//지도





///////// 어트리뷰트는 처음에 0으로 초기화하고 |= 이걸로 더해주세요
///////// 빼낼떄는 ^=



//타일 이미지 이름
static string TERRAIN_NAME_NONE = "";
static string TERRAIN_NAME1		= "tile_01";
static string TERRAIN_NAME2		= "tile_02";
static string TERRAIN_NAME3		= "tile_03";
static string TERRAIN_NAME4		= "tile_04";
static string TERRAIN_NAME5		= "tile_05";
static string TERRAIN_NAME6		= "tile_06";
static string TERRAIN_NAME7		= "tile_07";
static string TERRAIN_NAME8		= "tile_08";
static string TERRAIN_NAME9		= "tile_09";
static string TERRAIN_NAME10	= "tile_10";

//오브젝트 이미지 이름
static string OBJECT_NAME_NONE	= "";
static string OBJECT_NAME1		= "object_01";
static string OBJECT_NAME2		= "object_02";
static string OBJECT_NAME3		= "object_03";
static string OBJECT_NAME4		= "object_04";
static string OBJECT_NAME5		= "object_05";
static string OBJECT_NAME6		= "object_06";
static string OBJECT_NAME7		= "object_07";
static string OBJECT_NAME8		= "object_08";
static string OBJECT_NAME9		= "object_09";
static string OBJECT_NAME10		= "object_10";
static string OBJECT_NAME11		= "my_House";
static string OBJECT_NAME12		= "oak_House";
static string OBJECT_NAME13		= "pokemon_Center";
static string OBJECT_NAME14		= "pokemon_Shop";
static string OBJECT_NAME15		= "pokemon_Gym";


typedef struct tagTile
{
	string terrainImageName;	//TERRAIN_NAME_NONE 으로 초기화
	UINT terrainFrameX;			//0으로 초기화
	UINT terrainFrameY;			//0으로 초기화
	string objectImageName;		//OBJECT_NAME_NONE 으로 초기화
	UINT objectFrameX;			//0으로 초기화
	UINT objectFrameY;			//0으로 초기화
	DWORD attr;					//이건 ATTR_NONE으로 초기화 후에 시작합시다
}TILE;

//타일의 포인터를 LPTILE이라고 하겠다
typedef struct tagTile *LPTILE;

