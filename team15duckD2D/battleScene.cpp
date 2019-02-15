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
	_battleUI->update();
	if (!_battleUI->battleSceneUpdate()) return;
	
	_pms[TURN_ENEMY]->update();
	_pms[TURN_PLAYER]->update();

	// 테스트
	switch (_phase)
	{
		case PHASE_START:
			break;
		case PHASE_BATTLE:
		{
			// 행동 대기중이 아니라면 
			if (!_pms[_turn]->isIdle())
			{
				break;
			}

			++cnt;
			switch (cnt)
			{
				case 1:
				{
					_pms[_turn]->applyBuff();
					break;
				}

				case 2:
				{
					_pms[_turn]->useOwnerItem();
					break;
				}

				case 3:
				{
					_pms[_turn]->applyUpsetCondition();
					break;
				}

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
					cnt = 0;
					_turn = (BattleTurn)(TURN_MAX - _turn);

					break;
			}

			if (!_pms[TURN_ENEMY]->isAwake() || !_pms[TURN_PLAYER]->isAwake())
			{
				_phase = PHASE_CHANGE;
			}
			break;
		}
		case PHASE_END:
			break;
		case PHASE_CHANGE:
			break;
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
