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
#include "Winners.h"
#include "Run.h"
//#include "Game.h"

//using namespace
using namespace std;



int main()
{
    //Start Up informatiom
    cout << "Welcome to Dungeon Run!" << endl;
    cout << "Press [1] to start the game" << endl;
    cout << "Press [2] to end the game" << endl;

    // Defensive coding to ensure valid input
    int choice;
    while (true)
    {
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice != 1 && choice != 2)
        {
            cout << "Invalid input. Please press [1] to start the game or [2] to end." << endl;
        }
        else
        {
            break;
        }
    }

    // Exit if the user chooses to end the game
    if (choice == 2)
    {
        cout << "Game ended. See you next time!" << endl;
        return 0;
    }

    cout << "Game started! Let the adventure begin..." << endl;
    cout <<"Enter your name: ";
    string heroName;
    cin >> heroName;

    // Initialize player object with preset stats
    Player hero(heroName, 2000, 2000, 10, 10, 1000, 1, 0, 0, 500);
    Run Setter(hero);
    // Reset roll every time run is activated
    srand(static_cast<unsigned int>(time(0)));
    // Loop for 10 rounds
    for (int i = 0; i < 10; i++)
    {
        cout << "\n Step Number: " << i << endl;

        

        // Randomizer
        int roll = rand() % 100 + 1;
        cout << "\n roll number: " << roll << endl;


        // Shop (35% chance)
        if (roll <= 35)
        {
            cout << "You have encountered a shop!" << endl;

            // Create a shop at the current step number
            Shop newShop(i + 1);
            newShop.execute(); // Display the shop and available items

            char continueShopping = 'y'; // Variable to control shopping loop

            // Allow the player to purchase multiple pieces of equipment
            while (continueShopping == 'y' || continueShopping == 'Y')
            {
                // Simulate the player purchasing an item from the shop
                newShop.purchaseEquipment(&hero);

                // Display player stats after shopping
                cout << "\nPlayer stats after shopping:\n";
                hero.displayStats();

                // Display the currently equipped weapon
                if (hero.getWeapon() != nullptr)
                {
                    cout << "\nCurrent weapon: " << hero.getWeapon()->getName() << endl;
                }
                else
                {
                    cout << "\nCurrent weapon: None" << endl;
                }

                // Display remaining coins
                cout << "Coins: " << hero.getCoin() << "\n";

                // Ask if the player wants to continue shopping
                while (true)
                {
                    cout << "\nDo you want to buy and replace the weapon? (y/n): ";
                    cin >> continueShopping;

                    // Check if input is valid ('y' or 'n')
                    if (continueShopping == 'y' || continueShopping == 'Y' ||
                        continueShopping == 'n' || continueShopping == 'N')
                    {
                        break; // Valid input, exit the loop
                    }
                    else
                    {
                        // Invalid input, clear the error flag and ignore the rest of the invalid input
                        cout << "Invalid input. Please enter (y/n)" << endl;
                    }
                }

                // Stop shopping if the player runs out of coins
                if (hero.getCoin() <= 0)
                {
                    cout << "You have run out of coins!\n";
                    break;
                }
            }

            cout << "\nThank you for shopping!\n";
        }



        // Mystery (15% chance)
        else if (roll >= 36 && roll <= 50)
        {
            cout << "You have encountered a mystery!" << endl;
            int stepNum = i + 1;
            // Placeholder for Mystery logic
            Mystery mystery(stepNum, &hero); // Assuming Mystery works similarly to Shop or Encounter
            mystery.execute();              // Execute mystery action
        }



        // Encounter (50% chance) - Ignored for now
        if (roll >= 51)
        {
            Mob mob = Setter.randomMob();
            // Mob mob("Goblin", 1000, 1000, 10, 10, 50, 1);
            // mob.setDifficulty();

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
                hero.gainCoin();
                hero.levelUp();
                hero.displayStats();
            }
            else
            {
                cout << mob.getName() << " wins!" << endl;
                cout << "Player died! " << endl;
                cout << "Game Over!" << endl;
                return 0;
            }

        }
        
    }

    //boss fight
    Boss boss = Setter.randomBoss();
    
    // Boss boss("Goblin King", 1000, 1000, 10, 10, 50, 1);
    // boss.setDifficulty();

            cout << "You have encountered a "<<boss.getName()<< "!" << endl;
            cout << "Prepare for battle! " << endl;

            while (hero.getCurrentHealth() > 0 && boss.getCurrentHealth() > 0)
            {
                hero.doDamage(&boss);
                if (hero.getCurrentHealth() > 0)
                {
                    boss.enemyAttack(&boss);
                }
            }

            if (hero.getCurrentHealth() > 0)
            {
                Winners saving;
                cout << hero.getName() << " wins!" << endl;
                cout << "Saving " + hero.getName() << " to the list of winners!" << endl;
                saving.saveName(hero.getName(),hero.getLevel(), "Winners.txt");
            }
            else
            {
                cout << boss.getName() << " wins!" << endl;
                cout << "Player died! " << endl;
                cout << "Game Over!" << endl;
                return 0;
            }
    Winners loading;
    cout<<"Players who have became victorious:" << endl;
    vector<string> winnersList = loading.loadNames("Winners.txt");
    
    for(int i = 0; i < winnersList.size(); i++){
        cout<< (i+1)<<". " << winnersList[i] <<  endl;
    }

    //save file name of winner
    return 0;
}

// g++ main1.cpp Scene.cpp Player.cpp EquipmentList.cpp Equipment.cpp ContinuousEquipment.cpp Character.cpp ConditionialEquipment.cpp AfterBattleEquipment.cpp Enemy.cpp Mob.cpp Boss.cpp Shop.cpp Mystery.cpp -std=c++11 -o main1_test

