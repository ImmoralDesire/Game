#include "Game.h"

void Game::handleKeyboardInput(int key, bool state) {
    this->settings->setKeybindState(key, state);
}

void Game::handleMouseInput() {

}
