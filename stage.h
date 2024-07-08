#ifndef STAGE_H_INCLUDED
#define STAGE_H_INCLUDED

#include <vector>

#include "pc.h"
#include "npc.h"
#include "bullet.h"

struct Stage
{
    static PC*pc;
    static std::vector<NPC*>npcs;
    static std::vector<Bullet*>bullets;

    static void Initialize();
    static void Uninitialize();

};

#endif // STAGE_H_INCLUDED
