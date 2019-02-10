#pragma once
#include "tileNode.h"
#include <vector>
#include <assert.h>
#define	TILE_IMAGE_NUM		10
#define SAMPLE_TOTAL_SIZE	384
#define	CAMERA_SHOW_RANGE	8 * TILE_SIZE

//지형 상태 enum문(길, 벽, 그외...나중에 오브젝트 추가)
enum SAMPLETERRAIN
{
	TR_ROAD,
	TR_WALL,


	SAMPLE_NONE
};

//샘플타일의 프레임 번호 구조체. (Rect는 넣을까 말까...)
struct tagSampleTile
{
	D2D1_RECT_F sampleRc;
	int frameX;
	int frameY;
};

struct tagCurrentTile
{
	bool isObj = false;	//->일단 지형으로 시작해서
	int curX = 0;
	int curY = 0;
};
class mapTool
{
private:
	//샘플타일의 이미지
	image*	_sampleImg[TILE_IMAGE_NUM];
	//샘플타일 이미지를 string으로(이미지매니저에서 findeImg 할때 쓰려고)
	string _sampleImgStr[TILE_IMAGE_NUM];
	int		_curImgNum;

	//샘플타일의 배열
	tagSampleTile	_sampleTile[SAMPLETILE][SAMPLETILE];

	

	//맵그릴 부분의 이중벡터 
	vector<vector<tagTile*>> _vvTile;
	vector<vector<D2D1_RECT_F>> _vvRect;

	//이전, 다음 버튼
	D2D1_RECT_F		_preButton;
	D2D1_RECT_F		_nextButton;

	//맵의 타일 사이즈를 늘리는 버튼
	D2D1_RECT_F		_sizeUpWidth;
	D2D1_RECT_F		_sizeDownWidth;
	D2D1_RECT_F		_sizeUpHeight;
	D2D1_RECT_F		_sizeDownHeight;

	unsigned int TILEX;
	unsigned int TILEY;

	//선택한 샘플 타일
	tagCurrentTile	_pickSampleTile;
	//맵내에서 선택한 타일에 샘플타일을 넣을 용도
	//tagCurrentTile	 _curTile;

	bool _isTileClick;
	//bool _isMapClick;

public:
	mapTool();
	~mapTool();

	HRESULT init();
	void release();
	void update();
	void render();

	void setTile();
	void turnMap();
	void pickSampleMap();
	void mapSizeUp();

	void drawMap();

	void save();
	void load();




private:
	//내부함수

	inline RECT makeRECT(D2D1_RECT_F rc)
	{
		return RECT{(LONG)rc.left, (LONG)rc.top, (LONG)rc.right, (LONG)rc.bottom};
	}

	inline POINT makePOINT(POINTF pt)
	{
		return POINT{ (LONG)pt.x, (LONG)pt.y };
	}

	DWORD setAttribute(string imgName, UINT frameX, UINT frameY);
};

