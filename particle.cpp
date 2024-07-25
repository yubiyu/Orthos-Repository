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
    if(GetIsAlive() && GetIsInBounds())
    {
        lifespanElasped++;
        if(lifespanElasped >= lifespan)
            SetIsAlive(false);

        SetXPosition(GetXPosition() + GetMoveSpeed()*std::cos(GetMoveAngle()));
        SetYPosition(GetYPosition() + GetMoveSpeed()*std::sin(GetMoveAngle()));

        SetSpriteRotation(GetMoveAngle());

        if(GetXPosition() < 0 || GetXPosition() > Arena::WIDTH
                || GetYPosition() < 0 || GetYPosition() > Arena::HEIGHT)
        {
            SetIsInBounds(false);
        }
    }
    else
    {
        if(!GetIsAlive())
        {
            SetIsActive(false);
        }

        if(!GetIsInBounds())
        {
            SetIsActive(false);
        }
    }
}

void Particle::Drawing()
{
    al_draw_rotated_bitmap(Image::particleSub[GetForm()],
                           GetSpriteWidth()/2, GetSpriteHeight()/2,
                           GetXPosition(), GetYPosition(),
                           GetSpriteRotation(),
                           0);
}
