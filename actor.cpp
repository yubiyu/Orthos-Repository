#include "actor.h"

Actor::Actor()
{

}

Actor::~Actor()
{

}

void Actor::Initialize()
{
    SetIsActive(true);

    SetIsVisible(true);

    SetIsCollidable(true);

    SetXYPosition(0,0);
}
