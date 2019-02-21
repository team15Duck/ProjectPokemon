#pragma once
#include "singletonBase.h"
#include "baseUI.h"
#include "mainUi.h"
#include "IllustratedBook.h"
#include "possessionPokemon.h"
#include "bag.h"
#include "ui_player.h"
#include "report.h"
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
	UI_TYPE _beforeUI;

	bool _isuiopen;

public:
	uiManager();
	~uiManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void uiDataSetting();

	void selectUI(UI_TYPE type) { _currentUI = type; }
	void selecBeforeUI(UI_TYPE type) { _beforeUI = type; }
	void moveBeforeUI();
	map<UI_TYPE, baseUI*> getUiMap() { return _uiMap; }

	bool getUiUse() { return _isuiopen; }

};

