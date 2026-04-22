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

    int input;

    while (true)
    {
        cout << "Press [1] to start the game" << endl;
        cout << "Press [2] to end the game" << endl;
        cout << "insert: ";

        cin >> input;

        // Check if the input is valid and if it is either 1 or 2
        if (cin.fail() || (input != 1 && input != 2))
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
            cout << "Invalid input. Please enter 1 or 2." << endl;
        }
        else
        {
            break; // Exit the loop if the input is valid
        }
    }

    if (input == 1)
    {
        cout << "Starting the game..." << endl
             << endl;
    }
    else if (input == 2)
    {
        cout << "Ending the game..." << endl;
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
    system("clear");
    // Loop for 10 rounds
    for (int i = 0; i < 10; i++)
    {
        system("clear");
        cout << "Step Number: " << i + 1 << endl;
        // Randomizer
        int roll = rand() % 100 + 1;

        // Shop (35% chance)
        if (roll <= 35)
        {
            cout << endl;
            cout << "You have encountered a shop!" << endl;
            cout << "Your current coin: " << hero.getCoin() << endl;

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
            this_thread::sleep_for(chrono::seconds(3));

            while (hero.getCurrentHealth() > 0 && mob.getCurrentHealth() > 0)
            {
                system("clear");
                hero.doDamage(&mob);

                if (mob.getCurrentHealth() > 0)
                {
                    mob.enemyAttack(&hero);
                }

                int input;

                while (true)
                {
                    cout << "Press [1] for to attack" << endl;
                    cout << "Press [2] to flee battle" << endl;
                    cout << "Press [3] to exit game" << endl;
                    cout << "Insert: ";

                    cin >> input;

                    // Check if the input is valid and if it is either 1, 2, or 3
                    if (cin.fail() || (input != 1 && input != 2 && input != 3))
                    {
                        cin.clear();                                         // Clear the error flag
                        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore the rest of the invalid input
                        cout << "Invalid input. Please enter 1, 2, or 3." << endl;
                    }
                    else
                    {
                        // Perform actions based on the valid input
                        if (input == 1)
                        {
                            cout << "Game proceeds..." << endl;
                            break;
                        }
                        else if (input == 2)
                        {
                            cout << "Fleeing battle" << endl;
                            break; // Exit the loop
                        }
                        else if (input == 3)
                        {
                            cout << "Exiting game..." << endl;
                            return 0; // Exit the program
                        }

                    }
                    
                }

                if (input == 2)
                    {
                        break;
                    }

                if (hero.getCurrentHealth() > 0 && mob.getCurrentHealth() <= 0)
                {
                    system("clear");
                    cout << hero.getName() << " wins!" << endl;
                    cout << endl;
                    hero.gainCoin();
                    cout << endl;
                    hero.levelUp();
                    cout << endl;
                    hero.displayStats();
                    cout << endl;
                }
                else if (hero.getCurrentHealth() <= 0 && mob.getCurrentHealth() > 0)
                {
                    cout << mob.getName() << " wins!" << endl;
                    cout << "Player died!! " << endl;
                    cout << "Game Over!!" << endl;
                    return 0;
                }
            }

            this_thread::sleep_for(chrono::seconds(2));
            
        }
    }

    // boss fight
    Boss boss = Setter.randomBoss();

    system("clear");
    cout << "You have encountered a " << boss.getName() << "!" << endl;
    cout << "Prepare for battle! " << endl;
    this_thread::sleep_for(chrono::seconds(2));
    while (hero.getCurrentHealth() > 0 && boss.getCurrentHealth() > 0)
    {
        system("clear");
        hero.doDamage(&boss);
        if (boss.getCurrentHealth() > 0)
        {
            boss.enemyAttack(&hero);
        }
        this_thread::sleep_for(chrono::seconds(1));
    }

    if (hero.getCurrentHealth() > 0)
    {
        Winners saving;
        cout << hero.getName() << " wins!" << endl;
        cout << "\nSaving " + hero.getName() << " to the list of winners!" << endl;
        saving.saveName(hero.getName(),hero.getLevel(), "Winners.txt");
    }
    else
    {
        cout << boss.getName() << " wins!" << endl;
        cout << "Player died! " << endl;
        cout << "Game Over!" << endl;
        return 0;
    }
    this_thread::sleep_for(chrono::seconds(5));
    system("clear");
    Winners loading;
    cout << endl
         << endl
         << "Players who have became victorious:" << endl
         << endl;
    vector<string> winnersList = loading.loadNames("Winners.txt");
    int count = 1;
    for (int i = winnersList.size()-1; i > 0; i--)
    {
        
        cout << (count) << ". " << winnersList[i] << endl;
        count++;
    }

    // save file name of winner
    return 0;
}

// g++ main.cpp Scene.cpp Player.cpp EquipmentList.cpp Equipment.cpp ContinuousEquipment.cpp Character.cpp Enemy.cpp Mob.cpp Boss.cpp Shop.cpp Mystery.cpp -std=c++11 -o main1_test