#pragma once
#include "gameNode.h"
#include "baseUI.h"
#include "item.h"

enum CUSSOR_SELECT
{
	POKEMON_BOOK = 1,
	MY_POKEMON,
	BAG_ITEM,
	PLAYER,
	SAVE_REPORT,
	SETTING,
	CLOSE,
	NONE
};
class mainUi : public baseUI
{
private:

	CUSSOR_SELECT _menu_Select;
	UINT _uiType;

public:
	mainUi();
	~mainUi();

	HRESULT init();
	void release();
	void update();
	void render();

	UINT getUiType() { return _uiType; }
};

