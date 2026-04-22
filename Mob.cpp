#include "Mob.h"

// empty constructor
Mob::Mob() : Enemy ("Empty Child Mob", 3,3,3,3,3,3)
{

}
// constructor for Mob
Mob::Mob(string name, int currentHealth, int maxHealth, int strength, int speed, int damage, int difficulty) : 
Enemy(name, currentHealth, maxHealth, strength, speed, damage, difficulty)
{

}

// virtuals
void Mob::setDifficulty()
{
    // difficulty is set between  1 - 5
    this -> difficulty = (rand() % 5 + 1);
    cout << endl << "Mob difficulty: " << difficulty << endl << endl;
    currentHealth += 200 * difficulty;
    maxHealth += 200 * difficulty;
    strength += 3 * difficulty;
    speed += 3 * difficulty;
    cout << "Current health: " << currentHealth << endl;
    cout << "Max health: " << maxHealth <<  endl;
    cout << "Strength: " << strength << endl;
    cout << "Speed: " << speed << endl << endl;

}


// maxHealth
void Mob::setMaxHealth(int maxHealth)
{
    this->maxHealth = maxHealth;
}
// strength
void Mob::setStrength(int strength)
{
    this -> strength = strength;
}
// speed
void Mob::setSpeed(int speed)
{
    this -> speed = speed;
}
