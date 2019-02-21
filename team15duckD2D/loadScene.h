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
	//화살표의 시작점
	float			_startPointX;
	float			_startPointY;
	//화살표의 현재 지점
	float			_pointPosX;
	float			_pointPosY;
	//좌우 키 누르기 전에 save쪽에 있던 좌표를 저장해야해영
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

