#ifndef GAME_PINGPONG_H
#define GAME_PINGPONG_H

#include "Game.h"

class PingPong : Game {
    public:

    PingPong(char* title, float width, float height);

    ~PingPong();

    virtual bool init();
    virtual void render();

private:
    virtual void setIcon();
    void limitFPS();
};

#endif //GAME_PINGPONG_H
