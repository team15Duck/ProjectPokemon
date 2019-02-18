#pragma once
#include "singletonBase.h"
#include <queue>

class scriptManager : public singletonBase<scriptManager>
{

	queue<wstring>		_script;						//��ũ��Ʈ�� �����ϴ� ť! ���⿡ ������ ��������� �ٸ��༮�� �ƹ��͵� �Ҽ������� 
	UINT				_scriptLength;					//���� ������� ��ũ��Ʈ�� ���� ���ڸ� ������� �����ֱ� ����
	wstring				_viewScript;					//������ ��ũ��Ʈ��ŭ ���� �����ؿͼ� �����Ŵ�
	float				_scriptCount;					//��ũ��Ʈ ����ӵ��� üũ
	float				_scriptDelay;					//��ũ��Ʈ ����ӵ��� ����
	bool				_isSkip;						//�̽�ũ��Ʈ ��ŵ������?

public:
	scriptManager();
	~scriptManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void pushScript(wstring script);

	bool isUpdate();										//��� ��µɶ��� ������Ʈ�ȵǰ� �Ұ��帱����

	void setScriptSkip(bool skip) { _isSkip = skip; }		//� ��縦 ����ϴµ� ��ŵ�� �����ϰ� ���������� �߰��� �̳༮�� Ʈ�縦 �־���


};

