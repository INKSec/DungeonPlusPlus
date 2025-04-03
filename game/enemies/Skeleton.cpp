#include "Skeleton.h"

game::Skeleton::Skeleton() : Enemy() {
    name = "Skeleton";
    sprite = "../images/skeleton.png";
    currentHealth = 11;
    maxHealth = 11;
    attackPower = 8;
    accuracy = 65;
    posX = 0.5;
}
