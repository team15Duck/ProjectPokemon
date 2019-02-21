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


class playGround : public gameNode
{
private:

public:
	playGround();
	~playGround();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};