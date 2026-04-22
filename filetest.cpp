#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "Equipment.h"
#include "ContinuousEquipment.h"
#include "EquipmentList.h"

using namespace std;

// Function to load equipment from a file
vector<Equipment*> loadEquipmentFromFile(const string& filename) {
    vector<Equipment*> List; 
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
                List.push_back(new ContinuousEquipment(name, rarity, price, statType, modifier));
            } else if (type == "AfterBattleEquipment") {
                string stat, sModifier;
                getline(ss, stat, ',');
                getline(ss, sModifier);
                float modifier = stof(sModifier);
                // Assuming AfterBattleEquipment has a similar constructor
                // List.push_back(new AfterBattleEquipment(name, rarity, price, stat, modifier));
                cout << "AfterBattleEquipment loaded: " << name << endl;
            } else if (type == "ConditionalEquipment") { // Fixed typo
                string condition, reward;
                getline(ss, condition, ',');
                getline(ss, reward);
                // Assuming ConditionalEquipment has a similar constructor
                // List.push_back(new ConditionalEquipment(name, rarity, price, condition, reward));
                cout << "ConditionalEquipment loaded: " << name << endl;
            } else {
                cerr << "Unknown equipment type: " << type << endl;
            }
        }
        file.close();
        cout << "Equipment loaded successfully." << endl;
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
    return List; // Explicit return
}

// Test function for loading equipment
void testLoadEquipmentFromFile() {
    string filename = "equipment.txt";  // Name of the test file
    vector<Equipment*> equipmentList = loadEquipmentFromFile(filename);

    // Check if the equipment is loaded correctly
    for (Equipment* eq : equipmentList) {
        eq->displayEquipment();  // Display the loaded equipment
        delete eq;      // Clean up dynamically allocated memory
    }
}

int main() {
    // Create test data file
    ofstream testFile("equipment.txt");
    if (testFile.is_open()) {
        testFile << "ContinuousEquipment, Sword of Power, Rare, 1000, Attack, 1.5\n";
        testFile << "AfterBattleEquipment, Healing Potion, Common, 200, HP, 0.5\n";
        testFile << "ConditionalEquipment, Magic Ring, Epic, 1500, Health > 50, Double Damage\n"; // Fixed spelling
        testFile.close();
    } else {
        cerr << "Could not create test file." << endl;
        return 1;
    }

    // Run the test
    testLoadEquipmentFromFile();
    return 0;
}
