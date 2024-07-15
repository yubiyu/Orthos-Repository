#include "pc.h"

PC* PC::pc;

PC::PC()
{
    mainEmitter = nullptr;
    lockonEmitter = nullptr;
    bombEmitter = nullptr;
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
        mainEmitter->Initialize(Bullet::BULLET_FORM_LARGE_ARROW, 32, 1, 0, 1.5*M_PI, 4, 6, 1);
        break;
    case HULL_PC_ORTHOS_B:
        break;

    case HULL_PC_LITHOS_A:

        break;
    case HULL_PC_LITHOS_B:
        break;
    }

    SetXYPosition(640,720);
    SetMoveAngle(0.75 * 2*M_PI);
    SetHitboxXYOffset(28,28);
    SetHitboxDimensions(8,8);

    SetFireCommandReceived(false);


}

void PC::Logic()
{
    mainEmitter->SetIsOnline(fireCommandReceived);

    mainEmitter->SetXYPosition(GetXPosition(),GetYPosition());
    mainEmitter->Logic();

    for(std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end(); ++it)
    {
        if((*it)->GetIsNPCBullet())
        {
            if(Hax::AABBCollision(GetXPosition() + GetHitboxXOffset(), GetYPosition() + GetHitboxYOffset(), GetHitboxWidth(), GetHitboxHeight(),
                                  (*it)->GetXPosition() + (*it)->GetHitboxXOffset(), (*it)->GetYPosition() + (*it)->GetHitboxYOffset(), (*it)->GetHitboxWidth(), (*it)->GetHitboxHeight()))
            {
                (*it)->SetIsActive(false);
            }
        }
    }

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
