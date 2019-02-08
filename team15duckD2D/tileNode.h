#pragma once
#include "stdafx.h"

//요거 속성별로 다 추가해주세요 이거 있으면 판단이 너무쉬워집니다
//2배로 더해주세요
#define TILE_SIZE	64

#define ATTR_NONE   0x00000000
#define ATTR_UNMOVE 0x00000001
#define ATTR_WALL	0X00000016
#define ATTR_WATER  0x00000002
#define ATTR_FOREST 0x00000004
#define ATTR_TREE   0x00000008
#define ATTR_ROCK	0X00000032
#define ATTR_HILL	0X00000064

///////// 어트리뷰트는 처음에 0으로 초기화하고 |= 이걸로 더해주세요
///////// 빼낼떄는 ^=





typedef struct tagTile
{
	UINT terrainFrameX;		//이거는 -1로 초기화 합시다  -1일때 출력안하게요
	UINT terrainFrameY;		//이거는 -1로 초기화 합시다  -1일때 출력안하게요
	UINT objectFrameX;		//이거는 -1로 초기화 합시다  -1일때 출력안하게요
	UINT objectFrameY;		//이거는 -1로 초기화 합시다  -1일때 출력안하게요
	DWORD attr;				//이건 ATTR_NONE으로 초기화 후에 시작합시다
}TILE;

//타일의 포인터를 LPTILE이라고 하겠다
typedef struct tagTile *LPTILE;

