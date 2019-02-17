#pragma once
#include <queue>
#include <vector>

typedef struct tagPokemonSkillUIInfo
{
	wstring skillName;
	UINT currentPP;
	UINT maxPP;
}SKILLUI;

enum BATTLEUI_MENU
{
	BATTLEUI_MENU_SKILL,
	BATTLEUI_MENU_BAG,
	BATTLEUI_MENU_POKEMON,
	BATTLEUI_MENU_RUN,
	BATTLEUI_MENU_NONE
};


class battleUI
{
private:

	queue<wstring>		_script;						//��ũ��Ʈ�� �����ϴ� ť! ���⿡ ������ ��������� �ٸ��༮�� �ƹ��͵� �Ҽ������� 
	UINT				_scriptLength;					//���� ������� ��ũ��Ʈ�� ���� ���ڸ� ������� �����ֱ� ����
	wstring				_viewScript;					//������ ��ũ��Ʈ��ŭ ���� �����ؿͼ� �����Ŵ�
	float				_scriptCount;					//��ũ��Ʈ ����ӵ��� üũ
	float				_scriptDelay;					//��ũ��Ʈ ����ӵ��� ����
	bool				_isSkip;						//�̽�ũ��Ʈ ��ŵ������?
	wstring				_pokemonName;					//�����ϸ��� �̸�
	wstring				_enemyName;						//�����ϸ��� �̸�
	UINT				_currentSelectMenu;				//���� ������ �޴��� ���ڴ�?

	vector<SKILLUI>		_skillUI;						//��ų������������ִ� ����ü�� ����  �ִ������� 4�� �����Ѵ�
	UINT				_currentSelectSkill;			//���� ���ų�� �����ϰ� �ִ�?

	BATTLEUI_MENU		_currentMenu;					//���� �޴� ����

public:
	battleUI();
	~battleUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void skillUIClear() { _skillUI.clear(); }
	void addSkill(wstring skillName, UINT cPP, UINT mPP)
	{
		SKILLUI skill;
		skill.skillName = skillName;
		skill.currentPP = cPP;
		skill.maxPP = mPP;
	}
	UINT getCurrentPP(UINT skillNum)
	{
		if (skillNum < 0 || skillNum >= _skillUI.size()) return 0;

		_skillUI[skillNum].currentPP;
	}
	void setCurrentPP(UINT skillNum)
	{
		if (skillNum < 0 || skillNum >= _skillUI.size()) return;

		_skillUI[skillNum].currentPP--;
		if (_skillUI[skillNum].currentPP < 0) _skillUI[skillNum].currentPP = 0;
	}





	void pushScript(wstring script);

	bool battleSceneUpdate();			//��� ��µɶ��� ������Ʈ�ȵǰ� �Ұ��帱����


	void setScriptSkip(bool skip) { _isSkip = skip; }

	void setPokemonName(wstring name) { _pokemonName = name; }
	void setEnemyName(wstring name) { _enemyName = name; }


	UINT getCurrentSelectMenuNum() { return _currentSelectMenu; }
	void setCurrentSelctMenuNum(UINT num) { _currentSelectMenu = num; }
};

