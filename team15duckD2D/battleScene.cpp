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

		_pms[TURN_PLAYER] = new pokemon;
		_pms[TURN_PLAYER]->init(NULL, PM_CHARIZARD, 100, true);

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

	if (!_battleUI->battleSceneUpdate())return;
	// 테스트
	{
		_pms[TURN_ENEMY]->update();
		_pms[TURN_PLAYER]->update();

		if (_pms[_turn]->isIdle())
		{
			termTime -= TIMEMANAGER->getElapsedTime();
			if (termTime < 0.f)
			{
				termTime = 1.0f;

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
						int cnt = 0;
						for (; cnt < POKEMON_SKILL_MAX_COUNT; ++cnt)
						{
							if (_pms[_turn]->getPokemonSkills()[cnt].getSkillID() == SKILL_INDEX_NONE)
								break;
						}

						_pms[_turn]->useSkill(RND->getInt(cnt));
						break;
					}

					default:
						cnt = 0;
						_turn = (BattleTurn)(TURN_MAX - _turn);

						break;
				}
			}
		}
	}
}

void battleScene::render()
{
	_pms[TURN_ENEMY]->render();
	_pms[TURN_PLAYER]->render();

	WCHAR str[128];
	swprintf_s(str, L" [%d] : time : %.2f", cnt, termTime);
	D2DMANAGER->drawText(str, CAMERA->getPosX() + WINSIZEX / 2, CAMERA->getPosY() + WINSIZEY / 2);
}
