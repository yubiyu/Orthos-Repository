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

void NPC::Initialize(int whichHullType)
{
    Ship::Initialize();
    Ship::SetHullType(whichHullType);

    mainEmitter = new Emitter();

    switch(Ship::GetHullType())
    {
        case HULL_NPC_OCELLUS:
            mainEmitter->Initialize(Bullet::BULLET_FORM_ROUND, 6, 3, 0.33* 2*M_PI, 0.125*2*M_PI, 15, 180, 6);
        break;

    }

    SetXYPosition(0,0);
    SetDimensions(64,64);

    SetMoveAI(MOVE_AI_UNMOVING);
}

void NPC::Logic()
{
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
        //if(Hax::AABBCollision()  )
    }

}

void NPC::Drawing()
{
    al_draw_bitmap(Image::npcShipSub[GetHullType()], GetXPosition(), GetYPosition(), 0);
}
