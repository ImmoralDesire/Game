#include <stdexcept>
#include "RendererGlobal.h"

RendererGlobal::RendererGlobal() {
    if (!setupFrameBuffers()) {
        throw std::runtime_error("FRAME BUFFER ERROR: NOT COMPLETE");
    }
}

bool RendererGlobal::setupFrameBuffers() {
    glGenFramebuffers(1, &fbo);
    glBindFramebuffer(GL_FRAMEBUFFER, fbo);

    //Disable new framebuffer
    glBindFramebuffer(GL_FRAMEBUFFER, 0);

    return true;
}
