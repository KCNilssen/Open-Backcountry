#ifndef AVALANCHE_MENU_STATE_HPP
#define AVALANCHE_MENU_STATE_HPP

#include <iostream>
#include <string>

#include "../menustate.h"

class AvalancheMenu : public MenuState
{
    // void loadapplication();

public:
    AvalancheMenu(System* system);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();
};

AvalancheMenu::AvalancheMenu(System* system)
{
    menuPosition = 0;
    NUM_OPTIONS = 8;
    OPTIONS_PER_ROW = 4;
    
    menuOptions.push_back((struct MenuOption){"Option1", "path/to/menuoption1_image"});
    menuOptions.push_back((struct MenuOption){"Option2", "path/to/menuoption2_image"});
    menuOptions.push_back((struct MenuOption){"Option3", "path/to/menuoption3_image"});
    menuOptions.push_back((struct MenuOption){"Option4", "path/to/menuoption4_image"});

    menuOptions.push_back((struct MenuOption){"Option5", "path/to/menuoption5_image"});
    menuOptions.push_back((struct MenuOption){"Option6", "path/to/menuoption6_image"});
    menuOptions.push_back((struct MenuOption){"Option7", "path/to/menuoption7_image"});
    menuOptions.push_back((struct MenuOption){"Option8", "path/to/menuoption8_image"});

    this->system = system;

    // Draw screen
    draw(0.0);
}

void AvalancheMenu::draw(const float dt)
{

    std::cout << "\n\n\n\n" << "   " << "Avalanche Menue \n" << std::endl;

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

void AvalancheMenu::update(const float dt) {}

void AvalancheMenu::handleInput()
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

// void SecondMenu::loadapplication() {}

#endif /* AVALANCHE_MENU_STATE_HPP */