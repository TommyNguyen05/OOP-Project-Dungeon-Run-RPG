#ifndef CONTINUOUSEQUIPMENT_H
#define CONTINUOUSEQUIPMENT_H

#include "Equipment.h"
#include "Character.h"
#include <string>
#include <iostream>

using namespace std;

class ContinuousEquipment : public Equipment
{
protected:
    string statType;
    float modifier;
public:
    ContinuousEquipment();
    ContinuousEquipment(string name, string rarity, int price,string statType, float modifier);
    void displayEquipment();

    void setStatType(string statType);
    void setModifier(float modifier);

    string getStatType();
    float getModifier();
    
    string getStatType() const;
    float getModifier() const;
    ~ContinuousEquipment() = default;

    void modifyPlayerStat(Character* player);

    void revertPlayerStat(Character* player);
    
};

#endif
