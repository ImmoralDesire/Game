#ifndef GAME_RENDERERGLOBAL_H
#define GAME_RENDERERGLOBAL_H


#include <GL/glew.h>

class RendererGlobal {
    public:
    RendererGlobal();

    private:
    bool setupFrameBuffers();

    GLuint fbo;
    GLuint fboTex;
    GLuint fboRbo;
};


#endif //GAME_RENDERERGLOBAL_H
