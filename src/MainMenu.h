//
// Created by Micha on 25.05.2022.
//
#pragma once


#include <utility>
#include <vector>
#include <string>
#include <functional>
#include <SFML/Graphics.hpp>
#include "GameScene.h"
#include "DungeonLayout.h"
#include "DungeonMap.h"
#include "Options.h"

namespace sfm {

    class MenuOption {
    public:

        explicit MenuOption(std::string, std::function<void(void)>);
        void select();
        void setText(const std::string &_text);
        const std::string &getText() const;

    private:
        std::string text;
        std::function<void(void)> callback;
    };

    class MenuLayout {
        friend class Menu;
    public:
        explicit MenuLayout(unsigned int spacing = 50, const sf::Vector2f &origin = sf::Vector2f(0.5, 0.5));
        MenuLayout(const MenuLayout &copy);
        void setSpacing(unsigned int spacing);
        void setOrigin(const sf::Vector2f &origin);
        static const MenuLayout VerticleCentered;
        static const MenuLayout VerticleLeft;
    private:
        void apply(std::vector<sf::Text> &options, const sf::Vector2u &windowSize) const;
        unsigned int spacing{}; //spacing between each option

        sf::Vector2f origin;
    };

    class Menu {
    public:
        void display(sf::RenderWindow &window);
        void addOption(const MenuOption &option);

        void setBackground(const std::string &path);
        void setTimeout(sf::Time timeout, std::function<void(void)> callback);
        void setExitCallback(std::function<void(void)> callback);
        void setLayout(const MenuLayout &_style);
        void setTemplateText(const sf::Text &t);
        void setFinished(const bool &_finished);
        void setFinished(const std::string &_finished);
        static void buildMenu(sf::RenderWindow&, int&, int&, int, const std::string&, sfm::Menu);
    private:
        std::vector<MenuOption> options;
        sf::Texture background;
        sf::Time timeout;
        std::function<void(void)> timeoutCallback;
        std::function<void(void)> exitCallback;
        MenuLayout layout;
        sf::Text templateText;
        bool finished = false;
    };

}
