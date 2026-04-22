//Welcome adventurer! the story of this game sets in a far away land where you must venture on your own
//defeating the Goblin king along with his minnions! farewell and goodluck, may the Goddess bless you 
//with great fortune!! -igie, maybe should be initial text 

//standard libraries
#include <cstdlib>
#include <ctime>
#include <iostream>

//file saving
#include <fstream>
#include <string>
#include <vector>

//classess libraries
#include "Boss.h"
#include "ContinuousEquipment.h"
#include "Mob.h"
#include "Mystery.h"
#include "Player.h"
#include "Shop.h"

using namespace std;

int main()
{
    Player hero("Hero", 2000, 2000, 10, 10, 100, 1, 0, 0, 500);
    Mob mob("Goblin", 1000, 1000, 10, 10, 50, 1);
            mob.setDifficulty();

            cout << "You have encountered a mob!" << endl;
            cout << "Prepare for battle! " << endl;

            while (hero.getCurrentHealth() > 0 && mob.getCurrentHealth() > 0)
            {
                hero.doDamage(&mob);
                if (hero.getCurrentHealth() > 0)
                {
                    mob.enemyAttack(&mob);
                }
            }

            if (hero.getCurrentHealth() > 0)
            {
                cout << hero.getName() << " wins!" << endl;
                cout << "Current Stat: " << endl;
                hero.displayStats();
                hero.levelUp();
                cout << "After lvl Up: " << endl;
                hero.displayStats();

            }
            else
            {
                cout << mob.getName() << " wins!" << endl;
                cout << "Player died! " << endl;
                cout << "Game Over!" << endl;
                return 0;
}}

//g++ Fightingtest.cpp Scene.cpp Player.cpp EquipmentList.cpp Equipment.cpp ContinuousEquipment.cpp Character.cpp ConditionialEquipment.cpp AfterBattleEquipment.cpp Enemy.cpp Mob.cpp Boss.cpp -std=c++11 -o Fighting_test