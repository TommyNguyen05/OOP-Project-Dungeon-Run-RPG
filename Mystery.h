#ifndef MYSTERY_H
#define MYSTERY_H

#include "Scene.h"
#include "Shop.h"
#include "Character.h"
#include "Player.h"
#include "Enemy.h"
#include "Mob.h"
#include "Boss.h"

class Mystery : public Scene {
public:
    Mystery(int stepNum, Player* hero);
    ~Mystery();
    //to randomly select an event
    void execute() override;

private:
    Player* player;

    // Corresponding function to initialise one of the scene
    void encounterEvent();
    void shopEvent(Player* hero);
    void peacefulEvent();
};

#endif 
