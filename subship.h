#ifndef SUBSHIP_H_INCLUDED
#define SUBSHIP_H_INCLUDED

#include "image.h"

#include "ship.h"
#include "particle.h"

#include "lockon.h"

#include <cmath>

class Subship : public Ship
{
    Ship* attachedShip;
    std::vector<size_t>assignedLockons;

    float attachmentAngle{};
    float attachmentRadius{};

    float attachmentXOffset{};
    float attachmentYOffset{};

    bool isDetached{}; // When in detached mode, subships obey their own positioning logic instead of having their positions automatically adjusted by the attached ship
    int phase{};
    enum enumPhases
    {
        ATTACHED_ORBIT,

        // "Xiphos routine"
        DETACHED_WARP_TO_TARGET, // Warp into vicinity of target.
        DETACHED_ATTACK_TARGET, // Fire subship weapon at target
        DETACHED_RETURN_WARP // Warp back to attachment position, ending detached mode
    };

    float warpToTargetAngle;
    float warpToTargetRadius;
    const float WARP_TO_TARGET_RADIUS_MIN = 64;
    const float WARP_TO_TARGET_RADIUS_MAX = 256;
    int warpToTargetDelay;
    const int WARP_TO_TARGET_DELAY_PERIOD = Timer::FPS * 0.2;

    int attackTargetDelay;
    const int ATTACK_TARGET_DELAY_PERIOD = Timer::FPS * 0.3;

    int returnWarpDelay;
    const int RETURN_WARP_DELAY_PERIOD = Timer::FPS * 0.2;

    Emitter *mainEmitter;


public:
    enum enumSubshipHull
    {
        HULL_SUBSHIP_XIPHOS = 0,
        HULL_SUBSHIP_EFTHYMIA = 1
    };
    static const int NUM_HULL_TYPES = 2;

    Subship();
    ~Subship();

    void Initialize(int hull_type, Ship *attached_ship);

    void Logic();
    void Drawing();

    float GetAttachmentAngle() const {return attachmentAngle;}
    void SetAttachmentAngle(float angle){attachmentAngle = angle;}
    float GetAttachmentRadius() const {return attachmentRadius;}
    void SetAttachmentRadius(float radius){attachmentRadius = radius;}

    float GetAttachmentXOffset() const { return attachmentXOffset; }
    void SetAttachmentXOffset(float x){ attachmentXOffset = x;}
    float GetAttachmentYOffset() const { return attachmentYOffset; }
    void SetAttachmentYOffset(float y){ attachmentYOffset = y;}
    void SetAttachmentXYOffset(float x, float y){ SetAttachmentXOffset(x); SetAttachmentYOffset(y);}

    Ship* GetAttachedShip(){return attachedShip;}
    void SetAttachedShip(Ship* attach){attachedShip = attach;}

    float GetIsDetached() const { return isDetached; }
    void SetIsDetached(bool is_detached){isDetached = is_detached;}

    int GetPhase() const { return phase; }
    void SetPhase(int which_phase);

    void AssignLockon(size_t index){assignedLockons.push_back(index);}

    void CreateWarpToTargetAfterimages(float x1, float y1, float x2, float y2);
};

#endif // SUBSHIP_H_INCLUDED
