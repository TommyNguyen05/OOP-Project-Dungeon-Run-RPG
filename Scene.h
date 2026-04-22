#ifndef SCENE_H
#define SCENE_H
#include"EquipmentList.h"
#include"Equipment.h"
#include<iostream>

class Scene{
    private:
        int stepNum;
        Equipment* equipmentForSale;
    public:
        Scene();
        Scene(int stepNum);
        int getStepNum();
        void setStepNum(int stepNumber);
        virtual void execute() = 0;
        // Tommy - destructor added
        virtual ~Scene() = default;
};

#endif