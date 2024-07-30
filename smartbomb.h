#ifndef SMARTBOMB_H_INCLUDED
#define SMARTBOMB_H_INCLUDED

#include "timer.h"

#include "pc.h"
#include "bullet.h"

struct Smartbomb
{
	static bool isActive;

	enum enumSmartbombTypes
	{
		SMARTBOMB_KATHETOS = 0,
		SMARTBOMB_KLAFTHMOS = 1
	};
	static const int NUM_TYPES = 2;
	static int type;

	enum enumHitboxShapes
	{
		SMARTBOMB_HITBOX_RECTANGULAR,
		SMARTBOMB_HITBOX_RADIAL
	};

	static int hitboxShape;

	static bool isReady;
	
	static int charge;
	static const int CHARGE_MAX = 100;
	static const int RECHARGE_OVER_TIME = 1;
	static const int RECHARGE_FROM_LOCKON = 1;
	static int timerCycles;
	static const int TIMER_CYCLES_PER_RECHARGE_TICK = Timer::FPS * 3;

	static int activeLifespan;
	static const int BASE_ACTIVE_LIFESPAN = Timer::FPS * 0.5;

	static float xPosition;
	static float yPosition;
	
	static float diameter;
	static constexpr float BASE_DIAMETER = 64;
	static float diameterScaling;
	static float diameterScalingRate;


	static void Initialize();
	static void Logic();
	static void Drawing();
	static void Fire(PC *firing_pc);
	static void Reset();
};

#endif // SMARTBOMB_H_INCLUDED
