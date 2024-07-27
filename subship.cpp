#include "subship.h"

Subship::Subship()
{

}

Subship::~Subship()
{
    attachedShip = nullptr;
    assignedLockons.clear();
}

void Subship::Initialize(int hull_type, Ship *attached_ship)
{
    Ship::Initialize();
    SetHullType(hull_type);
    SetAttachedShip(attached_ship);

    SetAttachmentAngle(0.0);
    SetAttachmentRadius(64);

    SetIsDetached(false);
    SetPhase(ATTACHED_ORBIT);
    warpToTargetAngle = 0.0;
    warpToTargetRadius = 0.0;
    warpToTargetDelay = 0.0;

    attackTargetDelay = 0.0;

    mainEmitter = new Emitter;

    switch(GetHullType())
    {
    case HULL_SUBSHIP_XIPHOS:
        mainEmitter->Initialize(Bullet::BULLET_FORM_LARGE_ARROW, 32, 1, 0, 1.5*ALLEGRO_PI, 1, 6, 1);
        break;
    case HULL_SUBSHIP_EFTHYMIA:

        break;
    }

    mainEmitter->SetIsOnline(false);
}

void Subship::Logic()
{
    if(GetHasTrackedTarget())
    {
        float opposite = GetTrackedTarget()->GetYPosition() - GetYPosition();
        float adjacent = GetTrackedTarget()->GetXPosition() - GetXPosition();

        SetMoveAngle( std::atan2( opposite, adjacent ) );
    }
    else
        SetMoveAngle(attachedShip->GetMoveAngle());

    if(isDetached)
    {
        for(std::vector<int>::iterator it = assignedLockons.begin(); it != assignedLockons.end();)
        {
            if(Lockon::lockTargets[*it] == nullptr)
                it = assignedLockons.erase(it);
            else
                ++it;
        }

        switch(phase)
        {
        case DETACHED_WARP_TO_TARGET:
            warpToTargetDelay ++;
            if(warpToTargetDelay >= WARP_TO_TARGET_DELAY_PERIOD)
            {
                if(assignedLockons.empty())
                    SetPhase(DETACHED_RETURN_WARP);
                else // ! assignedLockons.empty()
                    SetPhase(DETACHED_ATTACK_TARGET);
            }
            break;

        case DETACHED_ATTACK_TARGET:
            attackTargetDelay ++;
            if(attackTargetDelay >= ATTACK_TARGET_DELAY_PERIOD)
            {
                if(assignedLockons.empty())
                    SetPhase(DETACHED_RETURN_WARP);
                else // ! assignedLockons.empty()
                    SetPhase(DETACHED_WARP_TO_TARGET);
            }
            break;

        case DETACHED_RETURN_WARP:
            returnWarpDelay ++;
            if(returnWarpDelay >= RETURN_WARP_DELAY_PERIOD)
            {
                SetPhase(ATTACHED_ORBIT);
            }
            break;
        }

    }
    else
    {
        if(! assignedLockons.empty())
        {
            SetPhase(DETACHED_WARP_TO_TARGET);
        }
    }

    if(phase == ATTACHED_ORBIT || phase == DETACHED_RETURN_WARP)
    {
        attachmentXOffset = attachmentRadius*std::cos(attachmentAngle);
        attachmentYOffset = attachmentRadius*std::sin(attachmentAngle);

        SetXPosition(attachedShip->GetXPosition() + attachmentXOffset);
        SetYPosition(attachedShip->GetYPosition() + attachmentYOffset);
    }

    mainEmitter->SetXYPosition(GetXPosition(),GetYPosition());
    mainEmitter->Logic();
}

void Subship::Drawing()
{
    al_draw_rotated_bitmap(Image::pcSubshipPng, GetSpriteWidth()/2, GetSpriteHeight()/2, GetXPosition(), GetYPosition(), GetMoveAngle(), 0);
}

void Subship::SetPhase(int which_phase)
{
    phase = which_phase;

    switch(phase)
    {
    case ATTACHED_ORBIT:
        isDetached = false;
        break;

    case DETACHED_WARP_TO_TARGET:
        {
        SetTrackedTarget(Lockon::lockTargets[assignedLockons[0]]);

        isDetached = true;

        warpToTargetAngle = Hax::RandFloat(2*ALLEGRO_PI);
        warpToTargetRadius = Hax::RandFloatRange(WARP_TO_TARGET_RADIUS_MIN, WARP_TO_TARGET_RADIUS_MAX);
        warpToTargetDelay = 0;

        float x1 = GetXPosition();
        float y1 = GetYPosition();
        float x2 = Lockon::lockTargets[assignedLockons[0]]->GetXPosition() + warpToTargetRadius*std::cos(warpToTargetAngle);
        float y2 = Lockon::lockTargets[assignedLockons[0]]->GetYPosition() + warpToTargetRadius*std::sin(warpToTargetAngle);

        SetXPosition(x2);
        SetYPosition(y2);
        CreateWarpToTargetAfterimages(x1, y1, x2, y2);

        mainEmitter->SetIsOnline(false);
        break;
        }
    case DETACHED_ATTACK_TARGET:
        attackTargetDelay = 0;
        Lockon::SetLockStateReady( assignedLockons[0] );
        assignedLockons.erase(assignedLockons.begin());

        mainEmitter->SetTrackedTarget( GetTrackedTarget());
        mainEmitter->SetIsOnline(true);
        break;
    case DETACHED_RETURN_WARP:
        SetTrackedTarget(nullptr);

        returnWarpDelay = 0;

        float x1 = GetXPosition();
        float y1 = GetYPosition();
        float x2 = attachedShip->GetXPosition() + attachmentXOffset;
        float y2 = attachedShip->GetYPosition() + attachmentYOffset;

        SetXPosition(x2);
        SetYPosition(y2);
        CreateWarpToTargetAfterimages(x1, y1, x2, y2);

        mainEmitter->SetIsOnline(false);
        break;
    }
}

void Subship::CreateWarpToTargetAfterimages(float x1, float y1, float x2, float y2)
{
    const int numAfterimages = 8;

    Particle *afterimage;

    int lifespan = 0;
    if(phase == DETACHED_WARP_TO_TARGET)
        lifespan = WARP_TO_TARGET_DELAY_PERIOD;
    if(phase == DETACHED_RETURN_WARP)
        lifespan = RETURN_WARP_DELAY_PERIOD;

    for(int i = 0; i < numAfterimages; i++)
    {
        float createX = x1 + (x2-x1)*((float)i/numAfterimages);
        float createY = Hax::LinearInterpolateX(x1, y1, x2, y2, createX);
        lifespan += i * 1;

        afterimage = new Particle();
        afterimage->Initialize(Particle::PARTICLE_FORM_SUBSHIP_XIPHOS_AFTERIMAGE, 0, GetMoveAngle(), lifespan);
        afterimage->SetXYPosition(createX, createY);

        Particle::particles.push_back(afterimage);
    }


}
