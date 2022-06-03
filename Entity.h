#ifndef DUNGEONPLUSPLUS_ENTITY_H
#define DUNGEONPLUSPLUS_ENTITY_H

#include <string>
#include <memory>

namespace game {

    class Entity {
    public:
        Entity() = delete;
        virtual ~Entity() = default;
        using entityPtr = std::shared_ptr<Entity>;
        virtual void attack(entityPtr &opponent);
        virtual std::string getName() const;
        virtual std::string getSprite() const;
        virtual int getHealth() const;
        virtual int getAttackPower() const;
        virtual void setHealth(const int &_health);
        virtual void setAttackPower(const int &_attackPower);
    private:
        std::string name;
        std::string sprite;
        int health;
        int attackPower;
    };

}

#endif //DUNGEONPLUSPLUS_ENTITY_H
