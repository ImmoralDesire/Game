cmake_minimum_required(VERSION 3.8)
project(Game)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lmingw32")
set(CMAKE_EXE_LINKER_FLAGS "-static-libgcc -static-libstdc++")

include_directories(${PROJECT_SOURCE_DIR}/include)
link_directories(${PROJECT_SOURCE_DIR}/lib)

set(SOURCE_FILES main.cpp Game.cpp Game.h PingPong.cpp PingPong.h Entity/Player/Paddle.cpp Entity/Player/Paddle.h Entity/Entity.cpp Entity/Entity.h Entity/Player/Ball.cpp Entity/Player/Ball.h Physics/AABB.cpp Physics/AABB.h Physics/Vec2f.cpp Physics/Vec2f.h Bind.cpp Bind.h Settings.cpp Settings.h World/World.cpp World/World.h Renderer/RendererGlobal.cpp Renderer/RendererGlobal.h GlobalInfo.cpp GlobalInfo.h Entity/Objects/Wall.cpp Entity/Objects/Wall.h)
add_executable(${PROJECT_NAME} ${SOURCE_FILES})

target_link_libraries(${PROJECT_NAME}
        mingw32
        SDL2main
        SDL2 SDL2_ttf
        SDL2_image
        SDL2_mixer
        opengl32
        glu32
        glew32)