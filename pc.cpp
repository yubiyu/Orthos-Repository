#include "pc.h"

PC::PC()
{
    mainEmitter = nullptr;
    lockonEmitter = nullptr;
    bombEmitter = nullptr;
}

PC::~PC()
{
    if(mainEmitter != nullptr)
        delete mainEmitter;
}

void PC::Initialize(int whichHullType)
{
    Ship::Initialize();
    Ship::SetHullType(whichHullType);

    mainEmitter = new Emitter();

    switch(Ship::GetHullType())
    {
    case HULL_PC_ORTHOS_A:
        mainEmitter->Initialize(Bullet::BULLET_FORM_LARGE_ARROW, 1, 0, 1.5*M_PI, 0, 6, 1);
        break;
    case HULL_PC_ORTHOS_B:
        break;

    case HULL_PC_LITHOS_A:

        break;
    case HULL_PC_LITHOS_B:
        break;
    }

    SetXYPosition(640,720);
}
