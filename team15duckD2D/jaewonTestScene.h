#pragma once
#include "gameNode.h"
#include "soundFile.h"
#include <commdlg.h>


class jaewonTestScene : public gameNode
{
private:
	string				_bgmKey;
	string				_effectKey;


public:
	jaewonTestScene();
	~jaewonTestScene();

	HRESULT init();
	void release();
	void update();
	void render();

};

