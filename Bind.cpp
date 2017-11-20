#include "Bind.h"
#include "Settings.h"

Bind::Bind(int key) : key(key), state(false) {
    Settings::keyBinds.push_back(this);
}

Bind::~Bind() {

}
