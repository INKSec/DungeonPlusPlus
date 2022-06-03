#ifndef DUNGEONPLUSPLUS_DUNGEONMAP_H
#define DUNGEONPLUSPLUS_DUNGEONMAP_H

#include <SFML/Graphics.hpp>
#include "DungeonLayout.h"
#include "Button.h"

namespace gui {

    class DungeonMap {
    public:
        explicit DungeonMap(sf::RenderWindow &_window, const game::DungeonLayout::roomMap &_dungeonMap);
        void draw(const int &currentPosition);
    private:
        const game::DungeonLayout::roomMap &dungeonMap;
        sf::RenderWindow &window;
        float mapCenterX {0};
        float mapCenterY {0};
        enum class Axis {xAxis, yAxis};
        template<Axis axis>
        float calcPosition(const int &relativePosition) const;
    };

}

#endif //DUNGEONPLUSPLUS_DUNGEONMAP_H
