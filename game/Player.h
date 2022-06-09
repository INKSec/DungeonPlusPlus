#ifndef DUNGEONPLUSPLUS_PLAYER_H
#define DUNGEONPLUSPLUS_PLAYER_H

#include "Entity.h"
#include "Weapon.h"
namespace game {

    class Player : public Entity {
    public:
        explicit Player();
        void equipWeapon(const std::shared_ptr<Weapon> &_weapon);
        std::string getName() const override;
        std::string getSprite() const override;
        int getCurrentHealth() const override;
        int getMaxHealth() const override;
        int getAttackPower() const override;
        void setCurrentHealth(const int &_health) override;
        void setAttackPower(const int &_attackPower) override;

    private:
        std::string name {"Player"};
        std::string sprite {"../images/player.png"};
        int currentHealth {100};
        int maxHealth {100};
        int attackPower {8};



        std::shared_ptr<Weapon> weapon;};

}

#endif //DUNGEONPLUSPLUS_PLAYER_H




