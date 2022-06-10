#include "Entity.h"
#include <iostream>

void game::Entity::attack(const game::Entity::entityPtr &opponent) {
    this->setPosX(getPosXAttack());
    const int random {rand()};
    if(random % 100 < accuracy) {
        opponent->setCurrentHealth(opponent->getCurrentHealth() - getAttackPower());
        std::cout << "Hit! Target has " << opponent->getCurrentHealth() << " HP left." << std::endl;
    } else {
        std::cout << "Missed!" << std::endl;
    }
}

float game::Entity::getPosX() const {
    return posX;
}

float game::Entity::getPosXIdle() const {
    return posXIdle;
}

float game::Entity::getPosXAttack() const {
    return posXAttack;
}

float game::Entity::getPosXDamaged() const {
    return posXDamage;
}

void game::Entity::setPosX(float _posX) {
    posX = _posX;
}

std::string game::Entity::getName() const {
    return name;
}

std::string game::Entity::getSprite() const {
    return sprite;
}

int game::Entity::getCurrentHealth() const {
    return currentHealth;
}

int game::Entity::getMaxHealth() const {
    return maxHealth;
}

int game::Entity::getAttackPower() const {
    return attackPower;
}

int game::Entity::getAccuracy() const {
    return accuracy;
}

void game::Entity::setAttackPower(const int &_attackPower) {
    attackPower = _attackPower;
}

void game::Entity::setAccuracy(const int &_accuracy) {
    accuracy = _accuracy;
}

void game::Entity::setCurrentHealth(const int &_health) {
    currentHealth = _health;
    if(currentHealth < 0) currentHealth = 0;
}