#include "Enemy.h"

//empty constructor because we are not using Enemy as objects
Enemy::Enemy() : Character("Empty Child Enemy",2,2,2,2,2)
{
    difficulty = 2;
}
Enemy::Enemy(string name, int currentHealth, int maxHealth, int strength, int speed, int damage, int difficulty) 
: Character(name, maxHealth, currentHealth, strength, speed, damage), difficulty(difficulty)
{

}

int Enemy::getDifficulty()
{
    return difficulty;
}
void Enemy::setDifficulty()
{
   //Empty because it will change for Mob and Boss
}


//damage calculator
void Enemy::setDamage(int damage)
{
    this -> damage = damage + 10 * strength;
}


//displays stats
void Enemy::displayStats(){
    cout << "\n";
    cout << "                   Name: " << getName() << " (Level" << getDifficulty() << ")" << endl;
    cout << "                   HP: " << getCurrentHealth() << "/ " << getMaxHealth() << endl; 
} 


//Enemy way of attacking
void Enemy::enemyAttack(Character* opponent)
{
  cout << name << " attacks you! " << endl;
  opponent->takeDamage(damage);
}