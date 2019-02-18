#pragma once
#include "baseUI.h"

enum SETTING_MENU
{
	BACKGROUND_MUSIC = 1,
	EFFECT_SOUND,
	FRAMETYPE,
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

enum SETTING_BACKGROOUND_MUSIC
{
	BG_SOUND_0,
	BG_SOUND_1,
	BG_SOUND_2,
	BG_SOUND_3,
	BG_SOUND_4,
	BG_SOUND_5,
	BG_SOUND_6,
	BG_SOUND_7,
	BG_SOUND_8,
	BG_SOUND_9,
	BG_SOUND_10
};

enum SETTING_EFFECT_SOUND
{
	E_SOUND_0,
	E_SOUND_1,
	E_SOUND_2,
	E_SOUND_3,
	E_SOUND_4,
	E_SOUND_5,
	E_SOUND_6,
	E_SOUND_7,
	E_SOUND_8,
	E_SOUND_9,
	E_SOUND_10,
};
class setting : public baseUI
{
private:

	UINT						_currentSelectNum;

	SETTING_MENU				_smenu;				//∏ﬁ¥∫
	SETTING_FRAME_TYPE			_sframeType;		//«¡∑π¿”≈∏¿‘
	SETTING_BACKGROOUND_MUSIC	_sbgMusic;			//πË∞Ê ¿Ωæ«
	SETTING_EFFECT_SOUND		_seffSound;			//¿Ã∆Â∆Æ ¿Ωæ«


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

