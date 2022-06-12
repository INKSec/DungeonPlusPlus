#include <SFML/Graphics.hpp>
#include "MainMenu.h"
#include "GameScene.h"

#define GAME_TITLE "DungeonPlusPlus"
//#define WINDOW_WIDTH 1300
//#define WINDOW_HEIGHT 800
#define ROOM_COUNT 20

using namespace std;


void splashScreenCallback();


int main() {
    int WINDOW_WIDTH{1300};
    int WINDOW_HEIGHT{800};
    //create the splash screen
    sf::RenderWindow window;
    sfm::Menu splash;
    splash.setTimeout(sf::seconds(2), splashScreenCallback);
    splash.setBackground("../images/Splash.png");

    //create the main menu
    sfm::Menu::buildMenu(window, WINDOW_WIDTH, WINDOW_HEIGHT, ROOM_COUNT, GAME_TITLE, splash);

    return 0;
}

