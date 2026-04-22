#ifndef EQUIPMENT_H
#define EQUIPMENT_H

#include <string>
using namespace std;

class Equipment {
private:
    string name;
    string rarity;
    int price;

public:

    // Constructor functions
    Equipment();
    Equipment(string name, string rarity, int price);
    

    // Getter functions
    string getName() const;
    string getRarity() const;
    int getPrice() const;

    // Setter functions
    void setName(string name);
    void setRarity(string rarity);
    void setPrice(int price);

    // Pure virtual function for displaying equipment details
    virtual void displayEquipment();
};

#endif
