#include "pc.h"

PC::PC()
{
}

PC::~PC()
{

}

void PC::Initialize(int whichHullType)
{
    Ship::Initialize();
    Ship::SetHullType(whichHullType);

    switch(Ship::GetHullType())
    {
    case HULL_PC_ORTHOS:


        break;

    case HULL_PC_LITHOS:

        break;
    }
}
