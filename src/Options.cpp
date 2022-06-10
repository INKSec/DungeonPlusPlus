//
// Created by Micha on 10.06.2022.
//

#include "Options.h"
#include <fstream>
#include <exception>

Optionen::Options::Options(sf::RenderWindow &_window) : window(_window) {

    if(!background.loadFromFile("../images/dark_bg.jpg")){
        std::cerr << "Bild konnte nicht geladen werden" << std::endl;
    };
    backgroundImage.setTexture(background);
    if(!font.loadFromFile("../fonts/Arial.ttf")){
        std::cerr << "Font konnte nicht geladen werden" << std::endl;
    };


}
// IO Stream
void Optionen::Options::draw() {
    window.draw(backgroundImage);
    buttons.clear();
    std::ifstream Datei;
    std::vector<std::string> texts;
    std::string tempS;
    try {
        Datei.exceptions(std::ifstream::failbit | std::ifstream::badbit);
        Datei.open("../ConfigIni.txt");
        while (!Datei.eof()) {
            for(size_t i = 0; i<4; i++) {
                Datei >> tempS;
                texts.push_back(tempS);
            }
        }

        Datei.close();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    buttons.emplace_back(texts[0] + " x "+ texts[1], window.getSize().x - 700, window.getSize().y - 500, 200, 50, font,
                         10, sf::Color::White, sf::Color::Black, [this]() {
        // Funktionalitaet klappt noch nicht
    });
    buttons.emplace_back(texts[2] + " x " + texts[3], window.getSize().x - 700, window.getSize().y - 400, 200, 50, font,
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


