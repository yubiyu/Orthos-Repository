#include "bullet.h"

std::vector<Bullet*> Bullet::bullets;

Bullet::Bullet()
{

}

Bullet::~Bullet()
{

}

void Bullet::Initialize(int form, int colour, float speed, float angle, int lifespan)
{
    Particle::Initialize(form, colour, speed, angle, lifespan);

    SetIsNPCBullet(false);
    SetDamage(1);

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
        SetDamage(5);
        SetHitboxXYOffset(8,8);
        SetHitboxDimensions(48,48);
        break;
    }
}


void Bullet::Drawing()
{
    al_draw_rotated_bitmap(Image::bulletSub[GetForm() + NUM_BULLET_FORMS * GetColour()],
                           GetSpriteWidth()/2, GetSpriteHeight()/2,
                           GetXPosition(), GetYPosition(),
                           GetSpriteRotation(),
                           0);
}

void Bullet::EmitHitSparks(int particle_form, int particle_colour)
{
    Particle *spark;
    for(int i = 0; i < 6; i++)
    {
        float randAngle = Hax::RandFloatRange(0.0, 2*ALLEGRO_PI);
        float randMoveSpeed = Hax::RandFloatRange(6, 12);
        float randLifespan = Hax::RandFloatRange(8, 24);

        spark = new Particle();
        spark->Initialize(particle_form, particle_colour, randMoveSpeed, randAngle, randLifespan);
        spark->SetXYPosition(GetXPosition(), GetYPosition());
        Particle::particles.push_back(spark);
    }
}
