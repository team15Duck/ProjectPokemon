#include "stdafx.h"
#include "bag.h"


bag::bag()
{
}


bag::~bag()
{
}

HRESULT bag::init()
{
	//_type = UI_BAG;
	_bag_state = ITEM_LIST;

	_currentSelectNum = 0;
	_currentitemamount	= 0  ;
	_maxitemamount		= 0  ;

	_selectNumMoveCount = 0;
	_selectNumMoveDelay = 0.1f;


	_isitemUse = false;

	MENUMANAGER->addFrame("�����ۻ��", 700, 300, 8, 10);
	IMAGEMANAGER->addFrameImage("��������", L"image/common_menu/bag/item_bag.png", 472, 257, 2, 1);
	return S_OK;
}

void bag::release()
{
}

void bag::update()
{
	if (_bag_state == ITEM_LIST)
	{
		//���� �̵�����
		if (!_isitemUse)
		{
			if (KEYMANAGER->isStayKeyDown(VK_UP))
			{
				if (_currentSelectNum >= 0)
				{
					_selectNumMoveCount += TIMEMANAGER->getElapsedTime();
					if (_selectNumMoveCount >= _selectNumMoveDelay)
					{
						_selectNumMoveCount = 0;
						if (_currentSelectNum != 0)
						{
							_currentSelectNum--;
						}
					}
				}
			}
			if (KEYMANAGER->isStayKeyDown(VK_DOWN))
			{
				if (_currentSelectNum < 39)
				{
					_selectNumMoveCount += TIMEMANAGER->getElapsedTime();
					if (_selectNumMoveCount >= _selectNumMoveDelay)
					{
						_selectNumMoveCount = 0;
						if (_currentSelectNum != 150)
						{
							_currentSelectNum++;
						}
					}
				}
			}
			//������ ������ 
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				_isitemUse = true;
			}
		}

		if (_isitemUse)
		{
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				_isitemUse = false;
			}

			if (KEYMANAGER->isOnceKeyDown(VK_UP))
			{
				switch (_item_use)
				{
					case ITEM_USE:
						_item_use = ITEM_STATE_NONE;
					break;
					case ITEM_PASS:
						_item_use = ITEM_USE;
					break;
					case ITEM_THROW_AWAY:
						_item_use = ITEM_PASS;
					break;
					case ITEM_STATE_NONE:
						_item_use = ITEM_THROW_AWAY;
					break;
				}
			}
			if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
			{
				switch (_item_use)
				{
					case ITEM_USE:
						_item_use = ITEM_PASS;
					break;
					case ITEM_PASS:
						_item_use = ITEM_THROW_AWAY;
					break;
					case ITEM_THROW_AWAY:
						_item_use = ITEM_STATE_NONE;
					break;
					case ITEM_STATE_NONE:
						_item_use = ITEM_USE;
					break;
				}
			}
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				switch (_item_use)
				{
				case ITEM_USE:
					_bag_state = ITEM_USE_SELECT;
					break;
				case ITEM_PASS:
					_bag_state = ITEM_PASS_SELECT;
					break;
				case ITEM_THROW_AWAY:
					_item_use = ITEM_STATE_NONE;
					break;
				case ITEM_STATE_NONE:
					_item_use = ITEM_USE;
					break;
				}
			}
		}

		//���θ޴��� �̵��ϱ�
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			UIMANAGER->selectUI(UI_MAIN);
		}
	}
	if (_bag_state == ITEM_USE_SELECT)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			if (_ie_Pokemon == USE_MAIN_POKEMON)
			{
				if (0 < _pokemonCnt)
				{
					_ie_Pokemon = USE_SUB_POKEMON1;
				}
				else
				{
					_ie_Pokemon = USE_CANCEL;
				}
			}
			else if (_ie_Pokemon == USE_CANCEL)
			{
				_ie_Pokemon = USE_MAIN_POKEMON;
			}
			else
			{
				if (_pokemonCnt <= _ie_Pokemon + 1)
				{
					_ie_Pokemon = USE_CANCEL;
				}
				else
				{
					switch (_ie_Pokemon)
					{
					case USE_SUB_POKEMON1:
						_ie_Pokemon = USE_SUB_POKEMON2;
						break;
					case USE_SUB_POKEMON2:
						_ie_Pokemon = USE_SUB_POKEMON3;
						break;
					case USE_SUB_POKEMON3:
						_ie_Pokemon = USE_SUB_POKEMON4;
						break;
					case USE_SUB_POKEMON4:
						_ie_Pokemon = USE_SUB_POKEMON5;
						break;
					case USE_SUB_POKEMON5:
						_ie_Pokemon = USE_CANCEL;
						break;
					}
				}
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			switch (_ie_Pokemon)
			{
			case USE_MAIN_POKEMON:
				_ie_Pokemon = USE_CANCEL;
				break;
			case USE_SUB_POKEMON1:
				_ie_Pokemon = USE_MAIN_POKEMON;
				break;
			case USE_SUB_POKEMON2:
				_ie_Pokemon = USE_SUB_POKEMON1;
				break;
			case USE_SUB_POKEMON3:
				_ie_Pokemon = USE_SUB_POKEMON2;
				break;
			case USE_SUB_POKEMON4:
				_ie_Pokemon = USE_SUB_POKEMON3;
				break;
			case USE_SUB_POKEMON5:
				_ie_Pokemon = USE_SUB_POKEMON4;
				break;
			case USE_CANCEL:
				if (0 < _pokemonCnt)
				{
					_ie_Pokemon = (ITEM_USE_POKEMON)(_pokemonCnt - 1);
				}
				else
				{
					_ie_Pokemon = USE_MAIN_POKEMON;
				}

				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			switch (_ie_Pokemon)
			{
			case USE_MAIN_POKEMON:
				
				break;
			case USE_SUB_POKEMON1:
				
				break;
			case USE_SUB_POKEMON2:
				
				break;
			case USE_SUB_POKEMON3:
				
				break;
			case USE_SUB_POKEMON4:
				
				break;
			case USE_SUB_POKEMON5:
				
				break;
			case USE_CANCEL:
				_bag_state = ITEM_LIST;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_bag_state = ITEM_LIST;
		}
	}
	if (_bag_state == ITEM_PASS_SELECT)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			if (_ie_Pokemon == USE_MAIN_POKEMON)
			{
				if (0 < _pokemonCnt)
				{
					_ie_Pokemon = USE_SUB_POKEMON1;
				}
				else
				{
					_ie_Pokemon = USE_CANCEL;
				}
			}
			else if (_ie_Pokemon == USE_CANCEL)
			{
				_ie_Pokemon = USE_MAIN_POKEMON;
			}
			else
			{
				if (_pokemonCnt <= _ie_Pokemon + 1)
				{
					_ie_Pokemon = USE_CANCEL;
				}
				else
				{
					switch (_ie_Pokemon)
					{
					case USE_SUB_POKEMON1:
						_ie_Pokemon = USE_SUB_POKEMON2;
						break;
					case USE_SUB_POKEMON2:
						_ie_Pokemon = USE_SUB_POKEMON3;
						break;
					case USE_SUB_POKEMON3:
						_ie_Pokemon = USE_SUB_POKEMON4;
						break;
					case USE_SUB_POKEMON4:
						_ie_Pokemon = USE_SUB_POKEMON5;
						break;
					case USE_SUB_POKEMON5:
						_ie_Pokemon = USE_CANCEL;
						break;
					}
				}
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			switch (_ie_Pokemon)
			{
			case USE_MAIN_POKEMON:
				_ie_Pokemon = USE_CANCEL;
				break;
			case USE_SUB_POKEMON1:
				_ie_Pokemon = USE_MAIN_POKEMON;
				break;
			case USE_SUB_POKEMON2:
				_ie_Pokemon = USE_SUB_POKEMON1;
				break;
			case USE_SUB_POKEMON3:
				_ie_Pokemon = USE_SUB_POKEMON2;
				break;
			case USE_SUB_POKEMON4:
				_ie_Pokemon = USE_SUB_POKEMON3;
				break;
			case USE_SUB_POKEMON5:
				_ie_Pokemon = USE_SUB_POKEMON4;
				break;
			case USE_CANCEL:
				if (0 < _pokemonCnt)
				{
					_ie_Pokemon = (ITEM_USE_POKEMON)(_pokemonCnt - 1);
				}
				else
				{
					_ie_Pokemon = USE_MAIN_POKEMON;
				}

				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			switch (_ie_Pokemon)
			{
			case USE_MAIN_POKEMON:

				break;
			case USE_SUB_POKEMON1:

				break;
			case USE_SUB_POKEMON2:

				break;
			case USE_SUB_POKEMON3:

				break;
			case USE_SUB_POKEMON4:

				break;
			case USE_SUB_POKEMON5:

				break;
			case USE_CANCEL:
				_bag_state = ITEM_LIST;
				break;
			}
		}
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_bag_state = ITEM_LIST;
		}
	}
}

