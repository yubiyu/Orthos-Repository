#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED

#include "ship.h"

class PC : public Ship
{
public:
    enum enumPCHulls
    {
        HULL_PC_ORTHOS = 0,
        HULL_PC_LITHOS = 1,
    };

    PC();
    ~PC();

    void Initialize(int whichHullType);
};

#endif // PC_H_INCLUDED
