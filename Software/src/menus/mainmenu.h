#ifndef MAIN_MENU_STATE__HPP
#define MAIN_MENU_STATE__HPP

#include <iostream>
#include <string>

#include "../menustate.h" 

#include "messagesmenu.h"
#include "weathermenu.h"
#include "gpsmenu.h"
#include "mapsmenu.h"
#include "loramenu.h"
#include "sensorsmenu.h"
#include "avalanchemenu.h"
#include "loggingmenu.h"
#include "settingsmenu.h"

// #include "secondmenu.h"

class MainMenu : public MenuState
{
    // void loadapplication();

public:
    MainMenu(System* system);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();
};


MainMenu::MainMenu(System* system)
{
    // menuName = "Main Menu";
    menuPosition = 0;
    NUM_OPTIONS = 9;
    OPTIONS_PER_ROW = 4;
    
    menuOptions.push_back((struct MenuOption){"Messages ", "path/to/menuoption1_image"});
    menuOptions.push_back((struct MenuOption){"Weather  ", "path/to/menuoption2_image"});
    menuOptions.push_back((struct MenuOption){"GPS      ", "path/to/menuoption3_image"});
    menuOptions.push_back((struct MenuOption){"Maps     ", "path/to/menuoption4_image"});

    menuOptions.push_back((struct MenuOption){"Lora     ", "path/to/menuoption5_image"});
    menuOptions.push_back((struct MenuOption){"Sensors  ", "path/to/menuoption6_image"});
    menuOptions.push_back((struct MenuOption){"Avalanche", "path/to/menuoption7_image"});
    menuOptions.push_back((struct MenuOption){"Logging  ", "path/to/menuoption8_image"});

    menuOptions.push_back((struct MenuOption){"Settings ", "path/to/menuoption9_image"});

    this->system = system;

    // draw screen
    draw(0.0);
}

void MainMenu::draw(const float dt)
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

void MainMenu::update(const float dt) {
    // Maybe a call to a not made class statusbar with statusbar.update
    // and might "draw" itsself to current screen framebuffer if 
    // changes/updates were made.
}

void MainMenu::handleInput()
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
            } else if (NUM_OPTIONS +1 - menuPosition > 0) {
                menuPosition = NUM_OPTIONS-1;
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
            switch (menuPosition) {
                case 0: // Messages menu selected. Push MessagesMenu to system state vector
                    system->pushState(new MessagesMenu(system)); 
                    break;
                case 1: // Weather menu selected. Push WeatherMenu to system state vector
                    system->pushState(new WeatherMenu(system)); 
                    break;
                case 2: // GPS menu selected. Push GPSMenu to system state vector
                    system->pushState(new GpsMenu(system)); 
                    break;
                case 3: // Maps menu selected. Push MapsMenu to system state vector
                    system->pushState(new MapsMenu(system)); 
                    break;
                case 4: // Lora menu selected. Push LoraMenu to system state vector
                    system->pushState(new LoraMenu(system)); 
                    break;
                case 5: // Sensors menu selected. Push SensorsMenu to system state vector
                    system->pushState(new SensorsMenu(system)); 
                    break;
                case 6: // Avalanche menu selected. Push AvalancheMenu to system state vector
                    system->pushState(new AvalancheMenu(system)); 
                    break;
                case 7: // Logging menu selected. Push LoggingMenu to system state vector
                    system->pushState(new LoggingMenu(system)); 
                    break;
                case 8: // Settings menu selected. Push SettingsMenu to system state vector
                    system->pushState(new SettingsMenu(system)); 
                    break;                
            }
            break;
        case 'q':   // quit
            system->popState();
            break;
        
        defualt:
            std::cout << "Input does not trigger anything, try again. (Default Handled)" << std::endl;
            break;
    }

}

// void MainMenu::loadapplication() {}

#endif /* MAIN_MENU_STATE__HPP */