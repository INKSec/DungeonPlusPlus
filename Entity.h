#ifndef DUNGEONPLUSPLUS_ENTITY_H
#define DUNGEONPLUSPLUS_ENTITY_H

#include <string>
#include <memory>

namespace game {

    class Entity {
    public:
        virtual ~Entity() = default;
        using entityPtr = std::shared_ptr<Entity>;
        virtual void attack(const entityPtr &opponent);
        virtual std::string getName() const = 0;
        virtual std::string getSprite() const = 0;
        virtual int getCurrentHealth() const = 0;
        virtual int getMaxHealth() const = 0;
        virtual int getAttackPower() const = 0;
        virtual void setCurrentHealth(const int &_health) = 0;
        virtual void setAttackPower(const int &_attackPower) = 0;
    protected:
        Entity() = default;
    private:
        std::string name;
        std::string sprite;
        int currentHealth;
        int maxHealth;
        int attackPower;
    };

}

#endif //DUNGEONPLUSPLUS_ENTITY_H
