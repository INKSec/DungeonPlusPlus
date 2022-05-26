#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
using namespace std;


void splashScreenCallback();
void menuButton1();
void menuButton2();

int main() {
    //create the splash screen
    sfm::Menu splash;
    splash.setTimeout(sf::seconds(2.2), splashScreenCallback);
    splash.setBackground("D:/DungeonPlusPlus/images/Splash.png");

    //create the main menu
    sfm::Menu mainmenu;
    sfm::MenuOption opt("Start", menuButton1);
    mainmenu.addOption(opt);
    sfm::MenuOption opt2("Optionen", menuButton2);
    mainmenu.addOption(opt2);
    sfm::MenuOption opt3("Ende", menuButton2);
    mainmenu.addOption(opt3);
    mainmenu.setLayout(sfm::MenuLayout::VerticleCentered);
    mainmenu.setBackground("D:/DungeonPlusPlus/images/wald.jpg");
    sf::Font font;
    sf::Text text;
    font.loadFromFile("D:/DungeonPlusPlus/fonts/Arial.ttf");
    text.setFont(font);
    mainmenu.setTemplateText(text);

    //now create the window and display the menus
    sf::RenderWindow window;
    window.create(sf::VideoMode(800, 600), "DungeonPluPlus!");
    splash.display(window);
    mainmenu.display(window);
    window.close();




    return 0;
}
void splashScreenCallback() {
    cout << "Hat geklappt\n";
}

void menuButton1() {
    cout << "Hat geklappt\n";
}

void menuButton2() {
    cout << "Hat geklappt\n";
}