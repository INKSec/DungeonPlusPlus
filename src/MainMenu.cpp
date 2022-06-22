#include <iostream>
#include <utility>
#include "MainMenu.h"

using namespace sfm;

// Menu Options
// Constructor
MenuOption::MenuOption(std::string text, std::function<void(void)> callback)
:text(std::move(text)), callback(std::move(callback)) { }

void MenuOption::select() {
    if(callback) {callback();}
}

void MenuOption::setText(const std::string &_text) {
    text = _text;
}

const std::string &MenuOption::getText() const {
    return text;
}

const MenuLayout MenuLayout::VerticleCentered = MenuLayout(50, sf::Vector2f(0.50, 0.5));

//MenuLayout Methods
MenuLayout::MenuLayout(unsigned int spacing, const sf::Vector2f &origin) {
    setSpacing(spacing);
    setOrigin(origin);
}//end constructor


MenuLayout::MenuLayout(const MenuLayout &other) {
    this->spacing = other.spacing;
    this->origin = other.origin;
}//end copy constructor


void MenuLayout::setSpacing(unsigned int spacing) {
    this->spacing = spacing;
}//end setSpacing


void MenuLayout::setOrigin(const sf::Vector2f &origin) {
    this->origin = origin;
    if(this->origin.x > 1.0) {
        this->origin.x = 1.0;
    }
    if(this->origin.y > 1.0) {
        this->origin.y = 1.0;
    }
}//end setOrigin


void MenuLayout::apply(std::vector<sf::Text> &options, const sf::Vector2u &windowSize) const {
    if(options.empty()) { return; } //no options, do nothing

    sf::Vector2f orig; //origin position in pixels, instead of percentages
    orig.x = static_cast<float>(windowSize.x) * this->origin.x;
    orig.y = static_cast<float>(windowSize.y) * this->origin.y;
    //since we have n number of options, calculate where the first one will go
    int n = static_cast<int>(options.size());
    auto osize = options[0].getGlobalBounds(); //assume all options are the same height
    if(n % 2) { //odd number of options
        orig.y = orig.y - static_cast<float>((n / 2)) * (osize.height + static_cast<float>(spacing));
    }
    else { //even number of options
        orig.y = orig.y - (spacing/2.0f) - (osize.height/2.0f) - (n/2 - 1)*(spacing+osize.height);
    }

    for(sf::Text &text : options) { //use reference to update the position
        sf::FloatRect rect = text.getLocalBounds();
        //center text origin in the middle of the text
        text.setOrigin(rect.left + rect.width/2.0f,
                       rect.top + rect.height/2.0f);
        text.setPosition(orig); //set option position on the screen
        orig.y += osize.height + spacing; //calculate next position
    }
}//end apply



//Menu Methods
void Menu::display(sf::RenderWindow &window) {
    sf::Sprite backg;
    backg.setTexture(background);
    backg.setScale(static_cast<float>(window.getSize().x) / (float)background.getSize().x,
                   static_cast<float>(window.getSize().y) / (float)background.getSize().y);
    std::vector<sf::Text> texts;
    sf::Text text = this->templateText;
    for(const auto &o : options) {
        text.setString(o.getText());
        texts.push_back(text);
    }

    window.clear();
    window.draw(backg); //draw background
    layout.apply(texts, window.getSize()); //apply the layout on the options
    for(auto &t : texts) { //draw the options
        window.draw(t);
    }
    window.display();

    int i;
    // while for Main Menu checks if a Button is selected
    sf::Clock clock;
    while(!finished) {
        sf::Event e{};
        while(window.pollEvent(e)) {
            switch(e.type) {
                case sf::Event::Closed:
                    finished = true;
                    if(exitCallback) { exitCallback(); }
                    break;
                case sf::Event::Resized:
                case sf::Event::GainedFocus:
                    window.clear();
                    window.draw(backg); //draw background
                    for(auto &t : texts) { // draw buttons
                        window.draw(t);
                    }
                    window.display();
                    break;
                case sf::Event::MouseButtonReleased:
                    for(i = 0; i < texts.size(); i++) {
                        if(texts[i].getGlobalBounds().contains(static_cast<float>(e.mouseButton.x),
                                                               static_cast<float>(e.mouseButton.y))) {
                            //this option was clicked
                            options[i].select();
                            break;
                        }
                    }
                    break;
                default:
                    break;
            }
        }
        sf::sleep(sf::milliseconds(50));
        if(timeout > sf::seconds(0.0) && clock.getElapsedTime() >= timeout) {
            //this menu has a timeout and we have reached it
            finished = true;
            if(timeoutCallback) { timeoutCallback(); }
        }
    }
}


