#include "npc.h"

NPC::NPC()
{

}

NPC::~NPC()
{

}

void NPC::Initialize(int whichHullType)
{
    Ship::Initialize();
    Ship::SetHullType(whichHullType);

    switch(Ship::GetHullType())
    {
        case HULL_NPC_OCELLUS:
        mainEmitter->Initialize(Bullet::BULLET_FORM_ROUND, 12, M_PI, 0.5*M_PI, 30, 180, 6);

        break;

    }
}
