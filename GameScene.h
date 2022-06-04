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

namespace gui {

    class GameScene {
    public:
        explicit GameScene(sf::RenderWindow &_window, std::shared_ptr<game::Player> &_player, game::DungeonLayout &_dungeonLayout, gui::DungeonMap &_dungeonMap);
        void display(const std::shared_ptr<game::Room> &currentRoom);
        void setBackground(const std::string &path);
        void setHUD(const std::string &path);
        std::vector<Button> getButtons() const;
    private:
        void explorationView();
        void combatView();
        void drawPlayer();
        void drawEnemy();
        void drawHealthBar();
        std::shared_ptr<game::Player> &player;
        game::DungeonLayout &dungeonLayout;
        gui::DungeonMap &dungeonMap;
        std::shared_ptr<game::Room> activeRoom;
        std::vector<Button> buttons;
        sf::Texture background;
        sf::Texture hud;
        sf::Font font;
        sf::RenderWindow &window;
        bool mapIsOpen {false};
    };

}

#endif //DUNGEONPLUSPLUS_GAMESCENE_H
