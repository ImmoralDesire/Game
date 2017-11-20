#ifndef GAME_BIND_H
#define GAME_BIND_H

#include <iostream>

class Bind {
    public:
    int key;
    bool state;

    Bind(int key);
    virtual ~Bind();

    bool isPressed() {
        return state;
    }
};


#endif //GAME_BIND_H
