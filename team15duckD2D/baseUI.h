#pragma once
class baseUI
{
protected:
	//UI_TYPE _type;

public:
	baseUI();
	~baseUI();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	virtual void uiOpen();
	virtual void uiClose();

	virtual void uiInfoSet();
};

