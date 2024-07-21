#ifndef GENERATOR_H_INCLUDED
#define GENERATOR_H_INCLUDED

#include "npc.h"

#include "frame.h"

#include <map>

struct Generator
{
    static int stageNumber;
    static int elaspedTime;

    static std::multimap<int, NPC*>stageShipList;

    static void Initialize(int stage_number);
    static void Uninitialize();

    static void Logic();

    static void InitStage1();
    static void InitStage2();
    static void InitStage3();
    static void InitStage4();
    static void InitStage5();
};

#endif // GENERATOR_H_INCLUDED
