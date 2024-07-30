#ifndef ACTOR_H_INCLUDED
#define ACTOR_H_INCLUDED

class Actor
{
    bool isActive{};
    bool isAlive{};
    bool isInBounds{};
    bool isVisible{};
    bool isCollidable{};

    float xPosition{}, yPosition{};

    float moveSpeed{};
    float moveAngle{};

    float spriteWidth{}, spriteHeight{};
    float spriteRotation{};

    float hitboxXOffset{}, hitboxYOffset{};
    float hitboxWidth{}, hitboxHeight{};


public:
    Actor();
    ~Actor();

    void Initialize();

    bool GetIsActive() const { return isActive; }
    void SetIsActive(bool active){isActive = active;}

    bool GetIsAlive() const { return isAlive; }
    void SetIsAlive(bool alive){isAlive = alive;}

    bool GetIsInBounds() const { return isInBounds; }
    void SetIsInBounds(bool inBounds){ isInBounds = inBounds;}

    bool GetIsVisible() const { return isVisible; }
    void SetIsVisible(bool visible){isVisible = visible;}

    bool GetIsCollidable() const { return isCollidable; }
    void SetIsCollidable(bool collidable){isCollidable = collidable;}

    float GetXPosition() const { return xPosition; }
    void SetXPosition(float x){xPosition = x;}
    float GetYPosition() const { return yPosition; }
    void SetYPosition(float y){yPosition = y;}
    void SetXYPosition(float x, float y){ SetXPosition(x); SetYPosition(y); }

    float GetMoveSpeed() const { return moveSpeed; }
    void SetMoveSpeed(float speed){moveSpeed = speed;}

    float GetMoveAngle() const { return moveAngle; }
    void SetMoveAngle(float a){moveAngle = a;}

    float GetSpriteWidth() const { return spriteWidth; }
    void SetSpriteWidth(float w){spriteWidth = w;}
    float GetSpriteHeight() const { return spriteHeight; }
    void SetSpriteHeight(float h){spriteHeight = h;}
    void SetSpriteDimensions(float w, float h){SetSpriteWidth(w); SetSpriteHeight(h);}

    float GetSpriteRotation() const { return spriteRotation; }
    void SetSpriteRotation(float angle){spriteRotation = angle;}

    float GetHitboxXOffset() const { return hitboxXOffset; }
    void SetHitboxXOffset(float x){hitboxXOffset = x;}
    float GetHitboxYOffset() const { return hitboxYOffset; }
    void SetHitboxYOffset(float y){hitboxYOffset = y;}
    void SetHitboxXYOffset(float x, float y){SetHitboxXOffset(x); SetHitboxYOffset(y);}

    float GetHitboxWidth() const { return hitboxWidth; }
    void SetHitboxWidth(float w){hitboxWidth = w;}
    float GetHitboxHeight() const { return hitboxHeight; }
    void SetHitboxHeight(float h){hitboxHeight = h;}
    void SetHitboxDimensions(float w, float h){ SetHitboxWidth(w); SetHitboxHeight(h);}
};

#endif // ACTOR_H_INCLUDED
