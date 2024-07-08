#ifndef SHIP_H_INCLUDED
#define SHIP_H_INCLUDED

#include "actor.h"

#include <vector>

class Ship : public Actor
{

/// Identity
    int hullType;

/// Structure
    int currentHP, maxHP;

/// Mobility
    float moveSpeed;

/// Offense


public:
    Ship();
    ~Ship();

    void Initialize();

    int GetHullType(){return hullType;}
    void SetHullType(int whichHullType){ hullType = whichHullType;}

    void SetCurrentHP(int hp){currentHP = hp;}
    void SetMaxHP(int hp){currentHP = maxHP = hp;}

    void SetMoveSpeed(float speed){moveSpeed = speed;}

};

#endif // SHIP_H_INCLUDED
