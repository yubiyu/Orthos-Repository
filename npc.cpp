#include "npc.h"

std::vector<NPC*> NPC::npcs;

NPC::NPC()
{
    mainEmitter = nullptr;
}

NPC::~NPC()
{
    if(mainEmitter != nullptr)
        delete mainEmitter;
}

void NPC::Initialize(int whichHullType, float x_pos, float y_pos, float x_dest, float y_dest)
{
    Ship::Initialize();
    Ship::SetHullType(whichHullType);

    SetXYPosition(x_pos, y_pos);
    SetXYDestination(x_dest, y_dest);

    mainEmitter = new Emitter();

    switch(Ship::GetHullType())
    {
    case HULL_NPC_RAY:
        SetMoveSpeed(1.2);
        SetHitboxDimensions(64,64);
        SetMaxHP(50);
        mainEmitter->Initialize(Bullet::BULLET_FORM_ARROW, 3, 5, 0.33*2*ALLEGRO_PI, 0.25*2*ALLEGRO_PI, 15, 180, 6);
        break;

    case HULL_NPC_OCELLUS:
        SetMoveSpeed(1.2);
        SetHitboxDimensions(64,64);
        SetMaxHP(50);
        mainEmitter->Initialize(Bullet::BULLET_FORM_ROUND, 6, 1, 0.01*2*ALLEGRO_PI, 0.25*2*ALLEGRO_PI, 18, 180, 3);
        break;

    case HULL_NPC_ANGELFISH:
        SetMoveSpeed(1.2);
        SetHitboxDimensions(64,64);
        SetMaxHP(50);
        mainEmitter->Initialize(Bullet::BULLET_FORM_ARROW, 3, 5, 0.33*2*ALLEGRO_PI, 0.25*2*ALLEGRO_PI, 15, 180, 6);
        break;

    case HULL_NPC_ANTLION:
        SetMoveSpeed(0.8);
        SetHitboxDimensions(64,64);
        SetMaxHP(50);
        mainEmitter->Initialize(Bullet::BULLET_FORM_LARGE_ARROW, 12, 1, 0.33*2*ALLEGRO_PI, 0.25*2*ALLEGRO_PI, 15, 60, 1);
        break;

    }
    mainEmitter->SetIsNPCEmitter(true);

    SetMoveAI(MOVE_AI_APPROACH_DESTINATION);
    SetMoveAngle(0.25 * 2*ALLEGRO_PI);

}

void NPC::Logic()
{
    switch(moveAI)
    {
    case MOVE_AI_UNMOVING:

        break;

    case MOVE_AI_APPROACH_DESTINATION:
    {
        float opposite = yDestination - GetYPosition();
        float adjacent = xDestination - GetXPosition();
        SetMoveAngle( std::atan2(opposite, adjacent) );
        SetXPosition( GetXPosition() + std::cos(GetMoveAngle())*GetMoveSpeed());
        SetYPosition( GetYPosition() + std::sin(GetMoveAngle())*GetMoveSpeed());

        break;
    }

    case MOVE_AI_SHADOW_SHIP:

        break;

    case MOVE_AI_ORBIT_DESTINATION:

        break;
    }

    if(GetCurrentHP() <= 0)
    {
        EmitDeathSparks();
        SetIsActive(false);
    }

    SetSpriteRotation(GetMoveAngle());

    if(GetXPosition() < 0 || GetXPosition() > Frame::ARENA_WIDTH
            || GetYPosition() < 0 || GetYPosition() > Frame::ARENA_HEIGHT)
    {
        SetIsActive(false);
    }


    mainEmitter->SetXYPosition(GetXPosition(), GetYPosition());

    if(GetHasTrackedTarget())
    {
        if(mainEmitter->GetTrackedTarget() != Ship::GetTrackedTarget())
        {
            mainEmitter->SetTrackedTarget(Ship::GetTrackedTarget());
        }
    }

    mainEmitter->Logic();

    for(std::vector<Bullet*>::iterator it = Bullet::bullets.begin(); it != Bullet::bullets.end(); ++it)
    {
        if(!(*it)->GetIsNPCBullet())
        {
            if(Hax::AABBCollision(GetXPosition() + GetHitboxXOffset(), GetYPosition() + GetHitboxYOffset(), GetHitboxWidth(), GetHitboxHeight(),
                                  (*it)->GetXPosition() + (*it)->GetHitboxXOffset(), (*it)->GetYPosition() + (*it)->GetHitboxYOffset(), (*it)->GetHitboxWidth(), (*it)->GetHitboxHeight()))
            {
                SetCurrentHP(GetCurrentHP() - (*it)->GetDamage());

                (*it)->EmitHitSparks(Particle::PARTICLE_FORM_NPC_HIT);
                (*it)->SetIsActive(false);

            }
        }
    }

}

void NPC::Drawing()
{
    al_draw_rotated_bitmap(Image::npcShipSub[GetHullType()],
                           GetSpriteWidth()/2, GetSpriteHeight()/2,
                           GetXPosition(), GetYPosition(),
                           GetSpriteRotation(),
                           0);
}

void NPC::EmitDeathSparks()
{
    float circleAngle = 0;
    int numSparks = 12;

    Particle*spark;

    for(int i = 0; i < numSparks; i++)
    {
        circleAngle += (2*ALLEGRO_PI)/numSparks;

        spark = new Particle();
        spark->Initialize(Particle::PARTICLE_FORM_NPC_EXPLODE, 10, circleAngle, 16);
        spark->SetXYPosition(GetXPosition(), GetYPosition());
        Particle::particles.push_back(spark);
    }
}
