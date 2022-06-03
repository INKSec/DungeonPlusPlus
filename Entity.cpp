#include "Entity.h"

void game::Entity::attack(game::Entity::entityPtr &opponent) {
    opponent->setHealth(opponent->getHealth() - attackPower);
}

std::string game::Entity::getName() const {
    return name;
}

std::string game::Entity::getSprite() const {
    return sprite;
}

int game::Entity::getHealth() const {
    return health;
}

int game::Entity::getAttackPower() const {
    return attackPower;
}

void game::Entity::setHealth(const int &_health) {
    health = _health;
}

void game::Entity::setAttackPower(const int &_attackPower) {
    attackPower = _attackPower;
}