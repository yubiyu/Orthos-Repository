#ifndef EMITTER_H_INCLUDED
#define EMITTER_H_INCLUDED

#include "audio.h"

#include "ship.h"
#include "bullet.h"

#include <iostream>

// Analogous to a stencil/template for firing arcs and rings of bullets on repeat.9
// The characteristics of fired bullets are relative to the "lead" bullet.
class Emitter : public Actor
{
    bool isActive;
    bool isOnline;

    bool hasTrackedTarget;
    Ship *trackedTarget;

    float xPosition;
    float yPosition;

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

    bool GetIsActive(){return isActive;}
    void SetIsActive(bool is_active){isActive = is_active;}

    bool GetIsOnline(){return isOnline;}
    void SetIsOnline(bool is_online){isOnline = is_online;}

    Ship* GetTrackedTarget(){return trackedTarget;}
    void SetTrackedTarget(Ship* target)
    {
        trackedTarget = target;

        if(trackedTarget == nullptr)
            hasTrackedTarget = false;
        else
            hasTrackedTarget = true;
    }

    void SetXPosition(float x){xPosition = x;}
    void SetYPosition(float y){yPosition = y;}
    void SetXYPosition(float x, float y){ SetXPosition(x); SetYPosition(y); }
};

#endif // EMITTER_H_INCLUDED
