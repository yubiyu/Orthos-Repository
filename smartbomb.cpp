#include "smartbomb.h"

bool Smartbomb::isActive;
int Smartbomb::type;
int Smartbomb::hitboxShape;
bool Smartbomb::isReady;
int Smartbomb::charge;
int Smartbomb::timerCycles;
int Smartbomb::activeLifespan;
float Smartbomb::xPosition;
float Smartbomb::yPosition;
float Smartbomb::diameter;
float Smartbomb::diameterScaling;
float Smartbomb::diameterScalingRate;

void Smartbomb::Initialize()
{
	isActive = false;
	type = SMARTBOMB_KATHETOS;
	hitboxShape = SMARTBOMB_HITBOX_RECTANGULAR;

	isReady = true;

	charge = 100;
	timerCycles = 0;
	activeLifespan = BASE_ACTIVE_LIFESPAN;

	xPosition = 0;
	yPosition = 0;
	diameter = BASE_DIAMETER;
	diameterScaling = 1.0;
	diameterScalingRate = 0.8;
}

void Smartbomb::Logic()
{
	if (!isReady)
	{
		timerCycles++;
		if (timerCycles >= TIMER_CYCLES_PER_RECHARGE_TICK)
		{
			timerCycles = 0;
			charge += RECHARGE_OVER_TIME;
			std::cout << charge << std::endl;
			if (charge >= CHARGE_MAX)
			{
				Reset();
			}

		}

	}

	if (isActive)
	{
		activeLifespan--;
		if (activeLifespan <= 0)
		{
			isActive = false;
			diameter = BASE_DIAMETER;
			diameterScaling = 1.0;

			for (std::vector<NPC*>::iterator it = NPC::npcs.begin(); it != NPC::npcs.end(); ++it)
			{
				(*it)->SetCurrentHP((*it)->GetCurrentHP() - 100);
			}
		}
		else 
		{
			diameterScaling += diameterScalingRate;
			diameter = BASE_DIAMETER * diameterScaling;

			for (std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end(); ++it)
			{
				if ((*it)->GetXPosition() > xPosition - diameter / 2
					&& (*it)->GetXPosition() < xPosition + diameter / 2
					&& (*it)->GetYPosition() > yPosition - diameter / 2
					&& (*it)->GetYPosition() < yPosition + diameter / 2)
				{
					if((*it)->GetIsNPCBullet())
						(*it)->SetIsActive(false);
				}
			}
		}
	}
}

void Smartbomb::Drawing()
{
	if (isActive)
	{
		al_draw_scaled_rotated_bitmap(Image::orthosSmartbombPng,
			diameter/diameterScaling, diameter/diameterScaling,
			xPosition, yPosition,
			diameterScaling, diameterScaling,
			ALLEGRO_PI * 0.25, 0);
	}

}

void Smartbomb::Fire(PC* firing_pc)
{
	if (isReady)
	{
		isReady = false;
		isActive = true;
		charge = 0;
		xPosition = firing_pc->GetXPosition();
		yPosition = firing_pc->GetYPosition();

		/*
		switch (type)
		{
		case SMARTBOMB_KATHETOS:
			hitboxShape = SMARTBOMB_HITBOX_RECTANGULAR;
			diameterScalingRate = 0.1;
			break;

		case SMARTBOMB_KLAFTHMOS:
			hitboxShape = SMARTBOMB_HITBOX_RADIAL;
			diameterScalingRate = 0.1;
			break;
		}
		*/

	}
}

void Smartbomb::Reset()
{
	std::cout << "Debug: smartbomb reset" << std::endl;
	isReady = true;
	isActive = false;
	charge = CHARGE_MAX;
	timerCycles = 0;
	activeLifespan = BASE_ACTIVE_LIFESPAN;
	diameter = BASE_DIAMETER;
	diameterScaling = 1.0;
}

