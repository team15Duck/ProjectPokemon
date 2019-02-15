#pragma once

enum SETTING_MENU
{
	BACKGROUND_MUSIC = 1,
	EFFECT_SOUND,
	FRAMETYPE,
	SM_SELECT,
};

enum SETTING_FRAME_TYPE
{
	SETTING_FRAME_TYPE1,
	SETTING_FRAME_TYPE2,
	SETTING_FRAME_TYPE3,
	SETTING_FRAME_TYPE4,
	SETTING_FRAME_TYPE5,
	SETTING_FRAME_TYPE6,
	SETTING_FRAME_TYPE7,
	SETTING_FRAME_TYPE8,
	SETTING_FRAME_TYPE9,
	SETTING_FRAME_TYPE10

};
class setting
{
private:

	UINT _currentSelectNum;
	SETTING_MENU _smenu;
	SETTING_FRAME_TYPE _sframeType;
public:
	setting();
	~setting();

	HRESULT init();
	void release();
	void update();
	void render();

	SETTING_FRAME_TYPE getframeType() { return _sframeType; }
	void setframeType(SETTING_FRAME_TYPE sframeType);
};

