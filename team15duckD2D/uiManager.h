#pragma once
#include "singletonBase.h"
#include "baseUI.h"
#include "IllustratedBook.h"
#include "possessionPokemon.h"
#include "bag.h"
#include "setting.h"

enum UI_TYPE
{
	UI_MAIN,
	UI_ILLUST,
	UI_POKEMON,
	UI_BAG,
	UI_PLAYER,
	UI_REPORT,
	UI_SETTING,

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
