#include <iostream>
#include "Paddle.h"
#include "../../PingPong.h"

void Paddle::render() {
    //std::cout << this->position.x << " " << this->position.y << " " << this->box.dim.x << " " << this->box.dim.y << std::endl;

    glColor3f(1.0f, 0.0f, 1.0f);
    glBegin(GL_QUADS); {
        glVertex2d(this->position.x, this->position.y);
        glVertex2d(this->position.x + this->box.dim.x, this->position.y);
        glVertex2d(this->position.x + this->box.dim.x, this->position.y + this->box.dim.y);
        glVertex2d(this->position.x, this->position.y + this->box.dim.y);
    }
    glEnd();
}

void Paddle::collide(Vec2f* vel) {
    for(float x = this->position.x; x < this->position.x + this->box.dim.x; x++) {
        for(float y = this->position.y; y < this->position.y + this->box.dim.y; y++) {
            Entity& entity = this->world->getEntity(x, y);

            if(abs(entity.id) <= this->world->entityList.size() && entity.id != this->id) {
                if(vel->x > 0) {
                    //Right Side of Player
                    this->position.x = entity.position.x - this->box.dim.x;
                } else if(vel->x < 0) {
                    //Left Side of Player
                    this->position.x = entity.position.x + entity.box.dim.x;
                }

                if(vel->y > 0) {
                    //Right Side of Player
                    this->position.y = entity.position.y - this->box.dim.y;
                    this->velocity.y = 0;
                    this->jumpTicks = 0;
                } else if(vel->y < 0) {
                    //Left Side of Player
                    this->position.y = entity.position.y + entity.box.dim.y;
                    this->onGround = true;
                    this->velocity.y = 0;
                }

                entity.collisionResponse(*this, vel);
            }
        }
    }
}

void Paddle::collisionResponse(Entity& entity, Vec2f *vel) {
}

void Paddle::update() {
    if(Game::instance.settings->keyUp->isPressed() && this->jumpTicks == 0 && this->onGround) {
        //this->velocity.y = 5;
        this->jumpTicks = 40;
    }
    if(Game::instance.settings->keyDown->isPressed()) {
        //this->velocity.y = -5;
    }
    if(Game::instance.settings->keyLeft->isPressed()) {
        this->velocity.x = -5;
    }
    if(Game::instance.settings->keyRight->isPressed()) {
        this->velocity.x = 5;
    }

    if(this->jumpTicks > 0) {
        this->onGround = false;
        this->jumpTicks--;
    }

    this->onGround = false;

    this->position.x += this->velocity.x;
    this->collide(new Vec2f(this->velocity.x, 0));

    this->position.y += this->velocity.y;
    this->collide(new Vec2f(0, this->velocity.y));

    this->velocity.x *= 0.5f;
    this->velocity.y *= 2.0f;

    this->velocity.y = this->jumpTicks / 2.0f;
    this->velocity.y -= this->world->gravity;

    this->box.update(this->position);
}

Paddle::Paddle(World* world) : Entity(world) {}

Paddle::Paddle(World* world, const Vec2f &pos) : Entity(world, pos) {}

Paddle::Paddle(World* world, const Vec2f &pos, const Vec2f &box) : Entity(world, pos, box) {}