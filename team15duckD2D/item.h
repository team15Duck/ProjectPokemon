#pragma once
#include "pokemonInfo.h"

enum ITEM_TYPE
{
	//포켓몬은 현재 체력이 30퍼 미만이면 무조건 잡히고
	//그 이상이면 포켓몬볼의 포획률에 따라 잡힌다.
	MONSTER_BALL,				//몬스터볼
	SUPER_BALL,					//슈퍼볼
	HYPER_BALL,					//하이퍼볼
	MASTER_BALL,				//마스터볼

	NORMAL_POTION,				//상처약(20회복)
	SUPER_POTION,				//좋은상처약(60회복)
	HYPER_POTION,				//고급상처약(120회복)
	MAX_POTION,					//풀회복약(전체회복)
	FULL_RESTORE,				//회복약(전체회복+상태이상)

	NORMAL_ETHER,				//PP에이드(한기술 10회복)
	MAX_ETHER,					//pp회복(한기술 전체회복)
	NORMAL_ELIXIR,				//pp에이더(모든기술 10회복)
	MAX_ELIXIR,					//pp맥스(모든기술 전체회복)

	ANTIDOTE,					//해독제
	PARLYZE_HEAL,				//마비해독제
	BURN_HEAL,					//화상치료제
	ICE_HEAL,					//얼음상태치료제
	AWAKENING,					//잠깨는약
	FULL_HEAL,					//만병통치제				

	RARE_CANDY,					//이상한사탕
	ESCAPE_ROPE,				//동굴탈출로프
	REVIVE,						//기력의 조각

	//중요한 물건
	BICYCLE,					//자전거
	FISHING_ROD,				//낚시대
	TOWN_MAP,					//타운맵

	//비전머신(여러번 사용가능)
	HM_CUT,						//풀베기
	HM_FLASH,					//플래시

	//기술머신(한번만 사용가능)
	TM_THUNDERBOLT,				//10만볼트
	TM_THUNDER,					//번개
	TM_FLAMETHROWER,			//화염방사

	//나무열매
	CHERI_BERRY,				//버치열매(마비회복)
	CHESTO_BERRY,				//유루열매(잠듦회복)
	PECHA_BERRY,				//복슝열매(독회복)
	RAWST_BERRY,				//복분열매(화상회복)
	ASPEAR_BERRY,				//배리열매(동상회복)
	LEPPA_BERRY,				//과사열매(PP10회복)
	ORAN_BERRY,					//오랭열매(체력10회복)
	LUM_BERRY,					//리샘열매(모든상태이상회복)
	SITRUS_BERRY,				//자뭉열매(체력30회복)


	ITEM_TYPE_NONE,

	ITEM_TYPE_COUNT = ITEM_TYPE_NONE

};

enum ITEM_VALUE
{
	//최대적용치는 999, 중요한물건에서의 값 못정한 것은 255
	MONSTER_BALL_VALUE = 3,											   //몬스터볼
	SUPER_BALL_VALUE = 4,											   //슈퍼볼
	HYPER_BALL_VALUE = 5,											   //하이퍼볼
	MASTER_BALL_VALUE = 10,											   //마스터볼

	NORMAL_POTION_VALUE = 20,										   //상처약(20회복)
	SUPER_POTION_VALUE = 50,										   //좋은상처약(60회복)
	HYPER_POTION_VALUE = 120,										   //고급상처약(120회복)
	MAX_POTION_VALUE = 999,											   //풀회복약(전체회복)
	FULL_RESTORE_VALUE = 999,										   //회복약(전체회복+상태이상)

	NORMAL_ETHER_VALUE = 10,										   //PP에이드(한기술 10회복)
	MAX_ETHER_VALUE = 999,											   //pp회복(한기술 전체회복)
	NORMAL_ELIXIR_VALUE = 10,										   //pp에이더(모든기술 10회복)
	MAX_ELIXIR_VALUE = 999,											   //pp맥스(모든기술 전체회복)

