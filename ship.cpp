#include "ship.h"

Ship::Ship()
{

}

Ship::~Ship()
{

}

void Ship::Initialize()
{
    Actor::Initialize();
    SetMaxHP(1);
    SetMoveSpeed(4);
    SetTrackedTarget(nullptr);
}
