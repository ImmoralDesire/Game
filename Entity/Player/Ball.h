#ifndef GAME_BALL_H
#define GAME_BALL_H

#include "../Entity.h"

class Ball : public Entity {
    public:

    virtual void render();
    virtual void collide(Vec2f* vel);
    virtual void collisionResponse(Entity& entity, Vec2f *vel);
    virtual void update();

    void serve();

    Ball(World* world);

    Ball(World* world, const Vec2f &pos);

    Ball(World* world, const Vec2f &pos, const Vec2f &box);
};


#endif //GAME_BALL_H
