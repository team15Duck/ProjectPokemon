#pragma once
#include "tileNode.h"
#include <vector>
#include <assert.h>
#define	TILE_IMAGE_NUM		10
#define SAMPLE_TOTAL_SIZE	384
#define	CAMERA_SHOW_RANGE	8 * TILE_SIZE

//���� ���� enum��(��, ��, �׿�...���߿� ������Ʈ �߰�)
enum SAMPLETERRAIN
{
	TR_ROAD,
	TR_WALL,


	SAMPLE_NONE
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
	string _sampleImgStr[TILE_IMAGE_NUM];
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
	//�ʳ����� ������ Ÿ�Ͽ� ����Ÿ���� ���� �뵵
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