	ANTIDOTE_VALUE = POKEMON_UPSET_CONDITION::PMUC_POISON,			   //해독제
	PARLYZE_HEAL_VALUE = POKEMON_UPSET_CONDITION::PMUC_PALALYSIS,	   //마비해독제
	BURN_HEAL_VALUE = POKEMON_UPSET_CONDITION::PMUC_BURN,			   //화상치료제
	ICE_HEAL_VALUE = POKEMON_UPSET_CONDITION::PMUC_FROZEN,			   //얼음상태치료제
	AWAKENING_VALUE = POKEMON_UPSET_CONDITION::PMUC_SLEEP,			   //잠깨는약
	FULL_HEAL_VALUE = 999,											   //만병통치제				

	RARE_CANDY_VALUE = 1,											   //이상한사탕
	ESCAPE_ROPE_VALUE = 1,											   //동굴탈출로프
	REVIVE_VALUE = 255,												   //기력의 조각
	
	//중요한 물건
	BICYCLE_VALUE = 2,												   //자전거
	FISHING_ROD_VALUE = 255,										   //낚시대
	TOWN_MAP_VALUE = 255,											   //타운맵

	HM_CUT_VALUE = 255,												   //풀베기
	HM_FLASH_VALUE = 255,											   //플래시
																	   
	TM_THUNDERBOLT_VALUE = 255,										   //10만볼트
	TM_THUNDER_VALUE = 255,											   //번개
	TM_FLAMETHROWER_VALUE = 255,									   //화염방사
																	   
	CHERI_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_PALALYSIS,	   //버치열매(마비회복)
	CHESTO_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_SLEEP,		   //유루열매(잠듦회복)
	PECHA_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_POISON,		   //복슝열매(독회복)
	RAWST_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_BURN,			   //복분열매(화상회복)
	ASPEAR_BERRY_VALUE = POKEMON_UPSET_CONDITION::PMUC_FROZEN,		   //배리열매(동상회복)
	LEPPA_BERRY_VALUE = 10,											   //과사열매(PP10회복)
	ORAN_BERRY_VALUE = 10,											   //오랭열매(체력10회복)
	LUM_BERRY_VALUE = 999,											   //리샘열매(모든상태이상회복)
	SITRUS_BERRY_VALUE = 30,										   //자뭉열매(체력30회복)
																	   
	ITEM_VALUE_NONE,												   
																	   
	ITEM_VALUE_COUNT = ITEM_VALUE_NONE
};

enum ITEM_BUY_PRICE
{
	MONSTER_BALL_BUY_PRICE = 200,									   //몬스터볼
	SUPER_BALL_BUY_PRICE = 600,										   //슈퍼볼
	HYPER_BALL_BUY_PRICE = 1200,									   //하이퍼볼
	MASTER_BALL_BUY_PRICE = 50000,									   //마스터볼

	NORMAL_POTION_BUY_PRICE = 300,									   //상처약(20회복)
	SUPER_POTION_BUY_PRICE = 700,									   //좋은상처약(60회복)
	HYPER_POTION_BUY_PRICE = 1200,									   //고급상처약(120회복)
	MAX_POTION_BUY_PRICE = 2500,									   //풀회복약(전체회복)
	FULL_RESTORE_BUY_PRICE = 3000,									   //회복약(전체회복+상태이상)

	NORMAL_ETHER_BUY_PRICE = 0,										   //PP에이드(한기술 10회복)
	MAX_ETHER_BUY_PRICE = 0,										   //pp회복(한기술 전체회복)
	NORMAL_ELIXIR_BUY_PRICE = 0,									   //pp에이더(모든기술 10회복)
	MAX_ELIXIR_BUY_PRICE = 0,										   //pp맥스(모든기술 전체회복)

	ANTIDOTE_BUY_PRICE = 100,										   //해독제
	PARLYZE_HEAL_BUY_PRICE = 200,									   //마비해독제
	BURN_HEAL_BUY_PRICE = 250,										   //화상치료제
	ICE_HEAL_BUY_PRICE = 250,										   //얼음상태치료제
	AWAKENING_BUY_PRICE = 250,										   //잠깨는약
	FULL_HEAL_BUY_PRICE = 600,										   //만병통치제				

