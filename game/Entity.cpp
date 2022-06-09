#include "Entity.h"
#include <chrono>
#include <thread>

void game::Entity::attack(const game::Entity::entityPtr &opponent) {
    opponent->setCurrentHealth(opponent->getCurrentHealth() - getAttackPower());
    this->setPosX(getPosXAttack());







}

void game::Entity::setPosXIdle(const float &_posXidle) {
    posXIdle = _posXidle;
}

float game::Entity::getPosXIdle() const {
    return posXIdle;
}

float game::Entity::getPosX() const {
    return posX;
}

void game::Entity::setPosX(float _posX) {
    posX = _posX;
}

float game::Entity::getPosXAttack() const {
    return posXAttack;
}

void game::Entity::setPosXAttack(const float &_posXAttack) {
    posXAttack = _posXAttack;
}

float game::Entity::getPosXDamaged() const {
    return posXDamage;
}


