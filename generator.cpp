#include "generator.h"

int Generator::stageNumber;
int Generator::elaspedTime;

std::multimap<int, NPC*> Generator::stageShipList;

void Generator::Initialize(int stage_number)
{
    stageNumber = stage_number;
    elaspedTime = 0;

    switch(stageNumber)
    {
    case 1:
        InitStage1();
        break;

    case 2:
        InitStage2();
        break;

    case 3:
        InitStage3();
        break;

    case 4:
        InitStage4();
        break;

    case 5:
        InitStage5();
        break;
    }
}

void Generator::Uninitialize()
{
    for(std::multimap<int, NPC*>::iterator it = stageShipList.begin(); it != stageShipList.end();)
    {
        delete it->second;
        it = stageShipList.erase(it);
    }
}

void Generator::Logic()
{
    elaspedTime ++;
}

void Generator::InitStage1()
{
/// Practice npc
    NPC*dummy0;
    dummy0 = new NPC();
    dummy0->NPC::Initialize(NPC::HULL_NPC_OCELLUS, 720, 0, 420, 1200);
    stageShipList.insert( std::make_pair( 1, dummy0 ));

/// Three npcs
    NPC*dummy2;
    dummy2 = new NPC();
    dummy2->NPC::Initialize(NPC::HULL_NPC_RAY, 900, 0, 900, 1200);
    stageShipList.insert( std::make_pair( 8*Timer::FPS, dummy2));

    NPC*dummy3 = new NPC();
    dummy3->NPC::Initialize(NPC::HULL_NPC_ANTLION, 600, 0, 600, 1200);
    stageShipList.insert( std::make_pair( 8*Timer::FPS, dummy3));

    NPC*dummy4 = new NPC();
    dummy4->NPC::Initialize(NPC::HULL_NPC_RAY, 300, 0, 300, 1200);
    stageShipList.insert( std::make_pair( 8*Timer::FPS, dummy4));

}

void Generator::InitStage2()
{

}

void Generator::InitStage3()
{

}

void Generator::InitStage4()
{

}

void Generator::InitStage5()
{

}
