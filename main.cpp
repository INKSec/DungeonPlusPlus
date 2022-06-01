#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameScene.h"
#include "DungeonLayout.h"
#define GAME_TITLE "DungeonPlusPlus"
#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800
#define ROOM_COUNT 15

using namespace std;


void splashScreenCallback();
void menuButton2();

int main() {

    //create the splash screen
    sf::RenderWindow window;
    sfm::Menu splash;
    splash.setTimeout(sf::seconds(2), splashScreenCallback);
    splash.setBackground("../images/Splash.png");

    //create the dungeon rooms
    game::DungeonLayout dungeonLayout;
    game::GameScene gamescene{dungeonLayout};
    game::DungeonLayout::roomMap dungeonMap {dungeonLayout.generateDungeon(ROOM_COUNT)};

    // print room numbers and room count (just for testing - remove later)
    int actualRoomCount = 0;
    for(auto &pair : dungeonMap) {
        cout << pair.first << endl;
        actualRoomCount++;
    }
    cout << "Actual Room Count: " << actualRoomCount << endl;

    //create the main menu
    bool finished {false};
    sfm::Menu mainmenu;
    sfm::MenuOption opt("Start", [&mainmenu, &gamescene, &window, &dungeonLayout](){
        mainmenu.setFinished(true);
        gamescene.display(window, dungeonLayout.getCurrentRoom());
    });
    mainmenu.addOption(opt);
    sfm::MenuOption opt2("Optionen", menuButton2);
    mainmenu.addOption(opt2);
    sfm::MenuOption opt3("Beenden", [&mainmenu, &finished](){mainmenu.setFinished(true), finished = true;});
    mainmenu.addOption(opt3);
    mainmenu.setLayout(sfm::MenuLayout::VerticleCentered);
    mainmenu.setBackground("../images/wald.jpg");
    sf::Font font;
    sf::Text text;
    font.loadFromFile("../fonts/Arial.ttf");
    text.setFont(font);
    mainmenu.setTemplateText(text);


    //now create the window and display the menus
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE);
    splash.display(window);
    mainmenu.display(window);

    sf::Clock clock;
    while(!finished) {
        sf::Event e{};
        while(window.pollEvent(e)) {
            switch(e.type) {
                case sf::Event::Closed:
                    finished = true;
                    break;
                case sf::Event::MouseButtonReleased:
                    for(gui::Button &b : gamescene.getButtons()) {
                        if(b.getShape().getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)) {
                            b.clicked();
                            break;
                        }
                    }
                    break;
                case sf::Event::KeyPressed:
                    if(e.key.code == sf::Keyboard::Escape) {
                        finished = true;
                    }
                    break;
                default:
                    break;
            }
        }
        sf::sleep(sf::milliseconds(50));
    }

    return 0;
}

void splashScreenCallback() {
    cout << "Hat geklappt\n" << endl;
}

void menuButton2() {
    cout << "Hat geklappt\n" << endl;
}