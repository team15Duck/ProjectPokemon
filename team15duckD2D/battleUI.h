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

	bool _isSkip;


public:
	battleUI();
	~battleUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void pushScript(wstring script);

	bool battleSceneUpdate();			//��� ��µɶ��� ������Ʈ�ȵǰ� �Ұ��帱����


	void setScriptSkip(bool skip) { _isSkip = skip; }

};

