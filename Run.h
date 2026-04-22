#ifndef RUN_H
#define RUN_H


#include "Character.h"
#include "Scene.h"
#include "Player.h"
#include "Mob.h"
#include "Boss.h"
#include <vector>

class Run //Going to manage a "run" of the game, this wil include the scene randomisation and 
          //player handling ish. 
{
private:
    // Scene* CurrentScene;
    // vector<Scene*> PreviousScene;
    Player CurrentPlayer;
    
public:
    //In use
    Run(Player p); 
    Mob randomMob();            //Used for encounter
    Boss randomBoss();              //used for final fight

    //Not in use
    // Scene* setScene();                // Switches to a new scene randomly
    // Player getPlayer();            // Returns player
    // Scene* getCurrentScene();       // Returns pointer to the current scene
    // void runGame();                 // Main game loop
   

};

#endif