	RARE_CANDY_BUY_PRICE = 0,										   //이상한사탕
	ESCAPE_ROPE_BUY_PRICE = 0,										   //동굴탈출로프
	REVIVE_BUY_PRICE = 1500,										   //기력의 조각
	BICYCLE_BUY_PRICE = 0,											   //자전거
	FISHING_ROD_BUY_PRICE = 0,										   //낚시대
	TOWN_MAP_BUY_PRICE = 0,											   //타운맵
																	   
	HM_CUT_BUY_PRICE = 0,											   //풀베기
	HM_FLASH_BUY_PRICE = 0,											   //플래시
																	   
	TM_THUNDERBOLT_BUY_PRICE = 3000,								   //10만볼트
	TM_THUNDER_BUY_PRICE = 3000,									   //번개
	TM_FLAMETHROWER_BUY_PRICE = 3000,								   //화염방사
																	   
	CHERI_BERRY_BUY_PRICE = 20,										   //버치열매(마비회복)
	CHESTO_BERRY_BUY_PRICE = 20,									   //유루열매(잠듦회복)
	PECHA_BERRY_BUY_PRICE = 20,										   //복슝열매(독회복)
	RAWST_BERRY_BUY_PRICE = 20,										   //복분열매(화상회복)
	ASPEAR_BERRY_BUY_PRICE = 20,									   //배리열매(동상회복)
	LEPPA_BERRY_BUY_PRICE = 20,										   //과사열매(PP10회복)
	ORAN_BERRY_BUY_PRICE = 20,										   //오랭열매(체력10회복)
	LUM_BERRY_BUY_PRICE = 20,										   //리샘열매(모든상태이상회복)
	SITRUS_BERRY_BUY_PRICE = 20,									   //자뭉열매(체력30회복)
																	   
	ITEM_BUY_PRICE_NONE,											   

	ITEM_BUY_PRICE_COUNT = ITEM_BUY_PRICE_NONE
};

enum ITEM_SELL_PRICE
{
	MONSTER_BALL_SELL_PRICE = 100,									   //몬스터볼
	SUPER_BALL_SELL_PRICE = 300,									   //슈퍼볼
	HYPER_BALL_SELL_PRICE = 600,									   //하이퍼볼
	MASTER_BALL_SELL_PRICE = 25000,									   //마스터볼

	NORMAL_POTION_SELL_PRICE = 150,									   //상처약(20회복)
	SUPER_POTION_SELL_PRICE = 350,									   //좋은상처약(60회복)
	HYPER_POTION_SELL_PRICE = 600,									   //고급상처약(120회복)
	MAX_POTION_SELL_PRICE = 600,									   //풀회복약(전체회복)
	FULL_RESTORE_SELL_PRICE = 1500,									   //회복약(전체회복+상태이상)

	NORMAL_ETHER_SELL_PRICE = 600,									   //PP에이드(한기술 10회복)
	MAX_ETHER_SELL_PRICE = 1000,									   //pp회복(한기술 전체회복)
	NORMAL_ELIXIR_SELL_PRICE = 1500,								   //pp에이더(모든기술 10회복)
	MAX_ELIXIR_SELL_PRICE = 2250,									   //pp맥스(모든기술 전체회복)

	ANTIDOTE_SELL_PRICE = 50,										   //해독제
	PARLYZE_HEAL_SELL_PRICE = 100, 									   //마비해독제
	BURN_HEAL_SELL_PRICE = 125,										   //화상치료제
	ICE_HEAL_SELL_PRICE = 125,										   //얼음상태치료제
	AWAKENING_SELL_PRICE = 125,										   //잠깨는약
	FULL_HEAL_SELL_PRICE = 300,										   //만병통치제				

	RARE_CANDY_SELL_PRICE = 2400,									   //이상한사탕
	ESCAPE_ROPE_SELL_PRICE = 2400,									   //동굴탈출로프
	REVIVE_SELL_PRICE = 750,										   //기력의 조각
	BICYCLE_SELL_PRICE = 0,											   //자전거
	FISHING_ROD_SELL_PRICE = 0,										   //낚시대
	TOWN_MAP_SELL_PRICE = 0,										   //타운맵

