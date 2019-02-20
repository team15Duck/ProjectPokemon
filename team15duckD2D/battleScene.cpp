#include "stdafx.h"
#include "battleScene.h"


battleScene::battleScene()
: _frameX(0)
, _frameY(0)
{
}


battleScene::~battleScene()
{
}

HRESULT battleScene::init()
{
	// 배틀 ui
	_battleUI = new battleUI;
	_battleUI->init();
	
	// 적 포켓몬
	_pokemon = PLAYERDATA->getPokemon();
	PLAYERDATA->setPokemon(nullptr);

	// 플레이어 포켓몬 todo
	//int pmCnt = PLAYERDATA->getPlayer()->getCurrentPokemonCnt();
	for (int ii = 0; ii < 6; ++ii)
	{
		// todo
		//_myPms[ii] = PLAYERDATA->getPlayer()->getPokemon()[ii];
	}

	// 테스트용 삭제 될 것
	{
		_pokemon = new pokemon;
		_pokemon->init(NULL, PM_VENUSAUR, 5, false);
		
		_myPms[0] = new pokemon;
		_myPms[0]->init(NULL, PM_BULBASAUR, 99, true);

		_myPms[1] = new pokemon;
		_myPms[1]->init(NULL, PM_CHARMANDER, 10, true);

		_myPms[2] = new pokemon;
		_myPms[2]->init(NULL, PM_SQUIRTLE, 15, true);

		_myPms[3] = new pokemon;
		_myPms[3]->init(NULL, PM_MAGIKARP, 20, true);

		_myPms[4] = new pokemon;
		_myPms[4]->init(NULL, PM_PIKACHU, 25, true);

		_myPms[5] = new pokemon;
		_myPms[5]->init(NULL, PM_CHARIZARD, 30, true);
	}

	_turn = TURN_PLAYER;
	_phase = PHASE_START;
	_active = PA_NONE;
	_battleStep = STEP_APPLY_BUFF;
	_selPokemon = 0;
	_selectSkillIdx = 0;
	_pms[TURN_ENEMY] = _pokemon;
	_pms[TURN_PLAYER] = _myPms[_selPokemon];

	_pms[TURN_ENEMY]->setBattleUILink(_battleUI);
	_pms[TURN_PLAYER]->setBattleUILink(_battleUI);
	
	_pms[TURN_ENEMY]->battelStart();
	_pms[TURN_PLAYER]->battelStart();

	_pms[TURN_ENEMY]->setTargetPokemon(_pms[TURN_PLAYER]);
	_pms[TURN_PLAYER]->setTargetPokemon(_pms[TURN_ENEMY]);

	_background = IMAGEMANAGER->findImage("battleBackground");
	_pokemonImg = IMAGEMANAGER->findImage("pokemon_ingame");


	// todo 야생 포켓몬 출현 지역에 따라 배경이 바뀜

	string sceneName;
	sceneName.clear();
	
	sceneName = PLAYERDATA->getPlayer()->getSceneName();

	if (sceneName.compare("caveScene") == 0)		{ _frameX = 0; _frameY = 1; }
	else if (sceneName.compare("fieldScene") == 0)	{ _frameX = 1; _frameY = 0; }
	else if (sceneName.compare("gymScene") == 0)	{ _frameX = 0; _frameY = 0; }
	else if (sceneName.compare("oLabScene") == 0)	{ _frameX = 0; _frameY = 3; }

	return S_OK;
}

void battleScene::release()
{
	SAFE_DELETE(_pokemon);
	SAFE_RELEASE(_battleUI);
	SAFE_DELETE(_battleUI);

	_background = nullptr;
	for (int ii = 0; ii < 6; ++ii)
	{
		_myPms[ii] = nullptr;
	}

	_pms[TURN_PLAYER] = nullptr;
	_pms[TURN_ENEMY] = nullptr;
}

