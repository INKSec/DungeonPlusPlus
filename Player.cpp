#include "Player.h"

void game::Player::equipWeapon(const std::shared_ptr<Weapon> &_weapon) {
    weapon = _weapon;
    setAttackPower(weapon->getDamageOutput());
}

std::string game::Player::getName() const {
    return name;
}

std::string game::Player::getSprite() const {
    return sprite;
}

int game::Player::getCurrentHealth() const {
    return currentHealth;
}

int game::Player::getMaxHealth() const {
    return maxHealth;
}

int game::Player::getAttackPower() const {
    return attackPower;
}

void game::Player::setCurrentHealth(const int &_health) {
    currentHealth = _health;
    if(currentHealth < 0) currentHealth = 0;
}

void game::Player::setAttackPower(const int &_attackPower) {
    attackPower = _attackPower;
}

void game::Player::setPosX(const float &x) {
    PosX=  x;
}

float game::Player::getPosX() const {
    return PosX;
}
