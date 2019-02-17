#pragma once
class npc
{
public:
	npc();
	~npc();

	HRESULT init();
	void release();
	void update();
	void render();
};

