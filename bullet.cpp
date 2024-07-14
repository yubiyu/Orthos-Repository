#include "bullet.h"

std::vector<Bullet*> Bullet::bullets;

Bullet::Bullet()
{

}

Bullet::~Bullet()
{
    //std::cout << "destructor test " << std::endl;
}

void Bullet::Initialize(int form, float speed, float angle, float width)
{
    Actor::Initialize();

    SetLifespan(BASE_LIFESPAN);
    SetForm(form);
    SetSpeed(speed);
    SetAngle(angle);
    SetWidth(width);

}

void Bullet::Logic()
{
    lifespanElasped++;
    if(lifespanElasped >= lifespan)
    {
        SetIsActive(false);
    }

    SetXPosition(GetXPosition() + speed*std::cos(angle));
    SetYPosition(GetYPosition() + speed*std::sin(angle));
}

void Bullet::Drawing()
{
    al_draw_bitmap(Image::bulletSub[GetForm()], GetXPosition(), GetYPosition(), 0);
}
