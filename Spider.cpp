#include "Spider.h"

std::string game::Spider::getName() const {
    return name;
}

std::string game::Spider::getSprite() const {
    return sprite;
}

int game::Spider::getHealth() const {
    return health;
}

int game::Spider::getAttackPower() const {
    return attackPower;
}

void game::Spider::setHealth(const int &_health) {
    health = _health;
}

void game::Spider::setAttackPower(const int &_attackPower) {
    attackPower = _attackPower;
}