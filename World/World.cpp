#include <iostream>
#include "World.h"
#include "../Entity/Entity.h"

World::World() : gravity(9.81f) {

}

World::~World() {

}

Entity& World::getEntity(float x, float y) {
    for(std::vector<Entity*>::iterator it = entityList.begin(); it != entityList.end(); it++) {
        Entity *entity = *it;

        if(entity->id == 1) continue;
        if ((x < entity->position.x + entity->box.dim.x &&
             x > entity->position.x) &&
            (y < entity->position.y + entity->box.dim.y &&
             y > entity->position.y)) {
            return *entity;
        }
    }
}

void World::renderEntities() {
    for (std::vector<Entity*>::iterator it = entityList.begin(); it != entityList.end(); it++) {
        Entity *entity = *it;
        entity->render();
    }
}

void World::updateEntities() {
    for (std::vector<Entity*>::iterator it = entityList.begin(); it != entityList.end(); it++) {
        Entity *entity = *it;
        entity->update();
    }
}