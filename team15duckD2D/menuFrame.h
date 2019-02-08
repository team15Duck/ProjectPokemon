#pragma once
class menuFrame
{
public:

	typedef struct tagMenuFrameInfo
	{
		UINT frameWidth		= NULL;
		UINT frameHeight	= NULL;
		UINT destX			= NULL;
		UINT destY			= NULL;
	}MENU_FRAME_INFO, *LPMENU_FRMAE_INFO;


private:
	LPMENU_FRMAE_INFO _menuFrameInfo;
public:
	menuFrame();
	~menuFrame();

	HRESULT init(UINT destX, UINT destY, UINT frameWidth, UINT frameHeight);
	void release();

	void render(string imageName);



};

