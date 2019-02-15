#include "stdafx.h"
#include "item.h"


item::item()
{
}


item::~item()
{
	
}

HRESULT item::init()
{
	return S_OK;
}

HRESULT item::init(ITEM_TYPE type)
{
	_img = IMAGEMANAGER->findImage("items");
	_itemType = type;											//종류
	_rcPos = { 80, WINSIZEY - 95 };								//렉트위치
	_imgPos.x = _rcPos.x - _img->GetFrameWidth() / 2;			//이미지 그릴위치 (X)
	_imgPos.y = _rcPos.y - _img->GetFrameWidth() / 2;			//이미지 그릴위치 (Y)

	switch (type)
	{
		case MONSTER_BALL:
		{
			_itemName = "몬스터볼";
			_itemValue = MONSTER_BALL_VALUE;
			_buyPrice = MONSTER_BALL_BUY_PRICE;
			_sellPrice = MONSTER_BALL_SELL_PRICE;
			_itemInfo = "야생 포켓몬에게 던져서 잡기 위한 볼.\n캡슐식으로 되어 있다.";
			_imgSize = { 72, 72 };
			break;
		}
		case SUPER_BALL:
		{
			_itemName = "슈퍼볼";
			_itemValue = SUPER_BALL_VALUE;
			_buyPrice = SUPER_BALL_BUY_PRICE;
			_sellPrice = SUPER_BALL_SELL_PRICE;
			_itemInfo = "몬스터볼보다도 더욱 포켓몬을\n잡기 쉬워진 약간 성능이 좋은 볼.";
			_imgSize = { 72, 72 };
			break;
		}
		case HYPER_BALL:
		{
			_itemName = "하이퍼볼";
			_itemValue = HYPER_BALL_VALUE;
			_buyPrice = HYPER_BALL_BUY_PRICE;
			_sellPrice = HYPER_BALL_SELL_PRICE;
			_itemInfo = "슈퍼볼보다도 더욱 포켓몬을\n잡기 쉬워진 매우 성능이 좋은 볼.";
			_imgSize = { 72, 72 };
			break;
		}
		case MASTER_BALL:
		{
			_itemName = "마스터볼";
			_itemValue = MASTER_BALL_VALUE;
			_buyPrice = MASTER_BALL_BUY_PRICE;
			_sellPrice = MASTER_BALL_SELL_PRICE;
			_itemInfo = "야생 포켓몬을 반드시\n잡을 수 있는 최고 성능의 볼";
			_imgSize = { 72, 72 };
			break;
		}
		case NORMAL_POTION:
		{
			_itemName = "상처약";
			_itemValue = NORMAL_POTION_VALUE;
			_buyPrice = NORMAL_POTION_BUY_PRICE;
			_sellPrice = NORMAL_POTION_SELL_PRICE;
			_itemInfo = "스프레이식의 상처약.\n포켓몬 1마리의 HP를 20만큼 회복한다.";
			_imgSize = { 60, 84 };
			break;
		}
		case SUPER_POTION:
		{
			_itemName = "좋은상처약";
			_itemValue = SUPER_POTION_VALUE;
			_buyPrice = SUPER_POTION_BUY_PRICE;
			_sellPrice = SUPER_POTION_SELL_PRICE;
			_itemInfo = "스프레이식의 상처약.\n포켓몬 1마리의 HP를 50만큼 회복한다.";
			_imgSize = { 60, 84 };
			break;
		}
		case HYPER_POTION:
		{
			_itemName = "고급상처약";
			_itemValue = HYPER_POTION_VALUE;
			_buyPrice = HYPER_POTION_BUY_PRICE;
			_sellPrice = HYPER_POTION_SELL_PRICE;
			_itemInfo = "스프레이식의 상처약.\n포켓몬 1마리의 HP를 200만큼 회복한다.";
			_imgSize = { 60, 84 };
			break;
		}
		case MAX_POTION:
		{
			_itemName = "풀회복약";
			_itemValue = MAX_POTION_VALUE;
			_buyPrice = MAX_POTION_BUY_PRICE;
			_sellPrice = MAX_POTION_SELL_PRICE;
			_itemInfo = "스프레이식의 상처약.\n포켓몬 1마리의 HP를 모두 회복한다.";
			_imgSize = { 64, 88 };
			break;
		}
		case FULL_RESTORE:
		{
			_itemName = "회복약";
			_itemValue = FULL_RESTORE_VALUE;
			_buyPrice = FULL_RESTORE_BUY_PRICE;
			_sellPrice = FULL_RESTORE_SELL_PRICE;
			_itemInfo = "포켓몬 1마리의 HP와 상태이상을 모두 회복한다.";
			_imgSize = { 64, 88 };
			break;
		}
		case NORMAL_ETHER:
		{
			_itemName = "PP에이드";
			_itemValue = NORMAL_ETHER_VALUE;
			_buyPrice = NORMAL_ETHER_BUY_PRICE;
			_sellPrice = NORMAL_ETHER_SELL_PRICE;
			_itemInfo = "포켓몬이 기억하고 있는 기술 중 1개의 PP를 10만큼 회복한다.";
			_imgSize = { 64, 88 };
			break;
		}
		case MAX_ETHER:
		{
			_itemName = "PP회복";
			_itemValue = MAX_ETHER_VALUE;
			_buyPrice = MAX_ETHER_BUY_PRICE;
			_sellPrice = MAX_ETHER_SELL_PRICE;
			_itemInfo = "포켓몬이 기억하고 있는 기술 중 1개의 PP를 모두 회복한다.";
			_imgSize = { 64, 88 };
			break;
		}
		case NORMAL_ELIXIR:
		{
			_itemName = "PP에이더";
			_itemValue = NORMAL_ELIXIR_VALUE;
			_buyPrice = NORMAL_ELIXIR_BUY_PRICE;
			_sellPrice = NORMAL_ELIXIR_SELL_PRICE;
			_itemInfo = "포켓몬이 기억하고 있는 4개 기술의 PP를 10씩 회복한다.";
			_imgSize = { 64, 88 };
			break;
		}
		case MAX_ELIXIR:
		{
			_itemName = "PP맥스";
			_itemValue = MAX_ELIXIR_VALUE;
			_buyPrice = MAX_ELIXIR_BUY_PRICE;
			_sellPrice = MAX_ELIXIR_SELL_PRICE;
			_itemInfo = "포켓몬이 기억하고 있는 4개 기술의 PP를 모두 회복한다.";
			_imgSize = { 64, 88 };
			break;
		}
		case ANTIDOTE:
		{
			_itemName = "해독제";
			_itemValue = ANTIDOTE_VALUE;
			_buyPrice = ANTIDOTE_BUY_PRICE;
			_sellPrice = ANTIDOTE_SELL_PRICE;
			_itemInfo = "스프레이식의 약. 포켓몬 1마리의 독 상태를 회복한다.";
			_imgSize = { 52, 84 };
			break;
		}
		case PARLYZE_HEAL:
		{
			_itemName = "마비해독제";
			_itemValue = PARLYZE_HEAL_VALUE;
			_buyPrice = PARLYZE_HEAL_BUY_PRICE;
			_sellPrice = PARLYZE_HEAL_SELL_PRICE;
			_itemInfo = "스프레이식의 약. 포켓몬 1마리의 마비 상태를 회복한다.";
			_imgSize = { 52, 84 };
			break;
		}
		case BURN_HEAL:
		{
			_itemName = "화상치료제";
			_itemValue = BURN_HEAL_VALUE;
			_buyPrice = BURN_HEAL_BUY_PRICE;
			_sellPrice = BURN_HEAL_SELL_PRICE;
			_itemInfo = "스프레이식의 약. 포켓몬 1마리의 화상 상태를 회복한다.";
			_imgSize = { 52, 84 };
			break;
		}
		case ICE_HEAL:
		{
			_itemName = "얼음상태치료제";
			_itemValue = ICE_HEAL_VALUE;
			_buyPrice = ICE_HEAL_BUY_PRICE;
			_sellPrice = ICE_HEAL_SELL_PRICE;
			_itemInfo = "스프레이식의 약. 포켓몬 1마리의 얼음 상태를 회복한다.";
			_imgSize = { 52, 84 };
			break;
		}
		case AWAKENING:
		{
			_itemName = "잠깨는약";
			_itemValue = AWAKENING_VALUE;
			_buyPrice = AWAKENING_BUY_PRICE;
			_sellPrice = AWAKENING_SELL_PRICE;
			_itemInfo = "스프레이식의 약. 포켓몬 1마리의 잠듦 상태를 회복한다.";
			_imgSize = { 52, 84 };
			break;
		}
		case FULL_HEAL:
		{
			_itemName = "만병통치제";
			_itemValue = FULL_HEAL_VALUE;
			_buyPrice = FULL_HEAL_BUY_PRICE;
			_sellPrice = FULL_HEAL_SELL_PRICE;
			_itemInfo = "스프레이식의 약. 포켓몬 1마리의 상태이상을 모두 회복한다.";
			_imgSize = { 52, 84 };
			break;
		}
		case RARE_CANDY:
		{
			_itemName = "이상한사탕";
			_itemValue = RARE_CANDY_VALUE;
			_buyPrice = RARE_CANDY_BUY_PRICE;
			_sellPrice = RARE_CANDY_SELL_PRICE;
			_itemInfo = "에너지가 가득한 사탕. 먹이면 포켓몬 1마리의 레벨이 1만큼 올라간다.";
			_imgSize = { 84, 84 };
			break;
		}
		case ESCAPE_ROPE:
		{
			_itemName = "동굴탈출로프";
			_itemValue = ESCAPE_ROPE_VALUE;
			_buyPrice = ESCAPE_ROPE_BUY_PRICE;
			_sellPrice = ESCAPE_ROPE_SELL_PRICE;
			_itemInfo = "길고 튼튼한 밧줄. 동굴이나 던전등에서 빠져 나올 수 있다.";
			_imgSize = { 84, 68 };
			break;
		}
		case REVIVE:
		{
			_itemName = "기력의 조각";
			_itemValue = REVIVE_VALUE;
			_buyPrice = REVIVE_BUY_PRICE;
			_sellPrice = REVIVE_SELL_PRICE;
			_itemInfo = "기절해 버린 포켓몬 1마리의 HP를 절반까지 회복한다.";
			_imgSize = { 40, 60 };
			break;
		}
		case BICYCLE:
		{
			_itemName = "자전거";
			_itemValue = BICYCLE_VALUE;
			_buyPrice = BICYCLE_BUY_PRICE;
			_sellPrice = BICYCLE_SELL_PRICE;
			_itemInfo = "접이식 자전거. 운동화보다 빠르게 이동할 수 있다.";
			_imgSize = { 84, 88 };
			break;
		}
		case FISHING_ROD:
		{
			_itemName = "낚시대";
			_itemValue = FISHING_ROD_VALUE;
			_buyPrice = FISHING_ROD_BUY_PRICE;
			_sellPrice = FISHING_ROD_SELL_PRICE;
			_itemInfo = "굉장히 고급진 낚시대. 야생 물 포켓몬을 낚기 위해 수역에서 사용한다.";
			_imgSize = { 88, 84 };
			break;
		}
		case TOWN_MAP:
		{
			_itemName = "타운맵";
			_itemValue = TOWN_MAP_VALUE;
			_buyPrice = TOWN_MAP_BUY_PRICE;
			_sellPrice = TOWN_MAP_SELL_PRICE;
			_itemInfo = "언제든지 간편하게 볼 수 있는 편리한 지도. 자신의 위치도 알 수 있다.";
			_imgSize = { 84, 76 };
			break;
		}
		case HM_CUT:
		{
			_itemName = "풀베기";
			_itemValue = HM_CUT_VALUE;
			_buyPrice = HM_CUT_BUY_PRICE;
			_sellPrice = HM_CUT_SELL_PRICE;
			_itemInfo = "낫이나 손톱 등으로 상대를 베어 공격한다. 가느다란 나무 등도 자를 수 있다.";
			_imgSize = { 80, 80 };
			break;
		}
		case HM_FLASH:
		{
			_itemName = "플래시";
			_itemValue = HM_FLASH_VALUE;
			_buyPrice = HM_FLASH_BUY_PRICE;
			_sellPrice = HM_FLASH_SELL_PRICE;
			_itemInfo = "눈이 부신 빛으로 상대의 명중률을 떨어트린다. 어두운 동굴을 밝게 비춘다.";
			_imgSize = { 80, 80 };
			break;
		}
		case TM_THUNDERBOLT:
		{
			_itemName = "10만볼트";
			_itemValue = TM_THUNDERBOLT_VALUE;
			_buyPrice = TM_THUNDERBOLT_BUY_PRICE;
			_sellPrice = TM_THUNDERBOLT_SELL_PRICE;
			_itemInfo = "강한 전격을 상대에게 날려서 공격한다. 마비 상태로 만들 때가 있다.";
			_imgSize = { 80, 80 };
			break;
		}
		case TM_THUNDER:
		{
			_itemName = "번개";
			_itemValue = TM_THUNDER_VALUE;
			_buyPrice = TM_THUNDER_BUY_PRICE;
			_sellPrice = TM_THUNDER_SELL_PRICE;
			_itemInfo = "강한 번개를 상대에게 떨어트려 공격한다. 마비 상태로 만들 때가 있다.";
			_imgSize = { 80, 80 };
			break;
		}
		case TM_FLAMETHROWER:
		{
			_itemName = "화염방사";
			_itemValue = TM_FLAMETHROWER_VALUE;
			_buyPrice = TM_FLAMETHROWER_BUY_PRICE;
			_sellPrice = TM_FLAMETHROWER_SELL_PRICE;
			_itemInfo = "세찬 불꽃을 상대에게 발사하여 공격한다. 화상 상태로 만들 떄가 있다.";
			_imgSize = { 80, 80 };
			break;
		}
		case CHERI_BERRY:
		{
			_itemName = "버치열매";
			_itemValue = CHERI_BERRY_VALUE;
			_buyPrice = CHERI_BERRY_BUY_PRICE;
			_sellPrice = CHERI_BERRY_SELL_PRICE;
			_itemInfo = "버치열매는 꽤 매워서 조금 자극적인 맛이 난다. 먹으면 마비 상태를 낫게 한다.";
			_imgSize = { 88, 88 };
			break;
		}
		case CHESTO_BERRY:
		{
			_itemName = "유루열매";
			_itemValue = CHESTO_BERRY_VALUE;
			_buyPrice = CHESTO_BERRY_BUY_PRICE;
			_sellPrice = CHESTO_BERRY_SELL_PRICE;
			_itemInfo = "유루열매는 겉과 속이 모두 딱딱하고 떫지만 충분히 전부 먹을 수 있다. 먹으면 잠듦 상태를 낫게 한다.";
			_imgSize = { 72, 76 };
			break;
		}
		case PECHA_BERRY:
		{
			_itemName = "복슝열매";
			_itemValue = PECHA_BERRY_VALUE;
			_buyPrice = PECHA_BERRY_BUY_PRICE;
			_sellPrice = PECHA_BERRY_SELL_PRICE;
			_itemInfo = "속에 빈 공간이 있으므로 먹을 수 있는 부분은 적지만 매우 달고 맛있다. 먹으면 독 상태를 낫게 한다.";
			_imgSize = { 80, 80 };
			break;
		}
		case RAWST_BERRY:
		{
			_itemName = "복분열매";
			_itemValue = RAWST_BERRY_VALUE;
			_buyPrice = RAWST_BERRY_BUY_PRICE;
			_sellPrice = RAWST_BERRY_SELL_PRICE;
			_itemInfo = "다른 것보다 잎사귀가 길고 둥글게 말려 있는 것은 약간 쓴맛이 강하다. 먹으면 화상 상태를 낫게 한다.";
			_imgSize = { 84, 80 };
			break;
		}
		case ASPEAR_BERRY:
		{
			_itemName = "배리열매";
			_itemValue = ASPEAR_BERRY_VALUE;
			_buyPrice = ASPEAR_BERRY_BUY_PRICE;
			_sellPrice = ASPEAR_BERRY_SELL_PRICE;
			_itemInfo = "겉의 껍질은 딱딱하지만 속에는 매우 즙이 많다. 먹으면 얼음 상태를 낫게 한다.";
			_imgSize = { 80, 80 };
			break;
		}
		case LEPPA_BERRY:
		{
			_itemName = "과사열매";
			_itemValue = LEPPA_BERRY_VALUE;
			_buyPrice = LEPPA_BERRY_BUY_PRICE;
			_sellPrice = LEPPA_BERRY_SELL_PRICE;
			_itemInfo = "버치 등과 비교하면 조금 성장이 늦다. 열매가 작은 것일수록 맛있다. 먹으면 PP를 10 회복한다.";
			_imgSize = { 88, 84 };
			break;
		}
		case ORAN_BERRY:
		{
			_itemName = "오랭열매";
			_itemValue = ORAN_BERRY_VALUE;
			_buyPrice = ORAN_BERRY_BUY_PRICE;
			_sellPrice = ORAN_BERRY_SELL_PRICE;
			_itemInfo = "자연의 은혜가 하나되어 입 안에서 여러가지 맛이 펼치는 신기한 맛이다. 먹으면 체력을 10 회복한다.";
			_imgSize = { 76, 72 };
			break;
		}
		case LUM_BERRY:
		{
			_itemName = "리샘열매";
			_itemValue = LUM_BERRY_VALUE;
			_buyPrice = LUM_BERRY_BUY_PRICE;
			_sellPrice = LUM_BERRY_SELL_PRICE;
			_itemInfo = "포켓몬의 몸에 좋은 성분을 내부에 천천히 비축하므로 자라나기까지는 시간이 걸린다. 먹으면 모든 상태이상을 회복한다.";
			_imgSize = { 72, 68 };
			break;
		}
		case SITRUS_BERRY:
		{
			_itemName = "자뭉열매";
			_itemValue = SITRUS_BERRY_VALUE;
			_buyPrice = SITRUS_BERRY_BUY_PRICE;
			_sellPrice = SITRUS_BERRY_SELL_PRICE;
			_itemInfo = "원래는 오랭열매와 똑같은 종류에서 갈라져 나왔다. 먹으면 체력을 30 회복한다.";
			_imgSize = { 72, 80 };
			break;
		}
	}
	return S_OK;
}

void item::release()
{
	_img = nullptr;
}

void item::update()
{
}

void item::render()
{
	_img->frameRender(_imgPos.x + CAMERA->getPosX(), _imgPos.y + CAMERA->getPosY(), _itemType, 0, 1.0f);
}



item * item::settingItemInfo(ITEM_TYPE type)
{
	item* newItem = new item;
	newItem->init(type);

	return newItem;
}
