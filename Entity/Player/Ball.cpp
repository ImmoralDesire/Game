#include <GL/glew.h>
#include <cmath>
#include <iostream>
#include "Ball.h"

void Ball::collide(Vec2f* vel) {
    for(float x = this->position.x; x < this->position.x + this->box.dim.x; x++) {
        for(float y = this->position.y; y < this->position.y + this->box.dim.y; y++) {
            Entity& entity = this->world->getEntity(x, y);

            if(abs(entity.id) <= this->world->entityList.size() && entity.id != this->id) {
                if(vel->x > 0) {
                    //Right Side of Player
                } else if(vel->x < 0) {
                    //Left Side of Player
                }

                if(vel->y > 0) {
                    //Up Side of Player
                    //this->velocity.y = 0;
                } else if(vel->y < 0) {
                    //Down Side of Player
                    this->onGround = true;
                    this->velocity.y = 0;
                }

                entity.collisionResponse(*this, vel);
            }
        }
    }
}

void Ball::collisionResponse(Entity& entity, Vec2f *vel) {
    this->velocity.x = vel->x * 2;
    this->velocity.y = vel->y * 2;
}

void Ball::update() {
    this->collide(new Vec2f(this->velocity.x, 0));
    this->position.x += this->velocity.x;

    this->collide(new Vec2f(0, this->velocity.y));
    this->position.y += this->velocity.y;

    this->velocity.x *= 0.9f;
    this->velocity.y *= 0.9f;

    if(abs(this->velocity.x) < 0.01f) {
        this->velocity.x = 0.0f;
    }

    if(abs(this->velocity.y) < 0.01f) {
        this->velocity.y = 0.0f;
    }

    this->box.update(this->position);
}

void Ball::render() {
    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); {
        glVertex2d(this->position.x, this->position.y);
        glVertex2d(this->position.x + this->box.dim.x, this->position.y);
        glVertex2d(this->position.x + this->box.dim.x, this->position.y + this->box.dim.y);
        glVertex2d(this->position.x, this->position.y + this->box.dim.y);
    }
    glEnd();
}

void Ball::serve() {

}

Ball::Ball(World* world) : Entity(world) {}

Ball::Ball(World* world, const Vec2f &pos) : Entity(world, pos) {}

Ball::Ball(World* world, const Vec2f &pos, const Vec2f &box) : Entity(world, pos, box) {}