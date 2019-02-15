#pragma once

enum SETTING_MENU
{
	BACKGROUND_MUSIC = 1,
	EFFECT_SOUND,
	FRAMETYPE,
	SM_SELECT,
};

class setting
{
private:

	UINT _currentSelectNum;
	SETTING_MENU _smenu;

public:
	setting();
	~setting();

	HRESULT init();
	void release();
	void update();
	void render();
};

