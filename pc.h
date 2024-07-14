#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

#include "ship.h"

#include "bullet.h"
#include "emitter.h"

#include <cmath>

class PC : public Ship
{
    Emitter* mainEmitter;
    Emitter* lockonEmitter;
    Emitter* bombEmitter;

    bool fireCommandReceived;

public:
    static PC*pc;

    enum enumPCHulls
    {
        HULL_PC_ORTHOS_A = 0,
        HULL_PC_ORTHOS_B = 1,

        HULL_PC_LITHOS_A = 2,
        HULL_PC_LITHOS_B = 3
    };

    PC();
    ~PC();

    void Initialize(int whichHullType);

    void Logic();
    void Drawing();

    bool GetFireCommandReceived(){return fireCommandReceived;}
    void SetFireCommandReceived(bool active){fireCommandReceived = active;}
};

#endif // PC_H_INCLUDED
