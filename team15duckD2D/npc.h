#pragma once
class npc
{
private:

	string		_sceneName;						//������ ���̸�
	string		_npcName;						//���Ǿ��̸�
	UINT		_tileX;							//��ġ
	UINT		_tileY;							//��ġ



public:
	npc();
	~npc();

	HRESULT init(string sceneName);
	void release();
	void update();
	void render();

	void settingNPC();
};

