#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "ship.h"

#include "bullet.h"
#include "emitter.h"

#include <cmath>
#include <iostream>

class NPC : public Ship
{
    /// Behaviour
    enum enumMoveAI
    {
        MOVE_AI_UNMOVING,

        MOVE_AI_APPROACH_DESTINATION,
        MOVE_AI_ORBIT_DESTINATION,
        MOVE_AI_APPROACH_SHIP,
        MOVE_AI_ORBIT_SHIP
    };

    int moveAI;
    float xDestination, yDestination;

    Emitter *mainEmitter;


public:
    static std::vector<NPC*>npcs;

    enum enumNPCHulls
    {
        HULL_NPC_OCELLUS = 0
    };

    NPC();
    ~NPC();

    void Initialize(int whichHullType);
    void Uninitialize();

    void Logic();
    void Drawing();

    void SetMoveAI(int move_ai)
    {
        moveAI = move_ai;
    }

};

#endif // NPC_H_INCLUDED
