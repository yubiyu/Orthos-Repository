#ifndef LOCKON_H_INCLUDED
#define LOCKON_H_INCLUDED

#include <map>

#include "timer.h"

#include "audio.h"

#include "npc.h"
#include "reticle.h"
#include "hax.h"

struct Lockon
{
private:
    static std::map<size_t, int> lockState;
public:
    enum enumLockonState
    {
        LOCKON_STATE_READY = 0,
        LOCKON_STATE_ACQUIRED = 1,
        LOCKON_STATE_FIRE_GUIDANCE = 2
    };
    static std::map<size_t, int> lockCoherence;
    static std::map<size_t, NPC*> lockTargets;

    static const int BASE_LOCK_COHERENCE = Timer::FPS * 6;
    static const size_t NUM_LOCKS = 8;

    static std::map<size_t, float> lockAnimationScaling;

    static float animationScalingRate;
    static constexpr float MIN_LOCK_ANIMATION_SCALING = 1.0;
    static constexpr float MAX_LOCK_ANIMATION_SCALING = 8.0;

    static bool isLockCD;
    static int lockAcquisitionCD;
    static constexpr float LOCK_ACQUISITION_SECS = 0.25;
    static const int LOCK_ACQUISITION_RATE = Timer::FPS * LOCK_ACQUISITION_SECS;

    static void Initialize();
    static void Uninitialize();

    static void Logic();
    static void Drawing();

    static size_t GetLockState(size_t key){return lockState[key];}
    static void SetLockStateReady(size_t key);
    static void SetLockStateAcquired(size_t key, NPC* target);
    static void SetLockStateFireGuidance(size_t key);

    static size_t CountLocksAcquired(){ return lockState.count(LOCKON_STATE_ACQUIRED);}

};

#endif // LOCKON_H_INCLUDED
