//.cpp file for Player where we inpute the functions

#include "Player.h"

// default constructor
Player::Player() : Character("inherit to pplayer", 1, 1, 1, 1, 1) {
  coin = 0;
  level = 0;
  currentExpPoint = 0;
  maxExpPoint = 0;
  weapon = nullptr;
}

// constructor for player
Player::Player(string name, int currentHealth, int maxHealth, int strength,
               int speed, int damage, int level, int coin, int currentExpPoint,
               int maxExpPoint)
    : Character(name, currentHealth, maxHealth, strength, speed, damage) {
  this->level = level;
  this->coin = coin;
  this->currentExpPoint = currentExpPoint;
  this->maxExpPoint = maxExpPoint;
}


// virtuals from Character

// virtual maxHealth function
void Player::setMaxHealth(int maxHealth) 
{
  this->maxHealth = maxHealth + 1000 * level;
}

// virtual strength function

void Player::setStrength(int strength) 
{
  this->strength = strength + 10 * level;
}

// virtual speed function
void Player::setSpeed(int speed)
{
  this->speed = speed + 10 * level; 
}

void Player::setDamage(int damage) 
{ 
  this->damage = damage + 10 * strength; 
}

// getters and setters:
//  currentWeapon
ContinuousEquipment* Player::getWeapon() 
{ 
  return weapon; 
}

// level
int Player::getLevel() 
{ 
  return level; 
}
void Player::setLevel(int level) 
{ 
  this->level = level; 
}

// coin
int Player::getCoin() 
{ 
  return coin; 
}

void Player::setCoin(int coin) 
{ 
  this->coin = coin; 
}

// This is gaining coin after beating enemy
void Player::gainCoin() 
{
  // random coin increase from 100 - 1000
  int lootCoin = (rand() % 900 + 101);

  // player gained lootCoin amount
  cout << getName() << " picked up " << lootCoin << " coins" << endl;
  coin += lootCoin;
}

// currentExpPoint
int Player::getCurrentExpPoint() 
{
  return currentExpPoint; 
}

// set exp point
void Player::setCurrentExpPoint(int currentExpPoint) 
{
  this->currentExpPoint = currentExpPoint;
}

// maxExpPoint
int Player::getMaxExpPoint() 
{ 
  return maxExpPoint; 
}

// setter for maxExpPoint
void Player::setMaxExpPoint(int maxExpPoint) 
{
  this->maxExpPoint = maxExpPoint * level;
}

void Player::levelUp() 
{
    currentExpPoint += 550;

  if (maxExpPoint < currentExpPoint) {
    this->currentExpPoint -= maxExpPoint;
    level++;
    cout << "\n"<< getName() << " level increased by 1" << endl;
    cout << getName() << " is now level: " << level << endl;
    this->maxExpPoint = maxExpPoint * level;

    //increase stats according to leveling up
    strength += 10;
    speed += 10;
    maxHealth += 100;
    maxExpPoint += 500;
  }



}

// conditions for equipping weapon
// Tommy - adjust something in equipWeapn
void Player::equipWeapon(ContinuousEquipment* newWeapon, Character* player) 
{
  // Check if the player is already equipped with a weapon
  if (this->weapon != nullptr) {
    // Player already has a weapon equipped, revert the stats first
    // cout << "Player is already equipped with: " << this->weapon->getName()
    //      << ". Reverting stats..." << endl;
    this->weapon->revertPlayerStat(player);  // Revert the stats of the currently equipped weapon
  }

  // Equip the new weapon
  this->weapon = newWeapon;
  newWeapon->modifyPlayerStat(player);  
  cout <<name << " has now equipped: " << newWeapon->getName() << endl;
}

//displays stats of player
void Player::displayStats() {
  cout << "EXP: " << getCurrentExpPoint() << "/ " <<getMaxExpPoint() << endl;
  cout << "Name: " << getName() << "(Level " << getLevel() << ")" << endl;
  cout << "HP: Current: " << getCurrentHealth() << "/ Max: " << getMaxHealth()
       << endl;
  cout << "Stats: " << endl;
  cout << "Strength: " << getStrength() << "/ Speed: " << getSpeed() << endl;
}

//Damage calculator
void Player::doDamage(Character* opponent)
{
  cout << getName() << " swing their wand" << " at ";
  cout << opponent-> getName() << "!\n";
  opponent->takeDamage(damage);
}
