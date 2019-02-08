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
	D2D1_RECT_F sampeTerrainRect;
};

struct tagCurrentTile
{
	int curX;
	int curY;
};

class mapTool
{
private:
		

	tagSampleTerrain _sampleTerrain[SAMPLETILE * SAMPLETILE];	//샘플배치할 타일
	tagSampleTerrain _currentSampleTile;						//선택한 sample 타일을 이 변수에 넣어줌.
	
	tagSampleTerrain _currentTile;								//현재 타일(선택한 sample 타일을 이 변수에 넣어줌).

	vector<vector<tagTile*>> _vvTiles;
	
	D2D1_RECT_F		_preButton;
	D2D1_RECT_F		_nextButton;
	
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

