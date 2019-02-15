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
	_itemType = type;											//����
	_rcPos = { 80, WINSIZEY - 95 };								//��Ʈ��ġ
	_imgPos.x = _rcPos.x - _img->GetFrameWidth() / 2;			//�̹��� �׸���ġ (X)
	_imgPos.y = _rcPos.y - _img->GetFrameWidth() / 2;			//�̹��� �׸���ġ (Y)

	switch (type)
	{
		case MONSTER_BALL:
		{
			_itemName = "���ͺ�";
			_itemValue = MONSTER_BALL_VALUE;
			_buyPrice = MONSTER_BALL_BUY_PRICE;
			_sellPrice = MONSTER_BALL_SELL_PRICE;
			_itemInfo = "�߻� ���ϸ󿡰� ������ ��� ���� ��.\nĸ�������� �Ǿ� �ִ�.";
			_imgSize = { 72, 72 };
			break;
		}
		case SUPER_BALL:
		{
			_itemName = "���ۺ�";
			_itemValue = SUPER_BALL_VALUE;
			_buyPrice = SUPER_BALL_BUY_PRICE;
			_sellPrice = SUPER_BALL_SELL_PRICE;
			_itemInfo = "���ͺ����ٵ� ���� ���ϸ���\n��� ������ �ణ ������ ���� ��.";
			_imgSize = { 72, 72 };
			break;
		}
		case HYPER_BALL:
		{
			_itemName = "�����ۺ�";
			_itemValue = HYPER_BALL_VALUE;
			_buyPrice = HYPER_BALL_BUY_PRICE;
			_sellPrice = HYPER_BALL_SELL_PRICE;
			_itemInfo = "���ۺ����ٵ� ���� ���ϸ���\n��� ������ �ſ� ������ ���� ��.";
			_imgSize = { 72, 72 };
			break;
		}
		case MASTER_BALL:
		{
			_itemName = "�����ͺ�";
			_itemValue = MASTER_BALL_VALUE;
			_buyPrice = MASTER_BALL_BUY_PRICE;
			_sellPrice = MASTER_BALL_SELL_PRICE;
			_itemInfo = "�߻� ���ϸ��� �ݵ��\n���� �� �ִ� �ְ� ������ ��";
			_imgSize = { 72, 72 };
			break;
		}
		case NORMAL_POTION:
		{
			_itemName = "��ó��";
			_itemValue = NORMAL_POTION_VALUE;
			_buyPrice = NORMAL_POTION_BUY_PRICE;
			_sellPrice = NORMAL_POTION_SELL_PRICE;
			_itemInfo = "�������̽��� ��ó��.\n���ϸ� 1������ HP�� 20��ŭ ȸ���Ѵ�.";
			_imgSize = { 60, 84 };
			break;
		}
		case SUPER_POTION:
		{
			_itemName = "������ó��";
			_itemValue = SUPER_POTION_VALUE;
			_buyPrice = SUPER_POTION_BUY_PRICE;
			_sellPrice = SUPER_POTION_SELL_PRICE;
			_itemInfo = "�������̽��� ��ó��.\n���ϸ� 1������ HP�� 50��ŭ ȸ���Ѵ�.";
			_imgSize = { 60, 84 };
			break;
		}
		case HYPER_POTION:
		{
			_itemName = "��޻�ó��";
			_itemValue = HYPER_POTION_VALUE;
			_buyPrice = HYPER_POTION_BUY_PRICE;
			_sellPrice = HYPER_POTION_SELL_PRICE;
			_itemInfo = "�������̽��� ��ó��.\n���ϸ� 1������ HP�� 200��ŭ ȸ���Ѵ�.";
			_imgSize = { 60, 84 };
			break;
		}
		case MAX_POTION:
		{
			_itemName = "Ǯȸ����";
			_itemValue = MAX_POTION_VALUE;
			_buyPrice = MAX_POTION_BUY_PRICE;
			_sellPrice = MAX_POTION_SELL_PRICE;
			_itemInfo = "�������̽��� ��ó��.\n���ϸ� 1������ HP�� ��� ȸ���Ѵ�.";
			_imgSize = { 64, 88 };
			break;
		}
		case FULL_RESTORE:
		{
			_itemName = "ȸ����";
			_itemValue = FULL_RESTORE_VALUE;
			_buyPrice = FULL_RESTORE_BUY_PRICE;
			_sellPrice = FULL_RESTORE_SELL_PRICE;
			_itemInfo = "���ϸ� 1������ HP�� �����̻��� ��� ȸ���Ѵ�.";
			_imgSize = { 64, 88 };
			break;
		}
		case NORMAL_ETHER:
		{
			_itemName = "PP���̵�";
			_itemValue = NORMAL_ETHER_VALUE;
			_buyPrice = NORMAL_ETHER_BUY_PRICE;
			_sellPrice = NORMAL_ETHER_SELL_PRICE;
			_itemInfo = "���ϸ��� ����ϰ� �ִ� ��� �� 1���� PP�� 10��ŭ ȸ���Ѵ�.";
			_imgSize = { 64, 88 };
			break;
		}
		case MAX_ETHER:
		{
			_itemName = "PPȸ��";
			_itemValue = MAX_ETHER_VALUE;
			_buyPrice = MAX_ETHER_BUY_PRICE;
			_sellPrice = MAX_ETHER_SELL_PRICE;
			_itemInfo = "���ϸ��� ����ϰ� �ִ� ��� �� 1���� PP�� ��� ȸ���Ѵ�.";
			_imgSize = { 64, 88 };
			break;
		}
		case NORMAL_ELIXIR:
		{
			_itemName = "PP���̴�";
			_itemValue = NORMAL_ELIXIR_VALUE;
			_buyPrice = NORMAL_ELIXIR_BUY_PRICE;
			_sellPrice = NORMAL_ELIXIR_SELL_PRICE;
			_itemInfo = "���ϸ��� ����ϰ� �ִ� 4�� ����� PP�� 10�� ȸ���Ѵ�.";
			_imgSize = { 64, 88 };
			break;
		}
		case MAX_ELIXIR:
		{
			_itemName = "PP�ƽ�";
			_itemValue = MAX_ELIXIR_VALUE;
			_buyPrice = MAX_ELIXIR_BUY_PRICE;
			_sellPrice = MAX_ELIXIR_SELL_PRICE;
			_itemInfo = "���ϸ��� ����ϰ� �ִ� 4�� ����� PP�� ��� ȸ���Ѵ�.";
			_imgSize = { 64, 88 };
			break;
		}
		case ANTIDOTE:
		{
			_itemName = "�ص���";
			_itemValue = ANTIDOTE_VALUE;
			_buyPrice = ANTIDOTE_BUY_PRICE;
			_sellPrice = ANTIDOTE_SELL_PRICE;
			_itemInfo = "�������̽��� ��. ���ϸ� 1������ �� ���¸� ȸ���Ѵ�.";
			_imgSize = { 52, 84 };
			break;
		}
		case PARLYZE_HEAL:
		{
			_itemName = "�����ص���";
			_itemValue = PARLYZE_HEAL_VALUE;
			_buyPrice = PARLYZE_HEAL_BUY_PRICE;
			_sellPrice = PARLYZE_HEAL_SELL_PRICE;
			_itemInfo = "�������̽��� ��. ���ϸ� 1������ ���� ���¸� ȸ���Ѵ�.";
			_imgSize = { 52, 84 };
			break;
		}
		case BURN_HEAL:
		{
			_itemName = "ȭ��ġ����";
			_itemValue = BURN_HEAL_VALUE;
			_buyPrice = BURN_HEAL_BUY_PRICE;
			_sellPrice = BURN_HEAL_SELL_PRICE;
			_itemInfo = "�������̽��� ��. ���ϸ� 1������ ȭ�� ���¸� ȸ���Ѵ�.";
			_imgSize = { 52, 84 };
			break;
		}
		case ICE_HEAL:
		{
			_itemName = "��������ġ����";
			_itemValue = ICE_HEAL_VALUE;
			_buyPrice = ICE_HEAL_BUY_PRICE;
			_sellPrice = ICE_HEAL_SELL_PRICE;
			_itemInfo = "�������̽��� ��. ���ϸ� 1������ ���� ���¸� ȸ���Ѵ�.";
			_imgSize = { 52, 84 };
			break;
		}
		case AWAKENING:
		{
			_itemName = "����¾�";
			_itemValue = AWAKENING_VALUE;
			_buyPrice = AWAKENING_BUY_PRICE;
			_sellPrice = AWAKENING_SELL_PRICE;
			_itemInfo = "�������̽��� ��. ���ϸ� 1������ ��� ���¸� ȸ���Ѵ�.";
			_imgSize = { 52, 84 };
			break;
		}
		case FULL_HEAL:
		{
			_itemName = "������ġ��";
			_itemValue = FULL_HEAL_VALUE;
			_buyPrice = FULL_HEAL_BUY_PRICE;
			_sellPrice = FULL_HEAL_SELL_PRICE;
			_itemInfo = "�������̽��� ��. ���ϸ� 1������ �����̻��� ��� ȸ���Ѵ�.";
			_imgSize = { 52, 84 };
			break;
		}
		case RARE_CANDY:
		{
			_itemName = "�̻��ѻ���";
			_itemValue = RARE_CANDY_VALUE;
			_buyPrice = RARE_CANDY_BUY_PRICE;
			_sellPrice = RARE_CANDY_SELL_PRICE;
			_itemInfo = "�������� ������ ����. ���̸� ���ϸ� 1������ ������ 1��ŭ �ö󰣴�.";
			_imgSize = { 84, 84 };
			break;
		}
		case ESCAPE_ROPE:
		{
			_itemName = "����Ż�����";
			_itemValue = ESCAPE_ROPE_VALUE;
			_buyPrice = ESCAPE_ROPE_BUY_PRICE;
			_sellPrice = ESCAPE_ROPE_SELL_PRICE;
			_itemInfo = "��� ưư�� ����. �����̳� ������� ���� ���� �� �ִ�.";
			_imgSize = { 84, 68 };
			break;
		}
		case REVIVE:
		{
			_itemName = "����� ����";
			_itemValue = REVIVE_VALUE;
			_buyPrice = REVIVE_BUY_PRICE;
			_sellPrice = REVIVE_SELL_PRICE;
			_itemInfo = "������ ���� ���ϸ� 1������ HP�� ���ݱ��� ȸ���Ѵ�.";
			_imgSize = { 40, 60 };
			break;
		}
		case BICYCLE:
		{
			_itemName = "������";
			_itemValue = BICYCLE_VALUE;
			_buyPrice = BICYCLE_BUY_PRICE;
			_sellPrice = BICYCLE_SELL_PRICE;
			_itemInfo = "���̽� ������. �ȭ���� ������ �̵��� �� �ִ�.";
			_imgSize = { 84, 88 };
			break;
		}
		case FISHING_ROD:
		{
			_itemName = "���ô�";
			_itemValue = FISHING_ROD_VALUE;
			_buyPrice = FISHING_ROD_BUY_PRICE;
			_sellPrice = FISHING_ROD_SELL_PRICE;
			_itemInfo = "������ ����� ���ô�. �߻� �� ���ϸ��� ���� ���� �������� ����Ѵ�.";
			_imgSize = { 88, 84 };
			break;
		}
		case TOWN_MAP:
		{
			_itemName = "Ÿ���";
			_itemValue = TOWN_MAP_VALUE;
			_buyPrice = TOWN_MAP_BUY_PRICE;
			_sellPrice = TOWN_MAP_SELL_PRICE;
			_itemInfo = "�������� �����ϰ� �� �� �ִ� ���� ����. �ڽ��� ��ġ�� �� �� �ִ�.";
			_imgSize = { 84, 76 };
			break;
		}
		case HM_CUT:
		{
			_itemName = "Ǯ����";
			_itemValue = HM_CUT_VALUE;
			_buyPrice = HM_CUT_BUY_PRICE;
			_sellPrice = HM_CUT_SELL_PRICE;
			_itemInfo = "���̳� ���� ������ ��븦 ���� �����Ѵ�. �����ٶ� ���� � �ڸ� �� �ִ�.";
			_imgSize = { 80, 80 };
			break;
		}
		case HM_FLASH:
		{
			_itemName = "�÷���";
			_itemValue = HM_FLASH_VALUE;
			_buyPrice = HM_FLASH_BUY_PRICE;
			_sellPrice = HM_FLASH_SELL_PRICE;
			_itemInfo = "���� �ν� ������ ����� ���߷��� ����Ʈ����. ��ο� ������ ��� �����.";
			_imgSize = { 80, 80 };
			break;
		}
		case TM_THUNDERBOLT:
		{
			_itemName = "10����Ʈ";
			_itemValue = TM_THUNDERBOLT_VALUE;
			_buyPrice = TM_THUNDERBOLT_BUY_PRICE;
			_sellPrice = TM_THUNDERBOLT_SELL_PRICE;
			_itemInfo = "���� ������ ��뿡�� ������ �����Ѵ�. ���� ���·� ���� ���� �ִ�.";
			_imgSize = { 80, 80 };
			break;
		}
		case TM_THUNDER:
		{
			_itemName = "����";
			_itemValue = TM_THUNDER_VALUE;
			_buyPrice = TM_THUNDER_BUY_PRICE;
			_sellPrice = TM_THUNDER_SELL_PRICE;
			_itemInfo = "���� ������ ��뿡�� ����Ʈ�� �����Ѵ�. ���� ���·� ���� ���� �ִ�.";
			_imgSize = { 80, 80 };
			break;
		}
		case TM_FLAMETHROWER:
		{
			_itemName = "ȭ�����";
			_itemValue = TM_FLAMETHROWER_VALUE;
			_buyPrice = TM_FLAMETHROWER_BUY_PRICE;
			_sellPrice = TM_FLAMETHROWER_SELL_PRICE;
			_itemInfo = "���� �Ҳ��� ��뿡�� �߻��Ͽ� �����Ѵ�. ȭ�� ���·� ���� ���� �ִ�.";
			_imgSize = { 80, 80 };
			break;
		}
		case CHERI_BERRY:
		{
			_itemName = "��ġ����";
			_itemValue = CHERI_BERRY_VALUE;
			_buyPrice = CHERI_BERRY_BUY_PRICE;
			_sellPrice = CHERI_BERRY_SELL_PRICE;
			_itemInfo = "��ġ���Ŵ� �� �ſ��� ���� �ڱ����� ���� ����. ������ ���� ���¸� ���� �Ѵ�.";
			_imgSize = { 88, 88 };
			break;
		}
		case CHESTO_BERRY:
		{
			_itemName = "���翭��";
			_itemValue = CHESTO_BERRY_VALUE;
			_buyPrice = CHESTO_BERRY_BUY_PRICE;
			_sellPrice = CHESTO_BERRY_SELL_PRICE;
			_itemInfo = "���翭�Ŵ� �Ѱ� ���� ��� �����ϰ� ������ ����� ���� ���� �� �ִ�. ������ ��� ���¸� ���� �Ѵ�.";
			_imgSize = { 72, 76 };
			break;
		}
		case PECHA_BERRY:
		{
			_itemName = "��������";
			_itemValue = PECHA_BERRY_VALUE;
			_buyPrice = PECHA_BERRY_BUY_PRICE;
			_sellPrice = PECHA_BERRY_SELL_PRICE;
			_itemInfo = "�ӿ� �� ������ �����Ƿ� ���� �� �ִ� �κ��� ������ �ſ� �ް� ���ִ�. ������ �� ���¸� ���� �Ѵ�.";
			_imgSize = { 80, 80 };
			break;
		}
		case RAWST_BERRY:
		{
			_itemName = "���п���";
			_itemValue = RAWST_BERRY_VALUE;
			_buyPrice = RAWST_BERRY_BUY_PRICE;
			_sellPrice = RAWST_BERRY_SELL_PRICE;
			_itemInfo = "�ٸ� �ͺ��� �ٻ�Ͱ� ��� �ձ۰� ���� �ִ� ���� �ణ ������ ���ϴ�. ������ ȭ�� ���¸� ���� �Ѵ�.";
			_imgSize = { 84, 80 };
			break;
		}
		case ASPEAR_BERRY:
		{
			_itemName = "�踮����";
			_itemValue = ASPEAR_BERRY_VALUE;
			_buyPrice = ASPEAR_BERRY_BUY_PRICE;
			_sellPrice = ASPEAR_BERRY_SELL_PRICE;
			_itemInfo = "���� ������ ���������� �ӿ��� �ſ� ���� ����. ������ ���� ���¸� ���� �Ѵ�.";
			_imgSize = { 80, 80 };
			break;
		}
		case LEPPA_BERRY:
		{
			_itemName = "���翭��";
			_itemValue = LEPPA_BERRY_VALUE;
			_buyPrice = LEPPA_BERRY_BUY_PRICE;
			_sellPrice = LEPPA_BERRY_SELL_PRICE;
			_itemInfo = "��ġ ��� ���ϸ� ���� ������ �ʴ�. ���Ű� ���� ���ϼ��� ���ִ�. ������ PP�� 10 ȸ���Ѵ�.";
			_imgSize = { 88, 84 };
			break;
		}
		case ORAN_BERRY:
		{
			_itemName = "��������";
			_itemValue = ORAN_BERRY_VALUE;
			_buyPrice = ORAN_BERRY_BUY_PRICE;
			_sellPrice = ORAN_BERRY_SELL_PRICE;
			_itemInfo = "�ڿ��� ������ �ϳ��Ǿ� �� �ȿ��� �������� ���� ��ġ�� �ű��� ���̴�. ������ ü���� 10 ȸ���Ѵ�.";
			_imgSize = { 76, 72 };
			break;
		}
		case LUM_BERRY:
		{
			_itemName = "��������";
			_itemValue = LUM_BERRY_VALUE;
			_buyPrice = LUM_BERRY_BUY_PRICE;
			_sellPrice = LUM_BERRY_SELL_PRICE;
			_itemInfo = "���ϸ��� ���� ���� ������ ���ο� õõ�� �����ϹǷ� �ڶ󳪱������ �ð��� �ɸ���. ������ ��� �����̻��� ȸ���Ѵ�.";
			_imgSize = { 72, 68 };
			break;
		}
		case SITRUS_BERRY:
		{
			_itemName = "�ڹ�����";
			_itemValue = SITRUS_BERRY_VALUE;
			_buyPrice = SITRUS_BERRY_BUY_PRICE;
			_sellPrice = SITRUS_BERRY_SELL_PRICE;
			_itemInfo = "������ �������ſ� �Ȱ��� �������� ������ ���Դ�. ������ ü���� 30 ȸ���Ѵ�.";
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
