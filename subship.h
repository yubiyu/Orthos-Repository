#ifndef SUBSHIP_H_INCLUDED
#define SUBSHIP_H_INCLUDED

#include "image.h"

#include "ship.h"

#include <cmath>

class Subship : public Ship
{
    Ship* attachedShip;
    std::vector<Ship*>assignedTargets;

    float attachmentAngle;
    float attachmentRadius;

    float attachmentXOffset;
    float attachmentYOffset;

    bool isDetached; // When in detached mode, subships obey their own positioning logic instead of having their positions automatically adjusted by the attached ship
    int detachedModePhase;
    enum enumDetachedModePhases
    {
        // "Xiphos routine"
        DETACHED_WARP_TO_TARGET, // Warp into vicinity of target.
        DETACHED_ATTACK_TARGET, // Fire subship weapon at target
        DETACHED_RETURN_WARP // Warp back to attachment position, ending detached mode
    };

public:
    enum enumSubshipHull
    {
        HULL_SUBSHIP_XIPHOS = 0
    };

    Subship();
    ~Subship();

    void Initialize(int hull_type, Ship *attached_ship);

    void Logic();
    void Drawing();

    float GetAttachmentAngle(){return attachmentAngle;}
    void SetAttachmentAngle(float angle){attachmentAngle = angle;}
    float GetAttachmentRadius(){return attachmentRadius;}
    void SetAttachmentRadius(float radius){attachmentRadius = radius;}

    float GetAttachmentXOffset(){return attachmentXOffset;}
    void SetAttachmentXOffset(float x){ attachmentXOffset = x;}
    float GetAttachmentYOffset(){return attachmentYOffset;}
    void SetAttachmentYOffset(float y){ attachmentYOffset = y;}
    void SetAttachmentXYOffset(float x, float y){ SetAttachmentXOffset(x); SetAttachmentYOffset(y);}

    Ship* GetAttachedShip(){return attachedShip;}
    void SetAttachedShip(Ship* attach){attachedShip = attach;}

    float GetIsDetached(){return isDetached;}
    void SetIsDetached(bool is_detached){isDetached = is_detached;}

    int GetDetachedModePhase(){return detachedModePhase;}
    void SetDetachedModePhase(int phase){detachedModePhase = phase;}

    void AssignTarget(Ship* target){assignedTargets.push_back(target);}

};

#endif // SUBSHIP_H_INCLUDED
