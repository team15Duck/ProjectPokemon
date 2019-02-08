#pragma once
#include "stdafx.h"

//요거 속성별로 다 추가해주세요 이거 있으면 판단이 너무쉬워집니다
//2배로 더해주세요
#define TILE_SIZE	64

#define ATTR_NONE   0x00000000
#define ATTR_UNMOVE 0x00000001
#define ATTR_WALL	0X00000002
#define ATTR_WATER  0x00000004
#define ATTR_FOREST 0x00000008
#define ATTR_TREE   0x00000010
#define ATTR_ROCK	0X00000020
#define ATTR_HILL	0X00000040

///////// 어트리뷰트는 처음에 0으로 초기화하고 |= 이걸로 더해주세요
///////// 빼낼떄는 ^=



//타일 이미지 이름
static string TERRAIN_NAME_NONE = "";
static string TERRAIN_NAME1		= "";
static string TERRAIN_NAME2		= "";
static string TERRAIN_NAME3		= "";

//오브젝트 이미지 이름
static string OBJECT_NAME_NONE	= "";
static string OBJECT_NAME1		= "";
static string OBJECT_NAME2		= "";
static string OBJECT_NAME3		= "";
static string OBJECT_NAME4		= "";


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

