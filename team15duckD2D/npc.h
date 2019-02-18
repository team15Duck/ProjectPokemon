#pragma once
class npc
{
private:

	string		_sceneName;						//등장할 씬이름
	string		_npcName;						//엔피씨이름
	UINT		_tileX;							//위치
	UINT		_tileY;							//위치



public:
	npc();
	~npc();

	HRESULT init(string sceneName);
	void release();
	void update();
	void render();

	void settingNPC();
};

