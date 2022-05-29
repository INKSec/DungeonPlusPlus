#include "GameScene.h"
#include <iostream>


game::GameScene::GameScene() {
    font.loadFromFile("../fonts/Arial.ttf");
    setHUD("../images/hud.jpg");
}

// Diese Funktion setzt alle grafischen Elemente einer Spielszene zusammen und stellt sie dar
void game::GameScene::display(sf::RenderWindow &window, const Room &room) {
    sf::Sprite _hud;
    _hud.setTexture(hud);
    _hud.setPosition(0, window.getSize().y - _hud.getGlobalBounds().height);
    sf::Sprite bg;
    setBackground(room.getBackground());
    bg.setTexture(background);
    bg.setScale(window.getSize().x / (float)background.getSize().x,
                (window.getSize().y - _hud.getGlobalBounds().height) / (float)background.getSize().y);
    window.clear();
    window.draw(bg);
    window.draw(_hud);
    explorationView(window);
    window.display();

    sf::Clock clock;
    while(!finished) {
        sf::Event e{};
        while(window.pollEvent(e)) {
            switch(e.type) {
                case sf::Event::Closed:
                    finished = true;
                    break;
                case sf::Event::MouseButtonReleased:
                    for(gui::Button &b : buttons) {
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
}

void game::GameScene::explorationView(sf::RenderWindow &window) {
    const unsigned int Row1 {window.getSize().y - 200};
    const unsigned int Row2 {window.getSize().y - 100};
    const unsigned int Col1 {50};
    const unsigned int Col2 {300};
    buttons.emplace_back("Go North", Col1, Row1, 200, 50, font, [](){std::cout << "Going North!" << std::endl;});
    buttons.emplace_back("Go East", Col2, Row1, 200, 50, font, [](){std::cout << "Going East!" << std::endl;});
    buttons.emplace_back("Go West", Col1, Row2, 200, 50, font, [](){std::cout << "Going West!" << std::endl;});
    buttons.emplace_back("Go South", Col2, Row2, 200, 50, font, [](){std::cout << "Going South!" << std::endl;});
    for(auto &b : buttons) {
        b.render(window);
    }
}

void game::GameScene::combatView() {}

void game::GameScene::setBackground(const std::string &path) {
    background.loadFromFile(path);
}

void game::GameScene::setHUD(const std::string &path) {
    hud.loadFromFile(path);
}

void game::GameScene::setFinished(const bool &_finished) {
    finished = _finished;
}