#pragma once
#include <vector>
#include "tileNode.h"

//�ʵ��� �̰� ��ӹ޾Ƽ� �����.
class mapData
{
private:
	UINT						TILEX;							//Ÿ�ϰ��ΰ���
	UINT						TILEY;							//Ÿ�ϼ��ΰ���
	vector<vector<tagTile*>>	_vvTile;						//Ÿ���� ��� �ִ� ����
	player*						_player;						//�÷��̾ ����Ű�� �ִ� �����ͺ���



	UINT						ii;								//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						iiMax;							//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						jj;								//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
	UINT						jjMax;							//������ for���� �� ���� ���� �̳༮���� ������ �ش�.
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
	//�ټ�
	tagTile* getTile(UINT x, UINT y) { return _vvTile[y][x]; }



};

