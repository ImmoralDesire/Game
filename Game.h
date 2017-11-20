#ifndef GAME_GAME_H
#define GAME_GAME_H

#include <string>
#include <iostream>
#include <GL/glew.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>
#include "Settings.h"
#include "World/World.h"
#include "Renderer/RendererGlobal.h"
#include "Entity/Player/Paddle.h"

class Game {
    private:
    const char* title;

    public:
        bool loop;
        int width;
        int height;
        SDL_Window* window;
        SDL_GLContext context;
        Settings* settings;
        World* world;
        Uint32 lastTick;

        static Game& instance;
        Game(char* title, int width, int height) : title(title), loop(true), width(width), height(height), world(new World()) {};
        ~Game() {};

        virtual bool init() = 0;
        virtual void render() = 0;
        virtual void setIcon() = 0;

        virtual void handleKeyboardInput(int key, bool state);
        virtual void handleMouseInput();


        const char* getTitle() const {
            return title;
        }

        float getWidth() const {
            return width;
        }

        float getHeight() const {
            return height;
        }

        SDL_Window *getWindow() const {
            return window;
        }

        void setTitle(const char* title) {
            Game::title = title;
        }

        void setWindow(SDL_Window *window) {
            Game::window = window;
        }

        void clear(float r, float g, float b, float a) {
            glClearColor(r, g, b, a);
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

        void swapBuffer() {
            SDL_GL_SwapWindow(window);
        }

        void resized() {
            SDL_GetWindowSize(window, &width, &height);
            glMatrixMode(GL_PROJECTION);
            glLoadIdentity();
            glOrtho(0, width, 0, height, -1.0, 1.0);
            glViewport(0, 0, width, height);
            glMatrixMode(GL_MODELVIEW);
            glLoadIdentity();
        }
};

#endif //GAME_GAME_H
