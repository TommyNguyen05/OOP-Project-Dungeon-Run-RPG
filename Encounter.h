#ifndef ENCOUNTER_H
#define ENCOUNTER_H
#include"ContinuousEquipment.h"
#include"Equipment.h"
#include"Player.h"
#include"Enemy.h"
#include"Mob.h"
#include"Boss.h"
#include"Scene.h"

class Encounter : public Scene {
private:
    Player* player;
    Enemy* enemy;

    void displayStats(); // Function to display Player and Enemy stats.
    void applyContinuousEquipment(); // Apply and revert continuous equipment.
    void removeEquipmentEffect();
    void clearScreen();

public:
    Encounter(Player* player, Enemy* enemy, int stepNum);
    void execute(); // The main combat logic.
    ~Encounter();
};

#endif
