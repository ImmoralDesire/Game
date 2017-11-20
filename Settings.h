#ifndef GAME_SETTINGS_H
#define GAME_SETTINGS_H

#include <vector>
#include <SDL2/SDL.h>
#include "Bind.h"

class Settings {
    public:
    Settings();
    virtual ~Settings();
    static std::vector<Bind*> keyBinds;
    static Bind* keyUp;
    static Bind* keyDown;
    static Bind* keyLeft;
    static Bind* keyRight;

    void setKeybindState(int key, bool state);
};


#endif //GAME_SETTINGS_H
