#include "Boss.h"

// empty constructor
Boss::Boss() : Enemy("Empty Boss child of Enemy",3,3,3,3,3,3)
{

}
// constructor for Mob
Boss::Boss(string name, int currentHealth, int maxHealth, int strength, int speed, int damage, int difficulty) 
: Enemy(name, currentHealth, maxHealth, strength, speed, damage, difficulty)
{
}

// virtuals
void Boss::setDifficulty()
{
    //difficulty is set between 1 - 20
    //making it either very easy or very hard :)
    difficulty = (rand() % 20 + 1);
}
// maxHealth
void Boss::setMaxHealth(int maxHealth)
{
    this -> maxHealth = maxHealth + 1 * difficulty;
}
// strength
void Boss::setStrength(int strength)
{
    this -> strength = strength + 1 * difficulty;
}
// speed
void Boss::setSpeed(int speed)
{
    this -> speed = speed + 1 * difficulty;
}



