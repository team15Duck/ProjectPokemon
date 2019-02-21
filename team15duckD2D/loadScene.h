#pragma once
#include "gameNode.h"

enum LOAD_DATA
{
	LOAD_DATA_1,
	LOAD_DATA_2,
	LOAD_DATA_3,
	LOAD_DATA_4,
	LOAD_DATA_5,
	LOAD_DATA_6,

	LOAD_END
};

class loadScene : public gameNode
{
private:
	int			_select;
	//ȭ��ǥ�� ������
	float			_startPointX;
	float			_startPointY;
	//ȭ��ǥ�� ���� ����
	float			_pointPosX;
	float			_pointPosY;
	//�¿� Ű ������ ���� save�ʿ� �ִ� ��ǥ�� �����ؾ��ؿ�
	float			_storePosX;
	float			_storePosY;

	bool			_isSaveLocation;
	bool			_isData;

	

public:
	loadScene();
	~loadScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void loadPlayData(int dataNum);



};

