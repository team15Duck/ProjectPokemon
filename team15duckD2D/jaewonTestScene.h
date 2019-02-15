#pragma once
#include "gameNode.h"
#include "soundFile.h"
#include <commdlg.h>


class jaewonTestScene : public gameNode
{
private:
	string				_bgmKey;
	string				_effectKey;

	string				_soundKeys[3];
	int						_idx;
	
	string _imgKeys[3];


public:
	jaewonTestScene();
	~jaewonTestScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

