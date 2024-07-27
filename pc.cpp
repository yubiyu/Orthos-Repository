#include "pc.h"

PC* PC::pc;

PC::PC()
{
    mainEmitter = nullptr;
}

PC::~PC()
{
    if(mainEmitter != nullptr)
    {
        delete mainEmitter;
        mainEmitter = nullptr;
    }

    for(std::vector<Subship*>::iterator it = subships.begin(); it != subships.end();)
    {
        delete *it;
        it = subships.erase(it);
    }
}

void PC::Initialize(int whichHullType)
{
    Ship::Initialize();
    Ship::SetHullType(whichHullType);

    mainEmitter = new Emitter();

    Subship* initialSubshipA;
    Subship* initialSubshipB;

    initialSubshipA = new Subship();
    initialSubshipB = new Subship();


    switch(Ship::GetHullType())
    {
    case HULL_PC_ORTHOS_A:
        mainEmitter->Initialize(Bullet::BULLET_FORM_LARGE_ARROW, 32, 1, 0, 1.5*ALLEGRO_PI, 4, 6, 1);

        initialSubshipA->Initialize(Subship::HULL_SUBSHIP_XIPHOS, this);
        initialSubshipB->Initialize(Subship::HULL_SUBSHIP_XIPHOS, this);

        break;
    case HULL_PC_ORTHOS_B:
        break;

    case HULL_PC_LITHOS_A:

        break;
    case HULL_PC_LITHOS_B:
        break;
    }

    mainEmitter->SetHasTrackedPosition(true);

    subships.push_back(initialSubshipA);
    subships.push_back(initialSubshipB);

    SetXYPosition(320,720);
    SetMoveAngle(0.75 * 2*ALLEGRO_PI);
    SetHitboxXYOffset(28,28);
    SetHitboxDimensions(8,8);

    subshipOrbit = 0.0;
    subshipOrbitRate = (2*ALLEGRO_PI) / (Timer::FPS*4);

    SetFireCommandReceived(false);
}

void PC::Logic()
{
    if(GetXPosition() < 0)
        SetXPosition(0);
    else if(GetXPosition() > Arena::WIDTH)
        SetXPosition(Arena::WIDTH);
    if(GetYPosition() < 0)
        SetYPosition(0);
    else if(GetYPosition() > Arena::HEIGHT)
        SetYPosition(Arena::HEIGHT);


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

    subshipOrbit += subshipOrbitRate;
    if(subshipOrbit > 2*ALLEGRO_PI)
        subshipOrbit -= 2*ALLEGRO_PI;

    int subshipIndex = 0;
    for(std::vector<Subship*>::iterator it = subships.begin(); it != subships.end(); ++it)
    {
        float attachment_angle = 0.0 + subshipIndex * 2*ALLEGRO_PI/subships.size();
        //attachment_angle += GetMoveAngle() - ALLEGRO_PI/2; // Removed because it looked jank
        attachment_angle += subshipOrbit;

        (*it)->SetAttachmentAngle(attachment_angle);
        (*it)->Logic();

        subshipIndex ++;
    }
}

void PC::MainDrawing()
{
    al_draw_rotated_bitmap(Image::pcShipSub[GetHullType()],
                           GetSpriteWidth()/2, GetSpriteHeight()/2,
                           GetXPosition(), GetYPosition(),
                           GetSpriteRotation(),
                           0);
}

void PC::SubshipDrawing()
{
    for(std::vector<Subship*>::iterator it = subships.begin(); it != subships.end(); ++it)
    {
        (*it)->Drawing();
    }
}

void PC::LockonRelease()
{
    int assignmentIndex = 0;
    int numSubships = subships.size();

    for(size_t i = 0; i < Lockon::NUM_LOCKS; i++)
    {
        if(Lockon::GetLockState(i) == Lockon::LOCKON_STATE_ACQUIRED)
        {
            Lockon::SetLockStateFireGuidance(i);
            subships[assignmentIndex]->AssignLockon(i);

            assignmentIndex ++;
            if(assignmentIndex >= numSubships)
                assignmentIndex = 0;
        }
    }

/*
    for(std::vector<Subship*>::iterator jt = subships.begin(); jt != subships.end(); ++jt)
    {

    }
*/

}
