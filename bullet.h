#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "particle.h"

#include "hax.h"

class Bullet : public Particle
{
    bool isNPCBullet{};
    int damage{};

public:
    static std::vector<Bullet*>bullets;

    enum enumBulletForms
    {
        BULLET_FORM_ROUND = 0,
        BULLET_FORM_BEAM = 1,
        BULLET_FORM_ARROW = 2,
        BULLET_FORM_LARGE_ARROW = 3
    };
    static const int NUM_BULLET_FORMS = 4;

    Bullet();
    ~Bullet();

    void Drawing();

    void Initialize(int form, int colour, float speed, float angle, int lifespan);
    void EmitHitSparks(int particle_form, int particle_colour);

    bool GetIsNPCBullet() const { return isNPCBullet; }
    void SetIsNPCBullet(bool is_npc_bullet){isNPCBullet = is_npc_bullet;}

    int GetDamage() const { return damage; }
    void SetDamage(int dmg){damage = dmg;}
};

#endif // BULLET_H_INCLUDED
