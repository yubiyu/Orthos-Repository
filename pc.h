#ifndef PC_H_INCLUDED
#define PC_H_INCLUDED


#include "ship.h"

#include "particle.h"
#include "emitter.h"
#include "subship.h"

#include "reticle.h"

#include "hax.h"

#include <vector>
#include <cmath>

class PC : public Ship
{
    Emitter* mainEmitter = nullptr;
    std::vector<Subship*>subships;

    float subshipOrbit = 0.0;
    float subshipOrbitRate = 0.0;

    bool fireCommandReceived = false;

public:
    static PC*pc;

    enum enumPCHulls
    {
        HULL_PC_ORTHOS_A = 0,
        HULL_PC_ORTHOS_B = 1,

        HULL_PC_LITHOS_A = 2,
        HULL_PC_LITHOS_B = 3
    };
    static const int NUM_HULL_TYPES = 4;

    PC();
    ~PC();

    void Initialize(int whichHullType);

    void Logic();
    void MainDrawing();
    void SubshipDrawing();

    void LockonRelease();

    bool GetFireCommandReceived() const { return fireCommandReceived; }
    void SetFireCommandReceived(bool active){fireCommandReceived = active;}

    int GetSubshipHullType() const 
    {
        if (subships.size() > 0)
            return subships[0]->GetHullType();
        else
            return Subship::HULL_SUBSHIP_XIPHOS;
    }

    void SetSubshipOrbit(float angle) { subshipOrbit = angle; }
};

#endif // PC_H_INCLUDED
