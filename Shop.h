#ifndef SHOP_H
#define SHOP_H
#include"Player.h"
#include"EquipmentList.h"
#include "ContinuousEquipment.h"
#include"Equipment.h"
#include"Scene.h"
#include<vector>


class Shop : public Scene {
    private:
        std::vector<Equipment*> equipmentsForSale;
    public:
        Shop(int stepNum);
        void execute();
        void displayEquipments();
        void purchaseEquipment(Player* player);
        ~Shop();
};

#endif
