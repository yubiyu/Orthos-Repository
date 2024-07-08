#include "stage.h"

PC* Stage::pc;
std::vector<NPC*> Stage::npcs;
std::vector<Bullet*> Stage::bullets;

void Stage::Initialize()
{
    pc = new PC();
    pc->Initialize(PC::HULL_PC_ORTHOS);

}

void Stage::Uninitialize()
{
    delete pc;

    for(std::vector<NPC*>::iterator it = npcs.begin(); it != npcs.end();)
        delete *it;

    for(std::vector<Bullet*>::iterator it = bullets.begin(); it != bullets.end();)
        delete *it;
}
