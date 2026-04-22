#include "ContinuousEquipment.h"
#include <string>
#include <iostream>
using namespace std;

//Default Initializer
ContinuousEquipment::ContinuousEquipment():Equipment(){
    statType = "";
    modifier = 0;
}
// Initializer with variables
ContinuousEquipment::ContinuousEquipment(string name, string rarity, int price,string statType, float modifier):Equipment(name,rarity,price){
    this->statType = statType;
    this->modifier = modifier;
}

//Getters and Setters
string ContinuousEquipment::getStatType(){
    return statType;
}

float ContinuousEquipment::getModifier(){
    return modifier;
}

void ContinuousEquipment::setStatType(string statType){
    this->statType = statType;
}
void ContinuousEquipment::setModifier(float modifier){
    this->modifier = modifier;
}

//Displaying equipments
void ContinuousEquipment::displayEquipment(){
    cout << "Equipment:" << getName() << " , Rarity: " << getRarity()
    << ", Price: "<< getPrice()<<  ", Increases " << statType << " by " << modifier <<endl;
}

//Modifiying players stats with equipment
void ContinuousEquipment::modifyPlayerStat(Character* player) {
    cout << "Attempt to modify player's stat" << endl;
    if (getStatType() == " Health") {
        player->setNewMaxHealth(player->getMaxHealth() * getModifier());  
        cout << "Health has increased!" << endl;
    } else if (getStatType() == " Strength") {
        player->setNewStrength(player->getStrength() + (getModifier()));  
        cout << "Strength has increased!" << endl;
    } else if (getStatType() == " Speed") {
        player->setNewSpeed(player->getSpeed() * getModifier());  
        cout << "Speed has increased!" << endl;
    // } else {
        // cout << "Stat type: " << getStatType() << endl;
        // cout << "NO STAT CHANGE" << endl;
    }
}
//Reverting players stats with equipment
void ContinuousEquipment::revertPlayerStat(Character* player) {
    // cout << "Attempt to revert player's stat" << endl;
    if (getStatType() == " Health") {
        //(inverse of multiplication)
        player->setNewMaxHealth(player->getMaxHealth() / getModifier());
        // cout << "Health has reverted back!" << endl;
    } else if (getStatType() == " Strength") {
        player->setNewStrength(player->getStrength() - (getModifier()));
        // cout << "Strength has reverted back!" << endl;
    } else if (getStatType() == " Speed") {
        //(inverse of multiplication)
        player->setNewSpeed(player->getSpeed() / getModifier());
        // cout << "Speed has reverted back!" << endl;
    // } else {
        // cout << "Stat type: " << getStatType() << endl;
        // cout << "NO STAT CHANGE" << endl;
    }
}


