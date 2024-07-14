#include "pc.h"

PC* PC::pc;

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
        mainEmitter->Initialize(Bullet::BULLET_FORM_LARGE_ARROW, 32, 1, 0, 1.5*M_PI, 4, 6, 1);
        break;
    case HULL_PC_ORTHOS_B:
        break;

    case HULL_PC_LITHOS_A:

        break;
    case HULL_PC_LITHOS_B:
        break;
    }

    SetXYPosition(640,720);
    SetDimensions(64,64);

    SetFireCommandReceived(false);


}

void PC::Logic()
{
    mainEmitter->SetIsOnline(fireCommandReceived);

    mainEmitter->SetXYPosition(GetXPosition(),GetYPosition());
    mainEmitter->Logic();
}

void PC::Drawing()
{
    al_draw_bitmap(Image::pcShipSub[GetHullType()], GetXPosition(), GetYPosition(), 0);
}
