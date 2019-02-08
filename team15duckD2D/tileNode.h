#pragma once
#include "stdafx.h"

//��� �Ӽ����� �� �߰����ּ��� �̰� ������ �Ǵ��� �ʹ��������ϴ�
//2��� �����ּ���
#define TILE_SIZE	64

#define ATTR_NONE   0x00000000
#define ATTR_UNMOVE 0x00000001
#define ATTR_WALL	0X00000010
#define ATTR_WATER  0x00000020
#define ATTR_FOREST 0x00000040
#define ATTR_TREE   0x00000080
#define ATTR_ROCK	0X00000100
#define ATTR_HILL	0X00000200

///////// ��Ʈ����Ʈ�� ó���� 0���� �ʱ�ȭ�ϰ� |= �̰ɷ� �����ּ���
///////// �������� ^=



//Ÿ�� �̹��� �̸�
#define TERRAIN_NAME_NONE	""
#define TERRAIN_NAME1		""
#define TERRAIN_NAME2		""
#define TERRAIN_NAME3		""

//������Ʈ �̹��� �̸�
#define OBJECT_NAME_NONE	""
#define OBJECT_NAME1		""
#define OBJECT_NAME2		""
#define OBJECT_NAME3		""
#define OBJECT_NAME4		""


typedef struct tagTile
{
	string terrainImageName;	//TERRAIN_NAME_NONE ���� �ʱ�ȭ
	UINT terrainFrameX;			//0���� �ʱ�ȭ
	UINT terrainFrameY;			//0���� �ʱ�ȭ
	string objectImageName;		//OBJECT_NAME_NONE ���� �ʱ�ȭ
	UINT objectFrameX;			//0���� �ʱ�ȭ
	UINT objectFrameY;			//0���� �ʱ�ȭ
	DWORD attr;					//�̰� ATTR_NONE���� �ʱ�ȭ �Ŀ� �����սô�
}TILE;

//Ÿ���� �����͸� LPTILE�̶�� �ϰڴ�
typedef struct tagTile *LPTILE;

