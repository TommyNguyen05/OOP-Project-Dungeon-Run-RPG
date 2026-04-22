#include "Shop.h"
#include "Equipment.h"
#include "EquipmentList.h"
#include "ContinuousEquipment.h"
#include <iostream>

//Initilizer
Shop::Shop(int stepNum) : Scene(stepNum) {
  equipmentsForSale = EquipmentList::getEquipmentList("equipment.txt")->getRandomEquipmentList(5);  
        // From the EquipmentList static object, get a list of 5 random equipment items
}
//Destruction
Shop::~Shop() {
    // If equipmentsForSale should not be deleted because they are used elsewhere, don't delete them here.
    // Just clear the vector without deleting the equipment objects.
    equipmentsForSale.clear();
    std::cout << "Shop has been cleaned up.\n";
}

//Execute function
void Shop::execute() {
  std::cout << "Welcome to the Shop! Here are the available items:\n";
  displayEquipments();
}

//Display Equipments
void Shop::displayEquipments() {
    for (size_t i = 0; i < equipmentsForSale.size(); i++) {
        ContinuousEquipment* equipment = dynamic_cast<ContinuousEquipment*>(equipmentsForSale[i]);
        if (equipment) {
            std::cout << i + 1 << ". " << equipment->getName()
                      << " - Price: " << equipment->getPrice()
                      << " (" << equipment->getStatType() << " + " << equipment->getModifier() << " times)" << std::endl;
        } else {
            std::cout << "Error: Invalid equipment type." << std::endl;
        }
    }
}

void Shop::purchaseEquipment(Player* player) {
    int choice = 0;

    while (true) {
    std::cout << "Enter the Weapon number you want to buy (0 for exit, choose between 1 to 5): ";
    std::cin >> choice;

    // Check if the input is invalid (non-integer input) or out of the valid range (not between 0 and 5)
    if (std::cin.fail() || choice < 0 || choice > 5) {
        // Clear the error flag
        std::cin.clear();
        // Ignore the rest of the invalid input
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // Display an error message
        std::cout << "Invalid input. Please enter a number between 0 and 5." << std::endl;
    } else {
        // Ignore any extra input after the valid integer
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        
        // If the player enters 0, they exit the shop
        if (choice == 0) {
            std::cout << "Exiting the shop.\n";
            return;
        }

        // If the choice is valid (within range 1-5), break out of the loop
        if (choice >= 1 && choice <= 5) {
            break;
            }
        }
    }
}
