#ifndef GPS_MENU_STATE_HPP
#define GPS_MENU_STATE_HPP

#include <iostream>
#include <string>

#include "../menustate.h"

class GpsMenu : public MenuState
{
    void loadapplication();

public:
    GpsMenu(System* SYSTEM_HPP);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();
};

GpsMenu::GpsMenu(System* system)
{
    menuPosition = 0;
    NUM_OPTIONS = 8;
    OPTIONS_PER_ROW = 4;
    
    menuOptions.push_back((struct MenuOption){"Live Data", "path/to/menuoption1_image"});
    menuOptions.push_back((struct MenuOption){"Satellites", "path/to/menuoption2_image"});
    menuOptions.push_back((struct MenuOption){"Option3", "path/to/menuoption3_image"});
    menuOptions.push_back((struct MenuOption){"Settings", "path/to/menuoption4_image"});    // This will add gps settings menu to stack and jump there

    this->system = system;

    // Draw screen
    draw(0.0);
}

void GpsMenu::draw(const float dt)
{

    std::cout << "\n\n\n\n" << "   " << "Main Menue \n" << std::endl;

    for(unsigned int i = 0; i < menuOptions.size(); i++)
    {
        if (menuPosition == i) {
            std::cout << "   -> ";
        } else {
            std::cout << "      ";
        }
        std::cout << menuOptions[i].optionName;

        if (i % OPTIONS_PER_ROW == OPTIONS_PER_ROW-1) {
            std::cout << std::endl;
        }
    }

    std::cout << "\n\n\n\n" << std::endl;
    
}

void GpsMenu::update(const float dt) {}

void GpsMenu::handleInput()
{
    char input;
    std::cout << "Enter input: "; // Type a number and press enter
    std::cin >> input; // Get user input from the keyboard

    switch (input) {
        case 'w':   // up
            if (menuPosition - OPTIONS_PER_ROW >= 0) {
                menuPosition-=OPTIONS_PER_ROW;
            }
            break;
        case 's':   // down
            if (menuPosition + OPTIONS_PER_ROW < NUM_OPTIONS) {
                menuPosition+=OPTIONS_PER_ROW;
            }
            break;
        case 'a':   // left
            if (menuPosition > 0) {
                menuPosition--;
            }            
            break;
        case 'd':   // right
            if (menuPosition+1 < NUM_OPTIONS) {
                menuPosition++;
            }
            break;

        case 'e':   // enter/select
            // system->pushState(new (game));
            break;
        case 'q':   // quit
            system->popState();
            break;
        
        defualt:
            std::cout << "Input does not trigger anything, try again. (Default Handled)" << std::endl;
            break;
    }

}

void GpsMenu::loadapplication() {}

#endif /* GPS_MENU_STATE_HPP */