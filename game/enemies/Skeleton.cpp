#include "Skeleton.h"

game::Skeleton::Skeleton() : Enemy() {
    name = "Skeleton";
    sprite = "../images/skeleton.png";
    currentHealth = 15;
    maxHealth = 15;
    attackPower = 8;
    accuracy = 65;
    posX = 0.5;
}
