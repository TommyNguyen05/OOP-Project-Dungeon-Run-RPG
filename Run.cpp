#include "Run.h"
#include "Scene.h"
#include "Shop.h"
#include "Mystery.h"
#include "Encounter.h"
#include "Player.h"
#include "Mob.h"
#include "Boss.h"
#include <vector>
#include <iostream>
#include <cstdlib> // Use this for rand

using namespace std;

Run::Run(Player p){
    CurrentPlayer = p;
}

Mob Run::randomMob(){
    srand(static_cast<unsigned int>(time(nullptr)));

    // Random name generator
    std::string names[] = {"Goblin", "Orc", "Troll", "Dragon", "Bandit", "Skeleton"};
    std::string randomName = names[rand() % 6];  // Select a random name

    // Random attributes
    int randomHealth = rand() % 850 + 50;    // Health between 50 and 150
    int randomStrength = rand() % 20 + 5;    // Strength between 5 and 25
    int randomSpeed = rand() % 15 + 5;       // Speed between 5 and 20
    int randomDamage = rand() % 35 + 10;     // Damage between 10 and 35
    int randomDifficulty = rand() % 5 + 1;   // Difficulty between 1 and 5

    // Create a random enemy using the random attributes
    Mob randomMob = Mob(randomName, randomHealth, randomHealth, randomStrength, randomSpeed,randomDamage,randomDifficulty);
    return randomMob;
}
Boss Run::randomBoss(){
    srand(static_cast<unsigned int>(time(nullptr)));

    // Random name generator
    std::string names[] = {"Goblin King", "Orc King", "Troll King", "Dragon King", "Bandit King", "Skeleton King"};
    std::string randomName = names[rand() % 6];  // Select a random name

    // Random attributes
    int randomHealth = rand() % 3000 + 150;    // Health between 150 and 200
    int randomStrength = rand() % 40 + 15;    // Strength between 15 and 20
    int randomSpeed = rand() % 30 + 15;       // Speed between 15 and 30
    int randomDamage = rand() % 100 + 30;     // Damage between 30 and 40
    int randomDifficulty = rand() % 10 + 5;   // Difficulty between 5 and 10

    // Create a random enemy using the random attributes
    Boss randomBoss = Boss(randomName,randomHealth,randomHealth,randomStrength,randomSpeed,randomDamage,randomDifficulty);
    return randomBoss;
}
// Scene* Run::setScene(){
//     Scene* NewScene = nullptr;
//     int random = rand() % 3;  // Adjusting the range for 3 cases: 0, 1, 2

//     while (NewScene == nullptr) {
//         switch (random) {
//         case 0: // Encounter
//             if(PreviousScene.size()+1 == 10){
//                 // Encounter* temp = new Encounter(&CurrentPlayer,&(randomBoss()),PreviousScene.size() + 1);
//                 // NewScene = temp;
//                 break;
//             }
//             break;
//         case 1: { // Mystery
//             Mystery* temp = new Mystery(PreviousScene.size() + 1,&CurrentPlayer);
//             NewScene = temp;
//             break;
//         }
//         case 2: { // Shop
//             Shop* temp = new Shop(PreviousScene.size() + 1);
//             NewScene = temp;
//             break;
//         }
//         default:
//             break;
//         }
//     }
//     return NewScene;
// }

// void Run::setScore(float Score){ // Getters and setters for Score
//     this->Score = Score;
// }

// float Run::getScore() const{
//     return Score;
// }

// void Run::runGame(){ 
//     cout << "Welcome to the game! Let's start!" << endl;
    
//     // Looping until player dies or after 5 scenes
//     while(PreviousScene.size() < 5 && CurrentPlayer.getCurrentHealth() > 0){
//         // Randomizer
//         CurrentScene = setScene();
        
//         // Execute the scene
//         if (CurrentScene != nullptr) {
//             CurrentScene->execute();
            
//             // Adding to the vector of previous scenes
//             PreviousScene.push_back(CurrentScene);
//         }
//     }

//     // Checking if the player died
//     if (CurrentPlayer.getCurrentHealth() <= 0) {
//         cout << "Oh no, you died! Want to try again?" << endl;
//         // Code to return to main menu or handle retry
//     } else {
//         cout << "Congratulations, you finished the game!" << endl;
//         // Handle win scenario or continue the game
//     }
// }
