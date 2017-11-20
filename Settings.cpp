#include <GL/glew.h>
#include "Settings.h"

std::vector<Bind*> Settings::keyBinds;
Bind* Settings::keyUp = new Bind(SDLK_UP);
Bind* Settings::keyDown = new Bind(SDLK_DOWN);
Bind* Settings::keyLeft = new Bind(SDLK_LEFT);
Bind* Settings::keyRight = new Bind(SDLK_RIGHT);

Settings::Settings() {
    std::cout << "init" << std::endl;
}

Settings::~Settings() {

}

void Settings::setKeybindState(int key, bool state) {
    for(std::vector<Bind*>::iterator it = this->keyBinds.begin(); it != this->keyBinds.end(); ++it) {
        Bind* b = *it;
        if(b->key == key) {
            b->state = state;
        }
    }
}
