#pragma once
#include "stdafx.h"

//��� �Ӽ����� �� �߰����ּ��� �̰� ������ �Ǵ��� �ʹ��������ϴ�
//2��� �����ּ���
#define TILE_SIZE	64
#define SAMPLETILE  6

#define ATTR_NONE			0x00000000UL					//NONE
#define ATTR_UNMOVE			0x00000001UL					//��������
#define ATTR_WALL			0X00000002UL					//��
#define ATTR_WATER			0x00000004UL					//��
#define ATTR_FOREST			0x00000008UL					//��
#define ATTR_TREE			0x00000010UL					//����

#define ATTR_ROCK			0X00000020UL					//��
#define ATTR_JUMP			0X00000040UL					//������� ����
#define ATTR_COMPUTER		0X00000080UL					//��ǻ��(����/��)
#define ATTR_DOOR			0X00000100UL					//��
#define ATTR_CUT			0X00000200UL					//Ǯ����
#define ATTR_GRASS			0X00000400UL					//Ǯ(���͵���)
#define ATTR_OAK_MACHINE	0X00000800UL					//���ڻ���
#define ATTR_BOOKCASE		0X00001000UL					//å��
#define ATTR_TIP			0X00002000UL					//���Խ���
#define ATTR_MAT			0X00004000UL					//�߸�Ʈ
#define ATTR_SINK			0X00008000UL					//��ũ��
#define ATTR_PANTRY			0X00010000UL					//�ı���
#define ATTR_GAME			0X00020000UL					//���ӱ�
#define ATTR_STONE_STATUE	0X00040000UL					//����
#define ATTR_STORE_STAND    0X00800000UL					//������(����)
#define ATTR_STORE_DISPLAY  0X01000000UL					//������2(����)
#define ATTR_MAP			0X02000000UL					//����





///////// ��Ʈ����Ʈ�� ó���� 0���� �ʱ�ȭ�ϰ� |= �̰ɷ� �����ּ���
///////// �������� ^=



//Ÿ�� �̹��� �̸�
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

//������Ʈ �̹��� �̸�
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

