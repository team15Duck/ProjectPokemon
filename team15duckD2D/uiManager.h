#pragma once
#include "singletonBase.h"
#include "baseUI.h"
#include "IllustratedBook.h"


enum UI_TYPE
{
	UI_MAIN,
	UI_BAG,
	UI_ILLUST,

	UI_NONE,
};

class uiManager : public singletonBase<uiManager>
{
private:
	map<UI_TYPE, baseUI*> _uiMap;

	UI_TYPE _currentUI;

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();


	void selectUI(UI_TYPE type) { _currentUI = type; }
};

