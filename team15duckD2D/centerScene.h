#pragma once
#include "centerMap.h"
#include "gameNode.h"
#include "npc.h"
#include "object.h"

enum CENTER_TALK
{
	CENTER_TALK_HEAL,
	CENTER_TALK_HEALING,
	CENTER_TALK_NOPE_OR_BYE,

	CENTER_TALK_NONE,
	CENTER_TALK_COUNT = CENTER_TALK_NONE
};

class centerScene : public gameNode
{
private:
	mapData* _centerMap;
	npc*	_npc;
	object* _obj;


	bool				_isTalk;						//NPC랑 얘기하니
	bool				_isVisible;						//대사 가리기용
	CENTER_TALK			_centerTalk;					//상태

public:
	centerScene();
	~centerScene();

	HRESULT init();
	void release();
	void update();
	void render();

	void centerHeal();
	void centerHealing();
	void centerNopeBye();

};

