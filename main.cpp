#include "PingPong.h"

int main(int argc, char* argv[]) {
    PingPong* game = new PingPong("Pong!", 600, 600);
    game->init();
}