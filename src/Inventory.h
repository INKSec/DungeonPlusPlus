#ifndef DUNGEONPLUSPLUS_INVENTORY_H
#define DUNGEONPLUSPLUS_INVENTORY_H

#include <vector>
#include <memory>
#include <SFML/Graphics.hpp>
#include "Item.h"
#include "Button.h"
#include "GameScene.h"

namespace gui {

    class GameScene;

    class Inventory {
    public:
        explicit Inventory(sf::RenderWindow &_window, std::shared_ptr<game::Player> &_player);
        void draw(GameScene &gameScene);
        void putItem(const std::shared_ptr<game::Item> &_item);
        std::vector<std::shared_ptr<game::Item>> getItems() const;
        std::vector<Button> getButtons() const;
    private:
        sf::RenderWindow &window;
        std::shared_ptr<game::Player> &player;
        std::vector<std::shared_ptr<game::Item>> items;
        std::vector<Button> itemButtons;
        std::vector<sf::Text> itemTexts;
        static std::string buildItemSubText(const std::shared_ptr<game::Item> &item) ;
    };
}

#endif //DUNGEONPLUSPLUS_INVENTORY_H
