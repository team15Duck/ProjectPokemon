#pragma once
#include "mapData.h"
#include "item.h"

enum OBJECT_ACTIVE_TYPE
{
	OBJECT_ACTIVE_TYPE_COMPUTER,						 //������Ʈ�� ��ǻ���϶�
	OBJECT_ACTIVE_TYPE_DIALOG,							 //�׿� ������Ʈ
	OBJECT_ACTIVE_TYPE_ITEM,							 //������Ʈ�� �������϶�
	OBJECT_ACTIVE_TYPE_CUT,								 //������Ʈ�� ���������϶�(Ǯ����O)
	OBJECT_ACTIVE_TYPE_CENTER,							 //���ϸ� ġ���Ҷ�

	OBJECT_ACTIVE_TYPE_NONE,
	OBJECT_ACTIVE_TYPE_COUNT = OBJECT_ACTIVE_TYPE_NONE
};


class object
{
private:




	string						_sceneName;				//�����
	OBJECT_ACTIVE_TYPE			_activeType;			//������Ʈ �Ÿ������ �۵��ϴ���

	UINT						_tileX;					//��ġ
	UINT						_tileY;					//��ġ

	bool						_isActive;				//�۵��ߴ���?


	animation*					_motion;
	bool						_isHealing;
	int							_count;
	int							_ballX;

public:
	object();
	~object();

	HRESULT init();
	void release();
	void update();
	void render();




	//�׽����Լ�
	void aniSetting();
	void startAni();


	//=============�ټ�====================

	UINT getTileX() { return _tileX; }
	UINT getTIleY() { return _tileY; }
	void setTileX(UINT tileX) { _tileX = tileX; }
	void setTIleY(UINT tileY) { _tileY = tileY; }
};

