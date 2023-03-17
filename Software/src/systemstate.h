#ifndef SYSTEM_STATE_HPP
#define SYSTEM_STATE_HPP

#include "system.h" //doesn't' exist yet

class SystemState
{
public:
    virtual ~SystemState() {};
    virtual void draw(const float dt) = 0;
    virtual void update(const float dt) = 0;
    virtual void handleInput() = 0;

protected:
    System* system;
};

#endif /* GAME_STATE_HPP */