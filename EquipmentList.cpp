#include "EquipmentList.h"
// #include "ContinuousEquipment.h"   // Include other Equipment inherited
// classes
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

//Not using these so they are commented out
//#include "AfterBattleEquipment.h"
//#include "ConditionialEquipment.h"
#include "ContinuousEquipment.h"

using namespace std;


EquipmentList* EquipmentList::equipmentList = nullptr;

//getting the list, creating a new EquipmentList pointer if it's nullptr
EquipmentList* EquipmentList::getEquipmentList(const string& filename) {
  if (equipmentList == nullptr) {
    equipmentList = new EquipmentList(filename);
  }
  return equipmentList;
}

//Constructor, loading the equipment from the files
EquipmentList::EquipmentList(const string& filename) {
  loadEquipments(filename);  // Load all predefined weapons
}

void EquipmentList::loadEquipments(const string& filename) {
  // Create predefined weapons and add to the allEquipments vector
  // allEquipments.push_back(...));
  // allEquipments.push_back(...);
  // Add more equipment please...
  ifstream file(filename);
  if (file.is_open()) {
    string line;
    while (getline(file, line)) {
      stringstream ss(line);
      string type, name, rarity, sPrice;

      // Read data from the line
      getline(ss, type, ',');
      getline(ss, name, ',');
      getline(ss, rarity, ',');
      getline(ss, sPrice, ',');

      // Parse price
      int price = stoi(sPrice);

      // Create equipment based on type
      if (type == "ContinuousEquipment") {
        string statType, sModifier;
        getline(ss, statType, ',');
        getline(ss, sModifier);
        float modifier = stof(sModifier);
        allEquipments.push_back(
            new ContinuousEquipment(name, rarity, price, statType, modifier));
      } else if (type == "AfterBattleEquipment") {
        string stat, sModifier;
        getline(ss, stat, ',');
        getline(ss, sModifier);
        float modifier = stof(sModifier);
        // Assuming AfterBattleEquipment has a similar constructor
        //allEquipments.push_back(
            //new AfterBattleEquipment(name, rarity, price, stat, modifier));
      } else if (type == "ConditionalEquipment") {  // Fixed typo
        string condition, reward;
        getline(ss, condition, ',');
        getline(ss, reward);
        // Assuming ConditionalEquipment has a similar constructor
        //allEquipments.push_back(
            //new ConditionialEquipment(name, rarity, price, condition, reward));
      } else {
        cerr << "Unknown equipment type: " << type << endl;
      }
    }
    file.close();
  } else {
    cerr << "Error opening file: " << filename << endl;
  }  // Explicit return
}

//Random equipment for shop encounter
std::vector<Equipment*> EquipmentList::getRandomEquipmentList(int count) {
    std::vector<Equipment*> randomEquipments;
    std::vector<Equipment*> tempEquipments = allEquipments;  // Temporary copy

    std::srand(std::time(0));

    for (int i = 0; i < count && !tempEquipments.empty(); i++) {
        int randomIndex = std::rand() % tempEquipments.size();
        randomEquipments.push_back(tempEquipments[randomIndex]);
        tempEquipments.erase(tempEquipments.begin() + randomIndex);
    }

    return randomEquipments;
}