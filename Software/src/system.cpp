#include <iostream>

#include "system.h"
#include "systemstate.h"

const int WINDOW_HEIGHT = 240;
const int WINDOW_WIDTH = 400;

System::System()
{
    // Create main sprite (framebuffer) for drawing to screen
    // Set framerate for screen refreshing?
}

void System::pushState(SystemState* state)
{
    states.push_back(state);
}

void System::popState()
{
    // states.back();
    delete states.back();
    states.pop_back();

    // If we somehow dont have any system states in our vector then exit program. 
    // THIS SHOULD NEVER HAPPEN
    if (states.empty() || CurrentState() == nullptr) {
        std::cout << "We shouldnt be here but pressing q on main menu will cause this \n" << std::endl;
        exit(EXIT_FAILURE);
    }

}

System::~System()
{
    while (!states.empty())
        popState();
}

SystemState* System::CurrentState()
{
    if (states.empty())
        return nullptr;
    else
        return states.back();
}

SystemState* System::PreviousState()
{
    if (states.size() < 2)
        return nullptr;
    else
        return states.at(states.size()-1);
}

void System::systemLoop()
{

    while (1)
    {
        //get user input for current game state
        CurrentState()->handleInput();

        //update anything neccessary
        CurrentState()->update(0.00);

        //draw anything in the current game state
        CurrentState()->draw(0.00);
    }
}
