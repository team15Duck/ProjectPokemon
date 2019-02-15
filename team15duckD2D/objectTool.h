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
	//����Ÿ���̹���
	image* _sampleImg_Obj[OBJECT_IMG_NUM];

	//����Ÿ�Ϲ迭
	tagSampleTile_Object _sampleTile_Obj[SAMPLETILE][SAMPLETILE];

	//�� ���ߺ���
	vector<vector<tagTile*>> _vvTile;
	vector<vector<D2D1_RECT_F>> _vvRect;

	//����, ���� ��ư
	D2D1_RECT_F		_preButton;
	D2D1_RECT_F		_nextButton;

	//��ũ��
	unsigned int TILEX;
	unsigned int TILEY;

	//������ ���� Ÿ��
	tagCurrentTile_Object	_pickSampleTile;

	//������ ������Ʈ Ÿ��
	tagCurrentTile_Object _tempObjTile;
	
	//���� Ÿ�� Ŭ���ߴ�
	bool _isTileClick;

	//�ʿ��� �巡���ҰŴ�
	bool _isShift;

	//�ʿ��� �ٸ�Ÿ�Ϸ� ����Ŵ�
	bool _isCtrl;

	//������ �ҷ��ðŴ�
	bool _isSave;
	bool _isLoad;

	UINT _savePointX;
	UINT _savePointY;
	UINT _sampleSaveX;
	UINT _sampleSaveY;
	UINT _sampleDrawX;
	UINT _sampleDrawY;

	tagTile _saveTile;

	//���� ������Ʈ �̹���
	int _curImgNum;
	//������
	int _mapCase;

	//�׽�Ʈ�ʿ�
    //==================================
	UINT						ii;								//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						iiMax;							//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						jj;								//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						jjMax;
	//==================================

	//���̺����� ��Ʈ������
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

