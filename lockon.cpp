#include "lockon.h"

std::map<int, int> Lockon::lockState;
std::map<int, int> Lockon::lockCoherence;
std::map<int, NPC*> Lockon::lockTargets;

std::map<int, float> Lockon::lockAnimationScaling;
float Lockon::animationScalingRate;

bool Lockon::isLockCD;
int Lockon::lockAcquisitionCD;

void Lockon::Initialize()
{
    isLockCD = false;
    lockAcquisitionCD = 0;

    for(int i = 0; i < NUM_LOCKS; i++)
    {
        SetLockStateReady(i);
    }
    animationScalingRate = (MAX_LOCK_ANIMATION_SCALING - MIN_LOCK_ANIMATION_SCALING) / (Timer::FPS * LOCK_ACQUISITION_SECS);
}

void Lockon::Uninitialize()
{
    lockTargets.clear();
}

void Lockon::Logic()
{
    if(isLockCD)
    {
        lockAcquisitionCD ++;
        if(lockAcquisitionCD >= LOCK_ACQUISITION_RATE)
        {
            lockAcquisitionCD = 0;
            isLockCD = false;
        }
    }
    else // !isLockCD
    {
        if(Reticle::displayXPosition > Frame::ARENA_X
                && Reticle::displayXPosition < Frame::ARENA_X + Arena::WIDTH)
        {
            for(std::vector<NPC*>::iterator it = NPC::npcs.begin(); it != NPC::npcs.end(); ++it)
            {
                if(Reticle::frameXPosition > (*it)->GetXPosition() - (*it)->GetHitboxWidth()/2
                        && Reticle::frameXPosition < (*it)->GetXPosition() + (*it)->GetHitboxWidth()/2
                        && Reticle::frameYPosition > (*it)->GetYPosition() - (*it)->GetHitboxHeight()/2
                        && Reticle::frameYPosition < (*it)->GetYPosition() + (*it)->GetHitboxHeight()/2)
                {
                    for(size_t i = 0; i < NUM_LOCKS; i++)
                    {
                        if(lockState.at(i) == LOCKON_STATE_READY)
                        {
                            SetLockStateAcquired(i, *it);
                            break;
                        }
                    }

                    if(isLockCD)
                        break;
                }
            }
        }
    }

    for(size_t i = 0; i < NUM_LOCKS; i++)
    {
        if(lockAnimationScaling[i] > MIN_LOCK_ANIMATION_SCALING)
        {
            lockAnimationScaling[i] -= animationScalingRate;
            if(lockAnimationScaling[i] < 1.0)
                lockAnimationScaling[i] = 1.0;
        }

        switch(lockState.at(i))
        {
        case LOCKON_STATE_READY:

            break;

        case LOCKON_STATE_FIRE_GUIDANCE:

            if(! lockTargets.at(i)->GetIsActive())
                SetLockStateReady(i);
            break;

        case LOCKON_STATE_ACQUIRED:
            lockCoherence[i] --;

            if(! lockTargets.at(i)->GetIsActive() || lockCoherence.at(i) <= 0)
                SetLockStateReady(i);
            break;
        }
    }
}

void Lockon::Drawing()
{
    for(size_t i = 0; i < NUM_LOCKS; i++)
    {
        if(lockTargets.at(i) != nullptr)
        {
            al_draw_scaled_rotated_bitmap(Image::lockonPng, 32, 32, lockTargets.at(i)->GetXPosition(), lockTargets.at(i)->GetYPosition(),
                                          lockAnimationScaling.at(i),
                                          lockAnimationScaling.at(i),
                                          0, 0);
        }
    }
}

void Lockon::SetLockStateReady(int key)
{
    lockState[key] = LOCKON_STATE_READY;
    lockCoherence[key] = BASE_LOCK_COHERENCE;
    lockTargets[key] = nullptr;
    lockAnimationScaling[key] = MAX_LOCK_ANIMATION_SCALING;
}

void Lockon::SetLockStateAcquired(int key, NPC* target)
{
    isLockCD = true;
    lockState[key] = LOCKON_STATE_ACQUIRED;
    lockTargets[key] = target;
    lockAnimationScaling[key] = MAX_LOCK_ANIMATION_SCALING;

    Audio::AddSfx(Audio::acquireLockWav);
}

void Lockon::SetLockStateFireGuidance(int key)
{
    lockState[key] = LOCKON_STATE_FIRE_GUIDANCE;
}
