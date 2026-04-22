#ifndef PLAYER_H
#define PLAYER_H

#include "Character.h"
#include "ContinuousEquipment.h"


class Player : public Character {

    private:

    string name;
    int level;
    int coin;
    int currentExpPoint;
    int maxExpPoint;

    protected:
    
    ContinuousEquipment* weapon;

    public:
    Player();
    Player(string name, int currentHealth, int maxHealth, int strength, int speed, int damage, 
    int level, int coin, int currentExpPoint, int maxExpPoint);

    //pure virtuals from Character

    // pure only virtual maxHealth function
    void setMaxHealth(int maxHealth) override;

    // pure only virtual strength function
    void setStrength(int strength) override;

    // pure only virtual speed function
    void setSpeed(int speed) override;

    //virtual damage
    void setDamage(int damage) override;

    //getters and setters:

    //level
    int getLevel();
    void setLevel(int level);

    //coin
    int getCoin();
    void setCoin(int coin);
    void gainCoin();

    //currentExpPoint
    int getCurrentExpPoint();
    void setCurrentExpPoint(int currentExpPoint);

    //maxExpPoint
    int getMaxExpPoint();
    void setMaxExpPoint(int maxExpPoint);

    //checks if the player can level up
    void levelUp();

    //conditions for equipping weapon
    void equipWeapon(ContinuousEquipment* weapon, Character* player);

    ContinuousEquipment* getWeapon();

    //displays stats
    void displayStats() override; 

    // Tommy added- function to increase stats after equipped
    void setNewStrength(int strength);
    void setNewSpeed(int Speed);
    void setNewMaxHealth(int health);

    //attacking of player
    void doDamage(Character* opponent);
    
};



#endif