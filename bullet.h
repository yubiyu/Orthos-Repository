#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "actor.h"

#include "timer.h"
#include "image.h"

#include <vector>
#include <cmath>
#include <iostream>

class Bullet : public Actor
{
    bool isNPCBullet;

    int lifespanElasped, lifespan;
    static const int BASE_LIFESPAN = Timer::FPS * 10;

    int form;

public:
    static std::vector<Bullet*> bullets;

    enum enumBulletForms
    {
        BULLET_FORM_ROUND = 0,

        BULLET_FORM_BEAM = 1,

        BULLET_FORM_ARROW = 2,
        BULLET_FORM_LARGE_ARROW = 3

        //BULLET_FORM_DIAMOND = 4,
        //BULLET_FORM_RECTANGLE = 5
    };

    Bullet();
    ~Bullet();

    void Initialize(int form, float speed, float angle);

    void Logic();
    void Drawing();

    bool GetIsNPCBullet(){return isNPCBullet;}
    void SetIsNPCBullet(bool is_npc){isNPCBullet = is_npc;}

    void SetLifespan(int cycles)
    {
        lifespanElasped = 0;
        lifespan = cycles;
    }

    int GetForm(){return form;}
    void SetForm(int whichForm){form = whichForm;}
};

#endif // BULLET_H_INCLUDED
