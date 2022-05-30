#ifndef DUNGEONPLUSPLUS_GAMESCENE_H
#define DUNGEONPLUSPLUS_GAMESCENE_H

#include <SFML/Graphics.hpp>
#include <memory>
#include "MainMenu.h"
#include "Button.h"
#include "Room.h"
#include "DungeonLayout.h"

namespace game {

    class GameScene {
    public:
        explicit GameScene(DungeonLayout &_dungeonLayout);
        void display(sf::RenderWindow &window, const std::shared_ptr<Room> &room);
        void explorationView(sf::RenderWindow &window);
        void combatView();
        void setBackground(const std::string &path);
        void setHUD(const std::string &path);
        std::vector<gui::Button> getButtons() const;
    private:
        DungeonLayout& dungeonLayout;
        std::vector<gui::Button> buttons;
        sf::Texture background;
        sf::Texture hud;
        sf::Font font;
        std::shared_ptr<Room> activeRoom;
    };

}


#endif //DUNGEONPLUSPLUS_GAMESCENE_H
