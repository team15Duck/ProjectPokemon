#pragma once
#include "tileNode.h"
#include <vector>
#include <assert.h>
#define	TILE_IMAGE_NUM		10
#define SAMPLE_TOTAL_SIZE	384

struct tagSampleTerrain
{
	int sampleTerrainX;
	int sampleTerrainY;
	RECT sampeTerrainRect;
};

struct tagCurrentTile
{
	int curX;
	int curY;
};

class mapTool
{
private:
		
	tagSampleTerrain _sampleTerrain[SAMPLETILE * SAMPLETILE];	//���ù�ġ�� Ÿ��
	tagSampleTerrain _currentSampleTile;						//������ sample Ÿ���� �� ������ �־���.
	
	tagSampleTerrain _currentTile;								//���� Ÿ��(������ sample Ÿ���� �� ������ �־���).

	vector<vector<tagTile*>> _vvTiles;
	
	unsigned int	TILEX;
	unsigned int	TILEY;


public:
	mapTool();
	~mapTool();

	
	HRESULT init();
	void release();
	void update();
	void render();





};

