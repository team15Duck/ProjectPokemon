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
	// 1. 아이템은 비매품도 있다. 그르면 구입가는 0 / 판매가 설정
	// 2. value에는 속도, 몬스터 잡을 확률 등 필요하다.
	// 3. 아이템 이미지는 어느 UI든 위치가 동일하다. (상점, 가방, 도구시스템)
	// 4. 포켓몬볼은 포획률을 어떻게 할건지 생각해볼것
	// ==============================================================
	IMAGEMANAGER->addFrameImage("items", L"image/items.png", 2600, 100, 26, 1);
	IMAGEMANAGER->addImage("테스트11", L"image/test/ccc.png", 960, 640);
	
	initItems();
	_choiceItem = MONSTER_BALL;

	return S_OK;
}

void itemManager::release()
{
}

void itemManager::update()
{
	//임시용
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
	IMAGEMANAGER->render("테스트11", 0 + CAMERA->getPosX(), 0 + +CAMERA->getPosY(), 1.0f);
	_vItems[_choiceItem]->render();
}

void itemManager::initItems()
{
	//아이템종류, 적용값, (상태이상용?), 구입, 판매, 개수, (어디서에서 사용중?)

	//몬스터볼(적용값 변경할것)
	item* monsterBall = new item;
	monsterBall->init("몬스터볼", MONSTER_BALL, 10, 200, 100, 1);
	_vItems.push_back(monsterBall);

	//슈퍼볼(적용값 변경할것)
	item* superBall = new item;
	superBall->init("슈퍼볼", SUPER_BALL, 20, 600, 300, 1);
	_vItems.push_back(superBall);

	//하이퍼볼(적용값 변경할것)
	item* hyperBall = new item;
	hyperBall->init("하이퍼볼", HYPER_BALL, 30, 1200, 600, 1);
	_vItems.push_back(hyperBall);

	//마스터볼
	item* masterBall = new item;
	masterBall->init("마스터볼", MASTER_BALL, 999, 50000, 25000, 1);
	_vItems.push_back(masterBall);

	//상처약
	item* normalPotion = new item;
	normalPotion->init("상처약", NORMAL_POTION, 20, 300, 150, 1);
	_vItems.push_back(normalPotion);

	//좋은상처약
	item* superPotion = new item;
	superPotion->init("좋은상처약", SUPER_POTION, 60, 700, 350, 1);
	_vItems.push_back(superPotion);

	//고급상처약
	item* hyperPotion = new item;
	hyperPotion->init("고급상처약", HYPER_POTION, 120, 1200, 600, 1);
	_vItems.push_back(hyperPotion);

	//풀회복약
	item* maxPotion = new item;
	maxPotion->init("풀회복약", MAX_POTION, 999, 1200, 600, 1);
	_vItems.push_back(maxPotion);

	//회복약(상태이상도 없애줘야하는데..?)
	item* fullRestore = new item;
	fullRestore->init("회복약", FULL_RESTORE, 999, 3000, 1500, 1);
	_vItems.push_back(fullRestore);

	//PP에이드
	item* normalEther = new item;
	normalEther->init("PP에이드", NORMAL_ETHER, 10, 0, 600, 1);
	_vItems.push_back(normalEther);

	//PP회복
	item* maxEther = new item;
	maxEther->init("PP회복", MAX_ETHER, 255, 0, 1000, 1);
	_vItems.push_back(maxEther);

	//PP에이더
	item* normalElixir = new item;
	normalElixir->init("PP에이더", NORMAL_ELIXIR, 10, 0, 1500, 1);
	_vItems.push_back(normalElixir);

	//PP회복
	item* maxElixir = new item;
	maxElixir->init("PP맥스", MAX_ELIXIR, 255, 0, 2250, 1);
	_vItems.push_back(maxElixir);

	//상태이상 POKEMON_UPSET_CONDITION에서 확인
	//해독제
	item* antidote = new item;
	antidote->init("해독제", ANTIDOTE, 1, 100, 50, 1);
	_vItems.push_back(antidote);

	//마비치료제
	item* parlyzeHeal = new item;
	parlyzeHeal->init("마비치료제", PARLYZE_HEAL, 1, 200, 100, 1);
	_vItems.push_back(parlyzeHeal);

	//화상치료제
	item* burnHeal = new item;
	burnHeal->init("화상치료제", BURN_HEAL, 1, 250, 125, 1);
	_vItems.push_back(burnHeal);

	//얼음상태치료제
	item* iceHeal = new item;
	iceHeal->init("얼음상태치료제", ICE_HEAL, 1, 250, 125, 1);
	_vItems.push_back(iceHeal);

	//잠깨는약
	item* awakening = new item;
	awakening->init("잠깨는약", AWAKENING, 1, 250, 125, 1);
	_vItems.push_back(awakening);

	//만병통치제
	item* fullHeal = new item;
	fullHeal->init("만병통치제", FULL_HEAL, 1, 600, 300, 1);
	_vItems.push_back(fullHeal);

	//이상한사탕
	item* rareCandy = new item;
	rareCandy->init("이상한사탕", RARE_CANDY, 1, 0, 2400, 1);
	_vItems.push_back(rareCandy);

	//동굴탈출로프
	item* escapeRope = new item;
	escapeRope->init("동굴탈출로프", ESCAPE_ROPE, 1, 0, 2400, 1);
	_vItems.push_back(escapeRope);

	//기력의조각
	item* revive = new item;
	revive->init("기력의 조각", REVIVE, 255, 1500, 750, 1);
	_vItems.push_back(revive);

	//자전거
	item* bicycle = new item;
	bicycle->init("자전거", BICYCLE, 2, 0, 0, 1);
	_vItems.push_back(bicycle);

	//낚시대
	item* fishingRod= new item;
	fishingRod->init("낚시대", FISHING_ROD, 255, 0, 0, 1);
	_vItems.push_back(fishingRod);

	//타운맵
	item* townMap = new item;
	townMap->init("낚시대", TOWN_MAP, 255, 0, 0, 1);
	_vItems.push_back(townMap);

	//기술머신케이스

	item* tmCase = new item;
	tmCase->init("기술머신케이스", TM_CASE, 255, 0, 0, 1);
	_vItems.push_back(tmCase);
}
