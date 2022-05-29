#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameScene.h"
using namespace std;


void splashScreenCallback();
void menuButton2();

int main() {

    //create the splash screen
    sf::RenderWindow window;
    sfm::Menu splash;
    splash.setTimeout(sf::seconds(2), splashScreenCallback);
    splash.setBackground("../images/Splash.png");

    //create the main menu
    sfm::Menu mainmenu;
    game::GameScene testscene;
    game::Room startingRoom{"../images/dungeon_entrance.png", "Entrance"};
    sfm::MenuOption opt("Start", [&mainmenu, &testscene, &window, &startingRoom](){mainmenu.setFinished(true); testscene.setFinished(false); testscene.display(window, startingRoom);});
    mainmenu.addOption(opt);
    sfm::MenuOption opt2("Optionen", menuButton2);
    mainmenu.addOption(opt2);
    sfm::MenuOption opt3("Beenden", [&mainmenu](){mainmenu.setFinished(true);});
    mainmenu.addOption(opt3);
    mainmenu.setLayout(sfm::MenuLayout::VerticleCentered);
    mainmenu.setBackground("../images/wald.jpg");
    sf::Font font;
    sf::Text text;
    font.loadFromFile("../fonts/Arial.ttf");
    text.setFont(font);
    mainmenu.setTemplateText(text);

    //now create the window and display the menus
    window.create(sf::VideoMode(1200, 800), "DungeonPlusPlus!");
    splash.display(window);
    mainmenu.display(window);

    return 0;
}

void splashScreenCallback() {
    cout << "Hat geklappt\n" << endl;
}

void menuButton2() {
    cout << "Hat geklappt\n" << endl;
}