#include "Shop.h"
#include "Player.h"
#include "EquipmentList.h"
#include <iostream>

int main() {
    // Initialize equipment list (load from file)
    EquipmentList* equipmentList = EquipmentList::getEquipmentList("equipment.txt");

    // Create a player
    Player player("Hero", 100, 100, 10, 10, 10, 1, 1200, 0, 100);

    // Display initial player stats before shopping
    std::cout << "Initial player stats:\n";
    player.setCoin(5000);  // Set player's initial coin balance
    player.displayStats();
    
    // Check if the player has an initial weapon equipped
    if (player.getWeapon() != nullptr) {
        std::cout << "\nCurrent weapon: " << player.getWeapon()->getName() << std::endl;
    } else {
        std::cout << "\nCurrent weapon: None" << std::endl;
    }
    
    std::cout << "Coins: " << player.getCoin() << "\n";
    std::cout << "\n";

    // Create a shop at step number 1
    Shop shop(1);

    // Execute the shop (simulate entering the shop)
    shop.execute();

    char continueShopping = 'y';  // Variable to control shopping loop

    // Allow the player to purchase multiple pieces of equipment
    while (continueShopping == 'y' || continueShopping == 'Y') {
        // Simulate the player purchasing an item from the shop
        shop.purchaseEquipment(&player);

        // Display player stats after shopping
        std::cout << "\nPlayer stats after shopping:\n";
        player.displayStats();

        // Display the currently equipped weapon
        if (player.getWeapon() != nullptr) {
            std::cout << "\nCurrent weapon: " << player.getWeapon()->getName() << std::endl;
        } else {
            std::cout << "\nCurrent weapon: None" << std::endl;
        }

        // Display remaining coins
        std::cout << "Coins: " << player.getCoin() << "\n";

        // Ask if the player wants to continue shopping
        std::cout << "\nDo you want to purchase another item? (y/n): ";
        std::cin >> continueShopping;

        if (player.getCoin() <= 0) {
            std::cout << "You have run out of coins!\n";
            break;  // Stop shopping if the player runs out of coins
        }
    }

    std::cout << "\nThank you for shopping!\n";
    std::cout << "Shop has been deleted and its resources cleaned up.\n";

    return 0;
}
