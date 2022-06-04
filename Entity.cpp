#include "Entity.h"

void game::Entity::attack(const game::Entity::entityPtr &opponent) {
    opponent->setCurrentHealth(opponent->getCurrentHealth() - getAttackPower());
}