#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

class Actor
{
    bool isActive;
    bool isAlive;
    bool isInBounds;
    bool isVisible;
    bool isCollidable;

    float xPosition, yPosition;

    float moveSpeed;
    float moveAngle;

    float spriteWidth, spriteHeight;
    float spriteRotation;

    float hitboxXOffset, hitboxYOffset;
    float hitboxWidth, hitboxHeight;


public:
    Actor();
    ~Actor();

    void Initialize();

    bool GetIsActive(){return isActive;}
    void SetIsActive(bool active){isActive = active;}

    bool GetIsAlive(){return isAlive;}
    void SetIsAlive(bool alive){isAlive = alive;}

    bool GetIsInBounds(){return isInBounds;}
    void SetIsInBounds(bool inBounds){ isInBounds = inBounds;}

    bool GetIsVisible(){return isVisible;}
    void SetIsVisible(bool visible){isVisible = visible;}

    bool GetIsCollidable(){return isCollidable;}
    void SetIsCollidable(bool collidable){isCollidable = collidable;}

    float GetXPosition(){return xPosition;}
    void SetXPosition(float x){xPosition = x;}
    float GetYPosition(){return yPosition;}
    void SetYPosition(float y){yPosition = y;}
    void SetXYPosition(float x, float y){ SetXPosition(x); SetYPosition(y); }

    float GetMoveSpeed(){return moveSpeed;}
    void SetMoveSpeed(float speed){moveSpeed = speed;}

    float GetMoveAngle(){return moveAngle;}
    void SetMoveAngle(float a){moveAngle = a;}

    float GetSpriteWidth(){return spriteWidth;}
    void SetSpriteWidth(float w){spriteWidth = w;}
    float GetSpriteHeight(){return spriteHeight;}
    void SetSpriteHeight(float h){spriteHeight = h;}
    void SetSpriteDimensions(float w, float h){SetSpriteWidth(w); SetSpriteHeight(h);}

    float GetSpriteRotation(){return spriteRotation;}
    void SetSpriteRotation(float angle){spriteRotation = angle;}

    float GetHitboxXOffset(){return hitboxXOffset;}
    void SetHitboxXOffset(float x){hitboxXOffset = x;}
    float GetHitboxYOffset(){return hitboxYOffset;}
    void SetHitboxYOffset(float y){hitboxYOffset = y;}
    void SetHitboxXYOffset(float x, float y){SetHitboxXOffset(x); SetHitboxYOffset(y);}

    float GetHitboxWidth(){return hitboxWidth;}
    void SetHitboxWidth(float w){hitboxWidth = w;}
    float GetHitboxHeight(){return hitboxHeight;}
    void SetHitboxHeight(float h){hitboxHeight = h;}
    void SetHitboxDimensions(float w, float h){ SetHitboxWidth(w); SetHitboxHeight(h);}
};

#endif // ACTOR_H_INCLUDED
