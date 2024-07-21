#ifndef BULLET_H_INCLUDED
#define BULLET_H_INCLUDED

#include "particle.h"

#include "hax.h"

class Bullet : public Particle
{
    bool isNPCBullet;
    int damage;

public:
    static std::vector<Bullet*>bullets;

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

    void Drawing();

    void Initialize(int form, float speed, float angle, int lifespan);
    void EmitHitSparks(int particle_form);

    bool GetIsNPCBullet(){return isNPCBullet;}
    void SetIsNPCBullet(bool is_npc_bullet){isNPCBullet = is_npc_bullet;}

    int GetDamage(){return damage;}
    void SetDamage(int dmg){damage = dmg;}
};

#endif // BULLET_H_INCLUDED
