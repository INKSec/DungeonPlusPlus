#ifndef DUNGEONPLUSPLUS_SPIDER_H
#define DUNGEONPLUSPLUS_SPIDER_H

#include "Enemy.h"

namespace game {

    class Spider : public Enemy{
    public:
        Spider() = default;
        std::string getName() const override;
        std::string getSprite() const override;
        int getHealth() const override;
        int getAttackPower() const override;
        void setHealth(const int &_health) override;
        void setAttackPower(const int &_attackPower) override;
    private:
        std::string name {"Spider"};
        std::string sprite {"../images/spider.png"};
        int health {20};
        int attackPower {5};
    };

}

#endif //DUNGEONPLUSPLUS_SPIDER_H
