
// This program is a game that focuses on OOP rather than design etc. The purpose of the user is to
//  fight enemies, gain equipment, random encounters etc. -Tommy, Blake, and Igie

// standard libraries
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <thread>
#include <chrono>

// file saving
#include <fstream>
#include <string>
#include <vector>

// classess libraries
#include "Run.h"
#include "Boss.h"
#include "ContinuousEquipment.h"
#include "Mob.h"
#include "Mystery.h"
#include "Player.h"
#include "Shop.h"
#include "Winners.h"
#include "Defense.h"

// using namespace
using namespace std;

int main()
{
    // Start Up informatiom
    cout << endl
         << endl
         << endl
         << "Welcome adventurer! the story of "
         << "this game sets in a far away land where you must venture on your own " 
         << "defeating random mobs and set your heart ablaze and defeat the last Boss! \n \n " 
         << "farewell and goodluck, may the Goddess bless you with great fortune!!" << endl
         << endl;

    cout << "Press [1] to start the game" << endl;
    cout << "Press [2] to end the game" << endl
         << endl
         << endl;

    int choice = userInput12();

    // Exit if the user chooses to end the game
    if (choice == 2)
    {
        cout << "Game ended. See you next time!" << endl
             << endl;
        return 0;
    }

    cout << "Game started! Let the adventure begin..." << endl;
    cout << "Enter your name: ";
    string heroName;
    cin >> heroName;

    // Initialize player object with preset stats
    Player hero(heroName, 2000, 2000, 10, 10, 250, 1, 0, 0, 500);
    Run Setter(hero);
    // Reset roll every time run is activated
    srand(static_cast<unsigned int>(time(0)));
    // Loop for 10 rounds
    for (int i = 0; i < 10; i++)
    {
        cout << "\n Step Number: " << i + 1 << endl;

        // Randomizer
        int roll = rand() % 100 + 1;
        cout << "\n roll number: " << roll << endl;

        // Shop (35% chance)
        if (roll <= 35)
        {
            cout << endl;
            cout << "your current coin: " << hero.getCoin() << endl
                 << endl;
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
            cout << endl
                 << "You have encountered a mystery!" << endl;
            int stepNum = i + 1;
            // Placeholder for Mystery logic
            Mystery mystery(stepNum, &hero); // Assuming Mystery works similarly to Shop or Encounter
            mystery.execute();               // Execute mystery action
        }

        // Encounter (50% chance) - Ignored for now
        if (roll >= 51)
        {
            Mob mob = Setter.randomMob();

            // sets mob difficulty and increases stats
            mob.setDifficulty();

            cout << "You have encountered an enemy!" << endl;
            cout << "Prepare for battle! " << endl
                 << endl;

                userInput123();

                while (hero.getCurrentHealth() > 0 && mob.getCurrentHealth() > 0)
                {

                    hero.doDamage(&mob);

                    if (mob.getCurrentHealth() > 0)
                    {
                        mob.enemyAttack(&hero);
                    }
                }

                if (hero.getCurrentHealth() > 0)
                {
                    cout << hero.getName() << " wins!" << endl;
                    cout << endl;
                    hero.gainCoin();
                    cout << endl;
                    hero.levelUp();
                    cout << endl;
                    hero.displayStats();
                    cout << endl;
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

        this_thread::sleep_for(chrono::seconds(2));
    }

    // boss fight
    Boss boss = Setter.randomBoss();

    cout << "You have encountered a " << boss.getName() << "!" << endl;
    cout << "Prepare for battle! " << endl;

    while (hero.getCurrentHealth() > 0 && boss.getCurrentHealth() > 0)
    {
        hero.doDamage(&boss);
        if (boss.getCurrentHealth() > 0)
        {
            boss.enemyAttack(&hero);
        }
    }

    if (hero.getCurrentHealth() > 0)
    {
        Winners saving;
        cout << hero.getName() << " wins!" << endl;
        cout << "Saving " + hero.getName() << " to the list of winners!" << endl;
        saving.saveName(hero.getName(), "Winners.txt");
    }
    else
    {
        cout << boss.getName() << " wins!" << endl;
        cout << "Player died! " << endl;
        cout << "Game Over!" << endl;
        return 0;
    }
    Winners loading;
    cout << endl
         << endl
         << "Players who have became victorious:" << endl
         << endl;
    vector<string> winnersList = loading.loadNames("Winners.txt");

    for (int i = 0; i < winnersList.size(); i++)
    {
        cout << (i + 1) << ". " << winnersList[i] << endl;
    }

    // save file name of winner
    return 0;
}

// g++ main.cpp Scene.cpp Player.cpp EquipmentList.cpp Equipment.cpp ContinuousEquipment.cpp Character.cpp Enemy.cpp Mob.cpp Boss.cpp Shop.cpp Mystery.cpp -std=c++11 -o main1_test