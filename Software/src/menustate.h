#ifndef MENU_STATE_HPP
#define MENU_STATE_HPP

#include "systemstate.h"  //we will be deriving this abstract classes functions.

struct MenuOption {
    std::string optionName;
    std::string optionImagePath;
};

class MenuState : public SystemState  //make GameState functions public to this class so we can derive it's functions.
{

protected:
    std::vector<MenuOption> menuOptions;
    int NUM_OPTIONS;
    int OPTIONS_PER_ROW;

    int menuPosition;
    
public:
    //the three functions are teh three things we must do.
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();
};

#endif /* GAME_STATE_START_HPP */