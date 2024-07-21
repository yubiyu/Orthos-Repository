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
    if(elaspedTime == 18*Timer::FPS)
    {
        elaspedTime = 0;
        InitStage1();
    }
}

void Generator::InitStage1()
{
/// Practice npc
    NPC*dummy;
    dummy = new NPC();
    dummy->NPC::Initialize(NPC::HULL_NPC_OCELLUS, Frame::ARENA_WIDTH/2, 0, Frame::ARENA_WIDTH/2, Frame::ARENA_HEIGHT+100);
    stageShipList.insert( std::make_pair( 1, dummy ));

/// Three npcs
    dummy = new NPC();
    dummy->NPC::Initialize(NPC::HULL_NPC_RAY, Frame::ARENA_WIDTH-100, 0, Frame::ARENA_WIDTH-100, Frame::ARENA_HEIGHT+100);
    stageShipList.insert( std::make_pair( 4*Timer::FPS, dummy));

    dummy = new NPC();
    dummy->NPC::Initialize(NPC::HULL_NPC_ANTLION, Frame::ARENA_WIDTH/2, 0, Frame::ARENA_WIDTH/2, Frame::ARENA_HEIGHT+100);
    stageShipList.insert( std::make_pair( 4*Timer::FPS, dummy));

    dummy = new NPC();
    dummy->NPC::Initialize(NPC::HULL_NPC_RAY, 100, 0, 100, Frame::ARENA_HEIGHT+100);
    stageShipList.insert( std::make_pair( 4*Timer::FPS, dummy));

/// Four npcs
    dummy = new NPC();
    dummy->NPC::Initialize(NPC::HULL_NPC_OCELLUS, 0, 96, Frame::ARENA_WIDTH+100, 192);
    stageShipList.insert( std::make_pair( 10*Timer::FPS, dummy));

    dummy = new NPC();
    dummy->NPC::Initialize(NPC::HULL_NPC_RAY, Frame::ARENA_WIDTH, 192, 0, 384);
    stageShipList.insert( std::make_pair( 10*Timer::FPS, dummy));

    dummy = new NPC();
    dummy->NPC::Initialize(NPC::HULL_NPC_RAY, 0, 288, Frame::ARENA_WIDTH+100, 576);
    stageShipList.insert( std::make_pair( 12*Timer::FPS, dummy));

    dummy = new NPC();
    dummy->NPC::Initialize(NPC::HULL_NPC_OCELLUS, Frame::ARENA_WIDTH, 384, 0, 768);
    stageShipList.insert( std::make_pair( 12*Timer::FPS, dummy));
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
