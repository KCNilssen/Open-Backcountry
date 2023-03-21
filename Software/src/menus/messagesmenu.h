#ifndef MESSAGES_MENU_STATE_HPP
#define MESSAGES_MENU_STATE_HPP

#include <iostream>
#include <string>

#include "../menustate.h"

enum MessageGroupStatus {
    GROUP_HAS_UNSENT,
    GROUP_HAS_NEW,
    GROUP_NO_STATUS
};

enum OnlineStatus {
    ONLINE,
    OFFLINE
};

struct MessageGroupOptions {
    std::string messageGroupName;
    int messageGroupStatus; // New messages, unsent messages, ect....
    std::string messageTextDisplay; // Sample of message to display?
    int onlineStatus;
};

class MessagesMenu : public MenuState
{
    void loadapplication();
    std::vector<MessageGroupOptions> menuOptions;

public:
    MessagesMenu(System* system);

    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();
};

MessagesMenu::MessagesMenu(System* system)
{
    menuPosition = 0;
    OPTIONS_PER_ROW = 1;


    // Loads messages from storage and creates messages options
    // * for message group in stored messages groups"
    //      Push back the messages group thingies

    // Get message groups from storage, sort them by time

    NUM_OPTIONS = 8; // Set number of message groups
    // menuOptions.push_back((struct MessageGroupOptions){messageGroupName, menuOptionstatus, messageTextDisplay, onlineStatus});
    menuOptions.push_back((struct MessageGroupOptions){"Group1", GROUP_NO_STATUS, "Some text for display", ONLINE});
    menuOptions.push_back((struct MessageGroupOptions){"Group2", GROUP_NO_STATUS, "that is put here", ONLINE});
    menuOptions.push_back((struct MessageGroupOptions){"Group3", GROUP_NO_STATUS, "so that we have", OFFLINE});
    menuOptions.push_back((struct MessageGroupOptions){"Group4", GROUP_NO_STATUS, "something to look at", OFFLINE});
    menuOptions.push_back((struct MessageGroupOptions){"Group5", GROUP_NO_STATUS, "that emulates the most", ONLINE});
    menuOptions.push_back((struct MessageGroupOptions){"Group6", GROUP_NO_STATUS, "recent message from a", OFFLINE});
    menuOptions.push_back((struct MessageGroupOptions){"Group7", GROUP_NO_STATUS, "message group and", OFFLINE});
    menuOptions.push_back((struct MessageGroupOptions){"Group8", GROUP_NO_STATUS, "shows it here in messages", OFFLINE});
    
    
    this->system = system;

    // Draw screen
    draw(0.0);
}

void MessagesMenu::draw(const float dt)
{

    std::cout << "\n" << "   " << "Messages Menue:" << "\n" << std::endl;

    for(unsigned int i = 0; i < menuOptions.size(); i++)
    {
        if (menuPosition == i) {
            std::cout << "   -> ";
        } else {
            std::cout << "      ";
        }

        std::cout << menuOptions[i].messageGroupName;

        if (i % OPTIONS_PER_ROW == OPTIONS_PER_ROW-1) {
            std::cout << std::endl;
        }
    }

    std::cout << "\n" << std::endl;
    
}

void MessagesMenu::update(const float dt) {}

void MessagesMenu::handleInput()
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
            // if (menuPosition > 0) {
            //     menuPosition--;
            // }            
            break;
        case 'd':   // right
            // if (menuPosition+1 < NUM_OPTIONS) {
            //     menuPosition++;
            // }
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

void MessagesMenu::loadapplication() {}

#endif /* MESSAGES_MENU_STATE_HPP */