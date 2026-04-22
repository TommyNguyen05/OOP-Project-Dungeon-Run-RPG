#ifndef MOB_H
#define MOB_H

#include "Enemy.h" 
#include <cstdlib>
#include <ctime>

class Mob : public Enemy
{
    public:
    //empty constructor
    Mob();
    //constructor for Mob
    Mob(string name, int currentHealth, int maxHealth, int strength, int speed, int damage, int difficulty);

    //virtuals
    void setDifficulty();
    // maxHealth
    void setMaxHealth(int health);
    // strength
    void setStrength(int strength);
    // speed
    void setSpeed(int speed);

};
#endif