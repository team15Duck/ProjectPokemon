#pragma once
#include "baseUI.h"
typedef struct tagUiPlayer
{
	wstring name;	//¿Ã∏ß
	wstring money;	//µ∑
	wstring time;	//Ω√∞£

}UIPLAYER;
class ui_player : public baseUI
{
private:
	
	UIPLAYER _uiplayer;

public:
	ui_player();
	~ui_player();

	HRESULT init();
	void release();
	void update();
	void render();

	void uiDataSetting();
	void playerDataSet();
};

