#ifndef DUNGEONPLUSPLUS_GAMESCENE_H
#define DUNGEONPLUSPLUS_GAMESCENE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "MainMenu.h"
#include "Button.h"
#include "Room.h"
#include "DungeonLayout.h"
#include "DungeonMap.h"
#include "Player.h"
#include "Weapon.h"
#include "ItemFactory.h"
#include "Inventory.h"

namespace gui {

    class GameScene {
    public:
        explicit GameScene(sf::RenderWindow &_window, std::shared_ptr<game::Player> &_player, gui::Inventory &_inventory, game::DungeonLayout &_dungeonLayout, gui::DungeonMap &_dungeonMap);
        void display(const std::shared_ptr<game::Room> &currentRoom);
        void setBackground(const std::string &path);
        void setHUD(const std::string &path);
        std::vector<Button> getButtons() const;
        std::shared_ptr<game::Enemy> getEnemy() const;
        void setEnemy(const std::shared_ptr<game::Enemy> );

    private:
        void explorationView();
        void combatView();
        void drawPlayer();
        void drawEnemy();
        void drawHealthBar();
        void drawAttackCall();
        std::shared_ptr<game::Player> &player;
        std::shared_ptr<game::Enemy> enemy;
        game::DungeonLayout &dungeonLayout;
        gui::DungeonMap &dungeonMap;
        gui::Inventory &inventory;
        std::shared_ptr<game::Room> activeRoom;
        std::vector<Button> buttons;
        sf::Texture background;
        sf::Texture hud;
        sf::Font font;
        sf::RenderWindow &window;
        bool mapIsOpen {false};
        bool inventoryIsOpen {false};
    };

}

#endif //DUNGEONPLUSPLUS_GAMESCENE_H
