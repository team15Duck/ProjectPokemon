#pragma once
 
//턴 ----------- 인티저변수로 하나가 지나갈때마다 ++해주고 이걸로 비교 %2
enum BattleTurn
{
	TURN_PLAYER,
	TURN_ENEMY
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