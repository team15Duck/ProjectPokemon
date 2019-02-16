#include "stdafx.h"
#include "battleScene.h"


battleScene::battleScene()
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init()
{
	_pokemon = PLAYERDATA->getPokemon();
	PLAYERDATA->setPokemon(nullptr);
	_battleUI = new battleUI;
	_battleUI->init();
	// �׽�Ʈ�� ���� �� ��
	{
		_pms[TURN_ENEMY] = new pokemon;
		_pms[TURN_ENEMY]->init(NULL, PM_VENUSAUR, 100, false);
		_pms[TURN_ENEMY]->setBattleUILink(_battleUI);
		_pms[TURN_ENEMY]->battelStart();

		_pms[TURN_PLAYER] = new pokemon;
		_pms[TURN_PLAYER]->init(NULL, PM_CHARIZARD, 100, true);
		_pms[TURN_PLAYER]->setBattleUILink(_battleUI);
		_pms[TURN_PLAYER]->battelStart();

		_pms[TURN_ENEMY]->setTargetPokemon(_pms[TURN_PLAYER]);
		_pms[TURN_PLAYER]->setTargetPokemon(_pms[TURN_ENEMY]);

		_turn = TURN_PLAYER;
		_phase = PHASE_BATTLE; 
		cnt = 0;
		termTime = 1.0f;
	}
	return S_OK;
}

void battleScene::release()
{
	SAFE_DELETE(_pokemon);
	SAFE_RELEASE(_battleUI);
	SAFE_DELETE(_battleUI);
}

void battleScene::update()
{
	//�����̴� �ǽð������ؾߵ�
	_battleUI->update();


	//��ũ��Ʈ�� �������̴�? �׷� �ƹ��͵�����
	if (!_battleUI->battleSceneUpdate()) return;
	


	_pms[TURN_ENEMY]->update();
	_pms[TURN_PLAYER]->update();


	//�׳� ���̴����� ���⼭ ����
	//�׳� ���̴����� ���⼭ ����
	//�׳� ���̴����� ���⼭ ����
	//�׳� ���̴����� ���⼭ ����


	// �ൿ ������� �ƴ϶�� 
	if (!_pms[TURN_ENEMY]->isIdle() || !_pms[TURN_PLAYER]->isIdle())
	{
		return;
	}
	keyControl();

	//�÷��̾� ����
	//�÷��̾� ����
	//�÷��̾� ����
	//�÷��̾� ����


	

	// �׽�Ʈ
	switch (_phase)
	{
		case PHASE_START:
			break;
		case PHASE_BATTLE:
		{
			if (!_pms[TURN_ENEMY]->isAwake())				// �� ���ϸ� ������
			{
				wstring script = string2wstring(_pms[TURN_ENEMY]->getName());
				script.append(L"��(��) ��������!");

				_battleUI->pushScript(script);

				// ���� ��Ʋ ����
				_phase = PHASE_END;
			}
			else if (!_pms[TURN_PLAYER]->isAwake())			// �÷��̾� ���ϸ� ������
			{
				wstring script = string2wstring(_pms[TURN_ENEMY]->getName());
				script.append(L"��(��) ��������!");

				_battleUI->pushScript(script);

				// ���� ��Ʋ ����
				_phase = PHASE_END;
			}
			else // ��Ʋ ����
			{
				++cnt;
				switch (cnt)
				{
					case 1:	{ _pms[_turn]->applyBuff();	break;			 }
					case 2:	{ _pms[_turn]->useOwnerItem(); break;		 }
					case 3:	{ _pms[_turn]->applyUpsetCondition(); break; }
					case 4:
					{
						if (TURN_ENEMY == _turn)
						{
							int cnt = 0;
							for (; cnt < POKEMON_SKILL_MAX_COUNT; ++cnt)
							{
								if (_pms[_turn]->getPokemonSkills()[cnt].getSkillID() == SKILL_INDEX_NONE)
									break;
							}

							_pms[_turn]->useSkill(RND->getInt(cnt));
						}
						else
						{
							int cnt = 0;
							for (; cnt < POKEMON_SKILL_MAX_COUNT; ++cnt)
							{
								if (_pms[_turn]->getPokemonSkills()[cnt].getSkillID() == SKILL_INDEX_NONE)
									break;
							}

							_pms[_turn]->useSkill(RND->getInt(cnt));
						}
						break;
					}

					default:
					{
						cnt = 0;
						_turn = (BattleTurn)(TURN_MAX - _turn);

						break;
					}
				}
			}

			break;
		}
		case PHASE_END:
		{
			if (_pms[TURN_PLAYER]->isAwake())
			{
				// todo �÷��̾� ���ϸ� ���� ����ġ ���
				int value = 10;
				_pms[TURN_PLAYER]->gainExp(value);
				
				wstring script = string2wstring(_pms[TURN_PLAYER]->getName());
				script.append(L"��(��)");
				script.append(to_wstring(value));
				script.append(L"�� ����ġ�� ȹ���Ͽ���!");

				_battleUI->pushScript(script);
				
				// �� ���ϸ� ���� ���� �� ���̱� ������.
				_turn = TURN_ENEMY;
			}

			// ���ϸ� ����
			_phase = PHASE_CHANGE;
			break;
		}
		case PHASE_CHANGE:
		{
			wstring script = L"���ϸ��� ��ü�غ���";
			_battleUI->pushScript(script);

			break;
		}
		case PHASE_EVOLUTION:
			break;
		default:
			break;
	}

	
}

void battleScene::render()
{
	_pms[TURN_ENEMY]->render();
	_pms[TURN_PLAYER]->render();

	WCHAR str[128];
	swprintf_s(str, L" [%d] : time : %.2f", cnt, termTime);
	D2DMANAGER->drawText(str, CAMERA->getPosX() + WINSIZEX / 2, CAMERA->getPosY() + WINSIZEY / 2);

	_battleUI->render();
}

void battleScene::keyControl()
{
	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_battleUI->getCurrentSelectMenuNum() == 2 || _battleUI->getCurrentSelectMenuNum() == 3)
		{
			_battleUI->setCurrentSelctMenuNum(_battleUI->getCurrentSelectMenuNum() - 2);
		}
		else if (_battleUI->getCurrentSelectMenuNum() == 1)
		{
			_battleUI->setCurrentSelctMenuNum(2);
		}
		else if (_battleUI->getCurrentSelectMenuNum() == 0)
		{
			_battleUI->setCurrentSelctMenuNum(3);
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_battleUI->getCurrentSelectMenuNum() == 0 || _battleUI->getCurrentSelectMenuNum() == 1)
		{
			_battleUI->setCurrentSelctMenuNum(_battleUI->getCurrentSelectMenuNum() + 2);
		}
		else if (_battleUI->getCurrentSelectMenuNum() == 2)
		{
			_battleUI->setCurrentSelctMenuNum(1);
		}
		else if (_battleUI->getCurrentSelectMenuNum() == 3)
		{
			_battleUI->setCurrentSelctMenuNum(0);
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		if (_battleUI->getCurrentSelectMenuNum() > 0)
		{
			_battleUI->setCurrentSelctMenuNum(_battleUI->getCurrentSelectMenuNum() - 1);
		}
		else
		{
			_battleUI->setCurrentSelctMenuNum(3);
		}
	}
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_battleUI->setCurrentSelctMenuNum(_battleUI->getCurrentSelectMenuNum() + 1);
		if (_battleUI->getCurrentSelectMenuNum() == 4)
		{
			_battleUI->setCurrentSelctMenuNum(0);
		}
	}


}
