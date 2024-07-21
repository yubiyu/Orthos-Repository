#include "pc.h"

PC* PC::pc;

PC::PC()
{
    mainEmitter = nullptr;
}

PC::~PC()
{
    if(mainEmitter != nullptr)
        delete mainEmitter;
}

void PC::Initialize(int whichHullType)
{
    Ship::Initialize();
    Ship::SetHullType(whichHullType);

    mainEmitter = new Emitter();

    switch(Ship::GetHullType())
    {
    case HULL_PC_ORTHOS_A:
        mainEmitter->Initialize(Bullet::BULLET_FORM_LARGE_ARROW, 32, 1, 0, 1.5*ALLEGRO_PI, 4, 6, 1);
        break;
    case HULL_PC_ORTHOS_B:
        break;

    case HULL_PC_LITHOS_A:

        break;
    case HULL_PC_LITHOS_B:
        break;
    }

    mainEmitter->SetHasTrackedPosition(true);

    SetXYPosition(320,720);
    SetMoveAngle(0.75 * 2*ALLEGRO_PI);
    SetHitboxXYOffset(28,28);
    SetHitboxDimensions(8,8);

    SetFireCommandReceived(false);


}

void PC::Logic()
{
    if(GetXPosition() < 0)
        SetXPosition(0);
    else if(GetXPosition() > Frame::ARENA_WIDTH)
        SetXPosition(Frame::ARENA_WIDTH);
    if(GetYPosition() < 0)
        SetYPosition(0);
    else if(GetYPosition() > Frame::ARENA_HEIGHT)
        SetYPosition(Frame::ARENA_HEIGHT);


    mainEmitter->SetIsOnline(fireCommandReceived);
    if(fireCommandReceived)
        mainEmitter->SetTrackedXYPosition(Reticle::frameXPosition, Reticle::frameYPosition);

    mainEmitter->SetXYPosition(GetXPosition(),GetYPosition());
    mainEmitter->Logic();

    for(std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end(); ++it)
    {
        if((*it)->GetIsNPCBullet())
        {
            if(Hax::AABBCollision(GetXPosition() + GetHitboxXOffset(), GetYPosition() + GetHitboxYOffset(), GetHitboxWidth(), GetHitboxHeight(),
                                  (*it)->GetXPosition() + (*it)->GetHitboxXOffset(), (*it)->GetYPosition() + (*it)->GetHitboxYOffset(), (*it)->GetHitboxWidth(), (*it)->GetHitboxHeight()))
            {
                (*it)->EmitHitSparks(Particle::PARTICLE_FORM_PC_HIT);
                (*it)->SetIsActive(false);
            }
        }
    }


    float opposite = Reticle::frameYPosition - GetYPosition();
    float adjacent = Reticle::frameXPosition - GetXPosition();
    SetMoveAngle(std::atan2( opposite, adjacent ));

    SetSpriteRotation(GetMoveAngle());
}

void PC::Drawing()
{
    al_draw_rotated_bitmap(Image::pcShipSub[GetHullType()],
                           GetSpriteWidth()/2, GetSpriteHeight()/2,
                           GetXPosition(), GetYPosition(),
                           GetSpriteRotation(),
                           0);
}
