//Test for mob

#include "Mob.h"

int main()
{
    srand(static_cast<unsigned int>(time(0)));
    Mob rat;

    //Mob
    cout << "name: " << rat.getName() << endl;
    cout << "currentHealth: " << rat.getCurrentHealth() << endl;
    cout << "maxHealth: " << rat.getMaxHealth() << endl;
    cout << "strength: " << rat.getStrength() << endl;
    cout << "speed: " << rat.getSpeed() << endl;
    cout << "difficulty: " << rat.getDifficulty() << endl;


    //setters
    rat.setName("Blake");

    //make sure setDifficulty() is before setters otherwise it crashes.
    //unknown why
    rat.setDifficulty();
    rat.setSpeed(1);
    rat.setCurrentHealth(1);
    rat.setMaxHealth(1);
    rat.setStrength(1);

    cout << " " << endl ;
    cout << "after setting" << endl ;

    //renewed
    cout << "name: " << rat.getName() << endl;
    cout << "currentHealth: " << rat.getCurrentHealth() << endl;
    cout << "maxHealth: " << rat.getMaxHealth() << endl;
    cout << "strength: " << rat.getStrength() << endl;
    cout << "speed: " << rat.getSpeed() << endl;
    cout << "difficulty: " << rat.getDifficulty() << endl;

    return 0;
}

//hassle to write
//g++ Mobtest.cpp Mob.cpp Enemy.cpp Character.cpp -o mmob
//./mmob