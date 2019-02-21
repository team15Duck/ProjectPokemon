#pragma once
#include "gameNode.h"
#include "chiyeongTestScene.h"
#include "hayoungTestScene.h"
#include "mapToolScene.h"
#include "mapTestScene.h"
#include "objectToolScene.h"
#include "battleScene.h"
#include "battleScene2.h"
#include "startScene.h"
#include "loadScene.h"
#include "caveScene.h"
#include "centerScene.h"
#include "fieldScene.h"
#include "gymScene.h"
#include "homeScene.h"
#include "oLabScene.h"
#include "storeScene.h"
#include "townScene.h"
#include "newGameScene.h"
#include "endingScene.h"

#define LOADINGMAX 255
#define SLEEPCOUNT 1

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

