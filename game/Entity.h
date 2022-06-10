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
        virtual std::string getName() const;
        virtual std::string getSprite() const;
        virtual int getCurrentHealth() const;
        virtual int getMaxHealth() const;
        virtual int getAttackPower() const;
        virtual int getAccuracy() const;
        virtual float getPosX() const;
        virtual float getPosXIdle() const;
        virtual float getPosXAttack() const;
        virtual float getPosXDamaged() const;
        virtual void setCurrentHealth(const int &_health);
        virtual void setAttackPower(const int &_attackPower);
        virtual void setAccuracy(const int &_accuracy);
        virtual void setPosX(float _posX);

    protected:
        Entity() = default;
        float posX;
        float posXIdle;
        float posXAttack;
        float posXDamage;
        std::string name;
        std::string sprite;
        int currentHealth;
        int maxHealth;
        int attackPower;
        int accuracy;
    };

}

#endif //DUNGEONPLUSPLUS_ENTITY_H
