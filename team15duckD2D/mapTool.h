#pragma once
#include "tileNode.h"
#include <vector>
#include <assert.h>
#define	TILE_IMAGE_NUM		11
#define SAMPLE_TOTAL_SIZE	TILE_SIZE * SAMPLETILE
#define SAMPLETILE_STARTX  ( WINSIZEX - SAMPLE_TOTAL_SIZE)
#define	CAMERA_SHOW_RANGE	16 * TILE_SIZE

#define OBJ_IMG_NUM			16


enum MAP_NAME
{
	MAP_TEST,		//테스트맵
	MAP_TOWN,		//마을
	MAP_HOME,		//내집
	MAP_O_LAB,		//오박사 연구소
	MAP_STORE,		//상점
	MAP_CENTER,		//포켓몬센터
	MAP_GYM,		//체육관
	MAP_FIELD,		//필드
	MAP_CAVE,		//동굴

	MAP_NONE,		//
	MAP_COUNT = MAP_NONE,

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
	//string _sampleImgStr[TILE_IMAGE_NUM];

	image* _tempImg[OBJ_IMG_NUM];
	//string	_tempImgStr[OBJ_IMG_NUM];

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
	//선택한 오브젝트 타일
	tagCurrentTile _tempObjTile;

	bool _isTileClick;
	bool _isObj;
	bool _isRND;
	int	tempCount;	//오브젝트 이미지 띄웠다 지웠다 할때 쓰는 변수

	//세이브 파일의 스트링 벡터
	map<MAP_NAME, string> _mSizeNames;
	map<MAP_NAME, string> _mDataNames;
	int _mapCase;

	bool _isShift;
	UINT _savePointX;
	UINT _savePointY;

public:
	mapTool();
	~mapTool();

	HRESULT init();
	void release();
	void update();
	void render();

	void setSampleTile();
	void setTile();

	void turnMap();
	void pickSampleMap();
	void mapSizeChange();

	void drawMap();

	void save(int mapCase);
	void load();

	void nextSaveName();

	void nameInit();

	//void getSizeFile(string sizeFile){ _vSizeFile[]
	//void getDataFile(){}



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

