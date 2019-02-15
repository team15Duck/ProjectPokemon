#pragma once
#include "singletonBase.h"
#include "menuFrame.h"
#include <map>


class menuFrameManager : public singletonBase<menuFrameManager>
{
public:
	typedef map<string, menuFrame*>			 mapMenuFrameList;
	typedef map<string, menuFrame*>::iterator mapMenuFrameIter;

private:

	mapMenuFrameList _mMenuFrameList;

	map<int, string> _frameNameMap;
	int				_frameIndex;


public:
	menuFrameManager();
	~menuFrameManager();

	HRESULT init();
	void release();

	menuFrame* addFrame(string key, UINT destX, UINT destY, UINT frameWidth, UINT frameHeight);
	menuFrame* findMenuFrame(string key);
	void render(string key, string imgName);

	string getFrameName(int type) { return _frameNameMap[type]; }

	int getFrameType() { return _frameIndex; }
	void setFrameType(int type) { _frameIndex = type; }

};

