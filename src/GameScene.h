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
#include "EventWindow.h"

namespace gui {

    class Inventory;
    class EventWindow;

    class GameScene {
    public:
        explicit GameScene(sf::RenderWindow &_window, std::shared_ptr<game::Player> &_player,
                           gui::Inventory &_inventory, game::DungeonLayout &_dungeonLayout, gui::DungeonMap &_dungeonMap);
        void display(const std::shared_ptr<game::Room> &currentRoom);
        void setBackground(const std::string &path);
        void setHUD(const std::string &path);
        void setEnemy(const std::shared_ptr<game::Enemy> &_enemy);
        std::vector<Button> getButtons() const;
        std::shared_ptr<game::Enemy> getEnemy() const;
        game::DungeonLayout& getDungeonLayout() const;

    private:
        void explorationView();
        void combatView();
        void drawPlayer();
        void drawEnemy();
        void drawHealthBar();
        void drawAttackCall();
        std::shared_ptr<game::Player> &player;
        std::shared_ptr<game::Enemy> enemy;
        std::shared_ptr<gui::EventWindow> event;
        game::DungeonLayout &dungeonLayout;
        gui::DungeonMap &dungeonMap;
        gui::Inventory &inventory;
        std::vector<Button> buttons;
        sf::Texture background;
        sf::Texture hud;
        sf::Font font;
        sf::RenderWindow &window;
        bool mapIsOpen {false};
        bool inventoryIsOpen {false};
        bool eventIsOpen {false};
    };

}

#endif //DUNGEONPLUSPLUS_GAMESCENE_H