	HM_CUT_SELL_PRICE = 0,											   //풀베기
	HM_FLASH_SELL_PRICE = 0,										   //플래시

	TM_THUNDERBOLT_SELL_PRICE = 1500,								   //10만볼트
	TM_THUNDER_SELL_PRICE = 1500,									   //번개
	TM_FLAMETHROWER_SELL_PRICE = 1500,								   //화염방사

	CHERI_BERRY_SELL_PRICE = 10,									   //버치열매(마비회복)
	CHESTO_BERRY_SELL_PRICE = 10,									   //유루열매(잠듦회복)
	PECHA_BERRY_SELL_PRICE = 10,									   //복슝열매(독회복)
	RAWST_BERRY_SELL_PRICE = 10,									   //복분열매(화상회복)
	ASPEAR_BERRY_SELL_PRICE = 10,									   //배리열매(동상회복)
	LEPPA_BERRY_SELL_PRICE = 10,									   //과사열매(PP10회복)
	ORAN_BERRY_SELL_PRICE = 10,										   //오랭열매(체력10회복)
	LUM_BERRY_SELL_PRICE = 10,										   //리샘열매(모든상태이상회복)
	SITRUS_BERRY_SELL_PRICE = 10,									   //자뭉열매(체력30회복)

	ITEM_SELL_PRICE_NONE,

	ITEM_SELL_PRICE_COUNT = ITEM_SELL_PRICE_NONE
};

class item : public singletonBase<item>
{
private:
	
	image*					_img;			//이미지
	RECT					_rc;			//렉트
	
	string					_sceneName;		//맵내에 배치되어있다면 어느씬에?
	UINT					_tileX;			//있다면 어느 타일에?
	UINT					_tileY;			//있다면 어느 타일에?

	string					_itemName;		//아이템이름
	string					_itemInfo;		//아이템설명
	ITEM_TYPE				_itemType;		//종류
	ITEM_VALUE				_itemValue;		//아이템적용값(회복값, pp회복값, 포획률 등)
	UINT					_itemNum;		//개수
	ITEM_BUY_PRICE			_buyPrice;		//구입가격
	ITEM_SELL_PRICE			_sellPrice;		//판매가격

	POINTF					_rcPos;			//위치
	POINTF					_imgPos;		//이미지위치
	POINT					_imgSize;		//이미지크기

	vector<item*>			_fieldItem;


public:
	item();
	~item();

	HRESULT init();
	//이니니니닛(종류)
	HRESULT init(ITEM_TYPE type);
	void release();
	void update();
	void render();

	string makeName(ITEM_TYPE type);

	// ========== GET & SET ==========
	//이름
	string getItemName() { return _itemName; }

	//종류
	ITEM_TYPE getItemType() { return _itemType; }

	//적용값
	ITEM_VALUE getItemValue() { return _itemValue; }

	//개수
	UINT getItemNum() { return _itemNum; }

	//구입가격
	ITEM_BUY_PRICE getBuyPrice() { return _buyPrice; }
	
	//판매가격
	ITEM_SELL_PRICE getSellPrice() { return _sellPrice; }

	//아이템정보
	string getItemInfo() { return _itemInfo; }


	//아이템 위치
	UINT getTileX() { return _tileX; }
	UINT getTileY() { return _tileY; }
	void setTileX(UINT tileX) { _tileX = tileX; }
	void setTileY(UINT tileY) { _tileY = tileY; }

	//현재씬받아오기
	void setCurrentScene(string scene) { _sceneName = scene; }




	//ITEM_VALUE makeItemValue(ITEM_TYPE type);
	//ITEM_BUY_PRICE makeItemBuyPrice(ITEM_TYPE type);
	//ITEM_SELL_PRICE makeItemSellPrice(ITEM_TYPE type);
	//string makeItemName(ITEM_TYPE type);
	//string makeItemInfo(ITEM_TYPE type);
	
	//아이템정보를 쓸때 아이템타입 넣어주쎄요
	item* settingItemInfo(ITEM_TYPE type);

};

