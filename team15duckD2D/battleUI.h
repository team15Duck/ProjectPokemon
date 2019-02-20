#pragma once
#include <queue>
#include <vector>

typedef struct tagPokemonSkillUIInfo
{
	wstring skillName;
	UINT currentPP;
	UINT maxPP;
	wstring type;
}SKILLUI;

enum BATTLE_UI
{
	BATTLE_UI_SKILL,
	BATTLE_UI_BAG,
	BATTLE_UI_POKEMON,
	BATTLE_UI_RUN,
	BATTLE_UI_NONE
};

class pokemon;
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


	bool				_isEscape;						//����?
	bool				_isPlayerTurn;					//�÷��̾� �ൿ ��?
	bool				_isBattle;						//��Ʋ���ΰ�
	bool				_isKeyDownZ;					//ZŰ�� ���ȴ°�
	BATTLE_UI			_currentMenu;					//���� �޴� ����

	pokemon*			_myPokemon;						//������ ����ϱ� ����
	pokemon*			_enemyPokemon;					//������ ����ϱ� ����

public:
	battleUI();
	~battleUI();

	HRESULT init();
	void release();
	void update();
	void render();



	void skillUIClear() { _skillUI.clear(); }
	void addSkill(wstring skillName, UINT cPP, UINT mPP, wstring type)
	{
		SKILLUI skill;
		skill.skillName = skillName;
		skill.currentPP = cPP;
		skill.maxPP = mPP;
		skill.type = type;
		_skillUI.push_back(skill);
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
	UINT getSkillSize() { return _skillUI.size(); }


	BATTLE_UI getCurrentMenu() { return _currentMenu; }
	void setCurrentMenu(BATTLE_UI cMenu) { _currentMenu = cMenu; }


	void pushScript(wstring script);

	bool battleSceneUpdate();			//��� ��µɶ��� ������Ʈ�ȵǰ� �Ұ��帱����


	void setScriptSkip(bool skip) { _isSkip = skip; }

	void setPokemonName(wstring name) { _pokemonName = name; }
	void setEnemyName(wstring name) { _enemyName = name; }


	UINT getCurrentSelectMenuNum() { return _currentSelectMenu; }
	void setCurrentSelctMenuNum(UINT num) { _currentSelectMenu = num; }

	UINT getCurrentSelectSkill() { return _currentSelectSkill; }
	void setCurrentSelectSkill(UINT num) { _currentSelectSkill = num; }


	void setMyPokemonMemoryAdressLink(pokemon* m) { _myPokemon = m; }
	void setEnemyPokemonMemoryAdressLink(pokemon* e) { _enemyPokemon = e; }

	void setIsPlayerTurn(bool isPlayerTurn) { _isPlayerTurn = isPlayerTurn;	}
	void setIsBattle(bool isBattle)			{ _isBattle = isBattle;			}

	bool isKeyDownKeyZ() { return _isKeyDownZ; }
};

