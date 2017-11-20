#ifndef GAME_PADDLE_H
#define GAME_PADDLE_H

#include "../Entity.h"

class Paddle : public Entity {
    public:
    int jumpTicks;

    Paddle(World* world);

    Paddle(World* world, const Vec2f &pos);

    Paddle(World* world, const Vec2f &pos, const Vec2f &box);

    bool operator==(const Entity& other) const {
        if (!Entity::operator==(other))
            return false;

        return id == static_cast<const Paddle&>(other).id;
    }

    bool operator!=(const Entity& other) const {
        if (!Entity::operator==(other))
            return false;

        return id != static_cast<const Paddle&>(other).id;
    }

    virtual void render();
    virtual void collide(Vec2f* vel);
    virtual void update();
    virtual void collisionResponse(Entity& entity, Vec2f *vel);
};


#endif //GAME_PADDLE_H
