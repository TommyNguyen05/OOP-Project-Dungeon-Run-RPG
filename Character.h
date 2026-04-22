//This is an abstract class that got the basic functions effective to Player, Mob and Boss classess.
//Because of the pure virtual function, classess such as Player, Mob, and Boss would effectively have
//different functions for setting their maxHealth, strength, speed, and damage

#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include <iostream>
using namespace std;

class Character
{

protected:
    //basic stats of Characters
    string name;
    
    //health stats
    int currentHealth;
    int maxHealth;

    //strength increases damage output by strength * 10
    int strength;

    //speed increases the chance of not missing via roll
    int speed;

    //damage calculated here
    int damage;

public:
    // empty constructor
    Character();
    // default constructor
    Character(string name, int currentHealth, int maxHealth, int strength, int speed, int damage);

    // getters and setters:

    // Name
    string getName();
    void setName(string name);

    // currentHealth
    int getCurrentHealth();
    void setCurrentHealth(int health);

    //virtual maxHealth function
    int getMaxHealth();
    virtual void setMaxHealth(int maxHealth);

    //virtual strength function
    int getStrength();
    virtual void setStrength(int strength);

    //virtual speed function
    int getSpeed();
    virtual void setSpeed(int speed);

    //virtual damage function
    int getDamage();
    virtual void setDamage(int damage);

    // Function for attacking
    void attack(Character *opponent, int damage);

    // Function to take damage
    void takeDamage(int damage);

    //displays stats
    virtual void displayStats(); 

    // Tommy - Destructor added
    virtual ~Character() = default; 

    // Tommy added- function to increase stats after equipped
    void setNewStrength(int strength);
    void setNewSpeed(int Speed);
    void setNewMaxHealth(int health);
};


#endif
