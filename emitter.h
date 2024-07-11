#ifndef EMITTER_H_INCLUDED
#define EMITTER_H_INCLUDED

#include "bullet.h"

// Analogous to a stencil/template for firing arcs and rings of bullets on repeat.9
// The characteristics of fired bullets are relative to the "lead" bullet.
class Emitter
{
    bool isActive;
    bool isOnline;

    int bulletForm;

    unsigned numBullets; // Number of bullets to fire. Bullets will be evenly spaced.
    float fireArcLength; // In radians. A full 2*PI rads will fire a circular ring of bullets.
    float fireAngle; // In radians. The centre of the firing arc.

    int fireCD, fireRate;
    int fireRepeatCD, fireRepeatRate, fireRepeatPhase, fireRepeatLength;

public:
    Emitter();
    ~Emitter();

    void Initialize(int bullet_form, unsigned num_bullets, float fire_arc_length, float fire_angle, int fire_rate, int fire_repeat_rate, int fire_repeat_length)
    {
        isActive = true;
        isOnline = false;

        bulletForm = bullet_form;

        numBullets = num_bullets;
        fireArcLength = fire_arc_length;
        fireAngle = fire_angle;

        fireCD = 0;
        fireRate = fire_rate;

        fireRepeatCD = 0;
        fireRepeatRate = fire_repeat_rate;
        fireRepeatPhase = 0;
        fireRepeatLength = fire_repeat_length;
    }

    bool GetIsActive(){return isActive;}
    void SetIsActive(bool is_active){isActive = is_active;}

    bool GetIsOnline(){return isOnline;}
    void SetIsOnline(bool is_online){isOnline = is_online;}
};

#endif // EMITTER_H_INCLUDED
