#include "audio.h"

ALLEGRO_SAMPLE* Audio::genericBgmMp3;
ALLEGRO_SAMPLE* Audio::genericPickupCoinWav;
ALLEGRO_SAMPLE* Audio::genericClickWav;
ALLEGRO_SAMPLE* Audio::genericLaserShootWav;

ALLEGRO_SAMPLE_INSTANCE* Audio::activeBgmInstance;
std::vector<ALLEGRO_SAMPLE_INSTANCE*> Audio::activeSfxInstances;

float Audio::bgmGain;
float Audio::sfxGain;

void Audio::Initialize()
{
    al_install_audio();
    al_init_acodec_addon();

    LoadResources();

    SetBgmGain(0.0);
    SetSfxGain(0.0);

    activeBgmInstance = al_create_sample_instance(genericBgmMp3);
    al_attach_sample_instance_to_mixer(activeBgmInstance,al_get_default_mixer());
}

void Audio::Uninitialize()
{
    for(std::vector<ALLEGRO_SAMPLE_INSTANCE*>::iterator it = activeSfxInstances.begin(); it!= activeSfxInstances.end(); ++it)
    {
        al_destroy_sample_instance(*it);
    }
    activeSfxInstances.clear();

    al_destroy_sample_instance(activeBgmInstance);

    UnloadResources();
    al_uninstall_audio();
}

void Audio::LoadResources()
{
    al_reserve_samples(10);

    genericBgmMp3 = al_load_sample("genericBgmMp3.mp3");
    genericPickupCoinWav = al_load_sample("genericPickupCoinWav.wav");
    genericClickWav = al_load_sample("genericClickWav.wav");
    genericLaserShootWav = al_load_sample("genericLaserShootWav.wav");
}

void Audio::UnloadResources()
{
    al_destroy_sample(genericBgmMp3);
    al_destroy_sample(genericPickupCoinWav);
    al_destroy_sample(genericClickWav);
    al_destroy_sample(genericLaserShootWav);
}

void Audio::SetBgmGain(float gain)
{
    bgmGain = gain;
}

void Audio::SetSfxGain(float gain)
{
    sfxGain = gain;
}

void Audio::AddSfx(int whichSfx)
{
    ALLEGRO_SAMPLE_INSTANCE*sfx;

    switch(whichSfx)
    {
        default:
        sfx = al_create_sample_instance(Audio::genericLaserShootWav);
        break;
    }

    al_set_sample_instance_gain(sfx, Audio::sfxGain);
    al_attach_sample_instance_to_mixer(sfx, al_get_default_mixer());
    Audio::activeSfxInstances.push_back(sfx);
    al_play_sample_instance(sfx);
}

void Audio::Logic()
{
    for(std::vector<ALLEGRO_SAMPLE_INSTANCE*>::iterator it = activeSfxInstances.begin(); it != activeSfxInstances.end();)
    {
        if(!al_get_sample_instance_playing(*it))
        {
            al_detach_sample_instance(*it);
            al_destroy_sample_instance(*it);
            activeSfxInstances.erase(it);
        }
        else
        {
            ++it;
        }
    }
}
