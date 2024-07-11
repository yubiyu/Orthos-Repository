#ifndef AUDIO_H_INCLUDED
#define AUDIO_H_INCLUDED

#include <allegro5/allegro_audio.h>
#include <allegro5/allegro_acodec.h>

#include <vector>

struct Audio
{
    static ALLEGRO_SAMPLE_INSTANCE*activeBgmInstance;
    static std::vector<ALLEGRO_SAMPLE_INSTANCE*>activeSfxInstances;

    static ALLEGRO_SAMPLE*genericBgmMp3;
    static ALLEGRO_SAMPLE*genericPickupCoinWav;
    static ALLEGRO_SAMPLE*genericClickWav;
    static ALLEGRO_SAMPLE*genericLaserShootWav;

    static float bgmGain;
    static float sfxGain;

    static void Initialize();
    static void Uninitialize();

    static void LoadResources();
    static void UnloadResources();

    static void SetBgmGain(float gain);
    static void SetSfxGain(float gain);

    static void AddSfx(int whichSfx);

    static void Logic();
};

#endif // AUDIO_H_INCLUDED
