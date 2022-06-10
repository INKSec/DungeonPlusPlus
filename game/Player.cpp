#include "Player.h"

game::Player::Player() {
    name = "Player";
    sprite = "../images/player.png";
    maxHealth = 100;
    currentHealth = 100;
    attackPower = 1;
    accuracy = 50;
    posXIdle = 0.1;
    posXAttack =0.3;
    posXDamage = 0.05;
    posX = posXIdle;
}

void game::Player::equipWeapon(const std::shared_ptr<Weapon> &_weapon) {
    weapon = _weapon;
    setAttackPower(weapon->getDamageOutput());
    setAccuracy(weapon->getAccuracy());
}

std::shared_ptr<game::Weapon> game::Player::getEquippedWeapon() const {
    return weapon;
}


