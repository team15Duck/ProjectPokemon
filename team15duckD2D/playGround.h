#pragma once
#include "gameNode.h"
#include "chiyeongTestScene.h"
#include "hayoungTestScene.h"
#include "mapToolScene.h"
#include "mapTestScene.h"
#include "objectToolScene.h"
#include "battleScene.h"
#include "battleScene2.h"

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