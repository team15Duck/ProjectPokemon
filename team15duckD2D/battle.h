#pragma once
 
//�� ----------- 1���� ���簪�� ���ָ� ����
enum BattleTurn
{
	TURN_PLAYER,
	TURN_ENEMY,
	TURN_MAX = TURN_ENEMY
};

//������ �̳����� ������ ����
enum BattlePhase
{
	PHASE_START,
	PHASE_BATTLE,
	PHASE_EXP,
	PHASE_END,
	PHASE_EVOLUTION
};
