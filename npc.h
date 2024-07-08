#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "ship.h"

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

    int moveAIRoutine;
    float xDestination, yDestination;

    enum enumAttackAI
    {

    };

    int attackAIRoutine;

/// Linkage
    bool isLinked;      // Ship is part of a link.
    std::vector<Ship*>linkedShips;

/// Subordinates
    bool hasSubordinateShips;      // This ship directs the movements of subordinate ships.
    std::vector<Ship*>subordinateShips;

/// Load-bearing
    bool isLoadBearing; // Destruction of this ship destroys all ships it is load bearing for.
    std::vector<Ship*>loadShips;
    int loadBearingDestructionDelay; // Grace period before load ships are destroyed.


public:
    NPC();
    ~NPC();

    void Initialize(int whichHullType);
};

#endif // NPC_H_INCLUDED
