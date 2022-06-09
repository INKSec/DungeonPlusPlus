#ifndef DUNGEONPLUSPLUS_SPIDER_H
#define DUNGEONPLUSPLUS_SPIDER_H

#include "Enemy.h"

namespace game {

    class Spider : public Enemy{
    public:
        explicit Spider();
        std::string getName() const override;
        std::string getSprite() const override;
        int getCurrentHealth() const override;
        int getMaxHealth() const override;
        int getAttackPower() const override;
        void setCurrentHealth(const int &_health) override;
        void setAttackPower(const int &_attackPower) override;

    private:
        std::string name {"Spider"};
        std::string sprite {"../images/spider.png"};
        int currentHealth {20};
        int maxHealth {20};
        int attackPower {5};
        float PosX{0.5};
    };

}

#endif //DUNGEONPLUSPLUS_SPIDER_H