void Menu::addOption(const MenuOption &option) {
    options.push_back(option);
}





void Menu::setBackground(const std::string &path) {
    background.loadFromFile(path);
}


void Menu::setTimeout(sf::Time timeout, std::function<void(void)> callback) {
    this->timeout = timeout;
    this->timeoutCallback = std::move(callback);
}


void Menu::setExitCallback(std::function<void(void)> callback) {
    exitCallback = std::move(callback);
}


void Menu::setLayout(const MenuLayout &_layout) {
    layout = _layout;
}


void Menu::setTemplateText(const sf::Text &t) {
    templateText = t;
}

// for requirement function overload
void Menu::setFinished(const bool &_finished) {
    finished = _finished;
}
// same as above
void Menu::setFinished(const std::string &_finished) {
    if(_finished == "true"){
        finished = true;
    } else if (_finished == "false") {
        finished = false;
    }
}



void splashScreenCallback() {};

// draws menu
void Menu::buildMenu(sf::RenderWindow& window, int &WINDOW_WIDTH, int &WINDOW_HEIGHT, int ROOM_COUNT,
                     const std::string& GAME_TITLE, sfm::Menu splash) {

    auto player{std::make_shared<game::Player>()};
    game::DungeonLayout dungeonLayout;
    game::DungeonLayout::roomMap rooms{dungeonLayout.generateDungeon(ROOM_COUNT)};
    gui::DungeonMap dungeonMap{window, rooms};
    gui::Inventory inventory{window, player};
    gui::GameScene gamescene{window, player, inventory, dungeonLayout, dungeonMap};
    Optionen::Options optionsScreen(window);
    // menu closes when finished true
    bool finished{false};
    bool options {false};
    sfm::Menu mainmenu;
    // sets state for clicked buttons
    sfm::MenuOption opt("Start", [&mainmenu, &gamescene, &dungeonLayout, &options]() {
        // requirement function overload (String)
        mainmenu.setFinished("true");
        options = false;
        gamescene.display(dungeonLayout.getCurrentRoom());
    });
    mainmenu.addOption(opt);

    sfm::MenuOption opt2("Optionen", [&mainmenu, &optionsScreen, &options, &WINDOW_WIDTH, &WINDOW_HEIGHT]() {
        // requirement function overload (Bool)
        mainmenu.setFinished(true);
        options = true;
        optionsScreen.draw(WINDOW_WIDTH, WINDOW_HEIGHT);
    });
    mainmenu.addOption(opt2);
    // exit

    sfm::MenuOption opt3("Beenden", [&mainmenu, &finished]() { mainmenu.setFinished(true), finished = true; });
    mainmenu.addOption(opt3);
    mainmenu.setLayout(sfm::MenuLayout::VerticleCentered);
    mainmenu.setBackground("../images/wald.png");
    sf::Font font;
    sf::Text text;
    font.loadFromFile("../fonts/Arial.ttf");
    text.setFont(font);
    mainmenu.setTemplateText(text);

    //create window and display menu
    window.create(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), GAME_TITLE);
    splash.display(window);
    mainmenu.display(window);

    // while to get button functions

    sf::Clock clock;
    while (!finished) {
        sf::Event e{};
        while (window.pollEvent(e)) {
            switch (e.type) {
                case sf::Event::Closed:
                    finished = true;
                    break;
                case sf::Event::MouseButtonReleased:
                    // get buttons for option screen
                    if(options) {
                        for (gui::Button &b: optionsScreen.getButtons()) {
                            if (b.getShape().getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)) {
                                b.clicked();
                                break;
                            }
                        }
                        // get options for gamescene
                    } else {
                        for (gui::Button &b: gamescene.getButtons()) {
                            if (b.getShape().getGlobalBounds().contains(e.mouseButton.x, e.mouseButton.y)) {
                                b.clicked();
                                break;
                            }
                        }
                    }
                    break;
                case sf::Event::KeyPressed:
                    if (e.key.code == sf::Keyboard::Escape) {
                        finished = true;
                    }
                    break;
                default:
                    break;
            }
        }
        if(!window.isOpen()) {
            finished = true;
        }
        sf::sleep(sf::milliseconds(50));
    }
}
