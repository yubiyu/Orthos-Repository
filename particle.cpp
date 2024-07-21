#include "particle.h"

std::vector<Particle*> Particle::particles;

Particle::Particle()
{

}

Particle::~Particle()
{
    //std::cout << "destructor test " << std::endl;
}

void Particle::Initialize(int form, float speed, float angle, int lifespan)
{
    Actor::Initialize();

    SetForm(form);
    SetMoveSpeed(speed);
    SetMoveAngle(angle);
    SetLifespan(lifespan);
}

void Particle::Logic()
{
    lifespanElasped++;
    if(lifespanElasped >= lifespan)
        SetIsActive(false);



    SetXPosition(GetXPosition() + GetMoveSpeed()*std::cos(GetMoveAngle()));
    SetYPosition(GetYPosition() + GetMoveSpeed()*std::sin(GetMoveAngle()));

    SetSpriteRotation(GetMoveAngle());
}

void Particle::Drawing()
{
    al_draw_rotated_bitmap(Image::particleSub[GetForm()],
                           GetSpriteWidth()/2, GetSpriteHeight()/2,
                           GetXPosition(), GetYPosition(),
                           GetSpriteRotation(),
                           0);
}
