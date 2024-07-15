#include "bullet.h"

std::vector<Bullet*> Bullet::bullets;

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
    //std::cout << "destructor test " << std::endl;
}

void Bullet::Initialize(int form, float speed, float angle)
{
    Actor::Initialize();

    SetIsNPCBullet(false);

    SetLifespan(BASE_LIFESPAN);
    SetForm(form);
    SetMoveSpeed(speed);
    SetMoveAngle(angle);

    switch(GetForm())
    {
    case BULLET_FORM_ROUND:
        SetHitboxXYOffset(8,8);
        SetHitboxDimensions(48,48);
        break;

    case BULLET_FORM_BEAM:
        break;

    case BULLET_FORM_ARROW:
        SetHitboxXYOffset(20,20);
        SetHitboxDimensions(24,24);
        break;

    case BULLET_FORM_LARGE_ARROW:
        SetHitboxXYOffset(8,8);
        SetHitboxDimensions(48,48);
        break;
    }

}

void Bullet::Logic()
{
    lifespanElasped++;
    if(lifespanElasped >= lifespan)
        SetIsActive(false);

    SetXPosition(GetXPosition() + GetMoveSpeed()*std::cos(GetMoveAngle()));
    SetYPosition(GetYPosition() + GetMoveSpeed()*std::sin(GetMoveAngle()));

    SetSpriteRotation(GetMoveAngle());
}

void Bullet::Drawing()
{
    al_draw_rotated_bitmap(Image::bulletSub[GetForm()],
                           GetSpriteWidth()/2, GetSpriteHeight()/2,
                           GetXPosition(), GetYPosition(),
                           GetSpriteRotation(),
                           0);
}
