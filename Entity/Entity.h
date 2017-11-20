#ifndef GAME_ENTITY_H
#define GAME_ENTITY_H

#include <typeinfo>
#include "../Physics/Vec2f.h"
#include "../Physics/AABB.h"
#include "../World/World.h"

struct Entity {
    virtual void render() = 0;
    virtual void collide(Vec2f* vel) = 0;
    virtual void collisionResponse(Entity& entity, Vec2f* vel) = 0;
    virtual void update() = 0;

    int id;
    bool onGround;
    World* world;

    Entity(World* world);

    Entity(World* world, const Vec2f& pos);
    Entity(World* world, const Vec2f& pos, const Vec2f& box);

    virtual bool operator==(const Entity& other) const {
        if (typeid(*this) != typeid(other))
            return false;

        return id == other.id;
    }

    virtual bool operator!=(const Entity& other) const {
        if (typeid(*this) != typeid(other))
            return false;

        return id != other.id;
    }

    Vec2f position;
    Vec2f velocity;

    AABB box;
};


#endif //GAME_ENTITY_H
