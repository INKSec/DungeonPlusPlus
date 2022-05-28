#include <iostream>
#include <SFML/Graphics.hpp>
#include "MainMenu.h"
using namespace std;


void splashScreenCallback();
void menuButton1();
void menuButton2();

int main() {
    //create the splash screen
    sf::RenderWindow window;
    sfm::Menu splash;
    splash.setTimeout(sf::seconds(2.2), splashScreenCallback);
    splash.setBackground("../images/Splash.png");

    //create the main menu
    sfm::Menu mainmenu;
    sfm::MenuOption opt("Start");
    mainmenu.addOption(opt);
    sfm::MenuOption opt2("Optionen");
    mainmenu.addOption(opt2);
    sfm::MenuOption opt3("Ende");
    mainmenu.addOption(opt3);
    mainmenu.setLayout(sfm::MenuLayout::VerticleCentered);
    mainmenu.setBackground("../images/wald.jpg");
    sf::Font font;
    sf::Text text;
    font.loadFromFile("../fonts/Arial.ttf");
    text.setFont(font);
    mainmenu.setTemplateText(text);

    //now create the window and display the menus
    window.create(sf::VideoMode(800, 600), "DungeonPluPlus!");
    splash.display(window);
    mainmenu.display(window);

    return 0;
}
void splashScreenCallback() {
    cout << "Hat geklappt\n" << endl;
}

void menuButton1() {
    cout << "Hat geklappt\n" << endl;
}

void menuButton2() {
    cout << "Hat geklappt\n" << endl;
}