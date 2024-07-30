#ifndef RETICLE_H_INCLUDED
#define RETICLE_H_INCLUDED

#include "mouse.h"
#include "arena.h"

#include "image.h"

struct Reticle
{
    static float displayXPosition, displayYPosition;
    static float arenaXPosition, arenaYPosition;

    static void Initialize();

    static void Update();
    static void Drawing();
};

#endif // RETICLE_H_INCLUDED
