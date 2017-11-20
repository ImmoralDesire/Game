#include "PingPong.h"
#include "Entity/Player/Ball.h"
#include "Entity/Objects/Wall.h"

Mix_Music *music = NULL;

Paddle* player;
Ball* ball;

float maxFPS;

PingPong::PingPong(char *title, float width, float height) : Game(title, width, height) {
}

bool SetOpenGLAttributes() {
    // Set our OpenGL version.
    // SDL_GL_CONTEXT_CORE gives us only the newer version, deprecated functions are disabled
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // 3.2 is part of the modern versions of OpenGL, but most video cards whould be able to run it
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

    // Turn on double buffering with a 24bit Z buffer.
    // You may need to change this to 16 or 32 for your system
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

    return true;
}

bool PingPong::init() {

    if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0) {
        std::cout << "Failed to initialized SDL!" << std::endl;
    }

    window = SDL_CreateWindow(
            this->getTitle(),
            SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED,
            this->getWidth(),
            this->getHeight(),
            SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE);

    if(window == NULL) {
        std::cout << "The window is null??? NANI???" << std::endl;
    }

    this->setIcon();

    player = new Paddle(this->world, Vec2f(50, 50), Vec2f(50, 50));
    ball = new Ball(this->world, Vec2f(200, 30), Vec2f(30, 30));
    //new Ball(this->world, Vec2f(160, 30), Vec2f(30, 30));
    new Wall(this->world, Vec2f(0, 0), Vec2f(this->width, 30));
    //new Wall(this->world, Vec2f(0, this->height - 30), Vec2f(this->width, 30));

    new Wall(this->world, Vec2f(0, 30), Vec2f(30, this->height - 30));
    //new Wall(this->world, Vec2f(this->width - 30, 0), Vec2f(30, this->height));

    new Wall(this->world, Vec2f(300, 100), Vec2f(this->width - 300, 30));
    maxFPS = 60;

    context = SDL_GL_CreateContext(window);
    glewInit();

    RendererGlobal rendererGlobal;

    SetOpenGLAttributes();

    TTF_Init();
    IMG_Init(IMG_INIT_JPG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 4096);

    Mix_VolumeMusic(20);

    music = Mix_LoadMUS("res/music/bg.wav");
    std::cout << Mix_PlayMusic(music, -1) << std::endl;

    SDL_GL_SetSwapInterval(0);

    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, this->getWidth(), 0, this->getHeight(), -1.0, 1.0);
    glViewport(0, 0, this->getWidth(), this->getHeight());
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    SDL_GL_SwapWindow(window);

    Uint32 starting_tick;

    std::cout << "NANI" << std::endl;

    while(loop) {
        SDL_Event event;
        while(SDL_PollEvent(&event)) {
            switch(event.type) {
                case SDL_QUIT:
                    loop = false;
                    std::cout << "CALLED" << std::endl;
                    break;

                case SDL_KEYDOWN:
                    this->handleKeyboardInput(event.key.keysym.sym, true);
                    break;

                case SDL_KEYUP:
                    this->handleKeyboardInput(event.key.keysym.sym, false);
                    break;

                case SDL_WINDOWEVENT:
                    switch(event.window.event)
                    {
                        case SDL_WINDOWEVENT_RESIZED:
                            this->resized();
                            break;
                    }
                    break;
            }
        }

        this->render();
        //player->update();
        this->world->updateEntities();
        //std::cout << this->settings->keyUp->state << std::endl;
        this->lastTick = SDL_GetTicks();
        limitFPS();
    }

    SDL_DestroyWindow(window);

    Mix_FreeMusic(music);

    Mix_CloseAudio();

    TTF_Quit();

    SDL_Quit();
}

void PingPong::render() {
    this->clear(1.0f, 1.0f, 1.0f, 1.0f);
    this->world->renderEntities();
    this->swapBuffer();
}

void PingPong::setIcon() {
    SDL_Surface *surface;     // Declare an SDL_Surface to be filled in with pixel data from an image file
    surface = IMG_Load("icon.png");

    // The icon is attached to the window pointer
    SDL_SetWindowIcon(window, surface);

    // ...and the surface containing the icon pixel data is no longer required.
    SDL_FreeSurface(surface);
}

void PingPong::limitFPS() {
    if((1000 / maxFPS) > SDL_GetTicks() - this->lastTick) {
        SDL_Delay(1000 / maxFPS - (SDL_GetTicks() - this->lastTick));
    }
}