#ifndef DUNGEONPLUSPLUS_ROOM_H
#define DUNGEONPLUSPLUS_ROOM_H

#include <SFML/Graphics.hpp>

namespace game {

    class Room {
    public:
        Room() = delete;
        explicit Room(std::string pathToBackground, std::string _name);
        std::string getBackground() const;
        std::string getName() const;
    private:
        const std::string background;
        const std::string name;
    };

}


#endif //DUNGEONPLUSPLUS_ROOM_H
