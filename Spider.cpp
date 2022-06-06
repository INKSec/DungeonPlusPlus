#include "Spider.h"

std::string game::Spider::getName() const {
    return name;
}

std::string game::Spider::getSprite() const {
    return sprite;
}

int game::Spider::getCurrentHealth() const {
    return currentHealth;
}

int game::Spider::getMaxHealth() const {
    return maxHealth;
}

int game::Spider::getAttackPower() const {
    return attackPower;
}

void game::Spider::setCurrentHealth(const int &_health) {
    currentHealth = _health;
    if(currentHealth < 0) currentHealth = 0;
}

void game::Spider::setAttackPower(const int &_attackPower) {
    attackPower = _attackPower;
}

float game::Spider::getPosX() const {
    return 0;
}

void game::Spider::setPosX(const float &) {

}
