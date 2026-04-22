#ifndef BOSS_H
#define BOSS_H

#include "Enemy.h"
class Boss : public Enemy
{
    public:
    //empty constructor
    Boss();
    //constructor for Mob
    Boss(string name, int currentHealth, int maxHealth, int strength, int speed, int damage, int difficulty);

    //virtuals
    void setDifficulty();
    // maxHealth
    void setMaxHealth(int health);
    // strength
    void setStrength(int strength);
    // speed
    void setSpeed(int speed);
    // damage
    // void setDamage(int strength);

};

#endif
