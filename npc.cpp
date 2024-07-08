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
    default:

        break;

    }
}
