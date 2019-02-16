#pragma once
#include <queue>

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



public:
	battleUI();
	~battleUI();

	HRESULT init();
	void release();
	void update();
	void render();

	void pushScript(wstring script);

	bool battleSceneUpdate();			//��� ��µɶ��� ������Ʈ�ȵǰ� �Ұ��帱����


	void setScriptSkip(bool skip) { _isSkip = skip; }

	void setPokemonName(wstring name) { _pokemonName = name; }
	void setEnemyName(wstring name) { _enemyName = name; }


	UINT getCurrentSelectMenuNum() { return _currentSelectMenu; }
	void setCurrentSelctMenuNum(UINT num) { _currentSelectMenu = num; }



};

