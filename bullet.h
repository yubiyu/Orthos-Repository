#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "actor.h"

class Bullet : public Actor
{
    int form;

    float width;

public:
    enum enumBulletForms
    {
        BULLET_FORM_ROUND = 0,
        BULLET_FORM_BEAM = 1,
        BULLET_FORM_ARROW = 2,
        BULLET_FORM_LARGE_ARROW = 3
    };

    Bullet();
    ~Bullet();

    void Initialize();

    int GetForm(){return form;}
    void SetForm(int whichForm){form = whichForm;}

    float GetWidth(){return width;}
    void SetWidth(float w){width = w;}
};

#endif // BULLET_H_INCLUDED
