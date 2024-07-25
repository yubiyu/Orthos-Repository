#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "actor.h"
#include "propulsion.h"

#include "hax.h"

#include <vector>

class Ship : public Actor
{

/// Identity
    int hullType;

    int currentHP, maxHP;

    bool hasTrackedTarget;
    Ship* trackedTarget;

    bool hasTrackedPosition;

    Propulsion* movePropulsion;


public:
    Ship();
    ~Ship();

    void Initialize();

    int GetHullType(){return hullType;}
    void SetHullType(int whichHullType){ hullType = whichHullType;}

    int GetCurrentHP(){ return currentHP;}
    void SetCurrentHP(int hp){currentHP = hp;}
    int GetMaxHP(){return maxHP;}
    void SetMaxHP(int hp){currentHP = maxHP = hp;}

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
