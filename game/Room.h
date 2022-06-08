#ifndef DUNGEONPLUSPLUS_ROOM_H
#define DUNGEONPLUSPLUS_ROOM_H

#include "Enemy.h"

namespace game {

    class Room {
    public:
        Room() = delete;
        explicit Room(std::string pathToBackground, std::string _name);
        std::string getBackground() const;
        std::string getName() const;
        std::shared_ptr<Enemy> getEnemy() const;
        void setEnemy(std::shared_ptr<Enemy> _enemy);
    private:
        const std::string background;
        const std::string name;
        std::shared_ptr<Enemy> enemy {nullptr};
    };

}

#endif //DUNGEONPLUSPLUS_ROOM_H