void bag::render()
{
	WCHAR itemuse[1024];
	if (_bag_state == ITEM_LIST)
	{
		IMAGEMANAGER->findImage("����޴����")->frameRender(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY(), 0, 0);
		
		if (PLAYERDATA->getPlayer()->getIsMan())
		{
			IMAGEMANAGER->findImage("��������")->frameRender(45 + CAMERA->getPosX(), 160 + CAMERA->getPosY(), 0, 0);
		}
		else
		{
			IMAGEMANAGER->findImage("��������")->frameRender(45 + CAMERA->getPosX(), 160 + CAMERA->getPosY(), 1, 0);
		}
		
		//���� �������� ���� �̰ɷιٲ�ߵ�
		//unordered_map<ITEM_TYPE, UINT> itemList = PLAYERDATA->getPlayet()->getItem();
		//imax �񱳿��� �༮ size�� �����ؾߵ� 
		//�̰� �������̻��ϰԳ��� �� �����ʿ� 
	

		int i = _currentSelectNum - 3;
		int iMax = _currentSelectNum + 3;

		if (i < 0)
		{
			i = 0;
		}
		if (i == 0)
		{
			iMax = 6;
		}
		if (iMax > 39)
		{
			iMax = 39;
		}
		if (iMax == 39)
		{
			i = 33;
		}

		int height = 48;
		for (; i < iMax; ++i, height += 63)
		{
			D2DMANAGER->drawText(_bag[i].name.c_str(), 400, height, 40);
			D2DMANAGER->drawText(_bag[i].amount.c_str(), 870, height, 40);
			//���࿡ i�� ������ ��ȣ��� 
			if (i == _currentSelectNum)
			{

				IMAGEMANAGER->findImage("ȭ��ǥ")->render(370 + CAMERA->getPosX(), height + CAMERA->getPosY());
				IMAGEMANAGER->findImage("items")->frameRender(30 + CAMERA->getPosX(), 495 + CAMERA->getPosY(), _bag[i].type, 0);

				if (!_isitemUse)
				{
					D2DMANAGER->drawText(_bag[i].info.c_str(), 160, 495, 38);
				}
			}
			if (_isitemUse)
			{
				MENUMANAGER->findMenuFrame("�����ۻ��")->render();

				swprintf_s(itemuse, L"����ϱ�");
				D2DMANAGER->drawText(itemuse, 760 + CAMERA->getPosX(), 330 + CAMERA->getPosY(), 40);
				swprintf_s(itemuse, L"�ǳ��ֱ�");
				D2DMANAGER->drawText(itemuse, 760 + CAMERA->getPosX(), 400 + CAMERA->getPosY(), 40);
				swprintf_s(itemuse, L"������");
				D2DMANAGER->drawText(itemuse, 760 + CAMERA->getPosX(), 470 + CAMERA->getPosY(), 40);
				swprintf_s(itemuse, L"�׸��α�");
				D2DMANAGER->drawText(itemuse, 760 + CAMERA->getPosX(), 540 + CAMERA->getPosY(), 40);
			
				switch (_item_use)
				{
				case ITEM_USE:
					IMAGEMANAGER->findImage("ȭ��ǥ")->render(735 + CAMERA->getPosX(), 330 + CAMERA->getPosY());
					break;
				case ITEM_PASS:
					IMAGEMANAGER->findImage("ȭ��ǥ")->render(735 + CAMERA->getPosX(), 400 + CAMERA->getPosY());
					break;
				case ITEM_THROW_AWAY:
					IMAGEMANAGER->findImage("ȭ��ǥ")->render(735 + CAMERA->getPosX(), 470 + CAMERA->getPosY());
					break;
				case ITEM_STATE_NONE:
					IMAGEMANAGER->findImage("ȭ��ǥ")->render(735 + CAMERA->getPosX(), 540 + CAMERA->getPosY());
					break;
				}
			
			}
		}
	}
	if (_bag_state == ITEM_USE_SELECT)
	{
		itemUseScreen();
		swprintf_s(itemuse, L"�������� ����ұ��?");
		D2DMANAGER->drawText(itemuse, 50 + CAMERA->getPosX(), 555 + CAMERA->getPosY(), 40);

		swprintf_s(itemuse, L"���");
		D2DMANAGER->drawText(itemuse, 835 + CAMERA->getPosX(), 558 + CAMERA->getPosY(), 40, RGB(255,255,255));
	}
	if (_bag_state == ITEM_PASS_SELECT)
	{
		itemUseScreen();
		swprintf_s(itemuse, L"�������� �ǳ��ٱ�?");
		D2DMANAGER->drawText(itemuse, 50 + CAMERA->getPosX(), 555 + CAMERA->getPosY(), 40);

		swprintf_s(itemuse, L"���");
		D2DMANAGER->drawText(itemuse, 835 + CAMERA->getPosX(), 558 + CAMERA->getPosY(), 40, RGB(255, 255, 255));
	}
}

