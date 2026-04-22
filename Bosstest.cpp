//Test for Boss

#include "Boss.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Boss goblinKing;

    //Boss
    cout << "name: " << goblinKing.getName() << endl;
    cout << "currentHealth: " << goblinKing.getCurrentHealth() << endl;
    cout << "maxHealth: " << goblinKing.getMaxHealth() << endl;
    cout << "strength: " << goblinKing.getStrength() << endl;
    cout << "speed: " << goblinKing.getSpeed() << endl;
    cout << "difficulty: " << goblinKing.getDifficulty() << endl;


    //setters
    goblinKing.setName("Igie");

    //make sure setDifficulty() is before setters otherwise it crashes.
    //unknown why
    goblinKing.setDifficulty();
    goblinKing.setSpeed(0);
    goblinKing.setCurrentHealth(10);
    goblinKing.setMaxHealth(0);
    goblinKing.setStrength(0);

    cout << " " << endl ;
    cout << "after setting" << endl ;

    //renewed
    cout << "name: " << goblinKing.getName() << endl;
    cout << "currentHealth: " << goblinKing.getCurrentHealth() << endl;
    cout << "maxHealth: " << goblinKing.getMaxHealth() << endl;
    cout << "strength: " << goblinKing.getStrength() << endl;
    cout << "speed: " << goblinKing.getSpeed() << endl;
    cout << "difficulty: " << goblinKing.getDifficulty() << endl;

    return 0;
}

//hassle to write
//g++ Bosstest.cpp Boss.cpp Enemy.cpp Character.cpp -o mboss
//./mboss