//
// Created by Micha on 10.06.2022.
//

#include "Options.h"

Optionen::Options::Options(sf::RenderWindow &_window) : window(_window) {

    if(!background.loadFromFile("../images/dark_bg.jpg")){
        std::cerr << "Bild konnte nicht geladen werden" << std::endl;
    };
    backgroundImage.setTexture(background);
    if(!font.loadFromFile("../fonts/Arial.ttf")){
        std::cerr << "Font konnte nicht geladen werden" << std::endl;
    };


}

void Optionen::Options::draw() {
    window.draw(backgroundImage);
    buttons.clear();
    buttons.emplace_back("Option1", window.getSize().x - 700, window.getSize().y - 500, 200, 50, font,
                         10, sf::Color::White, sf::Color::Black, [this]() {

    });
    buttons.emplace_back("Option2", window.getSize().x - 700, window.getSize().y - 400, 200, 50, font,
                         10, sf::Color::White, sf::Color::Black, [this]() {
            });
    buttons.emplace_back("back", window.getSize().x - 700, window.getSize().y - 300, 200, 50, font,
                         10, sf::Color::White, sf::Color::Black, [this]() {
            });
    for(auto &b : buttons) {
        b.render(window);
    }
    window.display();
}


