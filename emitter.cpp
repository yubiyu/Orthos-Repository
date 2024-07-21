#include "emitter.h"

Emitter::Emitter()
{

}

Emitter::~Emitter()
{

}

void Emitter::Initialize(int bullet_form, float bullet_speed, unsigned num_bullets, float fire_arc_length, float fire_angle, int fire_rate, int fire_repeat_rate, int fire_repeat_length)
{
    Actor::Initialize();

    SetIsOnline(true);
    SetIsNPCEmitter(false);
    SetTrackedTarget(nullptr);

    SetHasTrackedPosition(false);
    SetTrackedXYPosition(0,0);

    bulletForm = bullet_form;
    bulletSpeed = bullet_speed;

    bulletLifespan = BULLET_BASE_LIFESPAN;

    numBullets = num_bullets;
    if(numBullets == 0)
        numBullets = 1;

    fireArcLength = fire_arc_length;
    fireAngle = fire_angle;

    fireCD = 0;
    fireRate = fire_rate;

    fireRepeatCD = 0;
    fireRepeatRate = fire_repeat_rate;
    fireRepeatPhase = 0;
    fireRepeatLength = fire_repeat_length;
}

void Emitter::Logic()
{
    if(hasTrackedTarget)
    {
        float opposite = GetTrackedTarget()->GetYPosition() - GetYPosition();
        float adjacent = GetTrackedTarget()->GetXPosition() - GetXPosition();

        fireAngle = std::atan2( opposite, adjacent );
    }
    else if(hasTrackedPosition)
    {
        float opposite = trackedYPosition - GetYPosition();
        float adjacent = trackedXPosition - GetXPosition();

        fireAngle = std::atan2( opposite, adjacent );
    }


    if(fireRepeatPhase < fireRepeatLength)
    {
        if(fireCD < fireRate)
            fireCD ++;
        if(fireCD >= fireRate)
        {
            if(isOnline)
            {
                Audio::AddSfx(0);

                float arcStartAngle = fireAngle - fireArcLength/2;
                //float arcEndAngle = fireAngle + fireArcLength/2;
                float seperationAngle = fireArcLength/numBullets;

                for(unsigned bulletPosition = 0; bulletPosition < numBullets; bulletPosition++)
                {
                    Bullet*bullet;
                    bullet = new Bullet();
                    bullet->Initialize(bulletForm, bulletSpeed, arcStartAngle + seperationAngle*(bulletPosition+0.5), bulletLifespan);
                    bullet->SetXYPosition(GetXPosition(), GetYPosition());
                    if(isNPCEmitter)
                        bullet->SetIsNPCBullet(true);

                    Bullet::bullets.push_back(bullet);
                }

                fireCD = 0;
                fireRepeatPhase ++;

                if(fireRepeatPhase == fireRepeatLength)
                {
                    fireRepeatCD = 0;
                }
            }
        }
    }
    else //fireRepeatPhase >= fireRepeatLength
    {
        if(fireRepeatCD < fireRepeatRate)
        {
            fireRepeatCD ++;
            if(fireRepeatCD >= fireRepeatRate)
            {
                fireRepeatPhase = 0;
                fireRepeatCD = 0;
            }
        }
    }
}
