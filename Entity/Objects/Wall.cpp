#include "Wall.h"

void Wall::collide(Vec2f* vel) {
}

void Wall::collisionResponse(Entity& entity, Vec2f *vel) {
    entity.collisionResponse(*this, new Vec2f(0, 0));
}

void Wall::update() {

    this->box.update(this->position);
}

void Wall::render() {
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); {
        glVertex2d(this->position.x, this->position.y);
        glVertex2d(this->position.x + this->box.dim.x, this->position.y);
        glVertex2d(this->position.x + this->box.dim.x, this->position.y + this->box.dim.y);
        glVertex2d(this->position.x, this->position.y + this->box.dim.y);
    }
    glEnd();
}

Wall::Wall(World* world) : Entity(world) {}

Wall::Wall(World* world, const Vec2f &pos) : Entity(world, pos) {}

Wall::Wall(World* world, const Vec2f &pos, const Vec2f &box) : Entity(world, pos, box) {}