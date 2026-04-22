#include"Encounter.h"

//Initializer with variables
Encounter::Encounter(Player* player, Enemy* enemy, int stepNum) : Scene(stepNum), player(player), enemy(enemy) {}

//Clearing the screen
void Encounter::clearScreen(){
        for (int i = 0; i < 100; ++i) {
        std::cout << std::endl;
    }
}

//Displaying stats
void Encounter::displayStats(){
    enemy->displayStats();
    cout << endl;
    player->displayStats();
}

//Apply the equipment
void Encounter::applyContinuousEquipment(){
    if (player->getWeapon() != nullptr){
        player->getWeapon()->modifyPlayerStat(player);
    }
}