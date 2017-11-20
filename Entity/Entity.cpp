#include <iostream>
#include <cmath>
#include "Entity.h"

Entity::Entity(World* world) : world(world), box(Vec2f(0, 0)), id(world->entityList.size() + 1) {
    world->entityList.push_back(this);
}

Entity::Entity(World* world, const Vec2f& pos) : world(world), position(pos), box(Vec2f(0, 0)), id(world->entityList.size() + 1) {
    world->entityList.push_back(this);
}

Entity::Entity(World* world, const Vec2f& pos, const Vec2f& box) : world(world), position(pos), box(box), id(world->entityList.size() + 1) {
    world->entityList.push_back(this);
}