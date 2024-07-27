#include "image.h"

ALLEGRO_BITMAP* Image::genericTitlePng;
ALLEGRO_BITMAP* Image::genericOverworldPng;
ALLEGRO_BITMAP* Image::genericResultsPng;
ALLEGRO_BITMAP* Image::genericBeingPng;
ALLEGRO_BITMAP* Image::genericTilePng;

ALLEGRO_BITMAP* Image::titleOptionMarkerPng;
ALLEGRO_BITMAP* Image::settingsVolumeBarPng;
ALLEGRO_BITMAP* Image::settingsVolumeBarEmptyPng;

ALLEGRO_BITMAP* Image::framePng;
ALLEGRO_BITMAP* Image::frameEmitterIconPng;
ALLEGRO_BITMAP* Image::frameEmitterIconSub[6];
ALLEGRO_BITMAP* Image::frameSubshipIconPng;
ALLEGRO_BITMAP* Image::frameSubshipIconSub[6];
ALLEGRO_BITMAP* Image::frameLockonBubbleBluePng;
ALLEGRO_BITMAP* Image::frameLockonBubbleRedPng;
ALLEGRO_BITMAP* Image::frameLockonBarBluePng;
ALLEGRO_BITMAP* Image::frameLockonBarRedPng;

ALLEGRO_BITMAP* Image::pcShipPng;
ALLEGRO_BITMAP* Image::pcShipSub[4];
ALLEGRO_BITMAP* Image::pcSubshipPng;

ALLEGRO_BITMAP *Image::npcShipPng;
ALLEGRO_BITMAP *Image::npcShipSub[4];

ALLEGRO_BITMAP* Image::bulletPng;
ALLEGRO_BITMAP* Image::bulletSub[4];

ALLEGRO_BITMAP* Image::particlePng;
ALLEGRO_BITMAP* Image::particleSub[5];

ALLEGRO_BITMAP* Image::reticlePng;
ALLEGRO_BITMAP* Image::lockonPng;

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

    framePng = al_load_bitmap("frame.png");
    frameEmitterIconPng = al_load_bitmap("frameEmitterIcon.png");
    for(int i = 0; i < 6; i++)
        frameEmitterIconSub[i] = al_create_sub_bitmap(frameEmitterIconPng, 0, i*0, 64, 64); /// placeholder

    frameSubshipIconPng = al_load_bitmap("frameSubshipIcon.png");
    for(int i = 0; i < 6; i++)
        frameSubshipIconSub[i] = al_create_sub_bitmap(frameSubshipIconPng, 0, i*0, 64, 64); /// placeholder

    frameLockonBubbleBluePng = al_load_bitmap("frameLockonBubbleBlue.png");
    frameLockonBubbleRedPng = al_load_bitmap("frameLockonBubbleRed.png");
    frameLockonBarBluePng = al_load_bitmap("frameLockonBarBlue.png");
    frameLockonBarRedPng = al_load_bitmap("frameLockonBarRed.png");

    pcShipPng = al_load_bitmap("pcShip.png");
    for(int i = 0; i < 4; i++)
        pcShipSub[i] = al_create_sub_bitmap(pcShipPng, 0, i*64, 64, 64);

    pcSubshipPng = al_load_bitmap("pcSubship.png");

    npcShipPng = al_load_bitmap("npcShip.png");
    for(int i = 0; i < 4; i++)
        npcShipSub[i] = al_create_sub_bitmap(npcShipPng, 0, i*64, 64, 64);

    bulletPng = al_load_bitmap("bullet.png");
    for(int i = 0; i < 4; i++)
        bulletSub[i] = al_create_sub_bitmap(bulletPng, 0, i*64, 64, 64);

    particlePng = al_load_bitmap("particle.png");
    for(int i = 0; i < 5; i++)
        particleSub[i] = al_create_sub_bitmap(particlePng, 0, i*64, 64, 64);

    reticlePng = al_load_bitmap("reticle.png");
    lockonPng = al_load_bitmap("lockon.png");


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

    al_destroy_bitmap(framePng);

    for(int i = 0; i < 6; i++)
        al_destroy_bitmap(frameEmitterIconSub[i]);
    al_destroy_bitmap(frameEmitterIconPng);

    for(int i = 0; i < 6; i++)
        al_destroy_bitmap(frameSubshipIconSub[i]);
    al_destroy_bitmap(frameSubshipIconPng);

    al_destroy_bitmap(frameLockonBubbleBluePng);
    al_destroy_bitmap(frameLockonBubbleRedPng);
    al_destroy_bitmap(frameLockonBarBluePng);
    al_destroy_bitmap(frameLockonBarRedPng);

    for(int i = 0; i < 4; i++)
        al_destroy_bitmap(pcShipSub[i]);
    al_destroy_bitmap(pcShipPng);

    al_destroy_bitmap(pcSubshipPng);

    for(int i = 0; i < 4; i++)
        al_destroy_bitmap(npcShipSub[i]);
    al_destroy_bitmap(npcShipPng);

    for(int i = 0; i < 4; i++)
        al_destroy_bitmap(bulletSub[i]);
    al_destroy_bitmap(bulletPng);

    for(int i = 0; i < 5; i++)
        al_destroy_bitmap(particleSub[i]);
    al_destroy_bitmap(particlePng);

    al_destroy_bitmap(reticlePng);
    al_destroy_bitmap(lockonPng);

}

