#ifndef EQUIPMENTLIST_H
#define EQUIPMENTLIST_H
#include "Player.h"
#include "Equipment.h"
#include <vector>

class EquipmentList {
public:
    static EquipmentList* getEquipmentList(); // Get the master list of Equipments
    static EquipmentList* getEquipmentList(const string& filename); // Get the master list of Equipments

    // Function to get random equipment
    std::vector<Equipment*> getRandomEquipmentList(int count); // Get the generated list of random Equipments

private:
    EquipmentList();  // Constructor is private since there's only one Master list of Equipments
    EquipmentList(const string& filename);  // Constructor is private since there's only one Master list of Equipments
    static EquipmentList* equipmentList; //stores a pointer to only one Master list of Equipments    
    // List of all predefined equipment
    std::vector<Equipment*> allEquipments;

    // For adding predefined weapons
    void loadEquipments();
    void loadEquipments(const string& filename);
};

#endif 