void bag::uiOpen()
{

}

void bag::uiClose()
{
	_currentSelectNum = 0;
}

void bag::uiInfoSet()
{
	itemDataSet();
}

void bag::itemDataSet()
{
	locale("kor");

	//unordered_map<ITEM_TYPE, UINT> itemList = PLAYERDATA->getPlayet()->getItem();

	//=====================================================================�׽�Ʈ�� �����Ұ���
	unordered_map<ITEM_TYPE, UINT> itemList;

	itemList.insert(make_pair((ITEM_TYPE)0, 1));
	itemList.insert(make_pair((ITEM_TYPE)1, 1));
	itemList.insert(make_pair((ITEM_TYPE)2, 1));
	itemList.insert(make_pair((ITEM_TYPE)3, 1));
	itemList.insert(make_pair((ITEM_TYPE)4, 1));
	itemList.insert(make_pair((ITEM_TYPE)5, 1));
	itemList.insert(make_pair((ITEM_TYPE)6, 1));
	itemList.insert(make_pair((ITEM_TYPE)7, 1));
	itemList.insert(make_pair((ITEM_TYPE)8, 1));
	itemList.insert(make_pair((ITEM_TYPE)9, 1));
	itemList.insert(make_pair((ITEM_TYPE)10, 1));
	itemList.insert(make_pair((ITEM_TYPE)11, 1));
	itemList.insert(make_pair((ITEM_TYPE)12, 1));

	//======================================================================================


	unordered_map<ITEM_TYPE, UINT>::iterator iter = itemList.begin();
	unordered_map<ITEM_TYPE, UINT>::iterator end = itemList.end();

	for (int i = 0; iter != end && i < 39; ++iter, ++i)
	{
		if (iter->second == 0) continue;
		
		_bag[i]._isDataset = true;
		_bag[i].name.clear();

		item bagItem;
		bagItem.init(iter->first);

		_bag[i].name = string2wstring(bagItem.getItemName());
		_bag[i].type = bagItem.getItemType();
		_bag[i].info = string2wstring(bagItem.getItemInfo());
		_bag[i].amount = to_wstring(bagItem.getItemNum());
	}


	//=============================================================== �����ۼ��� �� �ǳ��ֱ�� ������ ����

	//pokemon** pokemons = PLAYERDATA->getPlayer()->getPokemon();
	//_pokemonCnt = PLAYERDATA->getPlayer()->getCurrentPokemonCnt() + 1;

	//=============================================================�ӽõ����� ���ﲨ��
	pokemon** pokemons = new pokemon*[5];
	_pokemonCnt = 5;

	for (int i = 0; i < 5; ++i)
	{
		pokemons[i] = new pokemon;
	}
	pokemons[0]->init(0, (POKEMON)0, 5, true);
	pokemons[1]->init(0, (POKEMON)1, 10, true);
	pokemons[2]->init(0, (POKEMON)2, 15, true);
	pokemons[3]->init(0, (POKEMON)3, 20, true);
	pokemons[4]->init(0, (POKEMON)4, 15, true);
	//pokemons[5]->init(0, (POKEMON)5, 30, true);

	//===============================================================================
	for (int i = 0; i < _pokemonCnt; ++i)
	{

		if (pokemons[i] == nullptr) continue;

		_iuPokemon[i].isDataSet = false;
		_iuPokemon[i].level = to_wstring(pokemons[i]->getLevel());
		_iuPokemon[i].name = string2wstring(pokemons[i]->getName());
		_iuPokemon[i].currentHp = to_wstring(pokemons[i]->getHp()); // ����?
		_iuPokemon[i].maxHp = to_wstring(pokemons[i]->getMaxHp()); // ��ü?

	}
}

