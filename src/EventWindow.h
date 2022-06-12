#ifndef DUNGEONPLUSPLUS_EVENTWINDOW_H
#define DUNGEONPLUSPLUS_EVENTWINDOW_H

#include <vector>
#include <SFML/Graphics.hpp>
#include "Button.h"
#include "GameScene.h"

namespace gui {

    class GameScene;

    class EventWindow {
    public:
        explicit EventWindow(sf::RenderWindow &_window, std::string _eventText, std::string _button1Text, std::function<void(void)> callback1, std::string _button2Text, std::function<void(void)> callback2);
        void draw();
        std::vector<Button> getButtons() const;
    private:
        sf::RenderWindow &window;
        std::vector<Button> buttons;
        std::string eventText, button1Text, button2Text;
        std::function<void(void)> button1Callback, button2Callback;
    };

}

#endif //DUNGEONPLUSPLUS_EVENTWINDOW_H
