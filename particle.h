#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "actor.h"

#include "timer.h"
#include "image.h"

#include <vector>
#include <cmath>
#include <iostream>

#include "arena.h"

class Particle : public Actor
{

    int lifespanElasped, lifespan;
    static const int BASE_PARTICLE_LIFESPAN = Timer::FPS *0.5;

    int form;

public:
    static std::vector<Particle*> particles;

    enum enumParticleForms
    {
        PARTICLE_FORM_PC_HIT = 0,
        PARTICLE_FORM_PC_EXPLODE = 1,

        PARTICLE_FORM_NPC_HIT = 2,
        PARTICLE_FORM_NPC_EXPLODE = 3,

        PARTICLE_FORM_SUBSHIP_XIPHOS_AFTERIMAGE = 4
    };

    Particle();
    ~Particle();

    void Initialize(int form, float speed, float angle, int lifespan);

    void Logic();
    void Drawing();

    void SetLifespan(int cycles)
    {
        lifespanElasped = 0;
        lifespan = cycles;
    }

    int GetForm(){return form;}
    void SetForm(int whichForm){form = whichForm;}
};

#endif // BULLET_H_INCLUDED
