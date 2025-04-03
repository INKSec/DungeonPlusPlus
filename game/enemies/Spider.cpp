#include "Spider.h"

game::Spider::Spider() : Enemy() {
    name = "Spider";
    sprite = "../images/spider.png";
    currentHealth = 9;
    maxHealth = 9;
    attackPower = 5;
    accuracy = 90;
    posX = 0.5;
}
