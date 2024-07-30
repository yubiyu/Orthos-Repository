#ifndef EMITTER_H_INCLUDED
#define EMITTER_H_INCLUDED

#include "audio.h"

#include "ship.h"
#include "bullet.h"

#include "timer.h"

#include <iostream>

// Analogous to a stencil/template for firing arcs and rings of bullets on repeat.
class Emitter : public Actor
{
    bool isOnline{};
    bool isNPCEmitter{};

    bool hasTrackedTarget{};
    Ship *trackedTarget;

    bool hasTrackedPosition{};
    float trackedXPosition{};
    float trackedYPosition{};

    int bulletForm{};
    int bulletColour{};

    float bulletSpeed{};

    int bulletLifespan{};
    static const int BULLET_BASE_LIFESPAN = Timer::FPS * 10;

    unsigned numBullets{}; // Number of bullets to fire. Bullets will be evenly spaced.
    float fireArcLength{}; // In radians. A full 2*PI rads will fire a circular ring of bullets.
    float fireAngle{}; // In radians. The centre of the firing arc.

    int fireCD{}, fireRate{};
    int fireRepeatCD{}, fireRepeatRate{}, fireRepeatPhase{}, fireRepeatLength{};

public:
    Emitter();
    ~Emitter();

    void Initialize(int bullet_form, int bullet_colour, float bullet_speed, unsigned num_bullets, float fire_arc_length, float fire_angle, int fire_rate, int fire_repeat_rate, int fire_repeat_length);

    void Logic();

    bool GetIsOnline() const { return isOnline; }
    void SetIsOnline(bool is_online){isOnline = is_online;}

    void SetIsNPCEmitter(bool is_npc){isNPCEmitter = is_npc;}

    Ship* GetTrackedTarget(){return trackedTarget;}
    void SetTrackedTarget(Ship* target)
    {
        trackedTarget = target;

        if(trackedTarget == nullptr)
            hasTrackedTarget = false;
        else
            hasTrackedTarget = true;
    }

    void SetHasTrackedPosition(bool tracking){ hasTrackedPosition = tracking;}
    float GetTrackedXPosition() const { return trackedXPosition; }
    void SetTrackedXPosition(float x){trackedXPosition = x;}
    float GetTrackedYPosition() const { return trackedYPosition; }
    void SetTrackedYPosition(float y){trackedYPosition = y;}
    void SetTrackedXYPosition(float x, float y){SetTrackedXPosition(x); SetTrackedYPosition(y);}
};

#endif // EMITTER_H_INCLUDED
