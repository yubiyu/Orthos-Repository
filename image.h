#ifndef IMAGE_H_INCLUDED
#define IMAGE_H_INCLUDED

#include <allegro5/allegro5.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>

struct Image
{
    static ALLEGRO_BITMAP *genericTitlePng;
    static ALLEGRO_BITMAP *genericOverworldPng;
    static ALLEGRO_BITMAP *genericResultsPng;
    static ALLEGRO_BITMAP *genericBeingPng;
    static ALLEGRO_BITMAP *genericTilePng;

    static ALLEGRO_BITMAP *titleOptionMarkerPng;
    static ALLEGRO_BITMAP *settingsVolumeBarPng;
    static ALLEGRO_BITMAP *settingsVolumeBarEmptyPng;

    static ALLEGRO_BITMAP *framePng;
    static ALLEGRO_BITMAP *frameEmitterIconPng;
    static ALLEGRO_BITMAP *frameEmitterIconSub[6];
    static ALLEGRO_BITMAP *frameSubshipIconPng;
    static ALLEGRO_BITMAP *frameSubshipIconSub[6];
    static ALLEGRO_BITMAP *frameLockonBubbleBluePng;
    static ALLEGRO_BITMAP *frameLockonBubbleRedPng;
    static ALLEGRO_BITMAP *frameLockonBarBluePng;
    static ALLEGRO_BITMAP *frameLockonBarRedPng;

    static ALLEGRO_BITMAP *pcShipPng;
    static ALLEGRO_BITMAP *pcShipSub[4];
    static ALLEGRO_BITMAP *pcSubshipPng;

    static ALLEGRO_BITMAP *npcShipPng;
    static ALLEGRO_BITMAP *npcShipSub[4];

    static ALLEGRO_BITMAP *bulletPng;
    static ALLEGRO_BITMAP *bulletSub[4];

    static ALLEGRO_BITMAP *particlePng;
    static ALLEGRO_BITMAP *particleSub[5];

    static ALLEGRO_BITMAP *reticlePng;
    static ALLEGRO_BITMAP *lockonPng;

    static void Initialize();
    static void Uninitialize();

    static void LoadResources();
    static void UnloadResources();
};

#endif // IMAGE_H_INCLUDED
