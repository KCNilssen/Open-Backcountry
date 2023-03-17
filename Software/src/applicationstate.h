#ifndef APPLICATION_STATE_HPP
#define APPLICATION_STATE_HPP

#include "systemState.h"


class PlayState : public SystemState
{
protected:

private:

public:
    virtual void draw(const float dt) {};
    virtual void update(const float dt) {};
    virtual void handleInput() {};

};

#endif /* GAME_STATE_EDITOR_HPP */