#ifndef APPLICATION_STATE_HPP
#define APPLICATION_STATE_HPP

#include "systemstate.h"


class ApplicationState : public SystemState
{
protected:

private:

public:
    virtual void draw(const float dt);
    virtual void update(const float dt);
    virtual void handleInput();

};

#endif /* GAME_STATE_EDITOR_HPP */