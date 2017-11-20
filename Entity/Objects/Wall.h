#ifndef GAME_WALL_H
#define GAME_WALL_H

#include "../Entity.h"

class Wall : public Entity {
    public:

    virtual void render();
    virtual void collide(Vec2f* vel);
    virtual void collisionResponse(Entity& entity, Vec2f *vel);
    virtual void update();

    Wall(World* world);

    Wall(World* world, const Vec2f &pos);

    Wall(World* world, const Vec2f &pos, const Vec2f &box);
};

#endif //GAME_WALL_H
