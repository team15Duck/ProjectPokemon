#pragma once
#include "gameNode.h"
#include "tileNode.h"
#include <vector>

#define OBJECT_IMG_NUM			17
#define SAMPLE_TOTAL_SIZE	TILE_SIZE * SAMPLETILE
#define SAMPLETILE_STARTX  ( WINSIZEX - SAMPLE_TOTAL_SIZE)
#define	CAMERA_SHOW_RANGE	16 * TILE_SIZE

enum OBJECT_NAME
{
	OBJECT_OUTSIDE_01,						//풀과 꽃 그리고 음.. 산?
	OBJECT_OUTSIDE_02,						//울타리랑 나무
	OBJECT_OUTSIDE_03,						//큰나무랑 돌
	OBJECT_OUTSIDE_04,						//산...?과 언덕 그리고 가로등
	OBJECT_OUTSIDE_05,						//물, 다리, 동굴
	OBJECT_INSIDE_01,						//포켓몬센터
	OBJECT_INSIDE_02,						//상점
	OBJECT_INSIDE_03,						//집
	OBJECT_INSIDE_04,						//오박사집
	OBJECT_INSIDE_05,						//계단,테이블
	OBJECT_MY_HOUSE,						//주인공집
	OBJECT_OAK_HOUSE,						//오박사집
	OBJECT_CENTER,							//포켓몬센터
	OBJECT_SHOP,							//상점
	OBJECT_GYM,								//체육관
	OBJECT_DOOR,							//문
	
	OBJECT_NONE,
	OBJECT_COUNT = OBJECT_NONE
	
};

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
	string _sampleImgStr[OBJECT_IMG_NUM];

	int _curImgNum;

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


	bool _isShift;
	UINT _savePointX;
	UINT _savePointY;
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

