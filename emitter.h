#ifndef EMITTER_H_INCLUDED
#define EMITTER_H_INCLUDED

#include "audio.h"

#include "ship.h"
#include "bullet.h"

#include <iostream>

// Analogous to a stencil/template for firing arcs and rings of bullets on repeat.
class Emitter : public Actor
{
    bool isOnline;
    bool isNPCEmitter;

    bool hasTrackedTarget;
    Ship *trackedTarget;

    int bulletForm;
    float bulletSpeed;

    unsigned numBullets; // Number of bullets to fire. Bullets will be evenly spaced.
    float fireArcLength; // In radians. A full 2*PI rads will fire a circular ring of bullets.
    float fireAngle; // In radians. The centre of the firing arc.

    int fireCD, fireRate;
    int fireRepeatCD, fireRepeatRate, fireRepeatPhase, fireRepeatLength;

public:
    Emitter();
    ~Emitter();

    void Initialize(int bullet_form, float bullet_speed, unsigned num_bullets, float fire_arc_length, float fire_angle, int fire_rate, int fire_repeat_rate, int fire_repeat_length);

    void Logic();

    bool GetIsOnline(){return isOnline;}
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
};

#endif // EMITTER_H_INCLUDED
