#ifndef PARTICLE_H_INCLUDED
#define PARTICLE_H_INCLUDED

#include "actor.h"

#include "timer.h"
#include "image.h"

#include "arena.h"

#include "palette.h"

#include <vector>
#include <cmath>
#include <iostream>

class Particle : public Actor
{
    int colour;
    int lifespanElasped, lifespan;
    static const int BASE_PARTICLE_LIFESPAN = Timer::FPS *0.5;

    int form;

public:
    static std::vector<Particle*> particles;

    enum enumParticleForms
    {
        PARTICLE_FORM_HIT = 0,
        PARTICLE_FORM_EXPLODE = 1,
        PARTICLE_FORM_SUBSHIP_XIPHOS_AFTERIMAGE = 2
    };
    static const int NUM_PARTICLE_FORMS = 3;

    Particle();
    ~Particle();

    void Initialize(int form, int colour, float speed, float angle, int lifespan);

    void Logic();
    void Drawing();

    int GetColour(){return colour;}
    void SetColour(int which_colour){colour = which_colour;}

    void SetLifespan(int cycles)
    {
        lifespanElasped = 0;
        lifespan = cycles;
    }

    int GetForm(){return form;}
    void SetForm(int whichForm){form = whichForm;}
};

#endif // BULLET_H_INCLUDED
