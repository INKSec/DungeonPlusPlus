#include "GameScene.h"
#include <iostream>

using namespace game;

game::GameScene::GameScene() {
    font.loadFromFile("../fonts/Arial.ttf");
}

void game::GameScene::display(sf::RenderWindow &window) {
    setHUD("../images/hud.jpg");
    sf::Sprite _hud;
    _hud.setTexture(hud);
    _hud.setPosition(0, window.getSize().y - _hud.getGlobalBounds().height);
    sf::Sprite bg;
    bg.setTexture(background);
    bg.setScale(window.getSize().x / (float)background.getSize().x,
                window.getSize().y / (float)background.getSize().y);
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
                default:
                    break;
            }
        }
        sf::sleep(sf::milliseconds(50));
    }
}

void GameScene::explorationView(sf::RenderWindow &window) {
    const unsigned int Row1 {window.getSize().y - 200};
    const unsigned int Row2 {window.getSize().y - 100};
    const unsigned int Col1 {100};
    const unsigned int Col2 {350};
    buttons.emplace_back("Go North", Col1, Row1, 200, 50, font);
    buttons.emplace_back("Go East", Col2, Row1, 200, 50, font);
    buttons.emplace_back("Go West", Col1, Row2, 200, 50, font);
    buttons.emplace_back("Go South", Col2, Row2, 200, 50, font);
    for(auto &b : buttons) {
        b.render(window);
    }
}

void GameScene::combatView() {}

void game::GameScene::setBackground(const std::string &path) {
    background.loadFromFile(path);
}

void game::GameScene::setHUD(const std::string &path) {
    hud.loadFromFile(path);
}

void game::GameScene::setFinished(const bool &_finished) {
    finished = _finished;
}