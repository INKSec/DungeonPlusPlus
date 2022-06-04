#ifndef DUNGEONPLUSPLUS_INVENTORY_H
#define DUNGEONPLUSPLUS_INVENTORY_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Button.h"

namespace gui {

    class Inventory {
    public:
        explicit Inventory(sf::RenderWindow &_window);
        void draw();
        void drawContextMenu(const Button &_button);
        void putItem(const std::shared_ptr<game::Item> &_item);
        std::vector<std::shared_ptr<game::Item>> getItems() const;
        std::vector<Button> getButtons() const;
    private:
        sf::RenderWindow &window;
        std::vector<std::shared_ptr<game::Item>> items;
        std::vector<Button> itemButtons;
    };
}

#endif //DUNGEONPLUSPLUS_INVENTORY_H
