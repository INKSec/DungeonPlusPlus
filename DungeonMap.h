#ifndef DUNGEONPLUSPLUS_DUNGEONMAP_H
#define DUNGEONPLUSPLUS_DUNGEONMAP_H

#include <SFML/Graphics.hpp>
#include "DungeonLayout.h"

namespace gui {

    class DungeonMap {
    public:
        explicit DungeonMap(sf::RenderWindow &_window, const game::DungeonLayout::roomMap &_dungeonMap);
        void draw();
    private:
        const game::DungeonLayout::roomMap &dungeonMap;
        sf::RenderWindow &window;
    };

}

#endif //DUNGEONPLUSPLUS_DUNGEONMAP_H
