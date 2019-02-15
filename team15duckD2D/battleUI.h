#pragma once
#include <queue>

class battleUI
{
private:
	queue<wstring> _script;
	UINT _scriptLength;
	wstring _viewScript;
	float _scriptCount;
	float _scriptDelay;

public:
	battleUI();
	~battleUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void pushScript(wstring script);

	bool battleSceneUpdate();			//대사 출력될때는 업데이트안되게 불값드릴거임


};

