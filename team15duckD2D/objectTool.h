#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include "mapTool.h"
#include <vector>
#include <assert.h>

#define OBJECT_IMG_NUM			18
#define SAMPLE_TOTAL_SIZE	TILE_SIZE * SAMPLETILE
#define SAMPLETILE_STARTX  ( WINSIZEX - SAMPLE_TOTAL_SIZE)
#define	CAMERA_SHOW_RANGE	16 * TILE_SIZE


struct tagSampleTile_Object
{
	D2D1_RECT_F sampleRC;
	int frameX;
	int frameY;
};

struct tagCurrentTile_Object
{
	bool isObj = true;
	int curX = 0;
	int curY = 0;
};

class objectTool : public gameNode
{
private:
	//샘플타일이미지
	image* _sampleImg_Obj[OBJECT_IMG_NUM];

	//샘플타일배열
	tagSampleTile_Object _sampleTile_Obj[SAMPLETILE][SAMPLETILE];

	//맵 이중벡터
	vector<vector<tagTile*>> _vvTile;
	vector<vector<D2D1_RECT_F>> _vvRect;

	//이전, 다음 버튼
	D2D1_RECT_F		_preButton;
	D2D1_RECT_F		_nextButton;

	//맵크기
	unsigned int TILEX;
	unsigned int TILEY;

	//선택한 샘플 타일
	tagCurrentTile_Object	_pickSampleTile;

	//선택한 오브젝트 타일
	tagCurrentTile_Object _tempObjTile;
	
	//현재 타일 클릭했니
	bool _isTileClick;

	//맵에서 드래그할거니
	bool _isShift;

	//맵에서 다른타일로 덮어쓸거니
	bool _isCtrl;

	//맵정보 불러올거니
	bool _isSave;
	bool _isLoad;

	UINT _savePointX;
	UINT _savePointY;
	UINT _sampleSaveX;
	UINT _sampleSaveY;
	UINT _sampleDrawX;
	UINT _sampleDrawY;

	tagTile _saveTile;

	//현재 오브젝트 이미지
	int _curImgNum;
	//맵종류
	int _mapCase;

	//테스트맵용
    //==================================
	UINT						ii;								//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						iiMax;							//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						jj;								//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						jjMax;
	//==================================

	//세이브파일 스트링벡터
	map<MAP_NAME, string> _mSizeNames;
	map<MAP_NAME, string> _mDataNames;



public:
	objectTool();
	~objectTool();

	HRESULT init();
	void release();
	void update();
	void render();
	
	void setSampleTile();
	void setTile();
	void turnObject();
	void pickSampleObject();
	void drawObject();
	
	void save(int mapCase);
	void load();
	void nextSaveName();
	void nameInit();


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