void bag::itemUseScreen()
{
	//if (_bag_state == ITEM_USE_SELECT)
	{
		IMAGEMANAGER->findImage("���������ϸ�")->render(0 + CAMERA->getPosX(), 0 + CAMERA->getPosY());
		MENUMANAGER->findMenuFrame("���ϸ�������1")->render();

		if (_ie_Pokemon == USE_CANCEL)
		{
			IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 1);
		}
		else
		{
			IMAGEMANAGER->findImage("���ϸ�޴�_���")->frameRender(735 + CAMERA->getPosX(), 530 + CAMERA->getPosY(), 0, 0);
		}

		for (int i = 0; i < 6; ++i)
		{
			// ���� ���ϸ�
			if (i == 0)
			{
				if (_ie_Pokemon == SELECT_MAIN_POKEMON)
				{
					IMAGEMANAGER->findImage("�������ϸ�")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 2);
				}
				else
				{
					IMAGEMANAGER->findImage("�������ϸ�")->frameRender(80 + CAMERA->getPosX(), 50 + CAMERA->getPosY(), 0, 0);
				}

				//hp
				float currentHp = stof(_iuPokemon[i].currentHp);
				float maxHp = stof(_iuPokemon[i].maxHp);

				float hpPercent = currentHp / maxHp;

				if (hpPercent < 0)
				{
					hpPercent = 0;
				}
				if (hpPercent > 0.5f)
				{
					IMAGEMANAGER->findImage("ü�°�����")->frameRender(200 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), hpPercent * 192, 12, 2, 0);
				}
				else if (hpPercent > 0.2f && hpPercent <= 0.5f)
				{
					IMAGEMANAGER->findImage("ü�°�����")->frameRender(200 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), hpPercent * 192, 12, 1, 0);
				}
				else
				{
					IMAGEMANAGER->findImage("ü�°�����")->frameRender(200 + CAMERA->getPosX(), 213 + CAMERA->getPosY(), hpPercent * 192, 12, 0, 0);
				}

				D2DMANAGER->drawText(_iuPokemon[i].name.c_str(), 228, 115, 34, RGB(114, 114, 114));
				D2DMANAGER->drawText(_iuPokemon[i].name.c_str(), 225, 115, 34, RGB(255, 255, 255));
				D2DMANAGER->drawText(_iuPokemon[i].level.c_str(), 353, 170, 34, RGB(114, 114, 114));
				D2DMANAGER->drawText(_iuPokemon[i].level.c_str(), 350, 170, 34, RGB(255, 255, 255));
				D2DMANAGER->drawText(_iuPokemon[i].currentHp.c_str(), 263, 228, 48, RGB(114, 114, 114));
				D2DMANAGER->drawText(_iuPokemon[i].currentHp.c_str(), 260, 225, 48, RGB(255, 255, 255));
				D2DMANAGER->drawText(_iuPokemon[i].maxHp.c_str(), 343, 228, 48, RGB(114, 114, 114));
				D2DMANAGER->drawText(_iuPokemon[i].maxHp.c_str(), 340, 225, 48, RGB(255, 255, 255));
			}
			else
			{
				if (i < _pokemonCnt)
				{
					if (_ie_Pokemon == i)
					{
						// �ϴû�
						IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 50 + ((i - 1) * 90) + CAMERA->getPosY(), 1, 0);
					}
					else
					{
						// �Ķ���
						IMAGEMANAGER->findImage("�������ϸ�2")->frameRender(450 + CAMERA->getPosX(), 50 + ((i - 1) * 90) + CAMERA->getPosY(), 0, 0);
					}
					D2DMANAGER->drawText(_iuPokemon[i].name.c_str(), 553, 60 + ((i - 1) * 90), 30, RGB(114, 114, 114));
					D2DMANAGER->drawText(_iuPokemon[i].name.c_str(), 550, 60 + ((i - 1) * 90), 30, RGB(255, 255, 255));
					D2DMANAGER->drawText(_iuPokemon[i].level.c_str(), 623, 98 + ((i - 1) * 90), 38, RGB(114, 114, 114));
					D2DMANAGER->drawText(_iuPokemon[i].level.c_str(), 620, 95 + ((i - 1) * 90), 38, RGB(255, 255, 255));
					D2DMANAGER->drawText(_iuPokemon[i].currentHp.c_str(), 813, 98 + ((i - 1) * 90), 40, RGB(114, 114, 114));
					D2DMANAGER->drawText(_iuPokemon[i].currentHp.c_str(), 810, 95 + ((i - 1) * 90), 40, RGB(255, 255, 255));
					D2DMANAGER->drawText(_iuPokemon[i].maxHp.c_str(), 883, 98 + ((i - 1) * 90), 40, RGB(114, 114, 114));
					D2DMANAGER->drawText(_iuPokemon[i].maxHp.c_str(), 880, 95 + ((i - 1) * 90), 40, RGB(255, 255, 255));

					//hp
					float currentHp = stof(_iuPokemon[i].currentHp);
					float maxHp = stof(_iuPokemon[i].maxHp);

					float hpPercent = currentHp / maxHp;

					if (hpPercent < 0)
					{
						hpPercent = 0;
					}
					if (hpPercent > 0.5f)
					{
						IMAGEMANAGER->findImage("ü�°�����")->frameRender(770 + CAMERA->getPosX(), 80 + ((i - 1) * 90) + CAMERA->getPosY(), hpPercent * 160, 10, 2, 0);
					}
					else if (hpPercent > 0.2f && hpPercent <= 0.5f)
					{
						IMAGEMANAGER->findImage("ü�°�����")->frameRender(770 + CAMERA->getPosX(), 80 + ((i - 1) * 90) + CAMERA->getPosY(), hpPercent * 160, 10, 1, 0);
					}
					else
					{
						IMAGEMANAGER->findImage("ü�°�����")->frameRender(770 + CAMERA->getPosX(), 80 + ((i - 1) * 90) + CAMERA->getPosY(), hpPercent * 160, 10, 0, 0);
					}
				}
				else
				{
					IMAGEMANAGER->findImage("�������ϸ�1")->render(450 + CAMERA->getPosX(), 50 + ((i - 1) * 90) + CAMERA->getPosY());
				}
			}
		}
	}
}
