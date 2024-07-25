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
    SetIsAlive(true);
    SetIsInBounds(true);
    SetIsVisible(true);
    SetIsCollidable(true);

    SetXYPosition(0,0);
    SetMoveSpeed(0.0);
    SetMoveAngle(0.0);

    SetSpriteDimensions(64,64);
    SetSpriteRotation(GetMoveAngle());
    SetHitboxXYOffset(0,0);
    SetHitboxDimensions(1,1);
}
