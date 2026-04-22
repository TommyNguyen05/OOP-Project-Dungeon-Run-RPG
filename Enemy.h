#ifndef ENEMY_H
#define ENEMY_H

#include "Character.h"

class Enemy : public Character
{

    protected:
    int difficulty;

    public:
    //empty constructor
    Enemy();

    //default contstructor
    Enemy(string name, int currentHealth, int maxHealth, int strength, int speed, int damage, int difficulty);

    // getters and setters
    int getDifficulty();
    void setDifficulty();

    //damage calculator
    void setDamage(int damage);

    //display stats
    void displayStats() override; 

    //enemy way of attacking
    void enemyAttack(Character* opponent);

};

#endif