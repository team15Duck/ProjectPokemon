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
	// 테스트용 삭제 될 것
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
		_phase = PHASE_START; 
		_active = PA_NONE;
		_battleStep = STEP_APPLY_BUFF;
		_selectSkillIdx = 0;
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
	//유아이는 실시간업뎃해야됨
	_battleUI->update();

	//스크립트가 실행중이다? 그럼 아무것도못해
	if (!_battleUI->battleSceneUpdate()) return;
	
	switch (_phase)
	{
		case PHASE_START:
		{
			battleStart();
			break;
		}
		case PHASE_BATTLE:
		{
			// 포켓몬 상태 업데이트
			_pms[TURN_ENEMY]->update();
			_pms[TURN_PLAYER]->update();

			// 행동 대기중이 아니라면 
			if (!_pms[TURN_ENEMY]->isIdle() || !_pms[TURN_PLAYER]->isIdle())
			{
				return;
			}

			// 적 포켓몬이나 플레이어 포켓몬이 쓰러짐
			if (!_pms[TURN_ENEMY]->isAwake() || !_pms[TURN_PLAYER]->isAwake())
			{
				// 현재 배틀 종료
				_battleStep = STEP_END;
				battle();
			}
			else
			{
				if(TURN_ENEMY == _turn)						// 적 턴
					battle();
				else if(_active == PA_ACTIVE_END)			// 플레이어 행동 종료
					battle();
				else										// 플레이어 행동 선택
				{
					keyControl();

					// todo 키 선택 결과 행동
					switch (_active)
					{
						case PA_USE_SKILL:
						{
							_pms[_turn]->useSkill(_selectSkillIdx);
							_active = PA_ACTIVE_END;
							break;
						}
						case PA_USE_ITEM:
						{
							_active = PA_ACTIVE_END;
							break;
						}
						case PA_CHANGE_POKEMON:
						{
							_phase = PHASE_CHANGE;
							_active = PA_ACTIVE_END;
							break;
						}
						case PA_RUNAWAY:
						{
							_active = PA_ACTIVE_END;
							break;
						}
					}
				}
			}

			break;
		}
		case PHASE_END:
		{
			battleEnd();
			break;
		}
		case PHASE_CHANGE:
		{
			battleChange();
			break;
		}
		case PHASE_EVOLUTION:
		{
			battleEvolution();
			break;
		}
		default:
			break;
	}
}

void battleScene::render()
{
	_pms[TURN_ENEMY]->render();
	_pms[TURN_PLAYER]->render();

	_battleUI->render();
}

void battleScene::keyControl()
{
	if (_battleUI->getCurrentMenu() == BATTLE_UI_NONE)
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
	else if (_battleUI->getCurrentMenu() == BATTLE_UI_SKILL)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			if (_battleUI->getCurrentSelectSkill() > 0)
			{
				_battleUI->setCurrentSelectSkill(_battleUI->getCurrentSelectSkill() - 1);
			}
			else
			{
				_battleUI->setCurrentSelectSkill(_battleUI->getSkillSize() - 1);
			}
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_battleUI->setCurrentSelectSkill(_battleUI->getCurrentSelectSkill() + 1);
			if (_battleUI->getCurrentSelectSkill() == _battleUI->getSkillSize())
			{
				_battleUI->setCurrentSelectSkill(0);
			}
		}
		if (KEYMANAGER->isOnceKeyDown('Z'))
		{
			_active = PA_USE_SKILL;
			_selectSkillIdx = _battleUI->getCurrentSelectSkill();

			_battleUI->setCurrentMenu(BATTLE_UI_NONE);
			_battleUI->setCurrentSelectSkill(0);
		}
		if (KEYMANAGER->isOnceKeyDown('X'))
		{
			_battleUI->setCurrentMenu(BATTLE_UI_NONE);
		}
	}


}



void battleScene::battleStart()
{
	// todo

	wstring script = L"배틀 시작!";
	_battleUI->pushScript(script);

	pokemonSkill* skills = _pms[TURN_PLAYER]->getPokemonSkills();
	
	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		pokemonSkillInfo info = *skills[ii].getSkillInfomation();
		if (info.getSkillID() != SKILL_INDEX_NONE)
		{
			_battleUI->addSkill(string2wstring(info.getSkillName()), skills[ii].getCurrentPP(), skills[ii].getMaxPP(), info.getSkillTypeName());
		}
	} 

	_phase = PHASE_BATTLE;
}

void battleScene::battle()
{
	switch (_battleStep)
	{
		case STEP_APPLY_BUFF:			{ _pms[_turn]->applyBuff();				_battleStep = STEP_USE_OWNER_ITEM;		break;	}
		case STEP_USE_OWNER_ITEM:		{ _pms[_turn]->useOwnerItem();			_battleStep = STEP_APPLY_UPSETCONDITON; break;	}
		case STEP_APPLY_UPSETCONDITON:	{ _pms[_turn]->applyUpsetCondition();	_battleStep = STEP_ACTIVE;				break;	}
		
		case STEP_ACTIVE:
		{
			if (TURN_PLAYER == _turn)
			{
				_active = PA_NONE;
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

			// 다시 배틀 첫 단계로
			_battleStep = STEP_APPLY_BUFF;
			// 턴 변경
			_turn = (BattleTurn)(TURN_MAX - _turn);
			break;
		}

		case STEP_END:
		{
			if (_pms[TURN_PLAYER]->isAwake())
			{
				wstring script = string2wstring(_pms[TURN_ENEMY]->getName());
				script.append(L"이(가) 쓰러졌다!");

				_battleUI->pushScript(script);

				// todo 플레이어 포켓몬 전투 경험치 계산
				int value = 10;
				_pms[TURN_PLAYER]->gainExp(value);

				script.clear();
				script = string2wstring(_pms[TURN_PLAYER]->getName());
				script.append(L"은(는)");
				script.append(to_wstring(value));
				script.append(L"의 경험치를 획득하였다!");

				_battleUI->pushScript(script);

				// 적 포켓몬 변경
				_turn = TURN_ENEMY;
			}
			else
			{
				wstring script = string2wstring(_pms[TURN_ENEMY]->getName());
				script.append(L"이(가) 쓰러졌다!");

				_battleUI->pushScript(script);

				// 플레이어 포켓몬 변경
				_turn = TURN_PLAYER;
			}

			// 포켓몬 변경
			_phase = PHASE_CHANGE;
		}
	}
}

void battleScene::battleEnd()
{
}

void battleScene::battleChange()
{
	// todo
	wstring script = L"포켓몬을 교체해보자";
	_battleUI->pushScript(script);


}

void battleScene::battleEvolution()
{
}
