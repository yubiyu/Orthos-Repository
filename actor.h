#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

class Actor
{
    bool isActive;
    bool isVisible;
    bool isCollidable;

    float xPosition, yPosition;
    float width, height;

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

    float GetWidth(){return width;}
    void SetWidth(float w){width = w;}
    float GetHeight(){return height;}
    void SetHeight(float h){height = h;}
    void SetDimensions(float w, float h){ SetWidth(w); SetHeight(h);}
};

#endif // ACTOR_H_INCLUDED
