#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>

#define OBJECT_IMG_NUM			17
#define SAMPLE_TOTAL_SIZE	TILE_SIZE * SAMPLETILE
#define SAMPLETILE_STARTX  ( WINSIZEX - SAMPLE_TOTAL_SIZE)
#define	CAMERA_SHOW_RANGE	16 * TILE_SIZE

struct tagSampleTile1
{
	D2D1_RECT_F sampleRC;
	int frameX;
	int frameY;
};

struct tagCurrentTile1
{
	bool isObj = true;
	int curX = 0;
	int curY = 0;
};

class objectTool : public gameNode
{
private:
	image* _sampleImg[OBJECT_IMG_NUM];
	tagSampleTile1 _sampleTile[SAMPLETILE][SAMPLETILE];
	vector<vector<tagTile*>> _vvTile;
	vector<vector<D2D1_RECT_F>> _vvRect;

	//이전, 다음 버튼
	D2D1_RECT_F		_preButton;
	D2D1_RECT_F		_nextButton;

	unsigned int TILEX;
	unsigned int TILEY;

	//선택한 샘플 타일
	tagCurrentTile1	_pickSampleTile;
	//선택한 오브젝트 타일
	tagCurrentTile1 _tempObjTile;
	
	bool _isTileClick;
	bool _isObj;

	bool _isDraw;
	bool _isDrag;
	UINT _saveX;
	UINT _saveY;
	UINT _drawX;
	UINT _drawY;
	tagTile _saveTiles[SAMPLETILE][SAMPLETILE];


	bool _isShift;
	bool _isCtrl;
	UINT _savePointX;
	UINT _savePointY;
	tagTile _saveTile;

	int _curImgNum;

public:
	objectTool();
	~objectTool();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void setTile();
	void turnObject();
	void pickSampleObject();
	void drawObject();
	void dragSample();



private:
	inline RECT makeRECT(D2D1_RECT_F rc)
	{
		return RECT{ (LONG)rc.left, (LONG)rc.top, (LONG)rc.right, (LONG)rc.bottom };
	}

	inline POINT makePOINT(POINTF pt)
	{
		return POINT{ (LONG)pt.x, (LONG)pt.y };
	}
	DWORD setAttribute(string imgName, UINT frameX, UINT frameY);
};

