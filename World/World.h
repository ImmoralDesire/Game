#ifndef GAME_WORLD_H
#define GAME_WORLD_H


#include <vector>
#include "../Renderer/RendererGlobal.h"

class Entity;

class World {
    public:
    std::vector<Entity*> entityList;
    float gravity;

    World();
    virtual ~World();

    Entity& getEntity(float x, float y);

    void renderEntities();
    void updateEntities();
};


#endif //GAME_WORLD_H