void battleScene::update()
{
	//유아이는 실시간업뎃해야됨
	_battleUI->update();

	//스크립트가 실행중이다? 그럼 아무것도못해
	if (!_battleUI->battleSceneUpdate()) return;

	// 진화중이라면
	if (_isEvolution)
	{
		_evolutionDisTime -= TIMEMANAGER->getElapsedTime();
		if (_evolutionDisTime < 0.f)
		{
			_evolutionDisTime = 0.1;
			--_evolutionDisCount;

			if (_evolutionDisCount % 2 == 0)
			{
				_evolFrameX = _evPokemon.curFrameX;
				_evolFrameY = _evPokemon.curFrameY;
			}
			else
			{
				_evolFrameX = _evPokemon.evolutionFrameX;
				_evolFrameY = _evPokemon.evolutionFrameY;
			}
		}
		
		if (1 < _evolutionDisCount)
			return;
			
		_myPms[_evPokemon.index]->displayEvolution();
		
		if (!_battleUI->isKeyDownKeyZ())
		{
			wstring script;
			script.clear();
			script.append(string2wstring(_myPms[_evPokemon.index]->getName()));
			script.append(L"로 진화를 했다!");
			_battleUI->pushScript(script);
			_battleUI->setScriptSkip(false);
		}
		else
		{
			_isEvolution = false;
		}
	}
	
	// 포켓몬 상태 업데이트
	_pms[TURN_ENEMY]->update();
	_pms[TURN_PLAYER]->update();

	// 행동 대기중이 아니라면 
	if (!_pms[TURN_ENEMY]->isIdle() || !_pms[TURN_PLAYER]->isIdle())
	{
		return;
	}

	_battleUI->setIsBattle(false);
	switch (_phase)
	{
		case PHASE_START:
		{
			battleStart();
			break;
		}
		case PHASE_BATTLE:
		{
			_battleUI->setIsBattle(true);
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
					_battleUI->setIsPlayerTurn(true);
					keyControl();

					// todo 키 선택 결과 행동
					switch (_active)
					{
						case PA_USE_SKILL:
						{
							_pms[_turn]->useSkill(_selectSkillIdx);
							_battleUI->setCurrentPP(_selectSkillIdx);
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
	if (_isEvolution)
	{
		_pokemonImg->frameRender(CAMERA->getPosX() + (WINSIZEX - _pokemonImg->GetFrameWidth()) / 2.f, CAMERA->getPosY() + (WINSIZEY - _pokemonImg->GetFrameHeight()) / 2.f, _evolFrameX, _evolFrameY);
	}
	else
	{
		_background->frameRender(CAMERA->getPosX() + 0, CAMERA->getPosY() + 0, _frameX, _frameY);

		_pms[TURN_ENEMY]->render();
		_pms[TURN_PLAYER]->render();
	}

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
			_selectSkillIdx = _battleUI->getCurrentSelectSkill();
			if (_battleUI->getCurrentPP(_selectSkillIdx) <= 0) return;
			_active = PA_USE_SKILL;

			_battleUI->setCurrentMenu(BATTLE_UI_NONE);
			_battleUI->setCurrentSelectSkill(0);

			_battleUI->setIsPlayerTurn(false);
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
	
	_battleUI->skillUIClear();
	for (int ii = 0; ii < POKEMON_SKILL_MAX_COUNT; ++ii)
	{
		pokemonSkillInfo info = *skills[ii].getSkillInfomation();
		if (info.getSkillID() != SKILL_INDEX_NONE)
		{
			_battleUI->addSkill(string2wstring(info.getSkillName()), skills[ii].getCurrentPP(), skills[ii].getMaxPP(), info.getSkillTypeName());
		}
	} 

	_battleUI->setMyPokemonMemoryAdressLink(_pms[TURN_PLAYER]);
	_battleUI->setEnemyPokemonMemoryAdressLink(_pms[TURN_ENEMY]);

	_pms[TURN_ENEMY]->setBattleUILink(_battleUI);
	_pms[TURN_PLAYER]->setBattleUILink(_battleUI);

	_pms[TURN_ENEMY]->battelStart();
	_pms[TURN_PLAYER]->battelStart();

	_pms[TURN_ENEMY]->setTargetPokemon(_pms[TURN_PLAYER]);
	_pms[TURN_PLAYER]->setTargetPokemon(_pms[TURN_ENEMY]);

	_turn = TURN_PLAYER;
	_active = PA_NONE;
	_battleStep = STEP_APPLY_BUFF;
	_selectSkillIdx = 0;

	_phase = PHASE_BATTLE;

	if (_expList.find(_selPokemon) == _expList.end())
	{
		_expList.insert(_selPokemon);
	}
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
				int value = 1000; //2 * _pms[TURN_ENEMY]->getLevel();
				if(_pms[TURN_PLAYER]->getLevel() < _pms[TURN_ENEMY]->getLevel())
					value = _pms[TURN_ENEMY]->getLevel() - _pms[TURN_PLAYER]->getLevel();


				// 경험치 분배
				int cnt = _expList.size();
				value /= cnt;
				for (set<UINT>::iterator iter = _expList.begin(); _expList.end() != iter; ++iter)
				{
					int index = *iter;

					_myPms[index]->gainExp(value);
					
					script.clear();
					script = string2wstring(_myPms[index]->getName());
					script.append(L"은(는)");
					script.append(to_wstring(value));
					script.append(L"의 경험치를 획득하였다!");

					_battleUI->pushScript(script);
				}

				// 적 포켓몬 변경
				_turn = TURN_ENEMY;
				
				_phase = PHASE_EVOLUTION;
			}
			else
			{
				wstring script = string2wstring(_pms[TURN_PLAYER]->getName());
				script.append(L"이(가) 쓰러졌다!");

				_battleUI->pushScript(script);

				// 해당 포켓몬 기절함
				_pms[TURN_PLAYER]->faint();

				// 플레이어 포켓몬 변경
				_turn = TURN_PLAYER;
		
				// 포켓몬 변경
				_phase = PHASE_CHANGE;
			}
		}
	}
}

void battleScene::battleEnd()
{
	wstring script = L"배틀 종료";
	_expList.clear();
	_battleUI->pushScript(script);
}

void battleScene::battleChange()
{
	// todo
	//wstring script = L"포켓몬을 교체해보자";
	//_battleUI->pushScript(script);

	_selPokemon++;
	//if(PLAYERDATA->getPlayer()->getCurrentPokemonCnt() < _selPokemon)
	if(6 <= _selPokemon)
		_phase = PHASE_END;
	else
		_pms[TURN_PLAYER] = _myPms[_selPokemon];

	_phase = PHASE_START;
}

void battleScene::battleEvolution()
{
	set<UINT>::iterator iter = _expList.begin();
	set<UINT>::iterator end = _expList.end();

	for (; iter != end; )
	{
		int index = *iter;
		iter = _expList.erase(iter);

		if (_myPms[index]->isPossibleEvolution())
		{
			EVOLUTIONPOKEMON evPokemon;

			int idx = _myPms[index]->getPokeminIndex();
			int evIndex = _myPms[index]->getEvolutionIndex();

			evPokemon.curFrameX = (idx * 2) % _pokemonImg->GetMaxFrameX();
			evPokemon.curFrameY = (idx * 2) / _pokemonImg->GetMaxFrameX();

			evPokemon.evolutionFrameX = (evIndex * 2) % _pokemonImg->GetMaxFrameX();
			evPokemon.evolutionFrameY = (evIndex * 2) / _pokemonImg->GetMaxFrameX();

			_evPokemon = evPokemon;

			_isEvolution = true;
			
			_evPokemon.index = index;

			_evolFrameX = _evPokemon.curFrameX;
			_evolFrameY = _evPokemon.curFrameY;

			_evolutionDisTime = 0.1f;
			_evolutionDisCount = 20;

			wstring script = L"어..?\n";
			script.append(string2wstring(_myPms[index]->getName()));
			script.append(L"의 상태가..?");
			_battleUI->pushScript(script);
			
			return;
		}
	}

	_phase = PHASE_END;
}
