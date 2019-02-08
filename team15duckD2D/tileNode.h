#pragma once
#include "stdafx.h"

//��� �Ӽ����� �� �߰����ּ��� �̰� ������ �Ǵ��� �ʹ��������ϴ�
//2��� �����ּ���
#define TILE_SIZE	64

#define ATTR_NONE   0x00000000
#define ATTR_UNMOVE 0x00000001
#define ATTR_WALL	0X00000016
#define ATTR_WATER  0x00000002
#define ATTR_FOREST 0x00000004
#define ATTR_TREE   0x00000008
#define ATTR_ROCK	0X00000032
#define ATTR_HILL	0X00000064

///////// ��Ʈ����Ʈ�� ó���� 0���� �ʱ�ȭ�ϰ� |= �̰ɷ� �����ּ���
///////// �������� ^=





typedef struct tagTile
{
	UINT terrainFrameX;		//�̰Ŵ� -1�� �ʱ�ȭ �սô�  -1�϶� ��¾��ϰԿ�
	UINT terrainFrameY;		//�̰Ŵ� -1�� �ʱ�ȭ �սô�  -1�϶� ��¾��ϰԿ�
	UINT objectFrameX;		//�̰Ŵ� -1�� �ʱ�ȭ �սô�  -1�϶� ��¾��ϰԿ�
	UINT objectFrameY;		//�̰Ŵ� -1�� �ʱ�ȭ �սô�  -1�϶� ��¾��ϰԿ�
	DWORD attr;				//�̰� ATTR_NONE���� �ʱ�ȭ �Ŀ� �����սô�
}TILE;

//Ÿ���� �����͸� LPTILE�̶�� �ϰڴ�
typedef struct tagTile *LPTILE;

