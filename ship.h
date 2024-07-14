#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "actor.h"

#include "hax.h"

#include <vector>

class Ship : public Actor
{

/// Identity
    int hullType;

/// Structure
    int currentHP, maxHP;

/// Mobility
    float moveSpeed;

/// Tracking
    bool hasTrackedTarget;
    Ship* trackedTarget;


public:
    Ship();
    ~Ship();

    void Initialize();

    int GetHullType(){return hullType;}
    void SetHullType(int whichHullType){ hullType = whichHullType;}

    void SetCurrentHP(int hp){currentHP = hp;}
    void SetMaxHP(int hp){currentHP = maxHP = hp;}

    void SetMoveSpeed(float speed){moveSpeed = speed;}

    bool GetHasTrackedTarget(){return hasTrackedTarget;}
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

#endif // SHIP_H_INCLUDED
