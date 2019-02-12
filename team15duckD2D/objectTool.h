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
	OBJECT_OUTSIDE_01,						//Ǯ�� �� �׸��� ��.. ��?
	OBJECT_OUTSIDE_02,						//��Ÿ���� ����
	OBJECT_OUTSIDE_03,						//ū������ ��
	OBJECT_OUTSIDE_04,						//��...?�� ��� �׸��� ���ε�
	OBJECT_OUTSIDE_05,						//��, �ٸ�, ����
	OBJECT_INSIDE_01,						//���ϸ���
	OBJECT_INSIDE_02,						//����
	OBJECT_INSIDE_03,						//��
	OBJECT_INSIDE_04,						//���ڻ���
	OBJECT_INSIDE_05,						//���,���̺�
	OBJECT_MY_HOUSE,						//���ΰ���
	OBJECT_OAK_HOUSE,						//���ڻ���
	OBJECT_CENTER,							//���ϸ���
	OBJECT_SHOP,							//����
	OBJECT_GYM,								//ü����
	OBJECT_DOOR,							//��
	
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

	//����, ���� ��ư
	D2D1_RECT_F		_preButton;
	D2D1_RECT_F		_nextButton;

	unsigned int TILEX;
	unsigned int TILEY;

	//������ ���� Ÿ��
	tagCurrentTile1	_pickSampleTile;
	//������ ������Ʈ Ÿ��
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

