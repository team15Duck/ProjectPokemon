#pragma once
#include <vector>
#include "tileNode.h"

//맵들은 이거 상속받아서 사용함.
class mapData
{
private:
	UINT						TILEX;							//타일가로갯수
	UINT						TILEY;							//타일세로갯수
	vector<vector<tagTile*>>	_vvTile;						//타일을 담고 있는 벡터
	player*						_player;						//플레이어를 가르키고 있는 포인터변수



	UINT						ii;								//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						iiMax;							//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						jj;								//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
	UINT						jjMax;							//렌더시 for문을 덜 돌기 위해 이녀석들을 세팅해 준다.
public:
	mapData();
	~mapData();
	
	virtual HRESULT init(const char* mapSizeFileName, const char* mapFileName);
	virtual void release();
	virtual void update();
	virtual void render();
	virtual void load(const char* mapSizeFileName, const char* mapFileName);

	virtual void setPlayerMemoryAdressLink(player* p) { _player = p; }





public:
	//겟셋
	tagTile* getTile(UINT x, UINT y) { return _vvTile[y][x]; }



};

