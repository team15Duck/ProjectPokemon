#pragma once
 
//턴 ----------- 1에서 현재값을 빼주며 변경
enum BattleTurn
{
	TURN_PLAYER,
	TURN_ENEMY,
	TURN_MAX = TURN_ENEMY
};

//페이즈 이넘으로 나눠서 ㄱㄱ
enum BattlePhase
{
	PHASE_START,
	PHASE_BATTLE,
	PHASE_EXP,
	PHASE_END,
	PHASE_EVOLUTION
};
