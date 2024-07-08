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

    static void Initialize();
    static void Uninitialize();

    static void LoadResources();
    static void UnloadResources();
};

#endif // IMAGE_H_INCLUDED
