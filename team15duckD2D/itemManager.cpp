#include "stdafx.h"
#include "itemManager.h"


itemManager::itemManager()
{
}


itemManager::~itemManager()
{
}

HRESULT itemManager::init()
{
	_vItems.clear();
	// ==============================================================
	// 1. �������� ���ǰ�� �ִ�. �׸��� ���԰��� 0 / �ǸŰ� ����
	// 2. value���� �ӵ�, ���� ���� Ȯ�� �� �ʿ��ϴ�.
	// 3. ������ �̹����� ��� UI�� ��ġ�� �����ϴ�. (����, ����, �����ý���)
	// 4. ���ϸ��� ��ȹ���� ��� �Ұ��� �����غ���
	// ==============================================================
	IMAGEMANAGER->addFrameImage("items", L"image/items.png", 2600, 100, 26, 1);
	IMAGEMANAGER->addImage("�׽�Ʈ11", L"image/test/ccc.png", 960, 640);
	
	initItems();
	_choiceItem = MONSTER_BALL;

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	//�ӽÿ�
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		switch (_choiceItem)
		{
			case MONSTER_BALL:
				_choiceItem = SUPER_BALL;
				break;
			case SUPER_BALL:
				_choiceItem = HYPER_BALL;
				break;
			case HYPER_BALL:
				_choiceItem = MASTER_BALL;
				break;
			case MASTER_BALL:
				_choiceItem = MONSTER_BALL;
				break;
		}

	}
}

void itemManager::render()
{
	IMAGEMANAGER->render("�׽�Ʈ11", 0 + CAMERA->getPosX(), 0 + +CAMERA->getPosY(), 1.0f);
	_vItems[_choiceItem]->render();
}

void itemManager::initItems()
{
	//����������, ���밪, (�����̻��?), ����, �Ǹ�, ����, (��𼭿��� �����?)

	//���ͺ�(���밪 �����Ұ�)
	item* monsterBall = new item;
	monsterBall->init("���ͺ�", MONSTER_BALL, 10, 200, 100, 1);
	_vItems.push_back(monsterBall);

	//���ۺ�(���밪 �����Ұ�)
	item* superBall = new item;
	superBall->init("���ۺ�", SUPER_BALL, 20, 600, 300, 1);
	_vItems.push_back(superBall);

	//�����ۺ�(���밪 �����Ұ�)
	item* hyperBall = new item;
	hyperBall->init("�����ۺ�", HYPER_BALL, 30, 1200, 600, 1);
	_vItems.push_back(hyperBall);

	//�����ͺ�
	item* masterBall = new item;
	masterBall->init("�����ͺ�", MASTER_BALL, 999, 50000, 25000, 1);
	_vItems.push_back(masterBall);

	//��ó��
	item* normalPotion = new item;
	normalPotion->init("��ó��", NORMAL_POTION, 20, 300, 150, 1);
	_vItems.push_back(normalPotion);

	//������ó��
	item* superPotion = new item;
	superPotion->init("������ó��", SUPER_POTION, 60, 700, 350, 1);
	_vItems.push_back(superPotion);

	//��޻�ó��
	item* hyperPotion = new item;
	hyperPotion->init("��޻�ó��", HYPER_POTION, 120, 1200, 600, 1);
	_vItems.push_back(hyperPotion);

	//Ǯȸ����
	item* maxPotion = new item;
	maxPotion->init("Ǯȸ����", MAX_POTION, 999, 1200, 600, 1);
	_vItems.push_back(maxPotion);

	//ȸ����(�����̻� ��������ϴµ�..?)
	item* fullRestore = new item;
	fullRestore->init("ȸ����", FULL_RESTORE, 999, 3000, 1500, 1);
	_vItems.push_back(fullRestore);

	//PP���̵�
	item* normalEther = new item;
	normalEther->init("PP���̵�", NORMAL_ETHER, 10, 0, 600, 1);
	_vItems.push_back(normalEther);

	//PPȸ��
	item* maxEther = new item;
	maxEther->init("PPȸ��", MAX_ETHER, 255, 0, 1000, 1);
	_vItems.push_back(maxEther);

	//PP���̴�
	item* normalElixir = new item;
	normalElixir->init("PP���̴�", NORMAL_ELIXIR, 10, 0, 1500, 1);
	_vItems.push_back(normalElixir);

	//PPȸ��
	item* maxElixir = new item;
	maxElixir->init("PP�ƽ�", MAX_ELIXIR, 255, 0, 2250, 1);
	_vItems.push_back(maxElixir);

	//�����̻� POKEMON_UPSET_CONDITION���� Ȯ��
	//�ص���
	item* antidote = new item;
	antidote->init("�ص���", ANTIDOTE, 1, 100, 50, 1);
	_vItems.push_back(antidote);

	//����ġ����
	item* parlyzeHeal = new item;
	parlyzeHeal->init("����ġ����", PARLYZE_HEAL, 1, 200, 100, 1);
	_vItems.push_back(parlyzeHeal);

	//ȭ��ġ����
	item* burnHeal = new item;
	burnHeal->init("ȭ��ġ����", BURN_HEAL, 1, 250, 125, 1);
	_vItems.push_back(burnHeal);

	//��������ġ����
	item* iceHeal = new item;
	iceHeal->init("��������ġ����", ICE_HEAL, 1, 250, 125, 1);
	_vItems.push_back(iceHeal);

	//����¾�
	item* awakening = new item;
	awakening->init("����¾�", AWAKENING, 1, 250, 125, 1);
	_vItems.push_back(awakening);

	//������ġ��
	item* fullHeal = new item;
	fullHeal->init("������ġ��", FULL_HEAL, 1, 600, 300, 1);
	_vItems.push_back(fullHeal);

	//�̻��ѻ���
	item* rareCandy = new item;
	rareCandy->init("�̻��ѻ���", RARE_CANDY, 1, 0, 2400, 1);
	_vItems.push_back(rareCandy);

	//����Ż�����
	item* escapeRope = new item;
	escapeRope->init("����Ż�����", ESCAPE_ROPE, 1, 0, 2400, 1);
	_vItems.push_back(escapeRope);

	//���������
	item* revive = new item;
	revive->init("����� ����", REVIVE, 255, 1500, 750, 1);
	_vItems.push_back(revive);

	//������
	item* bicycle = new item;
	bicycle->init("������", BICYCLE, 2, 0, 0, 1);
	_vItems.push_back(bicycle);

	//���ô�
	item* fishingRod= new item;
	fishingRod->init("���ô�", FISHING_ROD, 255, 0, 0, 1);
	_vItems.push_back(fishingRod);

	//Ÿ���
	item* townMap = new item;
	townMap->init("���ô�", TOWN_MAP, 255, 0, 0, 1);
	_vItems.push_back(townMap);

	//����ӽ����̽�

	item* tmCase = new item;
	tmCase->init("����ӽ����̽�", TM_CASE, 255, 0, 0, 1);
	_vItems.push_back(tmCase);
}
