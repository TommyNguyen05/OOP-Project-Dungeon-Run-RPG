#include "Equipment.h"
#include <iostream>

using namespace std;

//Default initializer
Equipment::Equipment(){
    name = "mario";
    rarity = "luigi";
    price = 0;
}

//Variabled initializer
Equipment::Equipment(string name, string rarity, int price){
    this->name = name;
    this->rarity = rarity;
    this->price = price;
}

//Displaying equipment
void Equipment::displayEquipment(){
    cout << "Equipment:" << name << " , Rarity: " << rarity
    << "Price: "<< price <<endl;
}

//Getters and Setters
string Equipment::getName() const{
     return name; 
     }

void Equipment::setName(string newName){ 
    name = newName; 
    }

string Equipment::getRarity() const{ 
    return rarity; 
    }

void Equipment::setRarity(string newRarity){ 
    rarity = newRarity; 
    }

int Equipment::getPrice() const{ 
    return price; 
    }

void Equipment::setPrice(int newPrice){ 
    price = newPrice; 
    }

