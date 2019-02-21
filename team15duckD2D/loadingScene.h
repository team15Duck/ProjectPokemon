#pragma once
#include "gameNode.h"

#define LOADINGMAX 236

//모든데이터 로딩하고 스타트씬으로 넘어감
class loadingScene : public gameNode
{
private:
	image* _backGround;
	animation* _ani;

	float _loadingBar;


public:
	loadingScene();
	~loadingScene();

	int _currentCount;	//외부에서 접근할수있게 해둔당

	HRESULT init();
	void release();
	void update();
	void render();
};

static DWORD CALLBACK ThreadFunction(LPVOID lpParameter);

