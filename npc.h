#ifndef NPC_H_INCLUDED
#define NPC_H_INCLUDED

#include "ship.h"

#include "particle.h"
#include "emitter.h"
#include "flyingtext.h"

#include "arena.h"
#include "score.h"

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
        MOVE_AI_SHADOW_SHIP
    };

    float scoreValue{};

    int moveAI{};
    float xDestination{}, yDestination{};

    Ship *shadowedShip;
    float shadowingXDisplacement{}, shadowingYDisplacement{};

    Emitter *mainEmitter;


public:
    static std::vector<NPC*>npcs;

    enum enumNPCHulls
    {
        HULL_NPC_RAY = 0,
        HULL_NPC_OCELLUS = 1,
        HULL_NPC_ANGELFISH = 2,
        HULL_NPC_ANTLION = 3
    };

    NPC();
    ~NPC();

    void Initialize(int whichHullType, float x_pos, float y_pos, float x_dest, float y_dest);
    void Uninitialize();

    void Logic();
    void Drawing();

    void EmitDeathSparks();

    float GetScoreValue() const { return scoreValue; }
    void SetScoreValue(float score_value) { scoreValue = score_value; }
    void SetMoveAI(int move_ai){moveAI = move_ai;}
    void SetXDestination(float x){xDestination = x;}
    void SetYDestination(float y){yDestination = y;}
    void SetXYDestination(float x, float y){SetXDestination(x); SetYDestination(y);}

    void SetShadowedShip(Ship* target){shadowedShip = target;}
    float GetShadowingXDisplacement(float x) const { return shadowingXDisplacement; }
    void SetShadowingXDisplacement(float x){shadowingXDisplacement = x;}
    float GetShadowingYDisplacement(float y) const { return shadowingYDisplacement; }
    void SetShadowingYDisplacement(float y){shadowingYDisplacement = y;}
    void SetShadowingXYDisplacement(float x, float y){SetShadowingXDisplacement(x), SetShadowingYDisplacement(y);}


};

#endif // NPC_H_INCLUDED
