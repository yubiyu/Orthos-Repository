#include "subship.h"

Subship::Subship()
{

}

Subship::~Subship()
{
    attachedShip = nullptr;
    assignedTargets.clear();
}

void Subship::Initialize(int hull_type, Ship *attached_ship)
{
    Ship::Initialize();
    SetHullType(hull_type);
    SetAttachedShip(attached_ship);

    SetAttachmentAngle(0.0);
    SetAttachmentRadius(64);

    SetIsDetached(false);
    SetDetachedModePhase(DETACHED_WARP_TO_TARGET);
}

void Subship::Logic()
{
    if(isDetached)
    {
        if(assignedTargets.empty())
        {
            SetDetachedModePhase(DETACHED_RETURN_WARP);
        }

        for(std::vector<Ship*>::iterator it = assignedTargets.begin(); it != assignedTargets.end();)
        {
            if(! (*it)->GetIsActive())
                it = assignedTargets.erase(it);
            else
            {
                ++it;
            }
        }

        switch(detachedModePhase)
        {
        case DETACHED_WARP_TO_TARGET:

            /**
            warpToTargetXDestination = ?
            warpToTargetYDestination = ?

            afterimage vector

            fireDelay = ?

            */

            break;

        case DETACHED_ATTACK_TARGET:
            /**
            Emit attack
            End Lockon::fire guidance mode
            */
            break;

        case DETACHED_RETURN_WARP:
            // do stuff here
            isDetached = false;
            break;
        }

    }
    else
    {
        attachmentXOffset = attachmentRadius*std::cos(attachmentAngle);
        attachmentYOffset = attachmentRadius*std::sin(attachmentAngle);

        SetXPosition(attachedShip->GetXPosition() + attachmentXOffset);
        SetYPosition(attachedShip->GetYPosition() + attachmentYOffset);

        if(! assignedTargets.empty())
        {
            isDetached = true;
            SetDetachedModePhase(DETACHED_WARP_TO_TARGET);
        }
    }
}

void Subship::Drawing()
{
    al_draw_rotated_bitmap(Image::pcSubshipPng, GetSpriteWidth()/2, GetSpriteHeight()/2, GetXPosition(), GetYPosition(), attachedShip->GetMoveAngle(), 0);
}
