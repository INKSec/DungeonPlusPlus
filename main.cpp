#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameScene.h"
#include "DungeonLayout.h"
#include "DungeonMap.h"
#include "Player.h"

#define GAME_TITLE "DungeonPlusPlus"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define ROOM_COUNT 20

using namespace std;


void splashScreenCallback();


int main() {

    //create the splash screen
    sf::RenderWindow window;
    sfm::Menu splash;
    splash.setTimeout(sf::seconds(2), splashScreenCallback);
    splash.setBackground("../images/Splash.png");

    /*auto player {make_shared<game::Player>()};
    //create the dungeon rooms
    game::DungeonLayout dungeonLayout;
    game::DungeonLayout::roomMap rooms {dungeonLayout.generateDungeon(ROOM_COUNT)};
    gui::DungeonMap dungeonMap{window, rooms};
    gui::GameScene gamescene{window, player, dungeonLayout, dungeonMap};*/

    sfm::Menu::buildMenu(window, WINDOW_WIDTH, WINDOW_HEIGHT, ROOM_COUNT, GAME_TITLE, splash);
    //create the dungeon rooms


    //create the main menu


    return 0;
}

