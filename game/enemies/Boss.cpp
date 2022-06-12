#include "Boss.h"

game::Boss::Boss() : Enemy() {
    name = "Boss";
    sprite = "../images/boss.png";
    currentHealth = 50;
    maxHealth = 50;
    attackPower = 12;
    accuracy = 80;
    posX = 0.5;
}
