#ifndef STAGE_H_INCLUDED
#define STAGE_H_INCLUDED

#include <vector>
#include <string>

#include "keyboard.h"

#include "image.h"
#include "font.h"
#include "audio.h"

#include "pc.h"
#include "npc.h"
#include "bullet.h"
#include "generator.h"

#include "tile.h"
#include "camera.h"
#include "palette.h"
#include "scene.h"

#include "hax.h"

struct Stage
{
    static void Initialize();
    static void Uninitialize();

    static void Logic();
    static void Input();
    static void Drawing();

    static void DrawDebugGrid();
    static void DrawDebugGridCameraCrosshair();
    static void DrawDebugGridText(/*float mouseTransformedX, float mouseTransformedY*/);

};

#endif // STAGE_H_INCLUDED
