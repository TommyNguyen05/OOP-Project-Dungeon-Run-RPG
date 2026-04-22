#include "Mystery.h"


#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
#include <iostream>

//Constructor
Mystery::Mystery(int stepNum, Player* hero) : Scene(stepNum), player(hero){
  std::srand(std::time(0));
}

//Destructor
Mystery::~Mystery() {
  std::cout << "Mystery scene has been destroyed." << std::endl;
}

//Execute the command
void Mystery::execute() {
  std::cout << "You have entered a mysterious scene...\n";
  srand(time(0));   // So that the Rand() gives different random number everytime

  // Randomly select an event
  int event = 1 + rand() % (3);

  switch (event) {
    case 1:
      encounterEvent();
      break;
    case 2:
      shopEvent(player);
      break;
    case 3:
      peacefulEvent();
      break;
    default:
      std::cout << "Nothing happens... strange.\n";
      break;
  }
}

//encounter event?
void Mystery::encounterEvent() {
  std::cout << "You encounter some enemies! Prepare for battle!\n";
  // Something something ... Encounter constructor????
}

//Shop event?
void Mystery::shopEvent(Player* hero) {
  cout << "your current coin: " << hero->getCoin() << endl
                 << endl;
                 
  std::cout << "You stumble upon a hidden shop!\n";
  Shop newShop(getStepNum() + 1);
            newShop.execute();  // Display the shop and available items
            
            char continueShopping = 'y';  // Variable to control shopping loop

            // Allow the player to purchase multiple pieces of equipment
            while (continueShopping == 'y' || continueShopping == 'Y') {
                // Simulate the player purchasing an item from the shop
                newShop.purchaseEquipment(hero);

                // Display player stats after shopping
                cout << "\nPlayer stats after shopping:\n";
                hero->displayStats();

                // Display the currently equipped weapon
                if (hero->getWeapon() != nullptr) {
                    cout << "\nCurrent weapon: " << hero->getWeapon()->getName() << endl;
                } else {
                    cout << "\nCurrent weapon: None" << endl;
                }

                // Display remaining coins
                cout << "Coins: " << hero->getCoin() << "\n";

                // Ask if the player wants to continue shopping
                while (true) {
                    cout << "\nDo you want to buy and replace the weapon? (y/n): ";
                    cin >> continueShopping;

                    // Check if input is valid ('y' or 'n')
                    if (continueShopping == 'y' || continueShopping == 'Y' ||
                        continueShopping == 'n' || continueShopping == 'N') {
                        break;  // Valid input, exit the loop
                    } else {
                        // Invalid input, clear the error flag and ignore the rest of the invalid input
                        cout << "Invalid input. Please enter (y/n)" << endl;
                    }
                }

                // Stop shopping if the player runs out of coins
                if (hero->getCoin() <= 0) {
                    cout << "You have run out of coins!\n";
                    break;
                }
            }

            cout << "\nThank you for shopping!\n";
}

//Peaceful Event
void Mystery::peacefulEvent() {
  std::cout << "You find a peaceful spot to rest and heal.\n";
  player->setCurrentHealth(player->getMaxHealth());
  std::cout << "Your health has been fully restored!\n";
}
