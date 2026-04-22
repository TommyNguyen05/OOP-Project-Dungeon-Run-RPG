#include "Character.h"

//empty constructor because we are not using character as objects
Character::Character()
{
  name = "Empty";
  maxHealth = 0;
  currentHealth = 0;
  strength = 0;
  speed = 0;
  damage = 0;

}
//dafault constructor
Character::Character(string name, int currentHealth, int maxHealth, int strength, int speed, int damage)
{
  this -> name = name;
  this -> maxHealth = maxHealth;
  this -> currentHealth = currentHealth;
  this -> strength = strength;
  this -> speed = speed;
  this -> damage = damage;
}

//getters and setters

//name
string Character::getName()
{ 
  return name; 
}
void Character::setName(string name)
{ 
  this -> name = name;
}

//current healtj
int Character::getCurrentHealth()
{ 
  return currentHealth; 
}
void Character::setCurrentHealth(int currentHealth)
{
  this -> currentHealth = currentHealth; 
}

//max health
int Character::getMaxHealth()
{ 
  return maxHealth; 
}
void Character::setMaxHealth(int maxHealth)
{ 
  this -> maxHealth = maxHealth;
}

//strength
int Character::getStrength()
{ 
  return strength; 
}
void Character::setStrength(int strength)
{ 
  this -> strength = strength;
}

//speed
int Character::getSpeed()
{ 
  return speed; 
}
void Character::setSpeed(int speed)
{ 
   this -> speed = speed;
}

//damage
int Character::getDamage()
{
  return damage;
}
void Character::setDamage(int damage)
{
  this -> damage = damage;
}

// Function to take damage
void Character::takeDamage(int damage)
{
  cout << endl << name << ":" << endl;
  cout << "current health: " << currentHealth << endl;
  currentHealth -= damage;

  if (currentHealth <= 0) 
  {

    cout << "Damage taken: " << damage << endl << endl;

    // Since health cannot be negative.
    currentHealth = 0;  
    cout << "" << name << endl;
    cout << "Health left: " << currentHealth << endl;
    
  }
  else 
  {
    cout << "Damage taken: " << damage << endl;
    cout << "Current health: " << currentHealth << endl;
  }

}

// Virtual function for attacking
void Character::attack(Character* opponent, int damage)
{
  opponent -> takeDamage(damage);
}

//function for displaying stats
void Character::displayStats(){
  cout << "Display entity's stats:" << endl;
} 

// Tommy added - 
void Character::setNewStrength(int strength){
   this->strength = strength;
}

void Character::setNewSpeed(int speed){
  this->speed = speed;
}

void Character::setNewMaxHealth(int health){
  this ->maxHealth = health;
  this ->currentHealth = health;
}

