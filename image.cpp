#include "image.h"

ALLEGRO_BITMAP* Image::genericTitlePng;
ALLEGRO_BITMAP* Image::genericOverworldPng;
ALLEGRO_BITMAP* Image::genericResultsPng;
ALLEGRO_BITMAP* Image::genericBeingPng;
ALLEGRO_BITMAP* Image::genericTilePng;

ALLEGRO_BITMAP* Image::titleOptionMarkerPng;
ALLEGRO_BITMAP* Image::settingsVolumeBarPng;
ALLEGRO_BITMAP* Image::settingsVolumeBarEmptyPng;

ALLEGRO_BITMAP* Image::pcShipPng;
ALLEGRO_BITMAP* Image::pcShipSub[4];

ALLEGRO_BITMAP* Image::bulletPng;
ALLEGRO_BITMAP* Image::bulletSub[4];

void Image::Initialize()
{
    al_init_image_addon();
    al_init_primitives_addon();

    LoadResources();
}

void Image::Uninitialize()
{
    UnloadResources();
    al_shutdown_primitives_addon();
    al_shutdown_image_addon();
}

void Image::LoadResources()
{
    genericTitlePng = al_load_bitmap("genericTitlePng.png");
    genericOverworldPng = al_load_bitmap("genericOverworldPng.png");
    genericResultsPng = al_load_bitmap("genericResultsPng.png");
    genericBeingPng = al_load_bitmap("genericBeingPng.png");
    genericTilePng = al_load_bitmap("genericTilePng.png");

    titleOptionMarkerPng = al_load_bitmap("titleOptionMarker.png");
    settingsVolumeBarPng = al_load_bitmap("settingsVolumeBar.png");
    settingsVolumeBarEmptyPng = al_load_bitmap("settingsVolumeBarEmpty.png");

    pcShipPng = al_load_bitmap("pcShip.png");
    for(int i = 0; i < 4; i++)
        pcShipSub[i] = al_create_sub_bitmap(pcShipPng, i*64, 0, 64, 64);

    bulletPng = al_load_bitmap("bullet.png");
    for(int i = 0; i < 4; i++)
        bulletSub[i] = al_create_sub_bitmap(bulletPng, i*64, 0, 64, 64);


}

void Image::UnloadResources()
{
    al_destroy_bitmap(genericTitlePng);
    al_destroy_bitmap(genericOverworldPng);
    al_destroy_bitmap(genericResultsPng);
    al_destroy_bitmap(genericBeingPng);
    al_destroy_bitmap(genericTilePng);

    al_destroy_bitmap(titleOptionMarkerPng);
    al_destroy_bitmap(settingsVolumeBarPng);
    al_destroy_bitmap(settingsVolumeBarEmptyPng);

    for(int i = 0; i < 4; i++)
        al_destroy_bitmap(pcShipSub[i]);
    al_destroy_bitmap(pcShipPng);

    for(int i = 0; i < 4; i++)
        al_destroy_bitmap(bulletSub[i]);
    al_destroy_bitmap(bulletPng);

}

