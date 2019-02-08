#pragma once
#include "stdafx.h"

//��� �Ӽ����� �� �߰����ּ��� �̰� ������ �Ǵ��� �ʹ��������ϴ�
//2��� �����ּ���
#define TILE_SIZE	64

#define ATTR_NONE   0x00000000
#define ATTR_UNMOVE 0x00000001
#define ATTR_WALL	0X00000002
#define ATTR_WATER  0x00000004
#define ATTR_FOREST 0x00000008
#define ATTR_TREE   0x00000010
#define ATTR_ROCK	0X00000020
#define ATTR_HILL	0X00000040

///////// ��Ʈ����Ʈ�� ó���� 0���� �ʱ�ȭ�ϰ� |= �̰ɷ� �����ּ���
///////// �������� ^=



//Ÿ�� �̹��� �̸�
static string TERRAIN_NAME_NONE = "";
static string TERRAIN_NAME1		= "";
static string TERRAIN_NAME2		= "";
static string TERRAIN_NAME3		= "";

//������Ʈ �̹��� �̸�
static string OBJECT_NAME_NONE	= "";
static string OBJECT_NAME1		= "";
static string OBJECT_NAME2		= "";
static string OBJECT_NAME3		= "";
static string OBJECT_NAME4		= "";


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

