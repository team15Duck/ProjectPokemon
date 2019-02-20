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
	
	//ȸ����
	UINT						_tileX;					//��ġ
	UINT						_tileY;					//��ġ
	UINT						_curPokemon;			//�÷��̾ ������ �ִ� ���ϸ� ��
	UINT						_healedPokemon;			//ġ��޴� ���ϸ� ��(�񱳿�)
	OBJECT_ACTIVE_TYPE			_activeType;			//������Ʈ �Ÿ������ �۵��ϴ���



	bool						_isActive;				//�۵��ߴ���?
	bool						_isBallUp;				//���ø���������?
	bool						_isHealing;				//ȸ��������?


	animation*					_motion;
	int							_count;					//�����ӿ�
	int							_ballX;					//������x
	int							_time;					//�̽ð����� ȸ���ϴ� ������ ���Ŵ�

public:
	object();
	~object();

	HRESULT init();
	void release();
	void update();
	void render();

	
	void centerHealing();

	//�׽����Լ�
	void aniSetting();


	//=============�ټ�====================

	UINT getTileX() { return _tileX; }
	UINT getTIleY() { return _tileY; }
	void setTileX(UINT tileX) { _tileX = tileX; }
	void setTIleY(UINT tileY) { _tileY = tileY; }

	bool getIsActive() { return _isActive; }
	void setIsActive(bool active) { _isActive = active; }

	bool getIsBallUp() { return _isBallUp; }
	void setIsBallUp(bool ballUp) { _isBallUp = ballUp; }

	void setSceneName(string name) { _sceneName = name; }
};

