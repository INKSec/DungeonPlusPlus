#include "Entity.h"

void game::Entity::attack(game::Entity::entityPtr &opponent) {
    opponent->setHealth(opponent->getHealth() - attackPower);
}