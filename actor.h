#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

class Actor
{
    bool isActive;

    bool isVisible;

    bool isCollidable;

    /// Position
    float xPosition, yPosition;

public:
    Actor();
    ~Actor();

    void Initialize();

    bool GetIsActive(){return isActive;}
    void SetIsActive(bool active){isActive = active;}

    bool GetIsVisible(){return isVisible;}
    void SetIsVisible(bool visible){isVisible = visible;}

    bool GetIsCollidable(){return isCollidable;}
    void SetIsCollidable(bool collidable){isCollidable = collidable;}

    float GetXPosition(){return xPosition;}
    float GetYPosition(){return yPosition;}

    void SetXPosition(float x){xPosition = x;}
    void SetYPosition(float y){yPosition = y;}
    void SetXYPosition(float x, float y){ SetXPosition(x); SetYPosition(y); }
};

#endif // ACTOR_H_INCLUDED
