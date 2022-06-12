#ifndef DUNGEONPLUSPLUS_WEAPON_H
#define DUNGEONPLUSPLUS_WEAPON_H

#include "Item.h"
#include <memory>

namespace game {

    class Weapon : public Item {
    public:
        Weapon(std::string _name, const int &_damage, const int &_accuracy);
        int getDamageOutput() const;
        int getAccuracy() const;
        Weapon operator+(const game::Weapon &w);
    private:
        int damageOutput;
        int accuracy;
    };

}

#endif //DUNGEONPLUSPLUS_WEAPON_H
