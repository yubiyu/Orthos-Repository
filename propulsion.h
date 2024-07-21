#ifndef PROPULSION_H_INCLUDED
#define PROPULSION_H_INCLUDED

#include "framecounter.h"

class Propulsion : public Actor
{
    int form;
    float xOffset, yOffset;
    float angleOffset;

    Framecounter framecounter;

public:

    Propulsion()
    {
    }
    ~Propulsion()
    {

    }

    void Logic()
    {

    }

    void Drawing();

    void Initialize(int which_form, float x_offset, float y_offset, float angle_offset)
    {
        form = which_form;
        xOffset = x_offset;
        yOffset = y_offset;
        angleOffset = angle_offset;

        switch(which_form)
        {
        case 0:
            framecounter.Initialize(3,3);
            break;
        }
    }
};

#endif // PROPULSION_H_INCLUDED
