#pragma once
class baseUI
{
public:
	baseUI();
	~baseUI();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void uiOpen();
	virtual void uiClose();
};

