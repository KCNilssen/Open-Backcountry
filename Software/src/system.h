#ifndef SYSTEM_HPP
#define SYSTEM_HPP

#include <vector>

class SystemState;

class System
{
public:
    //constructor and deconstructor
    System();
    ~System();

    //functions for changing game state
    void pushState(SystemState* state);
    void popState();

    //function to get the current State (note this function must be a pointer)
    SystemState* CurrentState();
    SystemState* PreviousState();

    //game loop function
    void systemLoop();

private:
    std::vector<SystemState*> states;
};

#endif /* SYSTEM_HPP */
