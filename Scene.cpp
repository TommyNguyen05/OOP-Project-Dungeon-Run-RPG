#include"Scene.h"


//Constructor
Scene::Scene() : stepNum(){}
Scene::Scene(int stepNum) : stepNum(stepNum) {}

//Getter and Setters
int Scene::getStepNum(){
    return stepNum;
}

void Scene::setStepNum(int stepNumber){
    stepNum = stepNumber;
}