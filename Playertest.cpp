//Test for Player

#include "Player.h"

int main()
{   
    srand(static_cast<unsigned int>(time(0)));
    Player hero;

    //Player 
    cout << "name: " << hero.getName() << endl;
    cout << "currentHealth: " << hero.getCurrentHealth() << endl;
    cout << "maxHealth: " << hero.getMaxHealth() << endl;
    cout << "strength: " << hero.getStrength() << endl;
    cout << "speed: " << hero.getSpeed() << endl;
    cout << "level: " << hero.getLevel() << endl;
    cout << "coin: " << hero.getCoin() << endl;
    cout << "current Exp: " << hero.getCurrentExpPoint() << endl;
    cout << "max Exp: " << hero.getMaxExpPoint() << endl;

    //setters
    hero.setName("Tommy");
    hero.setLevel(11);
    hero.setSpeed(11);
    hero.setCurrentHealth(11);
    hero.setMaxHealth(11);
    hero.setStrength(11);
    hero.setCoin(11);
    hero.setCurrentExpPoint(11);
    hero.setMaxExpPoint(11);

    cout << "after setting" << endl << endl << endl;

    //renewed
    cout << "name: " << hero.getName() << endl;
    cout << "currentHealth: " << hero.getCurrentHealth() << endl;
    cout << "maxHealth: " << hero.getMaxHealth() << endl;
    cout << "strength: " << hero.getStrength() << endl;
    cout << "speed: " << hero.getSpeed() << endl;
    cout << "level: " << hero.getLevel() << endl;
    cout << "coin: " << hero.getCoin() << endl;
    cout << "current Exp: " << hero.getCurrentExpPoint() << endl;
    cout << "max Exp: " << hero.getMaxExpPoint() << endl;
    


    return 0;
}

//hassle to write
//g++ Playertest.cpp Player.cpp Character.cpp  Equipment.cpp -o mplayer