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
	MAP_TEST,		//�׽�Ʈ��
	MAP_TOWN,		//����
	MAP_HOME,		//����
	MAP_O_LAB,		//���ڻ� ������
	MAP_STORE,		//����
	MAP_CENTER,		//���ϸ���
	MAP_GYM,		//ü����
	MAP_FIELD,		//�ʵ�
	MAP_CAVE,		//����

	MAP_NONE,		//
	MAP_COUNT = MAP_NONE,

};


//����Ÿ���� ������ ��ȣ ����ü. (Rect�� ������ ����...)
struct tagSampleTile
{
	D2D1_RECT_F sampleRc;
	int frameX;
	int frameY;
};

struct tagCurrentTile
{
	bool isObj = false;	//->�ϴ� �������� �����ؼ�
	int curX = 0;
	int curY = 0;
};
class mapTool
{
private:
	//����Ÿ���� �̹���
	image*	_sampleImg[TILE_IMAGE_NUM];
	//����Ÿ�� �̹����� string����(�̹����Ŵ������� findeImg �Ҷ� ������)
	//string _sampleImgStr[TILE_IMAGE_NUM];

	image* _tempImg[OBJ_IMG_NUM];
	//string	_tempImgStr[OBJ_IMG_NUM];

	int		_curImgNum;

	//����Ÿ���� �迭
	tagSampleTile	_sampleTile[SAMPLETILE][SAMPLETILE];

	//�ʱ׸� �κ��� ���ߺ��� 
	vector<vector<tagTile*>> _vvTile;
	vector<vector<D2D1_RECT_F>> _vvRect;

	//����, ���� ��ư
	D2D1_RECT_F		_preButton;
	D2D1_RECT_F		_nextButton;

	//���� Ÿ�� ����� �ø��� ��ư
	D2D1_RECT_F		_sizeUpWidth;
	D2D1_RECT_F		_sizeDownWidth;
	D2D1_RECT_F		_sizeUpHeight;
	D2D1_RECT_F		_sizeDownHeight;

	unsigned int TILEX;
	unsigned int TILEY;

	//������ ���� Ÿ��
	tagCurrentTile	_pickSampleTile;
	//������ ������Ʈ Ÿ��
	tagCurrentTile _tempObjTile;

	bool _isTileClick;
	bool _isObj;
	bool _isRND;
	int	tempCount;	//������Ʈ �̹��� ����� ������ �Ҷ� ���� ����

	//���̺� ������ ��Ʈ�� ����
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
	//�����Լ�

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

