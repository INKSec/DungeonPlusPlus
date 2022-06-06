#include "Entity.h"
#include <chrono>
#include <thread>

void game::Entity::attack(const game::Entity::entityPtr &opponent) {
    opponent->setCurrentHealth(opponent->getCurrentHealth() - getAttackPower());

    this->setPosX(0.3);

    //using namespace std::chrono_literals;
    //std::this_thread::sleep_for(1s);



}


