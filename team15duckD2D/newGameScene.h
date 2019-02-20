#pragma once
#include "gameNode.h"

class newGameScene : public gameNode
{
private:
	enum NEWPLAYER
	{
		NEWPLAYER_GENDER,
		NEWPLAYER_NAME
	};

	NEWPLAYER _step;


	bool _isMan;

	string _name;

	string _nameSample[15];

	int _nameSelectNum;



public:
	newGameScene();
	~newGameScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

